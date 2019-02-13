#include "statelbl.h"
#include "ui_statelbl.h"

#include <QTimer>

#include <iostream>

#include "config.h"
#include "util.h"

using Configuration::cfg;

#include <iostream>

#define S(s)  (s).toStdString()
#define TRC(s) std::cerr << s << std::endl;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
StateLabel::StateLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateLabel)
{
    ui->setupUi(this);

    // Launch run thread
    //std::thread(&LocalArchiveView::run, this).detach();
    /*
    QTimer * refreshTimer = new QTimer(this);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(run()));
    refreshTimer->start(2000);
    */
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
StateLabel::~StateLabel()
{
    delete ui;
}

//----------------------------------------------------------------------
// SLOT: setState
//----------------------------------------------------------------------
void StateLabel::setState(QString s)
{
    QString pxmpName = QString::fromUtf8(":/state/img/%1.png").arg(s);
    ui->lblStateIcon->setPixmap(QPixmap(pxmpName));
}

//----------------------------------------------------------------------
// SLOT: run
//----------------------------------------------------------------------
void StateLabel::run()
{
}
