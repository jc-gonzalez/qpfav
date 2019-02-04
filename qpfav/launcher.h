/******************************************************************************
 * File:    launcher.h
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
 *   Launches a predefined application
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
#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QString>
#include <QVector>

//======================================================================
// Class: Launcher
//======================================================================
class Launcher {

public:
    
    //------------------------------------------------------------
    // Constructor
    // Generate a temporary file with unique file name in /tmp
    //------------------------------------------------------------
    Launcher() : isDefined(false) {}

    //----------------------------------------------------------------------
    // Method: create
    // Defines a new app launcher
    //----------------------------------------------------------------------
    virtual void create(QString prg, QStringList arg);
    
    //------------------------------------------------------------
    // Method: exec
    // Executes the defined launcher
    //------------------------------------------------------------
    virtual bool exec();
    
    
protected:
    bool isDefined;
    QString app;
    QStringList args;

};

//======================================================================
// Class: IPythonLauncher
//======================================================================
class IPythonLauncher : public Launcher {

public:
    
    //------------------------------------------------------------
    // Constructor
    // Generate a temporary file with unique file name in /tmp
    //------------------------------------------------------------
    IPythonLauncher(QString ipyApp, QString ipyPath);

};

//======================================================================
// Class: JupyterLauncher
//======================================================================
class JupyterLauncher : public Launcher {

public:
    
    //------------------------------------------------------------
    // Constructor
    // Generate a temporary file with unique file name in /tmp
    //------------------------------------------------------------
    JupyterLauncher(QString jpyApp, QString jptAddr);

};

#endif // LAUNCHER_H
