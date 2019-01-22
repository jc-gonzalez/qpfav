#ifndef TASKSVIEW_H
#define TASKSVIEW_H

#include <QWidget>
#include <QMap>

#include "tasksmodel.h"
#include "mainwindow.h"
#include "actionshandler.h"
#include "util.h"

using QPF::MainWindow;
using QPF::ActionsHandler;

namespace Ui {
class TasksView;
}

using QPF::TasksModel;

class TasksView : public QWidget
{
    Q_OBJECT

public:
    explicit TasksView(QWidget *parent = 0);
    ~TasksView();

public slots:
    void setActionsHandler(ActionsHandler * a);

    void showWorkDir();
    void displayTaskInfo();
    void stopTask();
    void restartTask();
    void doTaskPause();
    void doTaskResume();
    void doTaskCancel();
    void doAgentSuspend();
    void doAgentStop();
    void doAgentReactivate();
    void doHostSuspend();
    void doHostStop();
    void doHostReactivate();

private:
    Ui::TasksView * ui;

    TasksModel * model;
    MainWindow * mw;
    ActionsHandler * aHdl;

    QMap<QString,TaskStatus>  agentProcStatus;
    QMap<QString,TaskStatus>  hostProcStatus;
};

#endif // TASKSVIEW_H
