/******************************************************************************
 * File:    verbleveldlg.cpp
 *          Implementation of class VerbLevelDlg
 *
 * Domain:  QPF.qpfgui.verbleveldlg
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
 *   Implementation of class VerbLevelDlg
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

#include "verbleveldlg.h"
#include "ui_verbleveldlg.h"

namespace QPF {

VerbLevelDlg::VerbLevelDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VerbLevelDlg)
{
    ui->setupUi(this);

    verbLevels << "TRACE"
               << "DEBUG"
               << "INFO"
               << "WARNING"
               << "ERROR"
               << "FATAL";

    int uidx = 0; //(int)(Log::getMinLogLevel());
    ui->listWidget->addItems(verbLevels);
    ui->listWidget->setCurrentRow(uidx);

    connect(ui->listWidget, SIGNAL(currentRowChanged(int)),
            this, SLOT(setVerbosityLevel(int)));
}

//----------------------------------------------------------------------
// Method: setVerbosityLevel
// setVerbosityLevel
//----------------------------------------------------------------------
void VerbLevelDlg::setVerbosityLevel(QString lvl)
{
    static QMap<QString, int> VerbLevelIdx 
    {{"TRACE", 0}, {"DEBUG", 1}, {"INFO", 2}, {"WARNING", 3}, {"ERROR", 4}, {"FATAL", 5}};

    ui->listWidget->setCurrentRow(VerbLevelIdx[lvl]);
}

//----------------------------------------------------------------------
// Method: setVerbosityLevel
// setVerbosityLevel
//----------------------------------------------------------------------
void VerbLevelDlg::setVerbosityLevel(int lvl)
{
    currentLevel = ui->listWidget->currentItem()->text();
    currentLevelIdx = ui->listWidget->currentIndex().row();
}

//----------------------------------------------------------------------
// Method: getVerbosityLevelName
// getVerbosityLevelName
//----------------------------------------------------------------------
QString VerbLevelDlg::getVerbosityLevelName()
{
    return currentLevel;
}

//----------------------------------------------------------------------
// Method: getVerbosityLevelIdx
// getVerbosityLevelIdx
//----------------------------------------------------------------------
int VerbLevelDlg::getVerbosityLevelIdx()
{
    return currentLevelIdx;
}

VerbLevelDlg::~VerbLevelDlg()
{
    delete ui;
}

}
