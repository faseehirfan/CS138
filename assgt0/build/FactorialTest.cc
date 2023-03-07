#include "Factorial.h"
#include "gtest/gtest.h"

/* ************************************************************** */
/* Tests for factorial_iterative                                  */
/* ************************************************************** */
TEST(TestIterativeFactorial, OneIsGivenOneIsExpected)
{
    EXPECT_EQ(1, factorial_iterative(1));
}

TEST(TestIterativeFactorial, TwoIsGivenTwoIsExpected)
{
    EXPECT_EQ(2, factorial_iterative(2));
}

TEST(TestIterativeFactorial, FourIsGivenTwentyFourIsExpected)
{
    EXPECT_EQ(24, factorial_iterative(4));
}

TEST(TestIterativeFactorial, ZeroIsGivenOneIsExpected)
{
    EXPECT_EQ(1, factorial_iterative(0));
}

/* ************************************************************** */
/* Tests for factorial_recursive (which we know has a bug)        */
/* ************************************************************** */
TEST(TestRecursiveFactorial, OneIsGivenOneIsExpected)
{
    EXPECT_EQ(1, factorial_recursive(1));
}

TEST(TestRecursiveFactorial, TwoIsGivenTwoIsExpected)
{
    EXPECT_EQ(2, factorial_recursive(2));
}

TEST(TestRecursiveFactorial, FourIsGivenTwentyFourIsExpected)
{
    EXPECT_EQ(24, factorial_recursive(4));
}

TEST(TestRecursiveFactorial, ZeroIsGivenOneIsExpected)
{
    EXPECT_EQ(1, factorial_recursive(0));
}

/* ************************************************************** */
/* Tests for factorial_memory_leak (which we know has a leak)     */
/* ************************************************************** */
TEST(TestMemLeakFactorial, FourIsGivenTwentyFourIsExpected)
{
    EXPECT_EQ(24, factorial_memory_leak(4));
}

TEST(TestMemLeakFactorial, TwoIsGivenTwoIsExpected)
{
    EXPECT_EQ(2, factorial_memory_leak(2));
}

/* ************************************************************** */
/* TODO 3: Tests for factorial_untested                           */
/* ************************************************************** */

TEST(TestFactorialUntested, TwoIsGivenTwoIsExpected)
{
    EXPECT_EQ(2, factorial_untested(2));
}
