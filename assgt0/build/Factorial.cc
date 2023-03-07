#include <cstdlib>

// This code is correct, so the tests will pass.
int factorial_iterative(int n)
{
    int result = 1;

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

// This code has a bug, so the tests will fail.
int factorial_recursive(int n)
{
    if (n == 0)
    {
        return 1; // TODO 1: fix bug by returning 1 instead of 0
    }
    return n * factorial_recursive(n - 1);
}

// This code is correct, but has a memory leak.
// So the tests will pass, but valgrind will complain.
int factorial_memory_leak(int n)
{
    // allocate an array on the heap so we can have a leak
    // we will only use the first element of this array
    // array size 7 chosen arbitrarily
    int *leaky = new int[7];
    leaky[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        leaky[0] = leaky[0] * i;
    }

    // return the result (leak: but don't release the array memory)
    // TODO 2: comment out this line and uncomment the alternate ending
    // return leaky[0];

    // TODO 2: uncomment this alternate ending that releases the array
    int result = leaky[0];
    delete[] leaky;
    return result;
}

// There are no unit tests for this function,
// so it will show up in the coverage report.
// TODO 3: write a test for this in FactorialTest.cc
int factorial_untested(int n)
{
    int result = 1;

    for (int i = n; i > 0; i--)
    {
        result *= i;
    }

    return result;
}
