#include "a3p1.h"

#include <string>
#include <cassert>

using namespace std;

// provided for you
void initStew(Stew &q)
{
    // no preconditions
    // implementation
    q.first = nullptr;
    q.last = nullptr;
    // postconditions
    assert(isEmpty(q));
    assert(isValidStew(q));
}

// provided for you
bool isEmpty(const Stew &q)
{
    // no preconditions
    // note: if we called isValidStew(q) here we would likely get
    // stuck in an infinite loop, because isValidStew(q) might
    // call isEmpty(q)
    return (q.first == nullptr) && (q.last == nullptr);
}

// @TODO: define what a wellformed node looks like
// Note that simply returning true will pass some tests.
// Similarly, simply triggering an assertion will pass some tests.
// That is inherent in any procedure that returns bool.
// The challenge is to pass all the tests.
bool isValidNode(const Node &n)
{
    // either trip an assertion or return true
    // never return false
    assert(n.next != &n);
    assert(n.prev != &n);

    assert(n.prev == nullptr || n.prev->next == &n);
    assert(n.next == nullptr || n.next->prev == &n);

    // no assertions tripped, so return true
    return true;
}

// @TODO: define what a wellformed stew looks like
// Note that simply returning true will pass some tests.
// Similarly, simply triggering an assertion will pass some tests.
// That is inherent in any procedure that returns bool.
// The challenge is to pass all the tests.
bool isValidStew(const Stew &s)
{
    // either trip an assertion or return true
    // never return false
    assert(!(s.first == nullptr && s.last != nullptr));
    assert(!(s.last == nullptr && s.first != nullptr));

    Node *tmp = s.first;

    if (s.first == nullptr && s.last == nullptr)
    {
        return true;
    }
    else if (s.first == s.last)
    {
        assert(isValidNode(*tmp));
    }
    else
    {
        while (tmp->next != nullptr)
        {
            assert(isValidNode(*tmp));
            tmp = tmp->next;
        }
        assert(isValidNode(*tmp));
    }
    assert(tmp == s.last);
    //  no assertions tripped, so return true
    return true;
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void addFront(Stew &q, string val)
{
    // preconditions
    assert(isValidStew(q));

    // implementation
    Node *newNode = new Node();
    newNode->prev = nullptr;
    newNode->val = val;
    newNode->next = q.first;

    if (q.first == nullptr)
    {
        q.last = newNode;
    }
    else
    {
        q.first->prev = newNode;
    }
    q.first = newNode;

    // postconditions
    assert(!isEmpty(q));
    assert(isValidStew(q));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void addBack(Stew &q, string val)
{
    // preconditions
    assert(isValidStew(q));

    // implementation
    Node *newNode = new Node();
    newNode->prev = q.last;
    newNode->val = val;
    newNode->next = nullptr;

    if (q.first == nullptr)
    {
        q.first = newNode;
    }
    else
    {
        q.last->next = newNode;
    }
    q.last = newNode;

    // postconditions
    assert(!isEmpty(q));
    assert(isValidStew(q));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void leaveFront(Stew &q)
{
    // preconditions
    assert(isValidStew(q));
    assert(!isEmpty(q));

    // implementation
    Node *temp = q.first;
    if (q.first == q.last)
    {
        delete temp;
        q.first = nullptr;
        q.last = nullptr;
    }
    else
    {
        Node *temp2 = q.first->next;

        delete temp;

        q.first = temp2;
        q.first->prev = nullptr;
    }
    // postconditions
    assert(isValidStew(q));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void leaveBack(Stew &q)
{
    // preconditions
    assert(isValidStew(q));
    assert(!isEmpty(q));

    // implementation
    Node *temp = q.last;
    if (q.first == q.last)
    {
        delete temp;
        q.first = nullptr;
        q.last = nullptr;
    }
    else
    {
        Node *temp2 = q.last->prev;

        delete temp;

        q.last = temp2;
        q.last->next = nullptr;
    }
    // postconditions
    assert(isValidStew(q));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string peekBack(const Stew &q)
{
    // preconditions
    assert(isValidStew(q));
    assert(!isEmpty(q));

    // implementation

    // postconditions

    // return result
    return q.last->val; // so this stub compiles and runs
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string peekFront(const Stew &q)
{
    // preconditions
    assert(isValidStew(q));
    assert(!isEmpty(q));

    // implementation

    // postconditions

    // return result
    return q.first->val; // so this stub compiles and runs
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string toString(const Stew &q, char direction)
{
    // preconditions
    string line = "";
    if (direction != 'f' && direction != 'r')
    {
        line += "Error, illegal direction: (";
        line += direction;
        line += ")";
        return line;
    }
    assert(isValidStew(q));
    if (isEmpty(q)){
        return "[]";
    }
    // implementation
    
    line = "[";
    if (direction == 'f')
    {
        Node *tmp = q.first;
        while (tmp->next != nullptr)
        {
            line = line + tmp->val + ", ";
            tmp = tmp->next;
        }
        line = line + tmp->val + "]";
    } else if (direction == 'r'){
        Node *tmp = q.last;
        while (tmp->prev != nullptr){
            line = line + tmp->val + ", ";
            tmp = tmp->prev;
        }
        line = line + tmp->val + "]";
    }
    // postconditions

    // return result
    return line; // so this stub compiles and runs
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void nuke(Stew &q)
{
    // preconditions
    assert(isValidStew(q));

    // implementation
    Node *temp = q.first;
    while (temp != nullptr)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    q.first = nullptr;
    q.last = nullptr;

    // postconditions
    assert(isEmpty(q));
}
