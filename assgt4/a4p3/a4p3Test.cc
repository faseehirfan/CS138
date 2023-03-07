#include "gtest/gtest.h"
#include "a4p3.h"

using namespace std;

/* ************************************************************** */
/* Tests for Assignment 4 Part 3                                  */
/* ************************************************************** */
// By default this file contains exact copies of all the Marmoset
// public tests in a4p3c.

// Currently these tests achieve 81% coverage on the staff solution.
// To pass a4p3t you will need to augment them to achieve at lest
// 90% coverage on our solution (though, as usual, 100% coverage is
// possible).

// Because these tests are for Marmoset, each test can only call the
// function it is specifically meant to run. This makes them large
// and messy. The tests you write don't need to do this. Don't waste
// your time building and destroying linked structures manually.
// When you make your own tests, use your SBL_arrive and SBL_nuke
// functions to create and destroy your testing SBLs.

TEST(initPub, givenUninitializedSBLExpectInitAssignsCorrectValues) {
    SBL sbl;
    SBL_init(sbl);
    EXPECT_EQ(sbl.q.first, nullptr);
    EXPECT_EQ(sbl.q.last, nullptr);
    EXPECT_EQ(sbl.root, nullptr);
    EXPECT_EQ(sbl.numElts, 0);
}
// SBL_init is a simple function. This one test should be sufficient.
// There are no secret tests for SBL_init, however...
// WARNING: Most of the other public tests use SBL_init so make sure
// you get this one right first before moving on.

TEST(sizePub, givenEmptySBLExpectSizeIsZero) {
    SBL sbl;
    SBL_init(sbl);
    EXPECT_EQ(SBL_size(sbl), 0);
}

TEST(sizePub, givenOneElementSBLExpectSizeIsOne) {
    SBL sbl;
    sbl.q.first = sbl.q.last = sbl.root = new SBLnode{"test", nullptr, nullptr, nullptr};
    sbl.numElts = 1;
    EXPECT_EQ(SBL_size(sbl), 1);
    delete sbl.root;
}

TEST(arrivePub, givenFourArrivalsExpectCorrectlyConstructedSBL) {
    SBL sbl;
    SBL_init(sbl);
    SBL_arrive(sbl, "first");
    SBL_arrive(sbl, "second");
    SBL_arrive(sbl, "third");
    SBL_arrive(sbl, "fourth");

    // Make sure the root SBL struct looks good
    EXPECT_EQ(sbl.numElts, 4);
    EXPECT_NE(sbl.q.last, nullptr);
    ASSERT_NE(sbl.q.first, nullptr);
    ASSERT_NE(sbl.root, nullptr);

    // Make sure the Queue looks good
    Queue q = sbl.q;
    EXPECT_EQ(q.first->name, "first");
    ASSERT_NE(q.first->next, nullptr);
    EXPECT_EQ(q.first->next->name, "second");
    ASSERT_NE(q.first->next->next, nullptr);
    EXPECT_EQ(q.first->next->next->name, "third");
    ASSERT_NE(q.first->next->next->next, nullptr);
    EXPECT_EQ(q.first->next->next->next->name, "fourth");
    ASSERT_EQ(q.first->next->next->next->next, nullptr);
    EXPECT_EQ(q.first->next->next->next, q.last);

    // Make sure the BST looks good
    // Reference:
    //  first
    //      \
    //     second
    //     /    \
    // fourth   third
    BST bst = sbl.root;
    EXPECT_EQ(bst->name, "first");
    EXPECT_EQ(bst->left, nullptr);
    ASSERT_NE(bst->right, nullptr);
    EXPECT_EQ(bst->right->name, "second");
    ASSERT_NE(bst->right->left, nullptr);
    ASSERT_NE(bst->right->right, nullptr);
    EXPECT_EQ(bst->right->right->name, "third");
    EXPECT_EQ(bst->right->right->left, nullptr);
    EXPECT_EQ(bst->right->right->right, nullptr);
    EXPECT_EQ(bst->right->left->name, "fourth");
    EXPECT_EQ(bst->right->left->left, nullptr);
    EXPECT_EQ(bst->right->left->right, nullptr);

    // Check that the nodes in the BST are the same as the ones in the Queue
    EXPECT_EQ(q.first, bst);
    EXPECT_EQ(q.first->next, bst->right);
    EXPECT_EQ(q.first->next->next, bst->right->right);
    EXPECT_EQ(q.first->next->next->next, bst->right->left);

    // Delete the four SBLnodes
    delete q.first->next->next->next;
    delete q.first->next->next;
    delete q.first->next;
    delete q.first;
}

TEST(removePub, givenEmptySBLExpectRemoveDies) {
    SBL sbl;
    SBL_init(sbl);
    EXPECT_DEATH(SBL_leave(sbl), "Error, SBL is empty.");
}

TEST(removePub, givenOneElementSBLExpectRemoveLeavesItEmpty) {
    SBL sbl;
    sbl.numElts = 1;
    sbl.q.first = sbl.q.last = sbl.root = new SBLnode{"test", nullptr, nullptr, nullptr};
    SBL_leave(sbl);
    EXPECT_EQ(sbl.numElts, 0);
    EXPECT_EQ(sbl.root, nullptr);
    EXPECT_EQ(sbl.q.first, nullptr);
    EXPECT_EQ(sbl.q.last, nullptr);
}

