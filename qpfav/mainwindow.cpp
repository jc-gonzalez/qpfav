#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "darkpalette.h"
#include "dbmng.h"
#include "config.h"
#include "version.h"

#include "configtool.h"
#include "dbbrowser.h"
#include "exttoolsdef.h"
#include "verbleveldlg.h"

#include <iostream>

#include <QFileDialog>
#include <QMessageBox>

// Basic log macros
#define TMsg(s)  std::cerr << s << '\n';
#define DMsg(s)  std::cerr << s << '\n';
#define IMsg(s)  std::cerr << s << '\n';
#define WMsg(s)  std::cerr << s << '\n';
#define EMsg(s)  std::cerr << s << '\n';
#define FMsg(s)  std::cerr << s << '\n';

using Configuration::cfg;

namespace QPF {

// Status bar
const int MainWindow::MessageDelay = 2000;

// Valid Manager states
const int MainWindow::ERROR        = -1;
const int MainWindow::OFF          =  0;
const int MainWindow::INITIALISED  =  1;
const int MainWindow::RUNNING      =  2;
const int MainWindow::OPERATIONAL  =  3;

// Valid Manager state names (strings)
const std::string MainWindow::ERROR_StateName("ERROR");
const std::string MainWindow::OFF_StateName("OFF");
const std::string MainWindow::INITIALISED_StateName("INITIALISED");
const std::string MainWindow::RUNNING_StateName("RUNNING");
const std::string MainWindow::OPERATIONAL_StateName("OPERATIONAL");

// Sections in HMI
const int SectionArchive = 0;    
const int SectionTasks   = 1;  
const int SectionViewer  = 2;   
const int SectionFilter  = 3;   
const int SectionAlerts  = 4;   
const int SectionMonit   = 5;  
const int SectionLog     = 6;
const int SectionTools   = 7;  

// Template for pushTo/pullFromVoSpace request file
const QString MainWindow::VOSpaceURL =
    "https://vospace.esac.esa.int/vospace/";

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent, QString & cfgFile, QString s) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    styleName(s)
{
    // Configure object
    configure(cfgFile);

    // Set UI
    ui->setupUi(this);
    completeUi();
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

//----------------------------------------------------------------------
// Method: configure
// Rest of operations to setup UI completly
//----------------------------------------------------------------------
void MainWindow::configure(QString & cfgFile)
{
    // Load configuration
    cfg.load(cfgFile);
    getUserToolsFromSettings();

    // Initialize DB
    setDB();
}

//----------------------------------------------------------------------
// Method: completeUi
// Rest of operations to setup UI completly
//----------------------------------------------------------------------
void MainWindow::completeUi()
{
    // Create general GUI actions handler
    aHdl = new ActionsHandler(this);
    setUToolTasks();

    // Initialize palette
    initPalette();

    // Update tool button ids
    int i = 0;
    for (auto & tbtn: {ui->tbtnArchive, ui->tbtnTasks, ui->tbtnViewer,
                       ui->tbtnFilter, ui->tbtnAlerts, ui->tbtnMonit,
                       ui->tbtnLog, ui->tbtnTools}) {
        ui->btngrpNavigator->setId(tbtn, i++);
    }

    // Local Archive panel
    ui->localArchView->init(this);
    ui->localArchView->setAutoButtons(ui->cboxLocalArchAuto);
    connect(ui->tbtnRefresh, SIGNAL(clicked()), ui->localArchView, SLOT(arefresh()));
    connect(ui->tbtnExpand,  SIGNAL(clicked()), ui->localArchView, SLOT(aexpand()));
    connect(ui->tbtnCollapse, SIGNAL(clicked()), ui->localArchView, SLOT(acollapse()));
    connect(ui->tbtnResize, SIGNAL(clicked()), ui->localArchView, SLOT(aresize()));

    ui->localArchView->setActionsHandler(aHdl);

    // Tasks panel
    ui->tasksView->setActionsHandler(aHdl);

    // Product viewers panel
    connect(ui->localArchView, SIGNAL(openProductInViewer(QString)),
            ui->prodsViewer, SLOT(createNewViewer(QString)));
    connect(ui->prodsViewer, SIGNAL(newProductViewerAvailable(QString)),
            this, SLOT(addToProdViewersList(QString)));
    connect(ui->lstvwProducts, &QListWidget::itemDoubleClicked,
            [this](QListWidgetItem *item) { 
                this->ui->prodsViewer->selectProductViewer(item->text());
                this->showSection(SectionViewer); });

    // Tools panel
    connect(ui->btnCfgTool, SIGNAL(clicked()), aHdl->acConfigTool, SLOT(trigger()));
    connect(ui->btnDBBrowser, SIGNAL(clicked()), aHdl->acBrowseDB, SLOT(trigger()));
    connect(ui->btnUserDefTools, SIGNAL(clicked()), aHdl->acExtTools, SLOT(trigger()));
    connect(ui->btnVerbosity, SIGNAL(clicked()), aHdl->acVerbosity, SLOT(trigger()));

    connect(ui->btnCfgTool_txt, SIGNAL(clicked()), aHdl->acConfigTool, SLOT(trigger()));
    connect(ui->btnDBBrowser_txt, SIGNAL(clicked()), aHdl->acBrowseDB, SLOT(trigger()));
    connect(ui->btnUserDefTools_txt, SIGNAL(clicked()), aHdl->acExtTools, SLOT(trigger()));
    connect(ui->btnVerbosity_txt, SIGNAL(clicked()), aHdl->acVerbosity, SLOT(trigger()));

    // Alerts panel
    ui->procAlertsView->setActionsHandler(aHdl);
    ui->sysAlertsView->setActionsHandler(aHdl);
}

//----------------------------------------------------------------------
// Method: initPalette
// Initialize palete for the GUI (dark)
//----------------------------------------------------------------------
void MainWindow::initPalette()
{
    DarkPalette darkPalette(this);
    darkPalette.apply(styleName, "DarkBlue");
}

//----------------------------------------------------------------------
// Method: setDB
// Specify connection settings for internal QPF DB
//----------------------------------------------------------------------
void MainWindow::setDB()
{
    // Prepare DBManager
    if (QSqlDatabase::connectionNames().isEmpty()) {
        QString dbName   (cfg.db("name").toString()); // ( "qpfdb" );     //Config::DBName.c_str() );
        QString userName (cfg.db("user").toString()); // ( "eucops" );    //Config::DBUser.c_str() );
        QString password (cfg.db("pwd") .toString()); // ( "" );          //Config::DBPwd.c_str() );
        QString hostName (cfg.db("host").toString()); // ( "127.0.0.1" ); //Config::DBHost.c_str() );
        QString port     (cfg.db("port").toString()); // ( "5432" );      //Config::DBPort.c_str() );

        DBManager::DBConnection connection =
            { "QPSQL", dbName, userName, password, hostName, port.toInt() };

        DMsg("Adding DB connection");
        DBManager::addConnection("qpfdb", connection);
        DMsg("Adding DB connection - DONE");
    }

    statusBar()->showMessage(tr("QPF HMI Ready . . ."), MessageDelay);
}

//----------------------------------------------------------------------
// Method: getUserTools
// Returns a reference to the user defined tools map
//----------------------------------------------------------------------
void MainWindow::getUserTools(MapOfUserDefTools & u)
{
    if (! u.isEmpty()) { u.clear(); }

    foreach (QString k, userDefTools.keys()) { 
        QUserDefTool udt = userDefTools[k];
        u.insert(k, udt); 
    }
}

//----------------------------------------------------------------------
// Method: getUserToolsFromSettings
// Retrieves user defined tools from settings file
//----------------------------------------------------------------------
void MainWindow::getUserToolsFromSettings()
{
    userDefTools.clear();
    QJsonArray uts = cfg.userDefToolsArray();
    int numUdefTools = uts.size();
    for (int i = 0; i < numUdefTools; ++i) {
        QUserDefTool qudt;
        qudt.name       = uts.at(i).toObject()["name"].toString();
        qudt.desc       = uts.at(i).toObject()["description"].toString();
        qudt.exe        = uts.at(i).toObject()["executable"].toString();
        qudt.args       = uts.at(i).toObject()["arguments"].toString();
        qudt.prod_types = uts.at(i).toObject()["productTypes"].toString().split(",");
        std::cerr << qudt.name.toStdString() << ", " 
                  << qudt.desc.toStdString() << ", " 
                  << qudt.exe.toStdString() << ", " 
                  << qudt.args.toStdString() << ", " 
                  << std::endl;
        userDefTools[qudt.name] = qudt;
    }

    userDefProdTypes.clear();
    foreach (QJsonValue s, cfg.products()["productTypes"].toArray()) {
        userDefProdTypes.append(s.toString());
    }
}

//----------------------------------------------------------------------
// Method: putUserToolsToSettings
// Retrieves user defined tools from settings file
//----------------------------------------------------------------------
void MainWindow::putUserToolsToSettings()
{
    /*
     TODO
     */
}

//----------------------------------------------------------------------
// Method: getProductTypes
// Provide the list (vector) of product type names
//----------------------------------------------------------------------
void MainWindow::getProductTypes(std::vector<std::string> & pTypes, int & siz)
{
    siz = 0;
    pTypes.clear();
    for (auto & s : cfg.products("productTypes").toArray().toVariantList()) {
        QString item = s.toString();
        pTypes.push_back(item.replace("_LOG", "-LOG").toStdString());
        if (item.length() > siz) { siz = item.length(); }
    }
}

//----------------------------------------------------------------------
// Method: quitQPFAV
// Quits the application
//----------------------------------------------------------------------
void MainWindow::quitQPFAV()
{
    qApp->quit();
}

//----------------------------------------------------------------------
// Method: processPath
// Specify a folder and process the products contained therein
//----------------------------------------------------------------------
void MainWindow::processPath()
{
    QString folderName = QFileDialog::getExistingDirectory(this,
            tr("Process products in folder..."));
    if (! folderName.isEmpty()) {
        //QtConcurrent::run(this, &MainWindow::processProductsInPath, folderName);
    }
}

#ifndef QT_NO_CLIPBOARD
//----------------------------------------------------------------------
// Method: cut
//----------------------------------------------------------------------
void MainWindow::cut()
{
}

//----------------------------------------------------------------------
// Method: copy
//----------------------------------------------------------------------
void MainWindow::copy()
{
}

//----------------------------------------------------------------------
// Method: paste
//----------------------------------------------------------------------
void MainWindow::paste()
{
}
#endif

//----------------------------------------------------------------------
// Method: about
// Reads configuration file
//----------------------------------------------------------------------
void MainWindow::about()
{
#ifndef BUILD_ID
#define BUILD_ID ""
#endif

    QString buildId(BUILD_ID);
    if (buildId.isEmpty()) {
        char buf[20];
        sprintf(buf, "%ld", (long)(time(0)));
        buildId = QString(buf);
    }

    QMessageBox::about(this, tr("About " APP_NAME),
                       tr("This is the " APP_PURPOSE " v " APP_RELEASE "\n"
                          APP_COMPANY "\n"
                          APP_DATE " - Build ") + buildId);
}

//----------------------------------------------------------------------
// Method: showConfigTool
// Shows configuration tool window
//----------------------------------------------------------------------
void MainWindow::showConfigTool()
{
    static ConfigTool cfgTool(0);

    cfgTool.prepare(userDefTools, userDefProdTypes);
    if (cfgTool.exec()) {
        TMsg("Updating user tools!");
        cfgTool.getExtTools(userDefTools);
        setUToolTasks();
        //if (hmiNode != 0) {
        //    hmiNode->sendNewConfig();
        //    TMsg("Sending new configuration to all the nodes");
        //}
        // Update HMI
        ui->lblVerbosity->setText(cfg.general("logLevel").toString());
    }
}

//----------------------------------------------------------------------
// Method: showDBBrowser
// Shows System Database Browser
//----------------------------------------------------------------------
void MainWindow::showDBBrowser()
{
    DBBrowser dlg;

    dlg.exec();
}

//----------------------------------------------------------------------
// Method: showExtToolsDef
// Shows external toos definition window
//----------------------------------------------------------------------
void MainWindow::showExtToolsDef()
{
    ExtToolsDef dlg;
    dlg.initialize(userDefTools, userDefProdTypes);
    if (dlg.exec()) {
        dlg.getTools(userDefTools);
        storeQUTools2Cfg(userDefTools);
        setUToolTasks();
    }
}

//----------------------------------------------------------------------
// Method: showVerbLevel
// Shows verbosity level selector dialog
//----------------------------------------------------------------------
void MainWindow::showVerbLevel()
{
    VerbLevelDlg dlg;

    if (dlg.exec()) {
        //int minLvl = dlg.getVerbosityLevelIdx();
        //Log::setMinLogLevel((Log::LogLevel)(minLvl));
        ui->lblVerbosity->setText(dlg.getVerbosityLevelName());
        //hmiNode->sendMinLogLevel(dlg.getVerbosityLevelName().toStdString());
        statusBar()->showMessage(tr("Setting Verbosity level to ") +
                                dlg.getVerbosityLevelName(), 2 * MessageDelay);
    }
}

//----------------------------------------------------------------------
// Method: convertQUTools2UTools
// Convert Qt map of user def tools to std map
//----------------------------------------------------------------------
void MainWindow::storeQUTools2Cfg(MapOfUserDefTools qutmap)
{
    QJsonArray uts;
    QMap<QString, QUserDefTool>::const_iterator it  = qutmap.constBegin();
    auto end = qutmap.constEnd();
    while (it != end) {
        const QUserDefTool & t = it.value();
        QJsonObject ut = { {"name", t.name},
                           {"description", t.desc},
                           {"executable", t.exe},
                           {"arguments", t.args},
                           {"productTypes", t.prod_types.join(",")} };
        uts.append(ut);
        ++it;
    }

    cfg.data().remove("userDefTools");
    cfg.data().insert("userDefTools", uts); 
}

//----------------------------------------------------------------------
// Method: setUToolTasks
// Set map of user defined tasks
//----------------------------------------------------------------------
void MainWindow::setUToolTasks()
{
    aHdl->acUserTools.clear();
    foreach (QString key, userDefTools.keys()) {
        const QUserDefTool & udt = userDefTools.value(key);
        QAction * ac = new QAction(key, ui->localArchView);
        ac->setStatusTip(udt.desc);
        connect(ac, SIGNAL(triggered()), ui->localArchView, SLOT(openWith()));
        aHdl->acUserTools[key] = ac;
    }
}

//----------------------------------------------------------------------
// Method: addToProdViewersList
// Add viewer
//----------------------------------------------------------------------
void MainWindow::addToProdViewersList(QString name)
{
    ui->lstvwProducts->addItem(name);
    showSection(SectionViewer);
}

//----------------------------------------------------------------------
// Method: showSection()
// Add viewer
//----------------------------------------------------------------------
void MainWindow::showSection(int sec)
{
    ui->stckMain->setCurrentIndex(sec);
}

}
