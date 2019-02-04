/******************************************************************************
 * File:    launcher.cpp
 *          This file is part of QLA Processing Framework
 *
 * Domain:  QPF.Launcher
 *
 * Version:  1.0
 *
 * Date:    2017/12/01
 *
 * Author:   J C Gonzalez
 *
 * Copyright (C) 2015-2018 Euclid SOC Team @ ESAC
 *_____________________________________________________________________________
 *
 * Topic: General Information
 *
 * Purpose:
 *   Provides object implementation for class Launcher
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
 *   See <Changelog>
 *
 * About: License Conditions
 *   See <License>
 *
 ******************************************************************************/

#include "launcher.h"

#include <QProcess>
#include <iostream>

//----------------------------------------------------------------------
// Method: create
// Defines a new app launcher
//----------------------------------------------------------------------
void Launcher::create(QString prg, QStringList arg)
{
    app = prg;
    args = arg;
    isDefined = true;
}

//------------------------------------------------------------
// Method: exec
// Executes the defined launcher
//------------------------------------------------------------
bool Launcher::exec()
{
    if (! isDefined) { return false; }
    QProcess * proc = new QProcess;
    proc->startDetached(app, args);
}

//------------------------------------------------------------
// Constructor
// Generate a temporary file with unique file name in /tmp
//------------------------------------------------------------
IPythonLauncher::IPythonLauncher(QString ipyApp, QString ipyPath)
{
    QStringList vargs {ipyApp, "-i", "-c", "'%cd " + ipyPath + "'"};
    char * termApp = getenv("COLORTERM");
    if (termApp == nullptr) { termApp = getenv("TERM"); }
    if (strncmp(termApp, "xterm", 5) == 0) {
        vargs.insert(vargs.begin(), "-e");
    } else {
        vargs.insert(vargs.begin(), "--");
    }
    if (termApp != nullptr) {
        try {
            std::cerr << "Launching " << ipyApp.toStdString() << " with " << termApp << " . . .\n";
            create(termApp, vargs);
        } catch(...) {
            std::cerr << "Terminal application " << termApp << " not found.\n"
                      << "Please, set COLORTERM or TERM env. variables to an existing "
                      << "terminal application.\n";
        }
    }
}

//------------------------------------------------------------
// Constructor
// Generate a temporary file with unique file name in /tmp
//------------------------------------------------------------
JupyterLauncher::JupyterLauncher(QString jpyApp, QString jptAddr)
{
}
