#include "actionshandler.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableView>
#include <QTreeView>

#include <iostream>

#include "config.h"
using Configuration::cfg;

namespace QPF {

ActionsHandler::ActionsHandler(QWidget *parent)
{
    mw = qobject_cast<MainWindow*>(parent);
    init();
}

void ActionsHandler::init()
{
    buildMainMenuActions();
    buildMainMenu();

    buildLocalArchActions();
    buildTasksActions();
    buildAlertsActions();
    buildProductViewerActions();
    buildFilterActions();
    buildLocArchViewActions();
    buildLogActions();
}

void ActionsHandler::buildMainMenuActions()
{
    // File menu
    acProcessPath = new QAction(QIcon(":/img/orchestration.png"), tr("Pr&ocess products in folder..."), this);
    acProcessPath->setShortcuts(QKeySequence::Open);
    acProcessPath->setStatusTip(tr("Specify a user selected folder and process all products inside"));
    connect(acProcessPath, SIGNAL(triggered()), mw, SLOT(processPath()));

    acQuit = new QAction(QIcon(":/img/quit.png"), tr("Quit QPFAV"), this);
    acQuit->setShortcuts(QKeySequence::Quit);
    acQuit->setStatusTip(tr("Quit the QLA Processing Framework Archive Viewer"));
    connect(acQuit, SIGNAL(triggered()), mw, SLOT(quitQPFAV()));

    // Edit menu
#ifndef QT_NO_CLIPBOARD
    acCut = new QAction(QIcon(":/img/cut.png"), tr("Cu&t"), this);
    acCut->setShortcuts(QKeySequence::Cut);
    acCut->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(acCut, SIGNAL(triggered()), mw, SLOT(cut()));

    acCopy = new QAction(QIcon(":/img/copy.png"), tr("&Copy"), this);
    acCopy->setShortcuts(QKeySequence::Copy);
    acCopy->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(acCopy, SIGNAL(triggered()), mw, SLOT(copy()));

    acPaste = new QAction(QIcon(":/img/paste.png"), tr("&Paste"), this);
    acPaste->setShortcuts(QKeySequence::Paste);
    acPaste->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(acPaste, SIGNAL(triggered()), mw, SLOT(paste()));
#endif

    // View menu
    acNavig = new QAction(tr("Show &navigator panel"), this);
    acNavig->setStatusTip(tr("Shows or hides the navigator panel"));
    acNavig->setCheckable(true);
//    connect(acNavig, SIGNAL(toggled(bool)),
//            mw->ui->dockNavigator, SLOT(setVisible(bool)));
//    connect(mw->ui->dockNavigator, SIGNAL(visibilityChanged(bool)),
//            acNavig, SLOT(setChecked(bool)));
//    mw->ui->dockNavigator->setVisible(false);

    // Tools menu
    acConfigTool = new QAction(QIcon(":/img/general.png"), tr("&Configuration Tool ..."), this);
    acConfigTool->setStatusTip(tr("Open Configuration Tool with current configuration"));
    connect(acConfigTool, SIGNAL(triggered()), mw, SLOT(showConfigTool()));

    acBrowseDB = new QAction(QIcon(":/img/storage.png"), tr("&Browse System DB ..."), this);
    acBrowseDB->setStatusTip(tr("Open System Database Browser"));
    connect(acBrowseDB, SIGNAL(triggered()), mw, SLOT(showDBBrowser()));

    acExtTools = new QAction(QIcon(":/img/exttools.png"), tr("&Define External Tools ..."), this);
    acExtTools->setStatusTip(tr("Define external tools to open data products"));
    connect(acExtTools, SIGNAL(triggered()), mw, SLOT(showExtToolsDef()));

    acVerbosity = new QAction(QIcon(":/img/verblevel.png"), tr("&Define Verbosity Level ..."), this);
    acVerbosity->setStatusTip(tr("Define verbosity level to be used in this session"));
    connect(acVerbosity, SIGNAL(triggered()), mw, SLOT(showVerbLevel()));

    // Help menu
    acAbout = new QAction(tr("&About"), this);
    acAbout->setStatusTip(tr("Show the application's About box"));
    connect(acAbout, SIGNAL(triggered()), mw, SLOT(about()));

    acAboutQt = new QAction(tr("About &Qt"), this);
    acAboutQt->setStatusTip(tr("Show the Qt library's About box"));
    connect(acAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    acSeparator = new QAction(this);
    acSeparator->setSeparator(true);
}

//----------------------------------------------------------------------
// Method: buildMainMenu
// Build action menus in main menu bar
//----------------------------------------------------------------------
void ActionsHandler::buildMainMenu()
{
    // File menu
    fileMenu = mw->menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(acProcessPath);
    fileMenu->addSeparator();
    fileMenu->addAction(acQuit);

    // Edit menu
    editMenu = mw->menuBar()->addMenu(tr("&Edit"));
#ifndef QT_NO_CLIPBOARD
    editMenu->addAction(acCut);
    editMenu->addAction(acCopy);
    editMenu->addAction(acPaste);
#endif

    // Window menu
    viewMenu = mw->menuBar()->addMenu(tr("&View"));

    // Tools menu
    toolsMenu = mw->menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(acConfigTool);
    toolsMenu->addAction(acBrowseDB);
    toolsMenu->addAction(acExtTools);
    toolsMenu->addAction(acVerbosity);

    mw->menuBar()->addSeparator();

    // Help menu
    helpMenu = mw->menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(acAbout);
    helpMenu->addAction(acAboutQt);
}

void ActionsHandler::buildLocalArchActions()
{
    acArchiveOpenExt = new QMenu(tr("Open with ..."), mw->ui->localArchView);

    acArchiveShow = new QAction("Show location in local archive", mw->ui->localArchView);

    acDefault = new QAction("System Default", mw->ui->localArchView);

    acReprocess = new QAction("Reprocess data product", mw->ui->localArchView);

    acAnalyzeIPython = new QAction("Analyze within IPython", mw->ui->localArchView);
    acAnalyzeIPython->setObjectName("AnalyzeWithIPython");

    acAnalyzeJupyter = new QAction("Analyze within Jupyter Lab", mw->ui->localArchView);
    acAnalyzeJupyter->setObjectName("AnalyzeWithJupyter");
    acAnalyzeJupyter->setEnabled(false);

    acExport = new QAction("Export the selected product(s) ...", mw->ui->localArchView);
    /*
    acExportRemote = new QAction("Export to a remote folder", mw->ui->localArchView);
    acExportVOSpace = new QAction("Export to configured VOSpace folder", mw->ui->localArchView);
    acExportVOSpaceOther = new QAction("Export to another VOSpace folder", mw->ui->localArchView);
    */
}

void ActionsHandler::buildTasksActions()
{
    acWorkDir         = new QAction(tr("Open task working directory..."), mw->ui->tasksView);
    acShowTaskInfo    = new QAction(tr("Display task information"),       mw->ui->tasksView);
    /*
    acStopTask       = new QAction(tr("Stop"),   `                        mw->ui->tasksView);
    acRestartTask    = new QAction(tr("Restart"),                        mw->ui->tasksView);
    */
    acTaskPause       = new QAction(tr("Pause Task"),                     mw->ui->tasksView);
    acTaskResume      = new QAction(tr("Resume Task"),                    mw->ui->tasksView);
    acTaskCancel      = new QAction(tr("Cancel Task"),                    mw->ui->tasksView);
    /*
    acAgentSuspend    = new QAction(tr("Suspend Agent Processing"),       mw->ui->tasksView);
    acAgentStop       = new QAction(tr("Stop Agent Processing"),          mw->ui->tasksView);
    acAgentReactivate = new QAction(tr("Reactivate Agent Processing"),    mw->ui->tasksView);
    */
    acHostSuspend     = new QAction(tr("Suspend Host Processing"),        mw->ui->tasksView);
    acHostStop        = new QAction(tr("Stop Host Processing"),           mw->ui->tasksView);
    acHostReactivate  = new QAction(tr("Reactivate Host Processing"),     mw->ui->tasksView);
}

void ActionsHandler::buildProductViewerActions()
{

}

void ActionsHandler::buildFilterActions()
{

}

void ActionsHandler::buildAlertsActions()
{
    acProcAlertDisplayInfo = new QAction(tr("Show alert information"), this);
    acProcAlertLocateInProduct = new QAction(tr("Locate in product"), this);

    acSysAlertDisplayInfo = new QAction(tr("Show system alert information"), this);
}

void ActionsHandler::buildLocArchViewActions()
{

}

void ActionsHandler::buildLogActions()
{

}

void ActionsHandler::processPath()
{

}

void ActionsHandler::quitQPFAV()
{

}

void ActionsHandler::showLocalArchiveContextMenu(const QPoint & p)
{
    static const int NumOfProdTypeCol = 3;

    QTreeView * treevw = qobject_cast<QTreeView*>(sender());
    QModelIndex m = treevw->indexAt(p);

    QModelIndex m2 = m.model()->index(m.row(), NumOfProdTypeCol, m.parent());
    if (!m2.data().isValid()) { return; }
    QString productType = m2.data().toString();

    QList<QAction *> actions;
    if (! m.isValid()) { return; }

    foreach (QString key, mw->userDefTools.keys()) {
        const QUserDefTool & udt = mw->userDefTools.value(key);
        if (udt.prod_types.contains(productType) || true) {
            QAction * ac = acUserTools[key];
            actions.append(ac);
        }
    }
    acArchiveOpenExt->clear();
    acArchiveOpenExt->addAction(acDefault);
    acArchiveOpenExt->addSeparator();
    acArchiveOpenExt->addActions(actions);

    QMenu menu(mw);
    menu.addAction(acArchiveShow);
    menu.addSeparator();
    menu.addMenu(acArchiveOpenExt);

    if ((m.parent().isValid()) && ((productType.left(4) == "LE1_") ||
                                   (productType.left(4) == "SIM_") ||
                                   (productType.left(4) == "SOC_"))) {
        acReprocess->setEnabled(cfg.flags("allowReprocessing").toBool());
        menu.addSeparator();
        menu.addAction(acReprocess);
        acReprocess->setProperty("clickedItem", p);
    }

    QMenu * cmAnalyze = menu.addMenu("Analyze ...");
    cmAnalyze->addAction(acAnalyzeIPython);
    cmAnalyze->addAction(acAnalyzeJupyter);

    menu.addAction(acExport);

    /*
      QMenu * cmExport = menu.addMenu("Export ...");
      cmExport->addAction(acExport);
      cmExport->addAction(acExportRemote);
      cmExport->addAction(acExportVOSpace);
      cmExport->addAction(acExportVOSpaceOther);
    */
    menu.exec(mw->ui->localArchView->mapToGlobal(p));
}

void ActionsHandler::showTaskMonitContextMenu(const QPoint & p)
{
    QTableView * tblvw = qobject_cast<QTableView*>(sender());

    if (! tblvw->indexAt(p).isValid()) { return; }

    QMenu cm;

    cm.addAction(acWorkDir);
    cm.addAction(acShowTaskInfo);
    //cm.addAction(acRestartTask);
    //cm.addAction(acStopTask);

    cm.addSeparator();

    QMenu * cmTask = cm.addMenu("Task control ...");
    cmTask->addAction(acTaskPause);
    cmTask->addAction(acTaskResume);
    cmTask->addAction(acTaskCancel);

    // QMenu * cmAgent = cm.addMenu("Agent processing ...");
    // cmAgent->addAction(acAgentSuspend);
    // cmAgent->addAction(acAgentStop);
    // cmAgent->addAction(acAgentReactivate);

    QMenu * cmHost = cm.addMenu("Host processing ...");
    cmHost->addAction(acHostSuspend);
    cmHost->addAction(acHostStop);
    cmHost->addAction(acHostReactivate);

    //mw->isViewsUpdateActive = false;
    cm.exec(tblvw->mapToGlobal(p));
    //mw->isViewsUpdateActive = true;
}

void ActionsHandler::showProcAlertsContextMenu(const QPoint & p)
{
    QList<QAction *> actions;
    std::cerr << "BEEP!\n";
    QTableView * tblvw = qobject_cast<QTableView*>(sender());
    if (tblvw->indexAt(p).isValid()) {
        actions.append(acProcAlertDisplayInfo);
        actions.append(acProcAlertLocateInProduct);
    }
    if (actions.count() > 0) {
        QMenu::exec(actions, tblvw->mapToGlobal(p));
    }
}

void ActionsHandler::showSysAlertsContextMenu(const QPoint & p)
{
    QList<QAction *> actions;
    std::cerr << "BEEP!\n";
    QTableView * tblvw = qobject_cast<QTableView*>(sender());
    if (tblvw->indexAt(p).isValid()) {
        actions.append(acSysAlertDisplayInfo);
    }
    if (actions.count() > 0) {
        QMenu::exec(actions, tblvw->mapToGlobal(p));
    }
}

}
