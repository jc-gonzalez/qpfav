#include "sysalertsview.h"
#include "ui_sysalertsview.h"
#include "dlgalert.h"

using QPF::DlgAlert;

SysAlertsView::SysAlertsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysAlertsView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);

    mw = qobject_cast<MainWindow*>(parent);

    ui->vw->setContextMenuPolicy(Qt::CustomContextMenu);

    model = new SysAlertModel();
    ui->vw->setModel(model);
}

SysAlertsView::~SysAlertsView()
{
    delete ui;
}

//----------------------------------------------------------------------
// Method: setActionsHandler
// setActionsHandler
//----------------------------------------------------------------------
void SysAlertsView::setActionsHandler(ActionsHandler * a)
{
    aHdl = a;
    connect(aHdl->acSysAlertDisplayInfo, SIGNAL(triggered()),
            this, SLOT(showSysAlertInfo()));

    connect(ui->vw, SIGNAL(customContextMenuRequested(const QPoint &)),
            aHdl, SLOT(showSysAlertsContextMenu(const QPoint &)));
}

//----------------------------------------------------------------------
// Method: showSysAlertInfo
// showSysAlertInfo
//----------------------------------------------------------------------
void SysAlertsView::showSysAlertInfo()
{
    Alert alert = model->getAlertAt( ui->vw->currentIndex() );

    DlgAlert * dlg = new DlgAlert;
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setAlert(alert);
    dlg->show();
    dlg->raise();
    dlg->activateWindow();
}
