#!/bin/bash

CC_FILE=$1
CC_VERSION="c++26"
COMPILER="g++"
FLAGS="-O3"

${COMPILER} -std=${CC_VERSION} ${FLAGS} ${CC_FILE}
./a.out
rm a.out
