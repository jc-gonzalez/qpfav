#ifndef PRODUCTSVIEWER_H
#define PRODUCTSVIEWER_H

#include <QWidget>
#include <QMap>
#include <QListWidgetItem>
#include "tasksmodel.h"
#include "mainwindow.h"
#include "actionshandler.h"
#include "util.h"

using QPF::MainWindow;
using QPF::ActionsHandler;

namespace Ui {
class ProductsViewer;
}

using QPF::TasksModel;

class ProductsViewer : public QWidget
{
    Q_OBJECT

public:
    explicit ProductsViewer(QWidget *parent = 0);
    ~ProductsViewer();

signals:
    void newProductViewerAvailable(QString);

public slots:
    void createNewViewer(QString fullPath);
    bool selectProductViewer(QString name);

private:
    Ui::ProductsViewer * ui;
};

#endif // PRODUCTSVIEWER_H
