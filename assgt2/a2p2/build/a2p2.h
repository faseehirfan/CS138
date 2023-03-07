#include <string>
#include <vector>

struct Node {
    std::string val;
    Node *next;
};

Node* makeList (const std::vector<std::string> v);

std::string list2string (const Node *first);

std::string pair2sortedString (const Node *p1, const Node *p2);

Node* sortPair (Node *p1, Node *p2);
    
Node* makeSortedPairList (const std::string s1, const std::string s2);

Node* append (Node *p1, Node *p2);
