#!/bin/bash
# This script submits all the acceptable tar files of your project into Marmoset.

# check that we are in the scripts directory
if [ ! -f helper/colors.sh ] 
then
    echo "please cd to the scripts directory"
    echo "this script is intended to be run from the scripts directory"
    exit 1
fi
# in the scripts directory: proceed

# are we on the CS student server?
if [ ! -f /u/cs_build/bin/marmoset_submit ] ; then
    echo "ERROR: could not find marmoset_submit" 
    echo "QUERY: what machine is this script running on?"
    echo "INFO:  this script is running on a ma achine named: " `uname -n`
    exit 1
fi

source helper/variables.sh 1

echo
echo Submitting to Marmoset!
echo
cd ../${ASSIGNMENT}p1/
/u/cs_build/bin/marmoset_submit cs138 ${ASSIGNMENT}p1t ${ASSIGNMENT}p1Test.cc
/u/cs_build/bin/marmoset_submit cs138 ${ASSIGNMENT}p1c ${ASSIGNMENT}p1.cc
cd ../${ASSIGNMENT}p2/
/u/cs_build/bin/marmoset_submit cs138 ${ASSIGNMENT}p2t ${ASSIGNMENT}p2Test.cc
/u/cs_build/bin/marmoset_submit cs138 ${ASSIGNMENT}p2c ${ASSIGNMENT}p2.cc
