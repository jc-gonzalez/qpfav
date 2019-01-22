#!/bin/bash

CURDIR=$(pwd)
CURDIR_VM=/home/eucops/Work/Euclid/QPF/qpfav

MARK=${CURDIR}/.build.mark

echo 'COMPILE' > ${MARK}

while [ -f ${MARK} ]; do sleep 1 ; done

sed -e "s/${CURDIR_VM}/${CURDIR}/g" ${CURDIR}/make.log

date
