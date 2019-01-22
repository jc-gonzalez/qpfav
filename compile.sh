#!/bin/bash

CURDIR=/Users/jcgonzalez/mnt/lodqpf/Euclid/QPF/qpfav
CURDIR_VM=/home/eucops/Work/Euclid/QPF/qpfav

cd ${CURDIR}

MARK=${CURDIR}/.build.mark

echo 'COMPILE' > ${MARK}

while [ -f ${MARK} ]; do sleep 1 ; printf "." ; sync ; done

echo ''

sed -e "s#${CURDIR_VM}#${CURDIR}#g" ${CURDIR}/make.log

date
