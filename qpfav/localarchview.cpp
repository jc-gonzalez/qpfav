#include "localarchview.h"
#include "ui_localarchview.h"

#include "mainwindow.h"

using QPF::MainWindow;

LocalArchiveView::LocalArchiveView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalArchiveView)
{
    ui->setupUi(this);

    std::vector<std::string> pTypes;
    int siz = 0;
    MainWindow * mw = qobject_cast<MainWindow*>(parent);
    mw->getProductTypes(pTypes, siz);

    model = new ProductsModel(pTypes, siz);
    ui->vw->setModel(model);
}

LocalArchiveView::~LocalArchiveView()
{
    delete ui;
}
