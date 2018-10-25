#include "procalertsview.h"
#include "ui_procalertsview.h"

ProcAlertsView::ProcAlertsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcAlertsView)
{
    ui->setupUi(this);

    model = new ProcAlertModel;
    ui->vw->setModel(model);
}

ProcAlertsView::~ProcAlertsView()
{
    delete ui;
}
