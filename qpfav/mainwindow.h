#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QVector>
#include <QColor>
#include <QStatusBar>

#include <QStandardItemModel>

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
    explicit MainWindow(QWidget *parent, QString & cfgFile, 
                        QString s = QString("cleanlooks"));
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

    // Product Viewers
    void addToProdViewersList(QString);

    void getUserTools(MapOfUserDefTools & u);

private:
    void configure(QString & cfgFile);
    void completeUi();
    void initPalette();
    void setDB();

    void getUserToolsFromSettings();
    void putUserToolsToSettings();

    void storeQUTools2Cfg(MapOfUserDefTools qutmap);
    void setUToolTasks();
    void showSection(int sec);

private:
    Ui::MainWindow *ui;

    ActionsHandler * aHdl;

    // User Defined Tools
    MapOfUserDefTools userDefTools;
    QStringList       userDefProdTypes;

    QString styleName;

    QStandardItemModel* Model;
    QStandardItem* Item1;
    QStandardItem* Item2;
 
    std::vector<QStandardItem*> Items;

    friend class ActionsHandler;
};

}

#endif // MAINWINDOW_H
