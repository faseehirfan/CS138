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
    echo "INFO:  this script is running on a machine named: " `uname -n`
    exit 1
fi

./package.sh 1

echo
echo Submitting to Marmoset!
echo
cd ../a2p1/
/u/cs_build/bin/marmoset_submit cs138 a2p1t a2p1t.tar.gz
/u/cs_build/bin/marmoset_submit cs138 a2p1c a2p1.cc
cd ../a2p2/
/u/cs_build/bin/marmoset_submit cs138 a2p2t a2p2Test.cc
/u/cs_build/bin/marmoset_submit cs138 a2p2c a2p2.cc
