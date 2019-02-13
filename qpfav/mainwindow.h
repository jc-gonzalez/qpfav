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

private slots:
    QString getVar(QString var, QString filter);
    void setVar(QString var, QString filter, QString new_value);
    void run();

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

    void updateState();
    void updateVerbLogLevel();

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

    QString stateName;

    friend class ActionsHandler;
};

}

#endif // MAINWINDOW_H
