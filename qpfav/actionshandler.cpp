#include "actionshandler.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}

void ActionsHandler::buildTasksActions()
{

}

void ActionsHandler::buildAlertsActions()
{

}

void ActionsHandler::buildProductViewerActions()
{

}

void ActionsHandler::buildFilterActions()
{

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

}
