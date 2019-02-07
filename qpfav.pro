#----------------------------------------------------------------------
# QPFAV - QPF Archive Viewer
#----------------------------------------------------------------------
# Project file for the compilation of the QPFAV project
# using Qt's QMake.
# This includes the QsLog library, and the QPFAV executable
#
# Created by J C Gonzalez
# Copyright (C) 2018-2019 by the Euclid SOC Team at ESAC
#----------------------------------------------------------------------

UNAME = $$system(uname -a)
contains( UNAME, [lL]inux ):message(Compiling project for Linux ($$UNAME))

TEMPLATE = subdirs
#CONFIG += ordered

SUBDIRS = qslog/qslog.pro \
          qpfav/qpfav.pro

DESTDIR = $$PWD/build

