#!/bin/bash

# This is a shell script, which uses the bash shell (a very common one)
# Shell scripts are lists of commands that you can run at the command line.

# Compile the code in this directory with g++
# g++ is the GNU compiler for C++ (part of the GCC collection).
# The -lgtest and -lgtest_main options say to link to GoogleTest.
# GTest requires Pthreads to compile, so we need to
#       link against the pthreads library using -pthread option.
# GoogleTest is installed on the CS student environment.
# To install on your own system: sudo apt install libgtest-dev
echo "running g++ ..."
g++ -pthread *.cc -lgtest -lgtest_main

# g++ will produce an executable file named a.out
# --leak-check=yes [default: summary]
#       When enabled, search for memory leaks 
#       when the client program finishes. 
#       If set to full or yes, each individual leak
#       will be shown in detail and/or counted as an error.
# --num-callers=<number> [default: 12]
#       Specifies the maximum number of
#       entries shown in stack traces 
#       that identify program locations
# --quiet
#       Run silently, and only print error messages.
# Let's run it and see what happens!
# We run it with valgrind to see if there are memory leaks.
echo "running valgrind ..."
valgrind --leak-check=yes --quiet --num-callers=2 ./a.out > /dev/null
