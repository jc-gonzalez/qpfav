#----------------------------------------------------------------------
# QPFAV - QPF Archive Viewer
#----------------------------------------------------------------------
# Project file for the compilation of the QPFAV executable
# using Qt's QMake
#
# Created by J C Gonzalez
# Copyright (C) 2018-2019 by the Euclid SOC Team at ESAC
#----------------------------------------------------------------------

TARGET = qpfav
VERSION = "2.1"

TEMPLATE = app
QT       += core gui sql network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += ordered c++11

DESTDIR = $$PWD/../build/qpfav.dir
OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
UI_DIR = $$DESTDIR/ui
RCC_DIR = $$DESTDIR/rcc

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    darkpalette.cpp \
    procalertsview.cpp \
    sysalertsview.cpp \
    tasksview.cpp \
    localarchview.cpp \
    dbtblmodel.cpp \
    dbtreemodel.cpp \
    procalertmodel.cpp \
    productsmodel.cpp \
    sysalertmodel.cpp \
    tasksmodel.cpp \
    dbmng.cpp \
    config.cpp\
    alert.cpp \
    actionshandler.cpp \
    exttooledit.cpp \
    exttoolsdef.cpp \
    configtool.cpp \
    dbbrowser.cpp \
    verbleveldlg.cpp \
    browser.cpp \
    conthostedit.cpp \
    swarmedit.cpp \
    ruleedit.cpp \
    connectionwidget.cpp \
    dlgalert.cpp \
    util.cpp \
    qjsonviewer.cpp \
    dlgjsonviewer.cpp \
    qjsonitem.cpp \
    qjsonmodel.cpp \
    dlgreproc.cpp \
    productsviewer.cpp \
    xmlsyntaxhighlight.cpp \
    launcher.cpp \
    dlguserpwd.cpp \
    keyevt.cpp \
    voshdl.cpp \
    rwc.cpp \
    filetools.cpp \
    statelbl.cpp

HEADERS  += \
    mainwindow.h \
    darkpalette.h \
    procalertsview.h \
    sysalertsview.h \
    tasksview.h \
    localarchview.h \
    dbtblmodel.h \
    dbtreemodel.h \
    procalertmodel.h \
    productsmodel.h \
    sysalertmodel.h \
    tasksmodel.h \
    dbmng.h \
    propdef.h \
    auxtypes.h \
    config.h \
    version.h \
    alert.h \
    propdef.h \
    actionshandler.h \
    exttooledit.h \
    exttoolsdef.h \
    configtool.h \
    dbbrowser.h \
    verbleveldlg.h \
    hmitypes.h \
    browser.h \
    conthostedit.h \
    swarmedit.h \
    ruleedit.h \
    connectionwidget.h \
    dlgalert.h \
    util.h \
    qjsonviewer.h \
    dlgjsonviewer.h \
    qjsonitem.h \
    qjsonmodel.h \
    dlgreproc.h \
    productsviewer.h \
    xmlsyntaxhighlight.h \
    launcher.h \
    dlguserpwd.h \
    keyevt.h \
    rwc.h \
    voshdl.h \
    filetools.h \
    scopeexit.h \
    statelbl.h

MAINGUI  += \
    mainwindow.ui 

WIDGETS  += \
    procalertsview.ui \
    sysalertsview.ui \
    tasksview.ui \
    localarchview.ui \
    configtool.ui \
    browserwidget.ui \
    conthostedit.ui \
    swarmedit.ui \
    ruleedit.ui \
    qjsonviewer.ui \
    productsviewer.ui \
    statelbl.ui

DIALOGS  += \
    exttooledit.ui \
    exttoolsdef.ui \
    dbbrowser.ui \
    verbleveldlg.ui \
    dlgalert.ui \
    dlgjsonviewer.ui \
    dlgreproc.ui \
    dlguserpwd.ui 

FORMS = $$MAINGUI $$WIDGETS $$DIALOGS

RESOURCES += \
    icons_nav.qrc \
    states.qrc

DISTFILES +=

INCLUDEPATH += $$PWD/../qslog 
LIBS += -L$$PWD/../build/qslog.dir -lqslog -lcurl -L/lib64 -lX11
DEFINES += QSLOG_IS_SHARED_LIBRARY_IMPORT
