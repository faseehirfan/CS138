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
source helper/sanitize.sh


#QUESTION_DIR=$1
OUTPUT_MAKE=$2

cd $QUESTION_DIR

# https://stackoverflow.com/questions/3601515/how-to-check-if-a-variable-is-set-in-bash
if [ -z ${OUTPUT_MAKE+x} ] ; then
    echo -e "${RED}OUTPUT_MAKE variable not set in $0 ${NC}"
    exit 1
fi

# Making a bulid directory
mkdir -p $OUTPUT_MAKE
# cleanup old files
if [ ! -d $OUTPUT_MAKE ] ; then
    echo -e "${RED}OUTPUT_MAKE directory not created in $0 ${NC}"
    exit 1
fi
rm -rf $OUTPUT_MAKE/*
# copy in source files
cp -f *.cc *.h $OUTPUT_MAKE/ > /dev/null 2>&1
# copy input text files --- and sanitize them
if [ -d ${INPUT_FILES} ] ; then
    txtfiles=`find ${INPUT_FILES} -iname '*.txt'`
    for txt in $txtfiles
    do
        # sanitize txt --- results in tmp file
        s=`sanitize ${txt}`
        # copy tmp file to appropriate destination name
        cp ${s} $OUTPUT_MAKE/`basename ${txt}`
    done
fi
# change to the build directory
cd $OUTPUT_MAKE
