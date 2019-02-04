#include "localarchview.h"
#include "ui_localarchview.h"

#include <QListView>
#include <QTimer>

#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QProcess>

#include <iostream>

#include "hmitypes.h"
#include "config.h"
#include "util.h"
#include "dlgreproc.h"

using namespace QPF;

using Configuration::cfg;

#include <iostream>
#define TRC(s) std::cerr << s << std::endl;

static const int NumOfURLCol = 12;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
LocalArchiveView::LocalArchiveView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalArchiveView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
LocalArchiveView::~LocalArchiveView()
{
    delete ui;
}

//----------------------------------------------------------------------
// METHOD: Define parent main window and configure widget
//----------------------------------------------------------------------
void LocalArchiveView::init(MainWindow * x)
{
    std::vector<std::string> pTypes;
    int siz = 0;

    mw = x;
    mw->getProductTypes(pTypes, siz);

    ui->vw->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->vw->setEditTriggers(QAbstractItemView::NoEditTriggers);

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
    refreshTimer->start(2000);
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
    //aHdl->acReprocess->setEnabled(cfg.flags.allowReprocessing());

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

//----------------------------------------------------------------------
// Method: setActionsHandler
// setActionsHandler
//----------------------------------------------------------------------
void LocalArchiveView::setActionsHandler(ActionsHandler * a)
{
    aHdl = a;

    connect(aHdl->acArchiveShow, SIGNAL(triggered()),
            this, SLOT(openLocation()));
    connect(aHdl->acDefault, SIGNAL(triggered()),
            this, SLOT(openWithDefault()));
    connect(aHdl->acReprocess, SIGNAL(triggered()),
            this, SLOT(reprocessProduct()));
    connect(aHdl->acAnalyzeIPython, SIGNAL(triggered()),
            this, SLOT(analyzeProduct()));
    connect(aHdl->acAnalyzeJupyter, SIGNAL(triggered()),
            this, SLOT(analyzeProduct()));
    connect(aHdl->acExport, SIGNAL(triggered()),
            this, SLOT(exportProduct()));

    /*
    connect(aHdl->acExportRemote, SIGNAL(triggered()),
            this, SLOT(exportProduct()));
    connect(aHdl->acExportVOSpace, SIGNAL(triggered()),
            this, SLOT(exportProduct()));
    connect(aHdl->acExportVOSpaceOther, SIGNAL(triggered()),
            this, SLOT(exportProduct()));
    */

    connect(ui->vw, SIGNAL(customContextMenuRequested(const QPoint &)),
            aHdl, SLOT(showLocalArchiveContextMenu(const QPoint &)));

    connect(ui->vw, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(openLocalArchiveElement(QModelIndex)));
}

//----------------------------------------------------------------------
// Method: openLocation
// openLocation
//----------------------------------------------------------------------
void LocalArchiveView::openLocation()
{
    QModelIndex m = ui->vw->currentIndex();
    QString url = model->index(m.row(), NumOfURLCol, m.parent()).data().toString();
    QFileInfo fs(url.mid(7));
    url = fs.absolutePath();
    QDesktopServices::openUrl(QUrl::fromLocalFile(url));
}

//----------------------------------------------------------------------
// Method: openWithDefault
// openWithDefault
//----------------------------------------------------------------------
void LocalArchiveView::openWithDefault()
{
    QModelIndex m = ui->vw->currentIndex();
    QString url = model->index(m.row(), NumOfURLCol, m.parent()).data().toString();
    QDesktopServices::openUrl(QUrl::fromLocalFile(url));
}

//----------------------------------------------------------------------
// SLOT: openWith
//----------------------------------------------------------------------
void LocalArchiveView::openWith()
{
    QAction * ac = qobject_cast<QAction*>(sender());
    QString key = ac->text();

    MapOfUserDefTools userDefTools;
    mw->getUserTools(userDefTools);

    std::cerr << userDefTools.size() << " - " << key.toStdString() << std::endl;
    const QUserDefTool & udt = userDefTools.value(key);

    QModelIndex m = ui->vw->currentIndex();
    QString url = model->index(m.row(), NumOfURLCol, m.parent()).data().toString();

    // Build arguments by replacing placeholders
    //   -   %f        Product file name (without path)
    //   -   %F        Product complete file name (with path)
    //   -   %p        Path where the product file is located
    //   -   %x        Product file extension
    //   -   %1 - %9   User-requested inputs
    QUrl archUrl(url);
    QString fileName = archUrl.path();
    QString args = udt.args;
    QFileInfo fs(fileName);

    args.replace("%f", fs.fileName());
    args.replace("%F", fileName);
    args.replace("%p", fs.absolutePath());
    args.replace("%x", fs.suffix());

    std::cerr << fileName.toStdString() << ", "
              << udt.exe.toStdString() << ", "
              << args.toStdString() << ", "
              << std::endl;

    // Count how many %n placeholders are
    int nph = 0;
    for (int i = 1; i < 10; ++i) {
        QString ph("%" + QString("%1").arg(i));
        if (args.contains(ph)) ++nph;
    }

    if (nph > 0) {

        // Build dialog
        QDialog dlg;
        QVBoxLayout vly;
        vly.addWidget(new QLabel("Current command line is:"));
        vly.addWidget(new QLabel(QString("\t%1 %2").arg(udt.exe).arg(args)));
        vly.addWidget(new QLabel("\nSpecify the strings to be used in "
                                 "the additional placeholders:"));

        QVector<QLineEdit*> edPh;
        for (int i = 1; i <= nph; ++i) {
            QLabel * l = new QLabel("%" + QString("%1: ").arg(i));
            QLineEdit * e = new QLineEdit;
            QHBoxLayout * hly = new QHBoxLayout;
            hly->addWidget(l);
            hly->addWidget(e);
            vly.addLayout(hly);
            edPh.append(e);
        }
        QPushButton * btnOk = new QPushButton("&Ok");
        QPushButton * btnCancel = new QPushButton("&Cancel");
        QHBoxLayout * hly = new QHBoxLayout;
        hly->addSpacerItem(new QSpacerItem(1, 1));
        hly->addWidget(btnOk);
        hly->addWidget(btnCancel);
        vly.addLayout(hly);
        dlg.setLayout(&vly);
        connect(btnOk, SIGNAL(pressed()), &dlg, SLOT(accept()));
        connect(btnCancel, SIGNAL(pressed()), &dlg, SLOT(reject()));

        // Show dialog, and substitute the placeholders %n in args with the
        // content of the line edit widgets
        if (dlg.exec()) {
            for (int i = 1; i <= nph; ++i) {
                QString ph("%" + QString("%1").arg(i));
                QLineEdit * e = edPh.at(i - 1);
                args.replace(ph, e->text());
            }
        }

    }

    //  Build command line and run the tool
    QString cmd(QString("%1 %2").arg(udt.exe).arg(args));

    std::cerr << cmd.toStdString() << std::endl;

    QProcess tool;
    tool.startDetached(cmd);
}

//----------------------------------------------------------------------
// Method: reprocessProduct
// reprocessProduct
//----------------------------------------------------------------------
void LocalArchiveView::reprocessProduct()
{
    QPoint p = aHdl->acReprocess->property("clickedItem").toPoint();
    //QModelIndex m = ui->vw->indexAt(p);

    QStringList inProds;
    QModelIndexList list = ui->vw->selectionModel()->selectedIndexes();
    foreach (QModelIndex m, list) {
        if (m.column() == NumOfURLCol) {
            QString url = model->index(m.row(), NumOfURLCol,
                                          m.parent()).data().toString();
            QUrl archUrl(url);
            QString fileName = archUrl.path();
            TRC("Request of reprocessing: " + fileName.toStdString());
            inProds << fileName;
        }
    }
    
    std::string userWAType = cfg.general("userAreaType").toString().toUpper().toStdString();
    OutputsLocation out = ((userWAType == UserAreaName[UA_NOMINAL]) ?
                           LocalArch : ((userWAType == UserAreaName[UA_LOCAL]) ?
                                        LocalDir : VOSpaceFolder));
    int flags = (cfg.flags("intermediateProducts").toBool() ?
                 GenIntermProd : NullFlags);

    DlgReproc dlg;
    dlg.setFields(inProds, out, flags);
    if (!dlg.exec()) { return; }

    QString outLocation;
    dlg.getFields(inProds, out, outLocation, flags);

    TRC(userWAType + ' ' + std::to_string((int)(out)) + " : " +
        std::to_string(flags) + " - " + outLocation.toStdString());
/*
    ProductList reprocProducts;
    FileNameSpec fns;
    foreach (QString fileName, inProds) {
        ProductMetadata md;
        fns.parseFileName(fileName.toStdString(), md);
        md["urlSpace"]       = ReprocessingSpace;
        md["procTargetType"] = ((out == LocalDir) ?
                                UA_LOCAL : ((out == VOSpaceFolder) ?
                                               UA_VOSPACE : UA_NOMINAL));
        md["procTarget"]     = outLocation.toStdString();
        reprocProducts.append(md);
    }

    hmiNode->sendReprocCmd(reprocProducts, flags + (int)(out));

    if (flags & OpenVOSpace) { QDesktopServices::openUrl(QUrl(VOSpaceURL)); }
*/
}

//----------------------------------------------------------------------
// Method: analyzeProduct
// analyzeProduct
//----------------------------------------------------------------------
void LocalArchiveView::analyzeProduct()
{
    // Create product list
    /*
    QAction * caller = qobject_cast<QAction*>(sender());

    QPoint p = caller->property("clickedItem").toPoint();

    QModelIndexList list = ui->vw->selectionModel()->selectedIndexes();
    ProductList analyzeProducts;
    FileNameSpec fns;
    ProductMetadata md;

    foreach (QModelIndex m, list) {
        if (m.column() == NumOfURLCol) {
            QString url = model->index(m.row(), NumOfURLCol, m.parent()).data().toString();
            fns.parseFileName(QUrl(url).path().toStdString(), md);
            md["urlSpace"]       = LocalArchSpace;
            md["procTargetType"] = UA_LOCAL;
            md["procTarget"]     = cfg.connectivity.ipython.path();
            analyzeProducts.products.push_back(md);
        }
    }

    QString acName = caller->objectName();
    if (acName == "AnalyzeWithIPython") {

        // Link products to IPython working directory
        URLHandler urlh;
        for (auto & m : analyzeProducts.products) {
            urlh.setProduct(m);
            m = urlh.fromLocalArch2ExportLocation();
        }

        // Launch IPython session
        IPythonLauncher * ipy = new IPythonLauncher(cfg.connectivity.ipython.cmd(),
                                                    cfg.connectivity.ipython.path());
        ipy->exec();

    } else if (acName == "AnalyzeWithJupyter") {

        //TO DO: Send products to Jupyter remote host and open browser

    } else {

        //ERROR

    }
    */
}

//----------------------------------------------------------------------
// Method: exportProduct
// exportProduct
//----------------------------------------------------------------------
void LocalArchiveView::exportProduct()
{
    /*
    QPoint p = aHdl->acReprocess->property("clickedItem").toPoint();
    //QModelIndex m = ui->vw->indexAt(p);

    QStringList inProds;
    QModelIndexList list = ui->vw->selectionModel()->selectedIndexes();
    foreach (QModelIndex m, list) {
        if (m.column() == NumOfURLCol) {
            QString url = model->index(m.row(), NumOfURLCol,
                                          m.parent()).data().toString();
            QUrl archUrl(url);
            QString fileName = archUrl.path();
            TRC("Request of reprocessing: " + fileName.toStdString());
            inProds << fileName;
        }
    }

    std::string userWAType = cfg.general("userAreaType").toString().toUpper().toStdString();
    OutputsLocation out = ((userWAType == UserAreaName[UA_NOMINAL]) ?
                           LocalArch : ((userWAType == UserAreaName[UA_LOCAL]) ?
                                        LocalDir : VOSpaceFolder));
    int flags = (cfg.flags("intermediateProducts").toBool() ?
                 GenIntermProd : NullFlags);

    DlgReproc dlg;
    dlg.setLabels("Export products", "The following products will be exported",
                  "Export products to:", false);
    dlg.setFields(inProds, out, flags);
    if (!dlg.exec()) { return; }

    QString outLocation;
    dlg.getFields(inProds, out, outLocation, flags);

    TRC(userWAType + " " + std::to_string((int)(out)) + " : " +
        std::to_string(flags) + " - " + outLocation.toStdString());

    ProductList exportProducts;
    FileNameSpec fns;
    ProductMetadata md;
    foreach (QString fileName, inProds) {
        fns.parseFileName(fileName.toStdString(), md);
        md["urlSpace"]       = LocalArchSpace;
        md["procTargetType"] = ((out == LocalArch) ? UA_NOMINAL :
                                ((out == VOSpaceFolder) ? UA_VOSPACE : UA_LOCAL));
        md["procTarget"]     = outLocation.toStdString();
        exportProducts.products.push_back(md);
    }

    TRC(md.urlSpace() + " " + std::to_string(md.procTargetType()) +
        " " + md.procTarget());

    if ((md["procTargetType"] == UA_VOSPACE) &&
        (cfg.connectivity.vospace.user().empty() ||
         cfg.connectivity.vospace.pwd().empty())) {
        DlgUserPwd up;
        if (up.exec()) { up.storeValues(); }
    }

    statusBar()->showMessage(tr("Trying to export products . . ."), MessageDelay);

    // Copy products to export location
    URLHandler urlh;
    std::string expLoc;
    for (auto & m : exportProducts.products) {
        urlh.setProduct(m);
        statusBar()->showMessage(tr("Exporting %1 . . .")
                                .arg(QString::fromStdString(m.baseName())),
                                MessageDelay);
        m = urlh.fromLocalArch2ExportLocation();
        expLoc = m.urlSpace();
    }

    if ((md["procTargetType"] == UA_VOSPACE) && (expLoc == ReprocessingVOSpace)) {
        statusBar()->showMessage(tr("Products stored in VOSpace successfully"), MessageDelay);
    }
    */
}

//----------------------------------------------------------------------
// Method: openLocalArchiveElement
// openLocalArchiveElement
//----------------------------------------------------------------------
void LocalArchiveView::openLocalArchiveElement(QModelIndex idx)
{
    int row = idx.row();
    TRC(QString("(%1,%2)").arg(row).arg(idx.column()).toStdString());
    const QAbstractItemModel * model = idx.model();
    QModelIndex urlIdx  = model->index(row, NumOfURLCol, idx.parent());

    QString url = urlIdx.data().toString().trimmed();
    if (url.left(7) == "file://") {
        url.remove(0, 7);
    } else if (url.left(7) == "http://") {
        // TODO Download file to temporary folder, and set url to temporary file
    } else if (url.left(8) == "https://") {
        // TODO Download file to temporary folder, and set url to temporary file
    }
    openLocalArchiveFullPath(url);
}

//----------------------------------------------------------------------
// SLOT: openLocalArchiveFullPath
//----------------------------------------------------------------------
void LocalArchiveView::openLocalArchiveFullPath(QString fullPath)
{
    emit openProductInViewer(fullPath);
}