TEST(firstPub, givenEmptySBLExpectFirstDies) {
    SBL sbl;
    SBL_init(sbl);
    EXPECT_DEATH(SBL_first(sbl), "Error, SBL is empty.");
}

TEST(firstPub, givenOneElementSBLExpectFirstGivesTheOneElement) {
    SBL sbl;
    sbl.numElts = 1;
    sbl.q.first = sbl.q.last = sbl.root = new SBLnode{"test", nullptr, nullptr, nullptr};
    EXPECT_EQ(SBL_first(sbl), "test");
    delete sbl.root;
}

TEST(hasPub, gienEmptySBLExpectHasIsFalse) {
    SBL sbl;
    SBL_init(sbl);
    EXPECT_FALSE(SBL_has(sbl, "testInput"));
}

TEST(hasPub, givenOneElementSBLExpectItHasThatOneElement) {
    SBL sbl;
    sbl.numElts = 1;
    sbl.q.first = sbl.q.last = sbl.root = new SBLnode{"test", nullptr, nullptr, nullptr};
    EXPECT_TRUE(SBL_has(sbl, "test"));
    delete sbl.root;
}

TEST(toArrivalOrderStringPub, givenEmptySBLExpectArrivalOrderStringIsEmpty) {
    SBL sbl;
    SBL_init(sbl);
    EXPECT_EQ(SBL_toArrivalOrderString(sbl), "[]");
}

TEST(toArrivalOrderStringPub, givenOneElementSBLExpectArrivalOrderStringContainsThatElement) {
    SBL sbl;
    sbl.numElts = 1;
    sbl.q.first = sbl.q.last = sbl.root = new SBLnode{"test", nullptr, nullptr, nullptr};
    EXPECT_EQ(SBL_toArrivalOrderString(sbl), "[test]");
    delete sbl.root;
}

TEST(toArrivalOrderStringPub, givenThreeElementSBLExpectCorrectArrivalOrderString) {
    // Make some nodes for the SBL
    SBLnode* alice = new SBLnode{"alice", nullptr, nullptr, nullptr};
    SBLnode* bob = new SBLnode{"bob", nullptr, nullptr, nullptr};
    SBLnode* charlie = new SBLnode{"charlie", nullptr, nullptr, nullptr};

    // Setup the SBL
    SBL sbl;
    sbl.numElts = 3;
    sbl.q.first = sbl.root = bob;
    bob->left = alice;
    bob->right = charlie;
    bob->next = alice;
    alice->next = charlie;
    sbl.q.last = charlie;

    // Run the test
    EXPECT_EQ(SBL_toArrivalOrderString(sbl), "[bob, alice, charlie]");

    // Cleanup
    delete alice;
    delete bob;
    delete charlie;
}

TEST(toLexicographicalOrderStringPub, givenEmptySBLExpectLexicographicalOrderStringIsEmpty) {
    SBL sbl;
    SBL_init(sbl);
    EXPECT_EQ(SBL_toLexicographicalOrderString(sbl), "[]");
}

TEST(toLexicographicalOrderStringPub, givenOneElementSBLExpectLexicographicalOrderStringContainsThatElement) {
    SBL sbl;
    sbl.numElts = 1;
    sbl.q.first = sbl.q.last = sbl.root = new SBLnode{"test", nullptr, nullptr, nullptr};
    EXPECT_EQ(SBL_toLexicographicalOrderString(sbl), "[test]");
    delete sbl.root;
}

TEST(toLexicographicalOrderStringPub, givenThreeElementSBLExpectCorrectLexicographicalOrderString) {
    // Make some nodes for the SBL
    SBLnode* alice = new SBLnode{"alice", nullptr, nullptr, nullptr};
    SBLnode* bob = new SBLnode{"bob", nullptr, nullptr, nullptr};
    SBLnode* charlie = new SBLnode{"charlie", nullptr, nullptr, nullptr};

    // Setup the SBL
    SBL sbl;
    sbl.numElts = 3;
    sbl.q.first = sbl.root = bob;
    bob->left = alice;
    bob->right = charlie;
    bob->next = alice;
    alice->next = charlie;
    sbl.q.last = charlie;

    // Run the test
    EXPECT_EQ(SBL_toLexicographicalOrderString(sbl), "[alice, bob, charlie]");

    // Cleanup
    delete alice;
    delete bob;
    delete charlie;
}

TEST(nukePub, givenEmptySBLExpectNukeDoesNothing) {
    SBL sbl;
    SBL_init(sbl);
    SBL_nuke(sbl);
}

TEST(nukePub, givenThreeElementSBLExpectNukeCleansItUp) {
    // Make some nodes for the SBL
    SBLnode* alice = new SBLnode{"alice", nullptr, nullptr, nullptr};
    SBLnode* bob = new SBLnode{"bob", nullptr, nullptr, nullptr};
    SBLnode* charlie = new SBLnode{"charlie", nullptr, nullptr, nullptr};

    // Setup the SBL
    SBL sbl;
    sbl.numElts = 3;
    sbl.q.first = sbl.root = bob;
    bob->left = alice;
    bob->right = charlie;
    bob->next = alice;
    alice->next = charlie;
    sbl.q.last = charlie;

    // Test nuke
    SBL_nuke(sbl);
}

//
// Add your tests here  |
//                      V
