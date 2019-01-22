#include "tasksview.h"
#include "ui_tasksview.h"

#include <QFileInfo>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>

#include "tasksmodel.h"
#include "dlgjsonviewer.h"

#include "config.h"
using Configuration::cfg;

#include <iostream>

#define TRC(s) std::cerr << s << std::endl;

#define TASK_NAME_COLUMN    3
#define TASK_STATUS_COLUMN  6
#define TASK_DATA_COLUMN    9

TasksView::TasksView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TasksView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);

    mw = qobject_cast<MainWindow*>(parent);

    ui->vw->setContextMenuPolicy(Qt::CustomContextMenu);

    model = new TasksModel;
    ui->vw->setModel(model);
}

TasksView::~TasksView()
{
    delete ui;
}

void TasksView::setActionsHandler(ActionsHandler * a)
{
    aHdl = a;

    connect(aHdl->acWorkDir, SIGNAL(triggered()),
            this, SLOT(showWorkDir()));
    connect(aHdl->acShowTaskInfo, SIGNAL(triggered()),
            this, SLOT(displayTaskInfo()));
    /*
    connect(aHdl->acStopTask, SIGNAL(triggered()),
            this, SLOT(stopTask()));
    connect(aHdl->acRestartTask, SIGNAL(triggered()),
            this, SLOT(restartTask()));
    */

    connect(aHdl->acTaskPause, SIGNAL(triggered()),
            this, SLOT(doTaskPause()));
    connect(aHdl->acTaskResume, SIGNAL(triggered()),
            this, SLOT(doTaskResume()));
    connect(aHdl->acTaskCancel, SIGNAL(triggered()),
            this, SLOT(doTaskCancel()));

    /*
    connect(aHdl->acAgentSuspend, SIGNAL(triggered()),
            this, SLOT(doAgentSuspend()));
    connect(aHdl->acAgentStop, SIGNAL(triggered()),
            this, SLOT(doAgentStop()));
    connect(aHdl->acAgentReactivate, SIGNAL(triggered()),
            this, SLOT(doAgentReactivate()));
    */

    connect(aHdl->acHostSuspend, SIGNAL(triggered()),
            this, SLOT(doHostSuspend()));
    connect(aHdl->acHostStop, SIGNAL(triggered()),
            this, SLOT(doHostStop()));
    connect(aHdl->acHostReactivate, SIGNAL(triggered()),
            this, SLOT(doHostReactivate()));

    connect(ui->vw, SIGNAL(customContextMenuRequested(const QPoint &)),
            aHdl, SLOT(showTaskMonitContextMenu(const QPoint &)));
}

void TasksView::showWorkDir()
{
    QModelIndex idx        = ui->vw->currentIndex();
    // QModelIndex nameExtIdx = model->index(idx.row(), TASK_NAME_COLUMN);
    QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
    QJsonObject v = qStringToJObj(model->data(dataIdx).toString());
    QString localDir = v["Mounts"].toArray()[2].toObject()["Source"].toString();

    QFileInfo fs(localDir);
    if (fs.exists()) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(localDir));
    } else {
        (void)QMessageBox::warning(this, tr("Folder does not exist"),
                                   tr("The task folder does not exist in, "
                                      "or is not visible from this host.\n"
                                      "This problem normally appears when "
                                      "the task has been executed in a processing host "
                                      "that is not the host where the HMI "
                                      "is running"),
                                   QMessageBox::Ok);
    }
}

void TasksView::displayTaskInfo()
{
    QModelIndex idx = ui->vw->currentIndex();
    QModelIndex nameExtIdx = model->index(idx.row(), TASK_NAME_COLUMN);
    QModelIndex dataIdx = model->index(idx.row(), TASK_DATA_COLUMN);
    QString taskName = model->data(nameExtIdx).toString().trimmed();
    QString taskInfoString = model->data(dataIdx).toString().trimmed();

    DlgJSONViewer dlg("Task: " + taskName,
                      taskInfoString.toLocal8Bit(),
                      this);
    dlg.exec();
}

void TasksView::stopTask()
{
}

void TasksView::restartTask()
{
}

void TasksView::doTaskPause()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex statusIdx  = model->index(idx.row(), TASK_STATUS_COLUMN);
    TaskStatus  status     = TaskStatusValue[model->data(statusIdx)
                                             .toString().toStdString()];

    if (status == TASK_RUNNING) {
        QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
        QJsonObject v = qStringToJObj(model->data(dataIdx).toString());
        std::string taskId = v["Id"].toString().toStdString();
        // hmiNode->sendProcHdlCmd(PROC_TASK, taskId, PROC_HDL_PAUSE);
    }
}

void TasksView::doTaskResume()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex statusIdx  = model->index(idx.row(), TASK_STATUS_COLUMN);
    TaskStatus  status     = TaskStatusValue[model->data(statusIdx)
                                             .toString().toStdString()];

    if (status == TASK_PAUSED) {
        QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
        QJsonObject v = qStringToJObj(model->data(dataIdx).toString());
        std::string taskId = v["Id"].toString().toStdString();
        // hmiNode->sendProcHdlCmd(PROC_TASK, taskId, PROC_HDL_RESUME);
    }
}

void TasksView::doTaskCancel()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex statusIdx  = model->index(idx.row(), TASK_STATUS_COLUMN);
    TaskStatus  status     = TaskStatusValue[model->data(statusIdx)
                                             .toString().toStdString()];

    if ((status == TASK_PAUSED) || (status == TASK_RUNNING)) {
        QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
        QJsonObject v = qStringToJObj(model->data(dataIdx).toString());
        std::string taskId = v["Id"].toString().toStdString();
        // hmiNode->sendProcHdlCmd(PROC_TASK, taskId, PROC_HDL_CANCEL);
    }
}

