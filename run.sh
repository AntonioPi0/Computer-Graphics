#!/bin/bash

# check for the file number in input
if [ $# -ne 1 ]; then
    exit 1
fi

EJ=$1

# definition of the 3 possible version of the file
FILE_BASE="./tp"
case $EJ in
    1)
        FILE="$FILE_BASE/tp1.comp"
        ;;
    2)
        FILE="$FILE_BASE/tp2.comp"
        ;;
    3)
        FILE="$FILE_BASE/tp3.comp"
        ;;
    *)
        exit 1
        ;;
esac

# copy the file in the one used for the execution
cp $FILE ./BVH_TP-master/viewer/shaders/gpgpu_fullrt.comp

# compile and execute
qmake -qt5
make
./BVH_TP-master/viewer/myViewer

