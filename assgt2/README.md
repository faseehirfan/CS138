# CS138 W23 Assignment 2 README

This assignment has two different parts, as described in the PDF.

1. Part 1 is an extension of assignment 1 on text processing.
2. Part 2 is an introduction to linked lists.

Each part has two submissions to Marmoset:

- Tests
- Code

For a total of 4 Marmoset submissions:

1. Tests for Part 1 - a2p1t
2. Tests for Part 2 - a2p2t
3. Code for Part 1 - a2p1c
4. Code for Part 2 - a2p2c

To submit parts to Marmoset individually, use the
`/u/cs_build/bin/marmoset_submit` script. This will look like:

- `/u/cs_build/bin/marmoset_submit cs138 a2p1t a2p1t.tar.gz`
- `/u/cs_build/bin/marmoset_submit cs138 a2p2t a2p2Test.cc`
- `/u/cs_build/bin/marmoset_submit cs138 a2p1c a2p1.cc`
- `/u/cs_build/bin/marmoset_submit cs138 a2p2c a2p2.cc`

For a2p1t, remember to package all your test files together into
a2p1t.tar.gz first using `package.sh 1` before you submit.

Alternatively, there is a script that does all 4 submissions for you:

    `submit_all.sh`


## Test case coverage is measured on staff code

The test cases you create for this assignment will be assessed by
measuring their coverage _of the staff code_. This way you can write
your tests _before_ you write your code and get a measurement of how
good your tests are before your code exists. For full marks your tests
only need 90% coverage on the staff solution, but 100% coverage is
possible.

## 


## Test cases for Part 1 Text Processing

- Part 1 uses text files, like A1.
- Each test now has 4 files:
    - file in: test-inputs/test.txt     # new!
    - stdin:   test-inputs/test.in
    - stdout:  outputs-expected/test.out
    - stderr:  outputs-expected/test.err
- The input file can be shared by multiple tests.
- For example, pangram.txt is used by all of the provided tests.


## Test cases for Part 2 Linked List

- Part 2 uses GTest, like A0.
- Your GTest code goes in a2p2Test.cc
- There are already some provided tests in a2p2Test.cc
- Please write your tests at the bottom of the file.


## Code-related Scripts for Part 1 Text Processing

`run_tests.sh 1`

This script compiles your a2p1.cc, then tests it against input files in a2p1/test-inputs.

`run_tests.sh 1 gcov`

This script compiles your a2p1.cc, then tests it against input files in a2p1/test-inputs,
then reports gcov coverage.

`package.sh 1`

This script packages all of your testing files for part 1 into a single file named a1p1t.tar.gz.
This is the file Marmose expects you to submit.

## Code-related Scripts for Part 2 Linked List

`run_gtest.sh 2`

This script compiles your a2p2.cc, then tests it against the Google Test suites.

`run_gcov.sh 2`

This script compiles your a2p2.cc, then tests it against the Google Test suites, then reports
your gcov coverage.
