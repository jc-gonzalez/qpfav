#include "procalertsview.h"
#include "ui_procalertsview.h"
#include "dlgalert.h"

using QPF::DlgAlert;

ProcAlertsView::ProcAlertsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcAlertsView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);

    mw = qobject_cast<MainWindow*>(parent);

    ui->vw->setContextMenuPolicy(Qt::CustomContextMenu);

    model = new ProcAlertModel;
    ui->vw->setModel(model);
}

ProcAlertsView::~ProcAlertsView()
{
    delete ui;
}

//----------------------------------------------------------------------
// Method: setActionsHandler
// setActionsHandler
//----------------------------------------------------------------------
void ProcAlertsView::setActionsHandler(ActionsHandler * a)
{
    aHdl = a;

    connect(aHdl->acProcAlertDisplayInfo, SIGNAL(triggered()),
            this, SLOT(showProcAlertInfo()));
    connect(aHdl->acProcAlertLocateInProduct, SIGNAL(triggered()),
            this, SLOT(locateAlertInProduct()));

    connect(ui->vw, SIGNAL(customContextMenuRequested(const QPoint &)),
            aHdl, SLOT(showProcAlertsContextMenu(const QPoint &)));
}

//----------------------------------------------------------------------
// Method: showProcAlertInfo
// showProcAlertInfo
//----------------------------------------------------------------------
void ProcAlertsView::showProcAlertInfo()
{
    Alert alert = model->getAlertAt( ui->vw->currentIndex() );

    DlgAlert * dlg = new DlgAlert;
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setAlert(alert);
    dlg->show();
    dlg->raise();
    dlg->activateWindow();
}

//----------------------------------------------------------------------
// Method: locateAlertInProduct
// locateAlertInProduct
//----------------------------------------------------------------------
void ProcAlertsView::locateAlertInProduct()
{

}
