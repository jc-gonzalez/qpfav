#ifndef LOCALARCHVIEW_H
#define LOCALARCHVIEW_H

#include <QWidget>
#include <QComboBox>

#include "productsmodel.h"
#include "mainwindow.h"
#include "actionshandler.h"

using QPF::MainWindow;
using QPF::ActionsHandler;

namespace Ui {
class LocalArchiveView;
}

using QPF::ProductsModel;

class LocalArchiveView : public QWidget
{
    Q_OBJECT

public:
    explicit LocalArchiveView(QWidget *parent = 0);
    ~LocalArchiveView();
    void setAutoButtons(QComboBox * cboxAuto);
    void init(MainWindow * x);

signals:
    void openProductInViewer(QString);
    
public slots:
    void autoBtnsChanged(const QModelIndex& topLeft, 
                         const QModelIndex& bottomRight);

    void run();
    void arefresh();
    void aexpand();
    void acollapse();
    void aresize();

    void setActionsHandler(ActionsHandler * a);
    
    void openLocation();
    void openWithDefault();
    void reprocessProduct();
    void analyzeProduct();
    void exportProduct();

    void openLocalArchiveElement(QModelIndex idx);
    void openWith();

private slots:
    void openLocalArchiveFullPath(QString fullPath);
    void copyProducts(QStringList lst, QString from, QString to);

private:
    enum AutoBehavior { AUTO_UPDATE, 
                        AUTO_EXPAND, 
                        AUTO_RESIZE, 
                        MULTI_SELECT };

    Ui::LocalArchiveView * ui;
    ProductsModel * model;

    QStandardItemModel * autoBtnsModel;
    std::vector<QStandardItem*> autoBtns;

    bool autoUpdate, autoExpand, autoResize;

    MainWindow * mw;
    ActionsHandler * aHdl;

    static const int NumOfURLCol;
};

#endif // LOCALARCHVIEW_H
