CS138 Assgt 0
=============

The purpose of Assgt 0 is to get you to try out the tools.
See the slides for more details.  Here are the basics of what to do:

0. Get started:
    - Use `ssh` or `putty` log into to the CS student server
        - Then do this on the server:
	    ```
            $ cd
            $ mkdir cs138-code
            $ cd cs138-code
            $ git clone URL-for-the-assgt0-skeleton-repo assgt0
            $ cd assgt0
	    ```

        - For Winter 2023, the URL for the Assgt 0 skeleton code is <a href="https://git.uwaterloo.ca/cs138-2023/skeleton/assgt0"> https://git.uwaterloo.ca/cs138-2023/skeleton/assgt0</a>
        - Note that you can pick names other than `cs138-code` and `assgt0` for your own directories
	- Use `VSCode` on your local machine (e.g., your laptop)
        - Install the SSH extension
        - Connect it to the CS student server
        - Now you can edit files on the CS student server from VSCode

1. `./run_test.sh` (inside your ssh/putty window on the CS student server)
    - Observe that some tests pass and some tests fail
    - Observe that the failing tests are in `factorial_recursive(int)`
    - Fix `factorial_recursive(int)` in `Factorial.cc` (using VSCode)
    - `./run_test.sh` again to observe that all tests now pass
    - `git commit -m 'fixed off-by-one error in factorial_recursive'
      Factorial.cc`

2. `./run_valgrind.sh` (inside your ssh/putty window on the CS student server)
    - Observe that there is a memory leak in `factorial_memory_leak(int)`
    - Fix the leak (follow the instructions in `Factorial.cc`)
    - `./run_valgrind.sh` to observe that there is no longer a leak
    - `git commit -m 'fixed memory leak factorial_memory_leak' Factorial.cc`

3. `./run_gcov.sh` (inside your ssh/putty window on the CS student server)
    - Observe that `factorial_untested(int)` has 0% coverage
    - Observe that other functions have 100% coverage
    - Create a new test for `factorial_untested(int)` in `FactorialTest.cc`
    - `./run_gcov.sh` to observe coverage
    - `git commit -m 'new tests for factorial_untested' FactorialTest.cc`
    - Think:
        - Coverage here means a line of code was executed
        - It doesn't mean that the program has been tested on all inputs
        - So 100% line coverage is just a starting point in software quality

4. Now finally submit of your code to Marmoset
    - This can be done using the `marmoset_submit` script located on the student linux environment under the path `/u/cs_build/bin/marmoset_submit`
    - To use this script run the command: `/u/cs_build/bin/marmoset_submit <course_name> <project_name> <file1> <file2> ...`
        - For this course `<course_name>` will always be `cs138`
        - For Assgt 0, `<project_name>` should be `a0` (in the future this may look like `a1q1` or `a2q4`, you can check <a href=https://marmoset.student.cs.uwaterloo.ca/> https://marmoset.student.cs.uwaterloo.ca/</a> if you're not sure what a project is called)
        - `<file1> <file2> ...` should be a space-separated list of the names of the files you are submitting, and they should be in the current directory when you run the command (i.e. they should show up if you run the `ls` command)
            - For Assgt 0 you should submit `Factorial.cc` and `FactorialTest.cc`, you don't need to submit `Factorial.h`
            - If you are ever unsure what files to submit check the project description at <a href=https://marmoset.student.cs.uwaterloo.ca/> https://marmoset.student.cs.uwaterloo.ca/</a>
    - TLDR; to sumbit Assgt 0, run `/u/cs_build/bin/marmoset_submit cs138 a0 Factorial.cc FactorialTest.cc` from your `~/.../cs138-code/assgt0` directory

Once you're done you can see your results at <a href=https://marmoset.student.cs.uwaterloo.ca/> https://marmoset.student.cs.uwaterloo.ca/</a>.
    
