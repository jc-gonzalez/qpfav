#!/bin/bash

MARK_FILE=$(pwd)/.build.mark
SLEEP_TIME=0.5s

while [ -d . ]; do

    while [ ! -f ${MARK_FILE} ]; do sleep ${SLEEP_TIME} ; done

    sleep 2
    clear
    qmake-qt5 ./qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug 2>&1 | tee make.log
    make 2>&1 | tee -a make.log
    echo ""
    echo "DONE"

    rm -f ${MARK_FILE}

    sync

done
