/******************************************************************************
 * File:    dbbrowser.cpp
 *          Implementation of class DBBrowser
 *
 * Domain:  QPF.qpfgui.dbbrowser
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
 *   Implementation of class DBBrowser
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

#include "dbbrowser.h"
#include "ui_dbbrowser.h"
#include "config.h"

using Configuration::cfg;

DBBrowser::DBBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBBrowser)
{
    ui->setupUi(this);

    if (QSqlDatabase::connectionNames().isEmpty()) {
        Browser::DBConnection connection = { "QPSQL",        // .driverName
                                             cfg.DBName,
                                             cfg.DBUser,
                                             cfg.DBPwd,
                                             cfg.DBHost,
                                             cfg.DBPort.toInt() };
        ui->browser->addConnection(connection);
    }
}

DBBrowser::~DBBrowser()
{
    delete ui;
}
