
#include "version.h"

#ifndef BUILD_ID
#define BUILD_ID ""
#endif

#include "mainwindow.h"

#include <iostream>
#include <unistd.h>

#include <QApplication>
#include <QSplashScreen>
#include <QHostInfo>

#include <QDebug>
#include <QStyleFactory>

#include <thread>

#include "config.h"

#define DEFAULT_INITIAL_PORT 50000

#define INFO(s)  std::cerr << s << '\n';

static QString appName(APP_NAME " - " APP_LONG_NAME);
static QString appRev("Release " APP_RELEASE " - " APP_DATE);
static QString appBld(BUILD_ID);

QString configStr("");
QString sessionStr("");
QString masterIpAddress("");
int initialPort(DEFAULT_INITIAL_PORT);

int verbosityLevel(0);

using QPF::MainWindow;

using Configuration::cfg;

//----------------------------------------------------------------------
// Function: usage
// Shows the command line to be used to call this application
//----------------------------------------------------------------------
void usage(int code)
{
    QString exeName = QCoreApplication::arguments().at(0);

    INFO("Usage: " << exeName.toStdString() << " -c dbURL [ -s sessionId ] "
         "[ -p initialPort ] [ -I masterIPAddress ] [ -v ] [ -h ]\n"
         "where:\n"
         "\t-c dbURL            URL to access the system database, in the form\n"
         "\t                        db://user:passwd@host:port/dbnamefile\n"
         "\t-s sessoinId        Set sessoin identifier\n\n"
         "\t-p initialPort      Set initial port for system set up (default:"
         << DEFAULT_INITIAL_PORT << ").\n\n"
         "\t-I masterIPaddress  Set the host IP address (by default the program takes\n"
         "\t                    this information from the system).\n"
         "\t-C                  Shows the Configuration Tool.\n\n"
         "\t-v                  Increases verbosity (default:silent operation).\n\n"
         "\t-h                  Shows this help message.\n");

    exit(code);
}

//----------------------------------------------------------------------
// Function: sayHello
// Shows a minimal title and build id for the application
//----------------------------------------------------------------------
void sayHello()
{
    std::string buildId(BUILD_ID);
    if (buildId.empty()) {
        char buf[20];
        sprintf(buf, "%ld", (long)(time(0)));
        buildId = std::string(buf);
    }

    const std::string hline("----------------------------------------"
                            "--------------------------------------\n");
    INFO(hline
         << " " << APP_NAME << " - " << APP_LONG_NAME << "\n"
         << " " << APP_DATE << " - "
         << APP_RELEASE << " Build " << buildId << "\\n"
         << " Master located at " << masterIpAddress.toStdString() << ":"
         << initialPort << "\n"
         << " Database server at " << configStr.toStdString() << "\n"
         << hline << std::endl);
}

//----------------------------------------------------------------------
// Function: ctrlMsg
// Shows a minimal title and build id for the application
//----------------------------------------------------------------------
void ctrlMsg(QSplashScreen & splash, int k = 0)
{
    const int TimeLapse = 500;
    QString msgs[] = {"Loading system configuration",
                      "Connecting to database",
                      "Checking components running state",
                      "Preparing graphical user interface",
                      "Launching application window",
                      ""};
    static int i = 0;

    QString msgToShow = "<font color=\"yellow\"><b>" + appName +
                        "<br>" + appRev + "<br>" + appBld + "</b></font><br>" +
                        "<font color=\"white\">" + msgs[i] + "</font>";
    splash.showMessage(msgToShow, Qt::AlignLeft, Qt::white);
    qApp->processEvents(QEventLoop::AllEvents);
    std::this_thread::sleep_for(std::chrono::milliseconds(TimeLapse));
    ++i;
}

void lookedUp(const QHostInfo &host)
{
    if (host.error() != QHostInfo::NoError) {
        INFO("Lookup failed:" << host.errorString().toStdString());
        return;
    }

    const auto addresses = host.addresses();
    for (const QHostAddress &address : addresses)
        INFO("Found address:" << address.toString().toStdString());
}

//----------------------------------------------------------------------
// Function: main
// Creates the application main class, parses the command line arguments
// and invokes the main window
//----------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    foreach (const QString & s, QStyleFactory::keys()) {
        std::cerr << "Style: " << s.toStdString() << '\n';
    }
    //a.setStyle(QStyleFactory::create("Fusion"));

    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);

    QHostInfo::lookupHost(hostName, lookedUp);

    QString configStr("");
    QString sessionStr("");
    QString masterIpAddress("");
    QString styleName("cleanlooks");
    int initialPort(DEFAULT_INITIAL_PORT);
    bool showConfigTool = false;

    int exitCode = EXIT_FAILURE;

    int opt;
    while ((opt = getopt(argc, argv, "hvCp:c:s:I:S:")) != -1) {
        switch (opt) {
        case 'v':
            verbosityLevel++;
            break;
        case 'C':
            showConfigTool = true;
            break;
        case 'c':
            configStr = QString(optarg);
            break;
        case 'p':
            initialPort = atoi(optarg);
            break;
        case 's':
            sessionStr = QString(optarg);
            break;
        case 'S':
            styleName = QString(optarg);
            break;
        case 'I':
            masterIpAddress = QString(optarg);
            break;
        case 'h':
            exitCode = EXIT_SUCCESS;
        default: /* '?' */
            usage(exitCode);
        }
    }

    if (configStr.isEmpty()) { usage(EXIT_FAILURE); }

    QPixmap pixmap(":/img/EuclidQPFAV.png");
    QSplashScreen splash(pixmap);
    splash.show();
    ctrlMsg(splash);
    sayHello();

    ctrlMsg(splash);

    MainWindow w(0, configStr, styleName);
    // QPF::MainWindow w(configStr, sessionStr, masterIpAddress, initialPort);

    ctrlMsg(splash);
    //w.setAppInfo(APP_NAME " - " APP_LONG_NAME,
    //             "V" APP_RELEASE " " APP_DATE, BUILD_ID);

    ctrlMsg(splash);

    w.show();

    ctrlMsg(splash);

    splash.finish(&w);

    return a.exec();
}
