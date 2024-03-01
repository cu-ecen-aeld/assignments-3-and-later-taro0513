#!/bin/bash

if [ $# -ne 2 ]
then
    exit 1
else
    WRITEFILE=$1
    WRITESTR=$2
fi

mkdir -p $(dirname $WRITEFILE)

echo $WRITESTR > $WRITEFILE

if [ $? -eq 0 ]
then
    exit 0
else
    exit 1
fi