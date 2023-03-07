#!/bin/bash

# As gcov makes plenty of files,
#       creating a separate build directory
#       for these files is a good practice.

# Making a variable
OUTPUT=build
# Make the directory with -p option:
# no error if existing, make parent directories as needed
mkdir -p $OUTPUT
# Removing the existing files
rm -rf $OUTPUT/*
# In order to make an executable file, we need the source files.
cp *.cc *.h $OUTPUT
# Changing the directory to run the commands in it
cd $OUTPUT

# The only difference here with another script
#       for compiling is --coverage.
#       This option is used to compile and 
#       link code instrumented for coverage analysis.
echo "running g++ ..."
g++ --coverage -pthread *.h *.cc -lgtest -lgtest_main

# Running the program to make gcov related files
# let's redirect this output to /dev/null so we don't see it
echo "running a.out ..."
./a.out > /dev/null

# Running gcov with your program’s
#       source file names as arguments
#       will now produce a listing of 
#       the code along with frequency of
#       execution for each line.
echo "running gcov ..."
echo " "
gcov --demangled-names --function-summaries *Factorial.gcno
