/******************************************************************************
 * File:    dlgjsonviewer.cpp
 *          Implementation of class DlgJSONViewer
 *
 * Domain:  QPF.qpfgui.dlgjsonviewer
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
 *   Implementation of class DlgJSONViewer
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

#include "dlgjsonviewer.h"
#include "ui_dlgjsonviewer.h"

#include <QAction>
#include <QMenu>

DlgJSONViewer::DlgJSONViewer(QString title, QByteArray jsonData, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DlgJSONViewer)
{
    ui->setupUi(this);
    ui->wdg->init(title, jsonData);
}

DlgJSONViewer::~DlgJSONViewer()
{
    delete ui;
}
