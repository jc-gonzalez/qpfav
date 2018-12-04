#include "localarchview.h"
#include "ui_localarchview.h"

#include "mainwindow.h"

#include <QListView>
#include <QTimer>

#include <iostream>

using QPF::MainWindow;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
LocalArchiveView::LocalArchiveView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalArchiveView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);

    std::vector<std::string> pTypes;
    int siz = 0;
    MainWindow * mw = qobject_cast<MainWindow*>(parent);
    mw->getProductTypes(pTypes, siz);

    model = new ProductsModel(pTypes, siz);
    ui->vw->setModel(model);

    // Define auto-buttons model
    autoBtnsModel = new QStandardItemModel(this);
    std::vector<QString> autoBtnsLabels {"Auto update", 
                                         "Auto expand", 
                                         "Auto resize",
                                         "Multi-selection"};
    QStandardItem * item = nullptr;
    for (auto & s : autoBtnsLabels) {
        item = new QStandardItem();
        item->setText(s);
        item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        item->setData(Qt::Unchecked, Qt::CheckStateRole);
        autoBtnsModel->appendRow(item);
        autoBtns.push_back(item);   
    }

    connect(autoBtnsModel, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), 
            this, SLOT(autoBtnsChanged(const QModelIndex&, const QModelIndex&)));

    // Launch run thread
    //std::thread(&LocalArchiveView::run, this).detach();
    QTimer * refreshTimer = new QTimer(this);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(run()));
    refreshTimer->start(2000);}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
LocalArchiveView::~LocalArchiveView()
{
    delete ui;
}

//----------------------------------------------------------------------
// SLOT: setAutoButtons
// Defines the target combo box for the auto flags
//----------------------------------------------------------------------
void LocalArchiveView::setAutoButtons(QComboBox * cboxAuto)
{
    cboxAuto->setModel(autoBtnsModel);
    cboxAuto->setView(new QListView);
}
 
//----------------------------------------------------------------------
// SLOT: autoBtnsChanged
// Updates the auto-behavior flags
//----------------------------------------------------------------------
void LocalArchiveView::autoBtnsChanged(const QModelIndex& topLeft, 
                                       const QModelIndex& bottomRight)
{
    AutoBehavior autoBeh = (AutoBehavior)(topLeft.row());
    QStandardItem * item = autoBtns[topLeft.row()];
    bool currentState = (item->checkState() == Qt::Checked);
    switch (autoBeh) {
    case AUTO_UPDATE: 
        autoUpdate = currentState;
        break;
    case AUTO_EXPAND: 
        autoExpand = currentState;
        break;
    case AUTO_RESIZE: 
        autoResize = currentState; 
        break;
     case MULTI_SELECT: 
        ui->vw->setSelectionMode(currentState ? 
                                 QAbstractItemView::MultiSelection :
                                 QAbstractItemView::SingleSelection);
        break;
    default:
        break;
    }
}

//----------------------------------------------------------------------
// SLOT: run
// Periodic update of the view, if needed
//----------------------------------------------------------------------
void LocalArchiveView::run()
{
    // Update context menus depending on config flags
    //actHdl->getAcReprocess()->setEnabled(cfg.flags.allowReprocessing());
    
    if (autoUpdate) { arefresh(); }
    if (autoExpand) { aexpand(); }
    if (autoResize) { aresize(); }

    //ui->treevwArchive->hideColumn(1);
    //ui->treevwArchive->hideColumn(0);
}

//----------------------------------------------------------------------
// SLOT: arefresh
// Updates the local archive model on demand
//----------------------------------------------------------------------
void LocalArchiveView::arefresh()
{
    model->refresh();

    int sortCol = ui->vw->header()->sortIndicatorSection();
    Qt::SortOrder sortOrd = ui->vw->header()->sortIndicatorOrder();    
    ui->vw->sortByColumn(sortCol, sortOrd);
}

//----------------------------------------------------------------------
// SLOT: aexpand
// Expands all the trees in the view
//----------------------------------------------------------------------
void LocalArchiveView::aexpand()
{
    ui->vw->expandAll(); 
}

//----------------------------------------------------------------------
// SLOT: acollect
// Collect all the trees in the view
//----------------------------------------------------------------------
void LocalArchiveView::acollapse()
{
    ui->vw->collapseAll(); 
}

//----------------------------------------------------------------------
// SLOT: aresize
// Resize the columns in the view
//----------------------------------------------------------------------
void LocalArchiveView::aresize()
{
    for (int i = 0; i < model->columnCount(); ++i) {
        ui->vw->resizeColumnToContents(i);
    }
}
