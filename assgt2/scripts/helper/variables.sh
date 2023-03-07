#!/bin/bash

# question-related
QUESTION=$1
QUESTION_DIR="../a2p${QUESTION}"

if [ ! -d ${QUESTION_DIR} ] ; then
    echo -e "${RED}ERROR: question dir doesn't exist: ${QUESTION_DIR}${NC}"
    exit 1
fi


# build directory
OUTPUT=build
# these paths are relative to the build directory
# so some are back a level and some are not
TEST_INPUTS="../test-inputs"
INPUT_FILES="test-inputs"
#INPUT_FILES="input-files"
OUTPUTS_ACTUAL="outputs-actual"
OUTPUTS_EXPECTED="../outputs-expected"
EXECUTABLE_FILE="./a.out"

# types of compilation
GCOV=gcov
VALGRIND=valgrind
GTEST=gtest
