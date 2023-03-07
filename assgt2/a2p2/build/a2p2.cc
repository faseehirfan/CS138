#include <string>
#include <vector>
#include <cassert>

#include "a2p2.h"

using namespace std;

Node* makeList (const std::vector<std::string> v) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (auto i : v){
        Node *node = new Node;
        node->val = i;
        node->next = nullptr;

        if (head == nullptr){
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

std::string list2string (const Node *first) {
    string s;
    for (const Node *ptr = first; ptr != nullptr; ptr = ptr->next){
        s += ptr->val + " ";
    }
    s = s.substr(0, s.length() - 1);
    return s;
}

std::string pair2sortedString (const Node *p1, const Node *p2) {
    assert(p1 != nullptr && p2 != nullptr);

    string s;
    s += (p1->val < p2->val ? p1->val + " " + p2->val : p2->val + " " + p1->val);

    return s;
}

Node* sortPair (Node *p1, Node *p2) {
    assert(p1 != nullptr && p2 != nullptr);

    if (p1->val < p2->val)
    {
        p1->next = p2;
        return p1;
    }
    else
    {
        p2->next = p1;
        return p2;
    }
}

Node* makeSortedPairList (const std::string s1, const std::string s2) {
    Node *p1 = new Node;
    p1->val = s1;
    p1->next = nullptr;

    Node *p2 = new Node;
    p2->val = s2;
    p2->next = nullptr;

    return sortPair(p1, p2);
}

Node* append (Node *p1, Node *p2) {
    if (p1 == nullptr)
    {
        return p2;
    }
    if (p2 == nullptr){
        return p1;
    }

    Node *current = p1;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = p2;
    return p1;
}
