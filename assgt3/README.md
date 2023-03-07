# CS138 W23 Assignment 3 README

This assignment has two different parts, as described in the PDF.
Each part will have you implement various functions for interfacing
with a custom data structure.

1. Part 1 involves working with doubly linked lists.
2. Part 2 involves working with linked lists and dynamic arrays

Each part has two submissions to Marmoset:

- Tests
- Code

For a total of 4 Marmoset submissions:

1. Tests for Part 1 - a3p1t
2. Tests for Part 2 - a3p2t
3. Code for Part 1 - a3p1c
4. Code for Part 2 - a3p2c

To submit parts to Marmoset individually, use the
`/u/cs_build/bin/marmoset_submit` script. This will look like:

- `/u/cs_build/bin/marmoset_submit cs138 a3p1t a3p1Test.cc`
- `/u/cs_build/bin/marmoset_submit cs138 a3p2t a3p2Test.cc`
- `/u/cs_build/bin/marmoset_submit cs138 a3p1c a3p1.cc`
- `/u/cs_build/bin/marmoset_submit cs138 a3p2c a3p2.cc`

Alternatively, there is a script that does all 4 submissions for you:

    `submit_all.sh`


## Test case coverage is measured on staff code

Just like in assignnment 2, the test cases you create for this assignment
will be assessed by measuring their coverage _of the staff code_. For part
2, the provided tests achieve 89% coverage and a3p2t requires 95% to pass
the coverage test. Part 1 is a bit easier, the provided tests already get
100% coverage, so you don't have to worry about that, however there are
multiple memory leaks in a3p1Test.cc that you will have to fix in order to
get full marks on a3p1t.

## 

## Provided Scripts:
Replace <part_num> with 1 or 2 depending on which part of the assignment you
are working on.

`run_gtest.sh <part_num>`

This script compiles your a3pX.cc file, then tests it against the Google Test suites.

`run_gcov.sh <part_num>`

This script compiles your a3pX.cc, then tests it against the Google Test suites, then reports
your gcov coverage.

`run_valgrind.sh <part_num>`

This script compiles your a3pX.cc file, then tests it against the Google Test suites with
Valgrind. Note that Valgrind errors can be cause by issues in both a3pX.cc and a3pXTest.cc.
