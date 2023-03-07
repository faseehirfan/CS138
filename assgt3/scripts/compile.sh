#!/bin/bash
# This script compiles the program

# check that we are in the scripts directory
if [ ! -f helper/colors.sh ] 
then
    echo "please cd to the scripts directory"
    echo "this script is intended to be run from the scripts directory"
    exit 1
fi
# in the scripts directory: proceed

source helper/colors.sh

if [ "$#" -lt 1 ]; then
    echo -e "${RED}Run the script as follows:"
    echo -e "\t./compile.sh <QUESTION_NUMBER>${NC}"
    echo -e "${RED}If you want to compile the program to be used by valgrind, gcov, or gtest run it as follows:"
    echo -e "\t./compile.sh <QUESTION_NUMBER> <gcov|valgrind|gtest>${NC}"
    exit 1
fi

source helper/variables.sh $1
compilation_type=$2

helper/make_build.sh $1 $OUTPUT
cd ${QUESTION_DIR}/$OUTPUT

if [ "$compilation_type" = "$GCOV" ]; then
    echo "Running g++: gcov compatible"
    g++ --coverage -pthread *.cc -lgtest -lgtest_main
else
    echo "Running g++"
    g++ -pthread *.cc -lgtest -lgtest_main
fi
