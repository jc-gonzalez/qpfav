#ifndef ACTIONSHANDLER_H
#define ACTIONSHANDLER_H

#include <QObject>
#include <QMenu>
#include <QAction>

namespace QPF {

class MainWindow;

class ActionsHandler : public QObject
{
    Q_OBJECT
public:
    explicit ActionsHandler(QWidget * parent = 0);

signals:

public slots:
    void processPath();
    void quitQPFAV();

private:
    void init();

    void buildMainMenuActions();
    void buildMainMenu();

    void buildLocalArchActions();
    void buildTasksActions();
    void buildAlertsActions();
    void buildProductViewerActions();
    void buildFilterActions();
    void buildLocArchViewActions();
    void buildLogActions();

private:
    // MainWindow (parent) handler
    MainWindow * mw;

    // Main menu
    QMenu * fileMenu;
    QMenu * editMenu;
    QMenu * viewMenu;
    QMenu * toolsMenu;
    QMenu * helpMenu;

public:
    // - File menu
    QAction * acProcessPath;
    QAction * acQuit;

    // Edit menu
    QAction * acCut;
    QAction * acCopy;
    QAction * acPaste;

    // View menu
    QAction * acNavig;

    // Tools menu
    QAction * acConfigTool;
    QAction * acBrowseDB;
    QAction * acExtTools;
    QAction * acVerbosity;

    // Help menu
    QAction * acAbout;
    QAction * acAboutQt;

    QAction * acSeparator;

    // Local Archive - Main buttons
    QAction * acLocArchRefresh;
    QAction * acLocArchExpand;
    QAction * acLocArchCollapse;
    QAction * acLocArchResize;
    QAction * acLocArchToggleAuto;

    // Local Archive - Custom popup menu
    QAction * acLocArchShowLocation;
    QAction * acLocArchOpenWith;
    QAction * acLocArchReprocess;
    QAction * acLocArchAnalyzeIPython;
    QAction * acLocArchAnalyzeJupyter;
    QAction * acLocArchExport;

    // Tasks - Custom popup menu
    QAction * acTasksDisplayInfo;
    QAction * acTasksPauseTask;
    QAction * acTasksResumeTask;
    QAction * acTasksCancelTask;

    // System Alerts - Custom popup menu
    QAction * acSysAlertDisplayInfo;

    // Processing Alerts - Custom popup menu
    QAction * acProcAlertDisplayInfo;
    QAction * acProcAlertLocateInProduct;

    // Products
    QAction * acShowProductView;

    // Report filters
    QAction * acCreateReportsFilter;
    QAction * acEditReportsFilter;
    QAction * acShowReportFilter;

    // Local Archive Views
    QAction * acCreateLocArchView;
    QAction * acEditLocArchView;
    QAction * acShowLocArchView;

    // Logs
    QAction * acShowLog;
};

}

#endif // ACTIONSHANDLER_H
