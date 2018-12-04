#include "procalertsview.h"
#include "ui_procalertsview.h"

ProcAlertsView::ProcAlertsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcAlertsView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);

    model = new ProcAlertModel;
    ui->vw->setModel(model);
}

ProcAlertsView::~ProcAlertsView()
{
    delete ui;
}
