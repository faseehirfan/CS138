#!/bin/bash

# check that we are in the scripts directory
if [ ! -f helper/colors.sh ] 
then
    echo "please cd to the scripts directory"
    echo "this script is intended to be run from the scripts directory"
    exit 1
fi
# in the scripts directory: proceed

source helper/variables.sh $1

#QUESTION_DIR=$1
OUTPUT_MAKE=$2

cd $QUESTION_DIR

# Making a bulid directory
mkdir -p $OUTPUT_MAKE
rm -rf $OUTPUT_MAKE/*
cp *.cc *.h ${INPUT_FILES}/*.txt $OUTPUT_MAKE > /dev/null 2>&1
cd $OUTPUT_MAKE
