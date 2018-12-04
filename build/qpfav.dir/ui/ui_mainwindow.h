/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <localarchview.h>
#include <procalertsview.h>
#include <sysalertsview.h>
#include <tasksview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_11;
    QStackedWidget *stckMain;
    QWidget *pgLocalArch;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblLocalArch;
    QComboBox *cboxLocalArchAuto;
    QToolButton *tbtnRefresh;
    QToolButton *tbtnExpand;
    QToolButton *tbtnCollapse;
    QToolButton *tbtnResize;
    LocalArchiveView *localArchView;
    QWidget *pgProcTasks;
    QVBoxLayout *verticalLayout;
    QLabel *lblProcTasks;
    TasksView *tasksView;
    QWidget *pgProdView;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblProdView;
    QTabWidget *tabwdgViewers;
    QWidget *pgFilters;
    QVBoxLayout *verticalLayout_16;
    QLabel *lblFilters;
    QTabWidget *tabwdgFilters;
    QWidget *pgAlerts;
    QVBoxLayout *verticalLayout_14;
    QLabel *lblAlerts;
    QTabWidget *tabwdgAlerts;
    QWidget *tabProcAlerts;
    QVBoxLayout *verticalLayout_12;
    ProcAlertsView *procAlertsView;
    QWidget *tabSysAlerts;
    QVBoxLayout *verticalLayout_13;
    SysAlertsView *sysAlertsView;
    QWidget *pgMonit;
    QVBoxLayout *verticalLayout_7;
    QLabel *lblMonit;
    QFrame *frmMonit;
    QWidget *pgLog;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblLog;
    QComboBox *cboxLog;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stckLogs;
    QWidget *page;
    QWidget *page_2;
    QWidget *pgTools;
    QVBoxLayout *verticalLayout_15;
    QLabel *lblTools;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *btnCfgTool_txt;
    QPushButton *btnVerbosity_txt;
    QPushButton *btnUserDefTools_txt;
    QPushButton *btnDBBrowser_txt;
    QPushButton *btnCfgTool;
    QPushButton *btnDBBrowser;
    QPushButton *btnVerbosity;
    QPushButton *btnUserDefTools;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dckNavigator;
    QWidget *dckNavigatorContents;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbtnArchive;
    QToolButton *tbtnTasks;
    QToolButton *tbtnViewer;
    QToolButton *tbtnFilter;
    QToolButton *tbtnAlerts;
    QToolButton *tbtnMonit;
    QToolButton *tbtnLog;
    QToolButton *tbtnTools;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblVerbosity;
    QSpacerItem *horizontalSpacer_5;
    QToolBox *tboxNavigator;
    QWidget *navpgProducts;
    QVBoxLayout *verticalLayout_8;
    QListView *lstvwProducts;
    QWidget *navpgFilters;
    QVBoxLayout *verticalLayout_9;
    QListView *lstvwFilters;
    QWidget *navpgViews;
    QVBoxLayout *verticalLayout_10;
    QListView *lstvwViews;
    QWidget *navpgLogs;
    QVBoxLayout *verticalLayout_6;
    QListView *lstvwLogs;
    QButtonGroup *btngrpNavigator;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1009, 691);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/QPFav.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_11 = new QVBoxLayout(centralwidget);
        verticalLayout_11->setSpacing(2);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(2, 2, 2, 2);
        stckMain = new QStackedWidget(centralwidget);
        stckMain->setObjectName(QStringLiteral("stckMain"));
        stckMain->setToolTipDuration(-24);
        pgLocalArch = new QWidget();
        pgLocalArch->setObjectName(QStringLiteral("pgLocalArch"));
        verticalLayout_2 = new QVBoxLayout(pgLocalArch);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        lblLocalArch = new QLabel(pgLocalArch);
        lblLocalArch->setObjectName(QStringLiteral("lblLocalArch"));
        lblLocalArch->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_4->addWidget(lblLocalArch);

        cboxLocalArchAuto = new QComboBox(pgLocalArch);
        cboxLocalArchAuto->setObjectName(QStringLiteral("cboxLocalArchAuto"));

        horizontalLayout_4->addWidget(cboxLocalArchAuto);

        tbtnRefresh = new QToolButton(pgLocalArch);
        tbtnRefresh->setObjectName(QStringLiteral("tbtnRefresh"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnRefresh->setIcon(icon1);

        horizontalLayout_4->addWidget(tbtnRefresh);

        tbtnExpand = new QToolButton(pgLocalArch);
        tbtnExpand->setObjectName(QStringLiteral("tbtnExpand"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/expand.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnExpand->setIcon(icon2);

        horizontalLayout_4->addWidget(tbtnExpand);

        tbtnCollapse = new QToolButton(pgLocalArch);
        tbtnCollapse->setObjectName(QStringLiteral("tbtnCollapse"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/collapse.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnCollapse->setIcon(icon3);

        horizontalLayout_4->addWidget(tbtnCollapse);

        tbtnResize = new QToolButton(pgLocalArch);
        tbtnResize->setObjectName(QStringLiteral("tbtnResize"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/resize.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnResize->setIcon(icon4);

        horizontalLayout_4->addWidget(tbtnResize);

        horizontalLayout_4->setStretch(0, 100);
        horizontalLayout_4->setStretch(1, 20);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);

        localArchView = new LocalArchiveView(pgLocalArch);
        localArchView->setObjectName(QStringLiteral("localArchView"));

        verticalLayout_2->addWidget(localArchView);

        verticalLayout_2->setStretch(1, 1000);
        stckMain->addWidget(pgLocalArch);
        pgProcTasks = new QWidget();
        pgProcTasks->setObjectName(QStringLiteral("pgProcTasks"));
        verticalLayout = new QVBoxLayout(pgProcTasks);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        lblProcTasks = new QLabel(pgProcTasks);
        lblProcTasks->setObjectName(QStringLiteral("lblProcTasks"));
        lblProcTasks->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(lblProcTasks);

        tasksView = new TasksView(pgProcTasks);
        tasksView->setObjectName(QStringLiteral("tasksView"));

        verticalLayout->addWidget(tasksView);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1000);
        stckMain->addWidget(pgProcTasks);
        pgProdView = new QWidget();
        pgProdView->setObjectName(QStringLiteral("pgProdView"));
        verticalLayout_4 = new QVBoxLayout(pgProdView);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        lblProdView = new QLabel(pgProdView);
        lblProdView->setObjectName(QStringLiteral("lblProdView"));
        lblProdView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(lblProdView);

        tabwdgViewers = new QTabWidget(pgProdView);
        tabwdgViewers->setObjectName(QStringLiteral("tabwdgViewers"));

        verticalLayout_4->addWidget(tabwdgViewers);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1000);
        stckMain->addWidget(pgProdView);
        pgFilters = new QWidget();
        pgFilters->setObjectName(QStringLiteral("pgFilters"));
        verticalLayout_16 = new QVBoxLayout(pgFilters);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(2, 2, 2, 2);
        lblFilters = new QLabel(pgFilters);
        lblFilters->setObjectName(QStringLiteral("lblFilters"));
        lblFilters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_16->addWidget(lblFilters);

        tabwdgFilters = new QTabWidget(pgFilters);
        tabwdgFilters->setObjectName(QStringLiteral("tabwdgFilters"));

        verticalLayout_16->addWidget(tabwdgFilters);

        stckMain->addWidget(pgFilters);
        pgAlerts = new QWidget();
        pgAlerts->setObjectName(QStringLiteral("pgAlerts"));
        verticalLayout_14 = new QVBoxLayout(pgAlerts);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(2, 2, 2, 2);
        lblAlerts = new QLabel(pgAlerts);
        lblAlerts->setObjectName(QStringLiteral("lblAlerts"));
        lblAlerts->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_14->addWidget(lblAlerts);

        tabwdgAlerts = new QTabWidget(pgAlerts);
        tabwdgAlerts->setObjectName(QStringLiteral("tabwdgAlerts"));
        tabwdgAlerts->setTabPosition(QTabWidget::North);
        tabwdgAlerts->setTabShape(QTabWidget::Rounded);
        tabwdgAlerts->setTabBarAutoHide(true);
        tabProcAlerts = new QWidget();
        tabProcAlerts->setObjectName(QStringLiteral("tabProcAlerts"));
        verticalLayout_12 = new QVBoxLayout(tabProcAlerts);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(2, 2, 2, 2);
        procAlertsView = new ProcAlertsView(tabProcAlerts);
        procAlertsView->setObjectName(QStringLiteral("procAlertsView"));

        verticalLayout_12->addWidget(procAlertsView);

        tabwdgAlerts->addTab(tabProcAlerts, QString());
        tabSysAlerts = new QWidget();
        tabSysAlerts->setObjectName(QStringLiteral("tabSysAlerts"));
        verticalLayout_13 = new QVBoxLayout(tabSysAlerts);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(2, 2, 2, 2);
        sysAlertsView = new SysAlertsView(tabSysAlerts);
        sysAlertsView->setObjectName(QStringLiteral("sysAlertsView"));

        verticalLayout_13->addWidget(sysAlertsView);

        tabwdgAlerts->addTab(tabSysAlerts, QString());

        verticalLayout_14->addWidget(tabwdgAlerts);

        stckMain->addWidget(pgAlerts);
        pgMonit = new QWidget();
        pgMonit->setObjectName(QStringLiteral("pgMonit"));
        verticalLayout_7 = new QVBoxLayout(pgMonit);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        lblMonit = new QLabel(pgMonit);
        lblMonit->setObjectName(QStringLiteral("lblMonit"));

        verticalLayout_7->addWidget(lblMonit);

        frmMonit = new QFrame(pgMonit);
        frmMonit->setObjectName(QStringLiteral("frmMonit"));
        frmMonit->setFrameShape(QFrame::StyledPanel);
        frmMonit->setFrameShadow(QFrame::Raised);

        verticalLayout_7->addWidget(frmMonit);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 1000);
        stckMain->addWidget(pgMonit);
        pgLog = new QWidget();
        pgLog->setObjectName(QStringLiteral("pgLog"));
        verticalLayout_3 = new QVBoxLayout(pgLog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblLog = new QLabel(pgLog);
        lblLog->setObjectName(QStringLiteral("lblLog"));

        horizontalLayout_2->addWidget(lblLog);

        cboxLog = new QComboBox(pgLog);
        cboxLog->setObjectName(QStringLiteral("cboxLog"));

        horizontalLayout_2->addWidget(cboxLog);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 5);

        verticalLayout_3->addLayout(horizontalLayout_2);

        stckLogs = new QStackedWidget(pgLog);
        stckLogs->setObjectName(QStringLiteral("stckLogs"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stckLogs->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stckLogs->addWidget(page_2);

        verticalLayout_3->addWidget(stckLogs);

        stckMain->addWidget(pgLog);
        pgTools = new QWidget();
        pgTools->setObjectName(QStringLiteral("pgTools"));
        verticalLayout_15 = new QVBoxLayout(pgTools);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        lblTools = new QLabel(pgTools);
        lblTools->setObjectName(QStringLiteral("lblTools"));

        verticalLayout_15->addWidget(lblTools);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        frame = new QFrame(pgTools);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnCfgTool_txt = new QPushButton(frame);
        btnCfgTool_txt->setObjectName(QStringLiteral("btnCfgTool_txt"));
        btnCfgTool_txt->setMinimumSize(QSize(180, 38));
        btnCfgTool_txt->setIconSize(QSize(32, 32));
        btnCfgTool_txt->setFlat(false);

        gridLayout->addWidget(btnCfgTool_txt, 0, 1, 1, 1);

        btnVerbosity_txt = new QPushButton(frame);
        btnVerbosity_txt->setObjectName(QStringLiteral("btnVerbosity_txt"));
        btnVerbosity_txt->setMinimumSize(QSize(180, 38));
        btnVerbosity_txt->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnVerbosity_txt, 2, 1, 1, 1);

        btnUserDefTools_txt = new QPushButton(frame);
        btnUserDefTools_txt->setObjectName(QStringLiteral("btnUserDefTools_txt"));
        btnUserDefTools_txt->setMinimumSize(QSize(180, 38));
        btnUserDefTools_txt->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnUserDefTools_txt, 3, 1, 1, 1);

        btnDBBrowser_txt = new QPushButton(frame);
        btnDBBrowser_txt->setObjectName(QStringLiteral("btnDBBrowser_txt"));
        btnDBBrowser_txt->setMinimumSize(QSize(180, 38));
        btnDBBrowser_txt->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnDBBrowser_txt, 1, 1, 1, 1);

        btnCfgTool = new QPushButton(frame);
        btnCfgTool->setObjectName(QStringLiteral("btnCfgTool"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/general.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCfgTool->setIcon(icon5);
        btnCfgTool->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnCfgTool, 0, 0, 1, 1);

        btnDBBrowser = new QPushButton(frame);
        btnDBBrowser->setObjectName(QStringLiteral("btnDBBrowser"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/storage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDBBrowser->setIcon(icon6);
        btnDBBrowser->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnDBBrowser, 1, 0, 1, 1);

        btnVerbosity = new QPushButton(frame);
        btnVerbosity->setObjectName(QStringLiteral("btnVerbosity"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/verblevel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVerbosity->setIcon(icon7);
        btnVerbosity->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnVerbosity, 2, 0, 1, 1);

        btnUserDefTools = new QPushButton(frame);
        btnUserDefTools->setObjectName(QStringLiteral("btnUserDefTools"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/exttools.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUserDefTools->setIcon(icon8);
        btnUserDefTools->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnUserDefTools, 3, 0, 1, 1);


        horizontalLayout_3->addWidget(frame);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_15->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 607, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_2);

        stckMain->addWidget(pgTools);

        verticalLayout_11->addWidget(stckMain);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1009, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dckNavigator = new QDockWidget(MainWindow);
        dckNavigator->setObjectName(QStringLiteral("dckNavigator"));
        dckNavigatorContents = new QWidget();
        dckNavigatorContents->setObjectName(QStringLiteral("dckNavigatorContents"));
        verticalLayout_5 = new QVBoxLayout(dckNavigatorContents);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tbtnArchive = new QToolButton(dckNavigatorContents);
        btngrpNavigator = new QButtonGroup(MainWindow);
        btngrpNavigator->setObjectName(QStringLiteral("btngrpNavigator"));
        btngrpNavigator->addButton(tbtnArchive);
        tbtnArchive->setObjectName(QStringLiteral("tbtnArchive"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/archive.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnArchive->setIcon(icon9);

        horizontalLayout->addWidget(tbtnArchive);

        tbtnTasks = new QToolButton(dckNavigatorContents);
        btngrpNavigator->addButton(tbtnTasks);
        tbtnTasks->setObjectName(QStringLiteral("tbtnTasks"));
        tbtnTasks->setToolTipDuration(7);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/tasks.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnTasks->setIcon(icon10);

        horizontalLayout->addWidget(tbtnTasks);

        tbtnViewer = new QToolButton(dckNavigatorContents);
        btngrpNavigator->addButton(tbtnViewer);
        tbtnViewer->setObjectName(QStringLiteral("tbtnViewer"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnViewer->setIcon(icon11);

        horizontalLayout->addWidget(tbtnViewer);

        tbtnFilter = new QToolButton(dckNavigatorContents);
        btngrpNavigator->addButton(tbtnFilter);
        tbtnFilter->setObjectName(QStringLiteral("tbtnFilter"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnFilter->setIcon(icon12);

        horizontalLayout->addWidget(tbtnFilter);

        tbtnAlerts = new QToolButton(dckNavigatorContents);
        btngrpNavigator->addButton(tbtnAlerts);
        tbtnAlerts->setObjectName(QStringLiteral("tbtnAlerts"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/img/alerts.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnAlerts->setIcon(icon13);

        horizontalLayout->addWidget(tbtnAlerts);

        tbtnMonit = new QToolButton(dckNavigatorContents);
        btngrpNavigator->addButton(tbtnMonit);
        tbtnMonit->setObjectName(QStringLiteral("tbtnMonit"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/img/monit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnMonit->setIcon(icon14);

        horizontalLayout->addWidget(tbtnMonit);

        tbtnLog = new QToolButton(dckNavigatorContents);
        btngrpNavigator->addButton(tbtnLog);
        tbtnLog->setObjectName(QStringLiteral("tbtnLog"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/img/log.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnLog->setIcon(icon15);

        horizontalLayout->addWidget(tbtnLog);

        tbtnTools = new QToolButton(dckNavigatorContents);
        btngrpNavigator->addButton(tbtnTools);
        tbtnTools->setObjectName(QStringLiteral("tbtnTools"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/img/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbtnTools->setIcon(icon16);

        horizontalLayout->addWidget(tbtnTools);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        lblVerbosity = new QLabel(dckNavigatorContents);
        lblVerbosity->setObjectName(QStringLiteral("lblVerbosity"));
        lblVerbosity->setMinimumSize(QSize(80, 0));
        lblVerbosity->setFrameShape(QFrame::Box);
        lblVerbosity->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lblVerbosity);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_5);

        tboxNavigator = new QToolBox(dckNavigatorContents);
        tboxNavigator->setObjectName(QStringLiteral("tboxNavigator"));
        navpgProducts = new QWidget();
        navpgProducts->setObjectName(QStringLiteral("navpgProducts"));
        navpgProducts->setGeometry(QRect(0, 0, 274, 469));
        verticalLayout_8 = new QVBoxLayout(navpgProducts);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        lstvwProducts = new QListView(navpgProducts);
        lstvwProducts->setObjectName(QStringLiteral("lstvwProducts"));

        verticalLayout_8->addWidget(lstvwProducts);

        tboxNavigator->addItem(navpgProducts, QStringLiteral("Products"));
        navpgFilters = new QWidget();
        navpgFilters->setObjectName(QStringLiteral("navpgFilters"));
        navpgFilters->setGeometry(QRect(0, 0, 274, 469));
        verticalLayout_9 = new QVBoxLayout(navpgFilters);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        lstvwFilters = new QListView(navpgFilters);
        lstvwFilters->setObjectName(QStringLiteral("lstvwFilters"));

        verticalLayout_9->addWidget(lstvwFilters);

        tboxNavigator->addItem(navpgFilters, QStringLiteral("Filters"));
        navpgViews = new QWidget();
        navpgViews->setObjectName(QStringLiteral("navpgViews"));
        navpgViews->setGeometry(QRect(0, 0, 274, 469));
        verticalLayout_10 = new QVBoxLayout(navpgViews);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        lstvwViews = new QListView(navpgViews);
        lstvwViews->setObjectName(QStringLiteral("lstvwViews"));

        verticalLayout_10->addWidget(lstvwViews);

        tboxNavigator->addItem(navpgViews, QStringLiteral("Views"));
        navpgLogs = new QWidget();
        navpgLogs->setObjectName(QStringLiteral("navpgLogs"));
        navpgLogs->setGeometry(QRect(0, 0, 274, 469));
        verticalLayout_6 = new QVBoxLayout(navpgLogs);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lstvwLogs = new QListView(navpgLogs);
        lstvwLogs->setObjectName(QStringLiteral("lstvwLogs"));

        verticalLayout_6->addWidget(lstvwLogs);

        tboxNavigator->addItem(navpgLogs, QStringLiteral("Logs"));

        verticalLayout_5->addWidget(tboxNavigator);

        dckNavigator->setWidget(dckNavigatorContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dckNavigator);

        retranslateUi(MainWindow);
        QObject::connect(btngrpNavigator, SIGNAL(buttonClicked(int)), stckMain, SLOT(setCurrentIndex(int)));

        stckMain->setCurrentIndex(0);
        tabwdgViewers->setCurrentIndex(-1);
        tabwdgFilters->setCurrentIndex(-1);
        tabwdgAlerts->setCurrentIndex(0);
        tboxNavigator->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QPF Archive Viewer", Q_NULLPTR));
        lblLocalArch->setText(QApplication::translate("MainWindow", "Local Archive", Q_NULLPTR));
        tbtnRefresh->setText(QString());
        tbtnExpand->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        tbtnCollapse->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        tbtnResize->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        lblProcTasks->setText(QApplication::translate("MainWindow", "Processing Tasks", Q_NULLPTR));
        lblProdView->setText(QApplication::translate("MainWindow", "Product Viewer", Q_NULLPTR));
        lblFilters->setText(QApplication::translate("MainWindow", "Report Filters", Q_NULLPTR));
        lblAlerts->setText(QApplication::translate("MainWindow", "Alerts", Q_NULLPTR));
        tabwdgAlerts->setTabText(tabwdgAlerts->indexOf(tabProcAlerts), QApplication::translate("MainWindow", "Processing Alerts", Q_NULLPTR));
        tabwdgAlerts->setTabText(tabwdgAlerts->indexOf(tabSysAlerts), QApplication::translate("MainWindow", "System Alerts", Q_NULLPTR));
        lblMonit->setText(QApplication::translate("MainWindow", "Monitoring Information", Q_NULLPTR));
        lblLog->setText(QApplication::translate("MainWindow", "Logging Information", Q_NULLPTR));
        lblTools->setText(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnCfgTool_txt->setToolTip(QApplication::translate("MainWindow", "Open Configuration Tool dialog", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnCfgTool_txt->setText(QApplication::translate("MainWindow", "Configuration Tool", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnVerbosity_txt->setToolTip(QApplication::translate("MainWindow", "Shows available Verbosity Levels", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnVerbosity_txt->setText(QApplication::translate("MainWindow", "Verbosity", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnUserDefTools_txt->setToolTip(QApplication::translate("MainWindow", "Show user-defined tools list", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnUserDefTools_txt->setText(QApplication::translate("MainWindow", "User defined Tools", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnDBBrowser_txt->setToolTip(QApplication::translate("MainWindow", "Shows QPF Database Browser", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnDBBrowser_txt->setText(QApplication::translate("MainWindow", "Database Browser", Q_NULLPTR));
        btnCfgTool->setText(QString());
        btnDBBrowser->setText(QString());
        btnVerbosity->setText(QString());
        btnUserDefTools->setText(QString());
        dckNavigator->setWindowTitle(QApplication::translate("MainWindow", "Navigator", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tbtnArchive->setToolTip(QApplication::translate("MainWindow", "Click on this button to show the list of products in the Local Archive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnArchive->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show the list of products in the Local Archive", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnArchive->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tbtnTasks->setToolTip(QApplication::translate("MainWindow", "Click on this button to show the list of Processing Tasks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnTasks->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show the list of Processing Tasks", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnTasks->setText(QApplication::translate("MainWindow", "T", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tbtnViewer->setToolTip(QApplication::translate("MainWindow", "Click on this button to show the set of products open for viewing", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnViewer->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show the set of products open for viewing", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnViewer->setText(QApplication::translate("MainWindow", "V", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tbtnFilter->setToolTip(QApplication::translate("MainWindow", "Click on this button to show the create and view filters on data products", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnFilter->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show the set of products open for viewing", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnFilter->setText(QString());
#ifndef QT_NO_TOOLTIP
        tbtnAlerts->setToolTip(QApplication::translate("MainWindow", "Click on this button to show the list of processing and system alerts registered", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnAlerts->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show the list of processing and system alerts registered", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnAlerts->setText(QString());
#ifndef QT_NO_TOOLTIP
        tbtnMonit->setToolTip(QApplication::translate("MainWindow", "Click on this button to show a set of monitoring statistics and monitoring information", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnMonit->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show a set of monitoring statistics and monitoring information", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnMonit->setText(QApplication::translate("MainWindow", "M", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tbtnLog->setToolTip(QApplication::translate("MainWindow", "Click on this button to show the contents of the log files", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnLog->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show the contents of the log files", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnLog->setText(QApplication::translate("MainWindow", "L", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tbtnTools->setToolTip(QApplication::translate("MainWindow", "Click on this button to show a set of tools for the QPF Archive Viewer", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tbtnTools->setStatusTip(QApplication::translate("MainWindow", "Click on this button to show a set of tools for the QPF Archive Viewer", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tbtnTools->setText(QString());
        lblVerbosity->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        tboxNavigator->setItemText(tboxNavigator->indexOf(navpgProducts), QApplication::translate("MainWindow", "Products", Q_NULLPTR));
        tboxNavigator->setItemToolTip(tboxNavigator->indexOf(navpgProducts), QApplication::translate("MainWindow", "List of open products", Q_NULLPTR));
        tboxNavigator->setItemText(tboxNavigator->indexOf(navpgFilters), QApplication::translate("MainWindow", "Filters", Q_NULLPTR));
        tboxNavigator->setItemToolTip(tboxNavigator->indexOf(navpgFilters), QApplication::translate("MainWindow", "List of filters on QLA reports", Q_NULLPTR));
        tboxNavigator->setItemText(tboxNavigator->indexOf(navpgViews), QApplication::translate("MainWindow", "Views", Q_NULLPTR));
        tboxNavigator->setItemToolTip(tboxNavigator->indexOf(navpgViews), QApplication::translate("MainWindow", "List of QLA local archive defined views", Q_NULLPTR));
        tboxNavigator->setItemText(tboxNavigator->indexOf(navpgLogs), QApplication::translate("MainWindow", "Logs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