void TasksView::doAgentSuspend()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
    QJsonObject v = qStringToJObj(model->data(dataIdx).toString());

    std::string agentId = v["Info"].toObject()["Agent"].toString().toStdString();
    QString qagentId = QString::fromStdString(agentId);
    if (agentProcStatus.find(qagentId) == agentProcStatus.end()) {
        agentProcStatus[qagentId] = TASK_RUNNING;
    }
    TaskStatus agentStatus = agentProcStatus[qagentId];
    TRC("Agent: " + agentId + " has status " + TaskStatusName[agentStatus]);
    if (agentStatus == TASK_RUNNING) {
        // hmiNode->sendProcHdlCmd(PROC_AGENT, agentId, PROC_HDL_SUSPEND);
        agentProcStatus[qagentId] = TASK_PAUSED;
    }
}

void TasksView::doAgentStop()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
    QJsonObject v = qStringToJObj(model->data(dataIdx).toString());

    std::string agentId = v["Info"].toObject()["Agent"].toString().toStdString();
    QString qagentId = QString::fromStdString(agentId);
    if (agentProcStatus.find(qagentId) == agentProcStatus.end()) {
        agentProcStatus[qagentId] = TASK_RUNNING;
    }
    TaskStatus agentStatus = agentProcStatus[qagentId];
    if ((agentStatus == TASK_RUNNING) || (agentStatus == TASK_PAUSED)) {
        // hmiNode->sendProcHdlCmd(PROC_AGENT, agentId, PROC_HDL_STOP);
        agentProcStatus[qagentId] = TASK_PAUSED;
    }
}

void TasksView::doAgentReactivate()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
    QJsonObject v = qStringToJObj(model->data(dataIdx).toString());

    QString qagentId = v["Info"].toObject()["Agent"].toString();
    std::string agentId = qagentId.toStdString();
    if (agentProcStatus.find(qagentId) == agentProcStatus.end()) {
        agentProcStatus[qagentId] = TASK_RUNNING;
        return;
    }
    TaskStatus agentStatus = agentProcStatus[qagentId];
    if (agentStatus == TASK_PAUSED) {
        // hmiNode->sendProcHdlCmd(PROC_AGENT, agentId, PROC_HDL_REACTIVATE);
        agentProcStatus[qagentId] = TASK_RUNNING;
    }
}

void TasksView::doHostSuspend()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
    QJsonObject v = qStringToJObj(model->data(dataIdx).toString());

    QString agName = v["Info"].toObject()["Agent"].toString();
    QString qhostId = cfg.hostForAgent[agName];
    if (qhostId.isEmpty()) { return; }
    std::string hostId = qhostId.toStdString();
    if (hostProcStatus.find(qhostId) == hostProcStatus.end()) {
        hostProcStatus[qhostId] = TASK_RUNNING;
    }
    TaskStatus hostStatus = hostProcStatus[qhostId];
    if (hostStatus == TASK_RUNNING) {
        // hmiNode->sendProcHdlCmd(PROC_HOST, hostId, PROC_HDL_SUSPEND);
        hostProcStatus[qhostId] = TASK_PAUSED;
    }
    TRC("HOST PROCESSING (Suspend): " +
        agName.toStdString() + " @ " + qhostId.toStdString() + ": " +
        TaskStatusName[hostStatus] + " => " +
        TaskStatusName[hostProcStatus[qhostId]]);
}

void TasksView::doHostStop()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
    QJsonObject v = qStringToJObj(model->data(dataIdx).toString());

    QString agName = v["Info"].toObject()["Agent"].toString();
    QString qhostId = cfg.hostForAgent[agName];
    if (qhostId.isEmpty()) { return; }
    std::string hostId = qhostId.toStdString();
    if (hostProcStatus.find(qhostId) == hostProcStatus.end()) {
        hostProcStatus[qhostId] = TASK_RUNNING;
    }
    TaskStatus hostStatus = hostProcStatus[qhostId];
    if ((hostStatus == TASK_RUNNING) || (hostStatus == TASK_PAUSED)) {
        // hmiNode->sendProcHdlCmd(PROC_HOST, hostId, PROC_HDL_STOP);
        hostProcStatus[qhostId] = TASK_STOPPED;
    }
    TRC("HOST PROCESSING (Stop   ): " +
        agName.toStdString() + " @ " + qhostId.toStdString() + ": " +
        TaskStatusName[hostStatus] + " => " +
        TaskStatusName[hostProcStatus[qhostId]]);
}

void TasksView::doHostReactivate()
{
    QModelIndex idx        = ui->vw->currentIndex();
    QModelIndex dataIdx    = model->index(idx.row(), TASK_DATA_COLUMN);
    QJsonObject v = qStringToJObj(model->data(dataIdx).toString());

    QString agName = v["Info"].toObject()["Agent"].toString();
    QString qhostId = cfg.hostForAgent[agName];
    if (qhostId.isEmpty()) { return; }
    std::string hostId = qhostId.toStdString();
    if (hostProcStatus.find(qhostId) == hostProcStatus.end()) {
        hostProcStatus[qhostId] = TASK_RUNNING;
        //return;
    }
    TaskStatus hostStatus = hostProcStatus[qhostId];
    if ((hostStatus == TASK_PAUSED) || (hostStatus == TASK_STOPPED)) {
        // hmiNode->sendProcHdlCmd(PROC_HOST, hostId, PROC_HDL_REACTIVATE);
        hostProcStatus[qhostId] = TASK_RUNNING;
    }
    TRC("HOST PROCESSING (Reactiv): " +
        agName.toStdString() + " @ " + qhostId.toStdString() + ": " +
        TaskStatusName[hostStatus] + " => " +
        TaskStatusName[hostProcStatus[qhostId]]);
}
