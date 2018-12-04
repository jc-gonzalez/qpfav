#include "sysalertsview.h"
#include "ui_sysalertsview.h"

#include "sysalertmodel.h"

SysAlertsView::SysAlertsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysAlertsView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);

    model = new SysAlertModel();
    ui->vw->setModel(model);
}

SysAlertsView::~SysAlertsView()
{
    delete ui;
}
