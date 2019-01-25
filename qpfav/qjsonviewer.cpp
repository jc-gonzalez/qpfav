/******************************************************************************
 * File:    qjsonviewer.cpp
 *          Implementation of class QJSONViewer
 *
 * Domain:  QPF.qpfgui.qjsonviewer
 *
 * Version:  2.0
 *
 * Date:    2016-11-03
 *
 * Author:   J C Gonzalez
 *
 * Copyright (C) 2015-2018 Euclid SOC Team @ ESAC
 *_____________________________________________________________________________
 *
 * Topic: General Information
 *
 * Purpose:
 *   Implementation of class QJSONViewer
 *
 * Created by:
 *   J C Gonzalez
 *
 * Status:
 *   Prototype
 *
 * Dependencies:
 *   none
 *
 * Files read / modified:
 *   none
 *
 * History:
 *   See <ChangeLog>
 *
 * About: License Conditions
 *   See <License>
 *
 ******************************************************************************/

#include "qjsonviewer.h"
#include "ui_qjsonviewer.h"

#include <QAction>
#include <QMenu>

QJSONViewer::QJSONViewer(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QJSONViewer)
{
    ui->setupUi(this);
}

void QJSONViewer::init(QString & title, QByteArray & jsonData)
{
    ui->grpboxViewer->setTitle(title);

    model = new QJsonModel;
    model->loadJson(jsonData);
    model->setIcon(QJsonValue::Bool, QIcon(":/img/bullet_black.png"));
    model->setIcon(QJsonValue::Double, QIcon(":/img/bullet_red.png"));
    model->setIcon(QJsonValue::String, QIcon(":/img/bullet_blue.png"));
    model->setIcon(QJsonValue::Array, QIcon(":/img/table.png"));
    model->setIcon(QJsonValue::Object, QIcon(":/img/brick.png"));

    ui->vw->setModel(model);
    ui->vw->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->vw->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->vw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->vw, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showJsonContextMenu(const QPoint &)));
}

QJSONViewer::~QJSONViewer()
{
    delete model;
    delete ui;
}

//----------------------------------------------------------------------
// SLOT: showJsonContextMenu
//----------------------------------------------------------------------
void QJSONViewer::showJsonContextMenu(const QPoint & p)
{
    QAbstractItemView * w = qobject_cast<QAbstractItemView *>(sender());

    //QModelIndex m = ui->vw->indexAt(p);
    //if (m.parent() == QModelIndex()) { return; }

    if (ui->vw->indexAt(p).isValid()) {
        QAction * acExp   = new QAction(tr("Expand"), w);
        QAction * acExpS  = new QAction(tr("Expand subtree"), w);
        QAction * acExpA  = new QAction(tr("Expand all"), w);

        QAction * acColl  = new QAction(tr("Collapse"), w);
        QAction * acCollS = new QAction(tr("Collapse subtree"), w);
        QAction * acCollA = new QAction(tr("Collapse all"), w);

        connect(acExp,   SIGNAL(triggered()), this, SLOT(jsontreeExpand()));
        connect(acExpS,  SIGNAL(triggered()), this, SLOT(jsontreeExpandSubtree()));
        connect(acExpA,  SIGNAL(triggered()), this, SLOT(jsontreeExpandAll()));

        connect(acColl,  SIGNAL(triggered()), this, SLOT(jsontreeCollapse()));
        connect(acCollS, SIGNAL(triggered()), this, SLOT(jsontreeCollapseSubtree()));
        connect(acCollA, SIGNAL(triggered()), this, SLOT(jsontreeCollapseAll()));

        QMenu menu(w);
        menu.addAction(acExp);
        menu.addAction(acExpS);
        menu.addAction(acExpA);
        menu.addSeparator();
        menu.addAction(acColl);
        menu.addAction(acCollS);
        menu.addAction(acCollA);
        pointOfAction = p;

        //mw->isViewsUpdateActive = false;
        menu.exec(w->mapToGlobal(p));
        //mw->isViewsUpdateActive = true;
    }
}

//----------------------------------------------------------------------
// SLOT: jsontreeExpand
//----------------------------------------------------------------------
void QJSONViewer::jsontreeExpand()
{
    QModelIndex idx = ui->vw->indexAt(pointOfAction);
    ui->vw->expand(idx);
}

//----------------------------------------------------------------------
// SLOT: jsontreeExpandSubtree
//----------------------------------------------------------------------
void QJSONViewer::jsontreeExpandSubtree()
{
    QModelIndex idx = ui->vw->indexAt(pointOfAction);
    QModelIndexList indices;
    getAllChildren(idx, indices);
    foreach (QModelIndex i, indices) {
        ui->vw->expand(i);
    }
}

//----------------------------------------------------------------------
// SLOT: jsontreeExpandAll
//----------------------------------------------------------------------
void QJSONViewer::jsontreeExpandAll()
{
    ui->vw->expandAll();

}

//----------------------------------------------------------------------
// SLOT: jsontreeCollapse
//----------------------------------------------------------------------
void QJSONViewer::jsontreeCollapse()
{
    QModelIndex idx = ui->vw->indexAt(pointOfAction);
    ui->vw->collapse(idx);
}

//----------------------------------------------------------------------
// SLOT: jsontreeCollapseSubtree
//----------------------------------------------------------------------
void QJSONViewer::jsontreeCollapseSubtree()
{
    QModelIndex idx = ui->vw->indexAt(pointOfAction);
    QModelIndexList indices;
    getAllChildren(idx, indices);
    foreach (QModelIndex i, indices) {
        ui->vw->collapse(i);
    }
}

//----------------------------------------------------------------------
// SLOT: jsontreeCollapseAll
//----------------------------------------------------------------------
void QJSONViewer::jsontreeCollapseAll()
{
    ui->vw->collapseAll();
}

//----------------------------------------------------------------------
// SLOT: getAllChildren
//----------------------------------------------------------------------
void QJSONViewer::getAllChildren(QModelIndex index, QModelIndexList &indices)
{
    indices.push_back(index);
    for (int i = 0; i != index.model()->rowCount(index); ++i)
        getAllChildren(index.child(i,0), indices);
}
