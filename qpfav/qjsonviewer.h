/******************************************************************************
 * File:    qjsonviewer.h
 *          Declaration of class QJSONViewer
 *
 * Domain:  QPF.qpfgui.qjsonviewer
 *
 * Last update:  2.0
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
 *   Declaration of class QJSONViewer
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

#ifndef QJSONVIEWER_H
#define QJSONVIEWER_H

#include <QDialog>
#include <QDateTime>

#include "qjsonmodel.h"

namespace Ui {
class QJSONViewer;
}

class QJSONViewer : public QWidget
{
    Q_OBJECT

public:
    explicit QJSONViewer(QWidget *parent = 0);
    ~QJSONViewer();

    void init(QString & title, QByteArray & jsonData);

private slots:
    void showJsonContextMenu(const QPoint & p);

    void jsontreeExpand();
    void jsontreeExpandSubtree();
    void jsontreeExpandAll();

    void jsontreeCollapse();
    void jsontreeCollapseSubtree();
    void jsontreeCollapseAll();

    void getAllChildren(QModelIndex index, QModelIndexList &indices);

private:
    Ui::QJSONViewer *ui;

    QJsonModel * model;
    QPoint pointOfAction;
};

#endif // QJSONVIEWER_H
