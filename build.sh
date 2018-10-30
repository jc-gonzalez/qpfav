#!/bin/bash

qmake-qt5 ./qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
make

