/******************************************************************************
 * File:    dlgjsonviewer.h
 *          Declaration of class DlgJSONViewer
 *
 * Domain:  QPF.qpfgui.dlgjsonviewer
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
 *   Declaration of class DlgJSONViewer
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

#ifndef DLGJSONVIEWER_H
#define DLGJSONVIEWER_H

#include <QDialog>

namespace Ui {
class DlgJSONViewer;
}

class DlgJSONViewer : public QDialog
{
    Q_OBJECT

public:
    explicit DlgJSONViewer(QString title, QByteArray jsonData, QWidget *parent);
    ~DlgJSONViewer();

private:
    Ui::DlgJSONViewer *ui;
};

#endif // DLGJSONVIEWER_H
