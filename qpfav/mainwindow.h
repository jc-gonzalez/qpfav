#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QVector>
#include <QColor>

#include "actionshandler.h"
#include "hmitypes.h"

namespace Ui {
class MainWindow;
}

namespace QPF {

class MainWindow : public QMainWindow
{
    Q_OBJECT

    // Status bar
    static const int MessageDelay;

    // Valid Manager states
    static const int ERROR;
    static const int OFF;
    static const int INITIALISED;
    static const int RUNNING;
    static const int OPERATIONAL;

    // Valid Manager states
    static const std::string ERROR_StateName;
    static const std::string OFF_StateName;
    static const std::string INITIALISED_StateName;
    static const std::string RUNNING_StateName;
    static const std::string OPERATIONAL_StateName;

    // URLs
    static const QString VOSpaceURL;

public:
    explicit MainWindow(QWidget *parent, QString & cfgFile);
    ~MainWindow();

    void getProductTypes(std::vector<std::string> & pTypes, int & siz);

public slots:
    // File menu
    void quitQPFAV();
    void processPath();

    // Edit menu
    void cut();
    void copy();
    void paste();

    // View menu

    // Tools menu
    void showConfigTool();
    void showDBBrowser();
    void showExtToolsDef();
    void showVerbLevel();

    // Help menu
    void about();

private:
    void initPalette();
    void setDB();

    void storeQUTools2Cfg(MapOfUserDefTools qutmap);
    void setUToolTasks();

private:
    Ui::MainWindow *ui;

    // User Defined Tools
    MapOfUserDefTools userDefTools;
    QStringList       userDefProdTypes;

    friend class ActionsHandler;
};

}

#endif // MAINWINDOW_H
