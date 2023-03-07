#include <string>
#include <vector>

#include "a2p2.h"
#include "gtest/gtest.h"

using namespace std;

/* ************************************************************** */
/* Tests for making a simple list                                 */
/* ************************************************************** */
TEST(TestMakeList, SimpleList) {
    vector<string> input = {"alice", "bob"};
    Node *out = makeList(input);
    EXPECT_EQ("alice", out->val);
    EXPECT_EQ("bob", out->next->val);
    EXPECT_TRUE(out->next->next == nullptr);
}
/* ************************************************************** */
/* Tests for converting a simple list to a string                 */
/* ************************************************************** */
TEST(TestList2String, SimpleList) {
    vector<string> input = {"alice", "bob"};
    Node *out = makeList(input);
    EXPECT_EQ("alice bob", list2string (out));
}

/* ************************************************************** */
/* Tests for converting a simple pair to a string                 */
/* ************************************************************** */
TEST(TestPair2String, SimpleList) {
    Node *p1 = new Node;
    p1->val = "alpha";
    Node *p2 = new Node;
    p2->val = "omega";

    EXPECT_EQ("alpha omega", pair2sortedString (p1, p2));
    EXPECT_EQ("alpha omega", pair2sortedString (p2, p1));
}

TEST(TestPair2String, DeathTest) {
    Node *p = new Node;
    p->val = "test";
    EXPECT_DEATH(pair2sortedString(p, nullptr), "Assertion");
}

/* ************************************************************** */
/* Tests for sorting two nodes or two string                      */
/* ************************************************************** */
TEST(TestSorting, SimpleList) {
    Node *p1 = new Node;
    p1->val = "alpha";
    Node *p2 = new Node;
    p2->val = "omega";

    EXPECT_EQ("alpha omega", list2string (makeSortedPairList("omega", "alpha")));
    EXPECT_EQ("alpha omega", list2string (sortPair(p1, p2)));
}

/* ************************************************************** */
/* Tests for appending                                            */
/* ************************************************************** */
TEST(TestAppending, SimpleList) {
    vector<string> list1 = {"alpha", "baker", "charlie"};
    vector<string> list2 = {"delta", "echo"};

    EXPECT_EQ("alpha baker charlie delta echo",
              list2string (append(makeList(list1),
                               makeList(list2))));
}


/* ************************************************************** */
/* MORE TESTS HERE                                                */
/* ************************************************************** */

TEST(TestSorting, DeathTest)
{
    Node *p1 = nullptr;
    Node *p2 = nullptr;
    EXPECT_DEATH(sortPair(p1, p2), "Assertion");
}



TEST(TestSorting, SimpleList2)
{
    Node *p1 = new Node;
    p1->val = "zebra";
    Node *p2 = new Node;
    p2->val = "omega";

    EXPECT_EQ("omega zebra", list2string(makeSortedPairList("omega", "zebra")));
    EXPECT_EQ("omega zebra", list2string(sortPair(p1, p2)));
}

TEST(TestAppend, givennullptr)
{
    Node *p1 = nullptr;
    //p1->val = "zebra";
    Node *p2 = new Node;
    p2->val = "omega";
    p2->next = nullptr;

    EXPECT_EQ("omega", list2string(append(p1, p2)));
    EXPECT_EQ("omega", list2string(append(p2,p1)));
}