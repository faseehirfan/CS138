#include "a3p2.h"
#include "gtest/gtest.h"

using namespace std;

/* ************************************************************** */
/* Chunky Stack Validity                                          */
/* ************************************************************** */

TEST(StackForm, ChunkSizeAboveZero) {
    Stack s;
    s.chunkSize = -1;
    EXPECT_DEATH(isValidStack(s), "");
}

TEST(StackForm, TopEltGreaterThanChunkSize) {
    Stack s;
    s.chunkSize = 1;
    s.topElt = 2;
    EXPECT_DEATH(isValidStack(s), "");
}

TEST(StackForm, EmptyStackWithBadTopElt) {
    Stack s;
    s.firstChunk = nullptr;
    s.topElt = 1; // this should be -1 for an empty stack
    EXPECT_TRUE(isEmpty(s)); 
    EXPECT_DEATH(isValidStack(s), "");
}

TEST(StackForm, StackCannotStoreSpecialUnusedSlotValue) {
    Stack s;
    initStack(1, s);
    s.firstChunk = createNewNodeChunk(1);
    s.topElt = 0;
    s.firstChunk->val[0] = "alpha";
    EXPECT_FALSE(isEmpty(s)); 
    EXPECT_TRUE(isValidStack(s));
    // wellformed so far, now mess it up
    s.firstChunk->val[0] = UNUSED_SLOT;
    EXPECT_DEATH(isValidStack(s), "");
    delete[] s.firstChunk->val;
    delete s.firstChunk;
}

TEST(StackForm, UnusedStackSlotsShouldNotHaveGhostValues) {
    Stack s;
    initStack(5, s);
    s.firstChunk = createNewNodeChunk(5);
    s.topElt = 2;
    s.firstChunk->val[s.topElt+1] = "ghost value should not be here";
    EXPECT_FALSE(isEmpty(s)); 
    EXPECT_DEATH(isValidStack(s), "");
    delete[] s.firstChunk->val;
    delete s.firstChunk;
}

TEST(StackForm, SubsequentChunkShouldNotHaveUnusedSlots) {
    Stack s;
    initStack(1, s);
    s.topElt = 0;
    s.firstChunk = createNewNodeChunk(1);
    s.firstChunk->val[0] = "beta";
    s.firstChunk->next = createNewNodeChunk(1);
    s.firstChunk->next->val[0] = "alpha";
    EXPECT_FALSE(isEmpty(s)); 
    EXPECT_TRUE(isValidStack(s));
    // wellformed so far
    // now we break it
    s.firstChunk->next->val[0] = UNUSED_SLOT;
    EXPECT_DEATH(isValidStack(s), "");
    delete[] s.firstChunk->next->val;
    delete s.firstChunk->next;
    delete[] s.firstChunk->val;
    delete s.firstChunk;
}


/* ************************************************************** */
/* End-to-end testing                                             */
/* ************************************************************** */

TEST(EndToEnd, GivenOneItemIsPushedTheSameItemExpectedAtTop) {
    Stack s;
    initStack (3,s);
    
    string expected = "alpha";
    push(expected, s);
    EXPECT_EQ(expected, top(s));

    nuke(s);
}

TEST(EndToEnd, GivenTwoPushedElementsTheSecondItemExpectedAtTop) {
    Stack s;
    initStack (3,s);
    push("alpha", s);

    string expected = "beta";
    push(expected, s);

    EXPECT_EQ(expected, top(s));

    nuke(s);
}

TEST(EndToEnd, GivenTwoPushedElementsCombinationOfTheseTwoIsExpectedFromToString) {
    Stack s;
    initStack (3,s);
    push("alpha", s);
    push("beta", s);

    string expected = "[beta, alpha]";
    EXPECT_EQ(expected, toString(s));

    nuke(s);
}

TEST(EndToEnd, GivenTwoPushedElementsWhenPopIsInvokedSecondOneExpectedToRemain) {
    Stack s;
    initStack (3,s);
    push("alpha", s);
    push("beta", s);
    pop(s);

    string expected = "alpha";
    EXPECT_EQ(expected, top(s));

    nuke(s);
}

TEST(EndToEnd, GivenTwoPushedElementsTheSizeOfTwoIsExpected) {
    Stack s;
    initStack (3,s);

    push("alpha", s);
    push("beta", s);

    EXPECT_EQ(2, size(s));

    nuke(s);
}

TEST(EndToEnd, GivenTwoPushedElementsWhenSwapIsInvokedSwappedItemsExpectedFromToString) {
    Stack s;
    initStack (3,s);

    push("alpha", s);
    push("beta", s);

    swap(s);

    string expected = "[alpha, beta]";
    EXPECT_EQ(expected, toString(s));

    nuke(s);
}

TEST(EndToEnd, PushingWithFirstNodeChunkBeingFull)
{
    Stack s;
    initStack(3, s);

    push("alpha", s);
    push("beta", s);
    push("car", s);


    string expected = "dad";
    push(expected, s);
    EXPECT_EQ(expected, top(s));

    nuke(s);
}

TEST(EndToEnd, InvokingSwapWithOnlyOneElementInStack)
{
    Stack s;
    initStack(2, s);

    push("alpha", s);

    EXPECT_DEATH(swap(s), "");

    nuke(s);
}

TEST(EndToEnd, PoppingLastElem)
{
    Stack s;
    initStack(1, s);

    push("alpha", s);

    pop(s);

    EXPECT_TRUE(isEmpty(s));
    EXPECT_TRUE(isValidStack(s));

    nuke(s);
}

TEST(SizePub, GivenSingleElementStackWhenSizeIsInvokedExpectedOne)
{
    Stack s;
    initStack(3, s);
    s.firstChunk = createNewNodeChunk(3);
    s.firstChunk->val[0] = "alpha";
    s.topElt = 0;

    EXPECT_EQ(1, size(s));

    delete[] s.firstChunk->val;
    delete s.firstChunk;
}

TEST(SizePub, GivenTwoNodeStackWhenSizeIsInvokedExpectCorrectSize)
{
    Stack s;
    initStack(2, s);
    s.firstChunk = createNewNodeChunk(2);
    s.firstChunk->val[0] = "alpha";
    s.firstChunk->next = createNewNodeChunk(2);
    s.firstChunk->next->val[0] = "beta";
    s.firstChunk->next->val[1] = "delta";
    s.topElt = 0;

    EXPECT_EQ(3, size(s));

    delete[] s.firstChunk->next->val;
    delete s.firstChunk->next;
    delete[] s.firstChunk->val;
    delete s.firstChunk;
}

TEST(SizePub, GivenEmptyStackWhenSizeIsInvokedZeroExpected)
{
    Stack s;
    initStack(10, s);
    EXPECT_EQ(size(s), 0);
}

TEST(ToStringPub, GivenEmptyStackWhenToStringIsInvokedAnEmptyStringIsExpected)
{
    Stack s;
    initStack(10, s);

    string expected = "[]";
    EXPECT_EQ(expected, toString(s));
}

TEST(ToStringPub, GivenSingleElementStackWhenToStringIsInvokedItemExpectedInTheString)
{
    Stack s;
    initStack(10, s);
    s.firstChunk = createNewNodeChunk(10);
    s.firstChunk->val[0] = "alpha";
    s.topElt = 0;

    string expected = "[alpha]";
    EXPECT_EQ(expected, toString(s));

    delete[] s.firstChunk->val;
    delete s.firstChunk;
}