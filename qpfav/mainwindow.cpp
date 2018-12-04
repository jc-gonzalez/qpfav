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

// Template for pushTo/pullFromVoSpace request file
const QString MainWindow::VOSpaceURL =
    "https://vospace.esac.esa.int/vospace/";

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent, QString & cfgFile, QString s) :
    QMainWindow(parent),
    styleName(s),
    ui(new Ui::MainWindow)
{
    // Load configuration
    cfg.load(cfgFile);

    // Initialize DB
    setDB();

    // Set UI
    ui->setupUi(this);

    aHdl = new ActionsHandler(this);

    // Initialize palette
    initPalette();

    // Update tool button ids
    int i = 0;
    for (auto & tbtn: {ui->tbtnArchive, ui->tbtnTasks, ui->tbtnViewer,
                       ui->tbtnFilter, ui->tbtnAlerts, ui->tbtnMonit,
                       ui->tbtnLog, ui->tbtnTools}) {
        ui->btngrpNavigator->setId(tbtn, i++);
    }

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
// Method: completeUi
// Rest of operations to setup UI completly
//----------------------------------------------------------------------
void MainWindow::completeUi()
{
    // Local Archive panel
    ui->localArchView->setAutoButtons(ui->cboxLocalArchAuto);
    connect(ui->tbtnRefresh, SIGNAL(clicked()), ui->localArchView, SLOT(arefresh()));
    connect(ui->tbtnExpand,  SIGNAL(clicked()), ui->localArchView, SLOT(aexpand()));
    connect(ui->tbtnCollapse, SIGNAL(clicked()), ui->localArchView, SLOT(acollapse()));
    connect(ui->tbtnResize, SIGNAL(clicked()), ui->localArchView, SLOT(aresize()));

    // Tasks panel

    // Tools panel
    connect(ui->btnCfgTool, SIGNAL(clicked()), aHdl->acConfigTool, SLOT(trigger()));
    connect(ui->btnDBBrowser, SIGNAL(clicked()), aHdl->acBrowseDB, SLOT(trigger()));
    connect(ui->btnUserDefTools, SIGNAL(clicked()), aHdl->acExtTools, SLOT(trigger()));
    connect(ui->btnVerbosity, SIGNAL(clicked()), aHdl->acVerbosity, SLOT(trigger()));

    connect(ui->btnCfgTool_txt, SIGNAL(clicked()), aHdl->acConfigTool, SLOT(trigger()));
    connect(ui->btnDBBrowser_txt, SIGNAL(clicked()), aHdl->acBrowseDB, SLOT(trigger()));
    connect(ui->btnUserDefTools_txt, SIGNAL(clicked()), aHdl->acExtTools, SLOT(trigger()));
    connect(ui->btnVerbosity_txt, SIGNAL(clicked()), aHdl->acVerbosity, SLOT(trigger()));
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
// Method: getUserToolsFromSettings
// Retrieves user defined tools from settings file
//----------------------------------------------------------------------
void MainWindow::getUserToolsFromSettings()
{
    userDefTools.clear();
	QJsonArray & uts = cfg.userDefToolsArray();
    int numUdefTools = uts.size();
    for (int i = 0; i < numUdefTools; ++i) {
        QUserDefTool qudt;
        qudt.name       = uts.at(i).toObject()["name"].toString();
        qudt.desc       = uts.at(i).toObject()["description"].toString();
        qudt.exe        = uts.at(i).toObject()["executable"].toString();
        qudt.args       = uts.at(i).toObject()["arguments"].toString();
        qudt.prod_types = uts.at(i).toObject()["productTypes"].toString().split(",");

        userDefTools[qudt.name] = qudt;
    }

    userDefProdTypes.clear();
    for (auto & s : cfg.products.productTypes()) {
        userDefProdTypes.append(QString::fromStdString(s));
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
        int minLvl = dlg.getVerbosityLevelIdx();
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
    /*
    json uts;

    QMap<QString, QUserDefTool>::const_iterator it  = qutmap.constBegin();
    auto end = qutmap.constEnd();
    int i = 0;
    while (it != end) {
        const QUserDefTool & t = it.value();

        uts[i]["name"]         = t.name.toStdString();
        uts[i]["description"]  = t.desc.toStdString();
        uts[i]["executable"]   = t.exe.toStdString();
        uts[i]["arguments"]    = t.args.toStdString();
        uts[i]["productTypes"] = t.prod_types.join(",").toStdString();

        ++it;
        ++i;
    }

    cfg.userDefTools.fromStr(JValue(uts).str());
    */
}

//----------------------------------------------------------------------
// Method: setUToolTasks
// Set map of user defined tasks
//----------------------------------------------------------------------
void MainWindow::setUToolTasks()
{
    /*
    actHdl->getAcUserTools().clear();
    foreach (QString key, userDefTools.keys()) {
        const QUserDefTool & udt = userDefTools.value(key);
        QAction * ac = new QAction(key, ui->treevwArchive);
        ac->setStatusTip(udt.desc);
        connect(ac, SIGNAL(triggered()), this, SLOT(openWith()));
        actHdl->getAcUserTools()[key] = ac;
    }
    */
}


}
