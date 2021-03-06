/******************************************************************************
 * File:    dlgreproc.cpp
 *          Implementation of class DlgReproc
 *
 * Domain:  QPF.qpfgui.dlgreproc
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
 *   Implementation of class DlgReproc
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

#include "dlgreproc.h"
#include "ui_dlgreproc.h"

#include <QListWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

#include "config.h"
using Configuration::cfg;

#define QS(x) QString::fromStdString(x)

namespace QPF {

DlgReproc::DlgReproc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgReproc)
{
    ui->setupUi(this);

    ui->btngrpOutputsLocation->setId(ui->rbtnLocalArch, 0);   
    ui->btngrpOutputsLocation->setId(ui->rbtnLocalDir , 1);     
    ui->btngrpOutputsLocation->setId(ui->rbtnVOSpace  , 2);

    connect(ui->tbtnLocal, SIGNAL(clicked()), this, SLOT(selectLocalFolder()));
}

DlgReproc::~DlgReproc()
{
    delete ui;
}

//----------------------------------------------------------------------
// Method: setLabels
// setLabels
//----------------------------------------------------------------------
void DlgReproc::setLabels(QString aTitle, QString desc, QString aHeading,
                          bool showAddOpt)
{
    this->setWindowTitle(aTitle);
    ui->lblDesc->setText(desc);
    ui->grpboxOptions->setTitle(aHeading);
    ui->frmAdditionalOpts->setVisible(showAddOpt);
}
        
//----------------------------------------------------------------------
// Method: setFields
// setFields
//----------------------------------------------------------------------
void DlgReproc::setFields(QStringList inProds, OutputsLocation out,
                          int flags)
    
{
    ui->lstInputProducts->addItems(inProds);

    ui->edLocalArch->setText(cfg.general("workArea").toString() + "/data/archive");
    ui->edLocalDir->setText(cfg.general("userArea").toString().isEmpty() ?
                            cfg.general("workArea").toString() + "/data/user" :
                            cfg.general("userArea").toString());
    ui->edVOSpace->setText("VOSpace://" + cfg.connectivity("vospace").toObject()["folder"].toString());

    ui->btngrpOutputsLocation->button((out & LocalArch) ? 0 : 
                                    ((out & LocalDir) ? 1 :
                                     ((out & VOSpaceFolder) ? 2 : 0)))->setChecked(true);
    ui->chkGenIntermProd->setChecked(flags & GenIntermProd);
    ui->chkIPython->setChecked(flags & OpenIPython);
    ui->chkJupLab->setChecked(flags & OpenJupyterLab);
    ui->chkBrowserVOSpace->setChecked(flags & OpenVOSpace);
}
    
//----------------------------------------------------------------------
// Method: getFields
// getFields
//----------------------------------------------------------------------
void DlgReproc::getFields(QStringList & inProds, OutputsLocation & out,
                          QString & outDir, int & flags)
{
    static OutputsLocation outs[] = {LocalArch, LocalDir, VOSpaceFolder};
    out = outs[ui->btngrpOutputsLocation->checkedId()];
    switch (out) {
    case LocalArch:
        outDir = ui->edLocalArch->text();
        break;  
    case LocalDir:
        outDir = ui->edLocalDir->text();
        break;     
    case VOSpaceFolder:
        outDir = ui->edVOSpace->text().remove("VOSpace://");
        break;
    default:
        break;
    }

    flags = (int(ui->chkGenIntermProd->isChecked()  && ui->chkGenIntermProd->isChecked()  ?
                 GenIntermProd : NullFlags) |
             int(ui->chkIPython->isChecked()        && ui->chkIPython->isChecked()        ?
                 OpenIPython : NullFlags) |
             int(ui->chkJupLab->isChecked()         && ui->chkJupLab->isChecked()         ?
                 OpenJupyterLab : NullFlags) |
             int(ui->chkBrowserVOSpace->isChecked() && ui->chkBrowserVOSpace->isChecked() ?
                 OpenVOSpace : NullFlags));
}

//----------------------------------------------------------------------
// Method: selectLocalFolder
// selectLocalFolder
//----------------------------------------------------------------------
void DlgReproc::selectLocalFolder()
{
    QString pathName("/");
    pathName = QFileDialog::getExistingDirectory(this,
                                                 tr("Select local folder"),
                                                 pathName);
    QFileInfo fs(pathName);
    if (fs.exists()) {
        ui->edLocalDir->setText(pathName);
    }
}
    
//----------------------------------------------------------------------
// Method: selectLocalFolderToIPythonWorkDir
// selectLocalFolderToIPythonWorkDir
//----------------------------------------------------------------------
void DlgReproc::selectLocalFolderToIPythonWorkDir(bool togl)
{
    if (togl) {
        ui->edLocalDir->setText(cfg.connectivity("ipython").toObject()["path"].toString());
    } else {
        ui->edLocalDir->setText(cfg.general("userArea").toString().isEmpty() ?
                                cfg.general("workArea").toString() + "/data/user" :
                                cfg.general("userArea").toString());
    }
}

}
