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

public slots:
    void processPath();
    void quitQPFAV();

    void showLocalArchiveContextMenu(const QPoint & p);
    void showTaskMonitContextMenu(const QPoint & p);
    void showProcAlertsContextMenu(const QPoint & p);
    void showSysAlertsContextMenu(const QPoint & p);

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
    QMenu * acArchiveOpenExt;
    QAction * acArchiveShow;
    QAction * acDefault;
    QAction * acReprocess;
    QAction * acAnalyzeIPython;
    QAction * acAnalyzeJupyter;
    QAction * acExport;
    // QAction * acExportRemote;
    // QAction * acExportVOSpace;
    // QAction * acExportVOSpaceOther;

    // Tasks View
    QAction * acWorkDir;
    QAction * acShowTaskInfo;

    // QAction * acStopTask;
    // QAction * acRestartTask;

    QAction * acTaskPause;
    QAction * acTaskResume;
    QAction * acTaskCancel;

    // QAction * acAgentSuspend;
    // QAction * acAgentStop;
    // QAction * acAgentReactivate;

    QAction * acHostSuspend;
    QAction * acHostStop;
    QAction * acHostReactivate;

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

    // User Tools
    QMap<QString, QAction *> acUserTools;
};

}

#endif // ACTIONSHANDLER_H
