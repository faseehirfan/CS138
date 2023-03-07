#include "a3p2.h"

#include <string>
#include <cassert>

using namespace std;

// provided for you
NodeChunk *createNewNodeChunk(const int chunkSize)
{
    // preconditions
    assert(chunkSize > 0);
    // implementation
    NodeChunk *newNodeChunk = new NodeChunk;
    newNodeChunk->next = nullptr;
    newNodeChunk->val = new string[chunkSize];
    // C++ will initialize this array with empty strings
    // we will switch to our special value for unused stack slots
    for (int i = 0; i < chunkSize; i++)
    {
        newNodeChunk->val[i] = UNUSED_SLOT;
    }
    // postconditions
    return newNodeChunk;
}

// provided for you
void initStack(const int chunkSize, Stack &s)
{
    // preconditions
    assert(chunkSize > 0);
    // implementation
    s.chunkSize = chunkSize;
    s.firstChunk = nullptr;
    s.topElt = -1;
    // postconditions
    assert(isEmpty(s));
    assert(isValidStack(s));
}

// provided for you
bool isEmpty(const Stack &s)
{
    // do not call isValidStack() from here
    // because isEmpty() is part of isValidStack()
    return nullptr == s.firstChunk;
}

// @TODO: define what a wellformed chunkystack looks like
// Note that simply returning true will pass some tests.
// Similarly, simply triggering an assertion will pass some tests.
// That is inherent in any procedure that returns bool.
// The challenge is to pass all the tests.
bool isValidStack(const Stack &s)
{
    // either trip an assertion or return true
    // never return false
    assert(s.chunkSize > 0 && s.topElt >= -1);
    if (s.firstChunk == nullptr)
    {
        assert(s.topElt == -1);
    }
    assert(s.topElt < s.chunkSize);

    NodeChunk *tmp = s.firstChunk;

    while (tmp != nullptr)
    {
        assert(tmp->val != nullptr);

        assert(tmp->val[0] != UNUSED_SLOT);

        tmp = tmp->next;
    }
    return true;
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void push(const string v, Stack &s)
{
    // preconditions
    assert(isValidStack(s));
    // implementation
    if (s.topElt > -1 && (s.chunkSize -1) != s.topElt){
        s.firstChunk->val[s.topElt + 1] = v;
        s.topElt = s.topElt + 1;
    } else {
        s.topElt = 0;
        NodeChunk *newNode = createNewNodeChunk(s.chunkSize);
        newNode->val[s.topElt] = v;
        newNode->next = s.firstChunk;
        s.firstChunk = newNode;
    }

    // postconditions
    assert(isValidStack(s));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void pop(Stack &s)
{
    // preconditions
    assert(isValidStack(s));
    assert(!isEmpty(s));

    // implementation
    if (s.topElt == 0) // if only item in chunk
    {
        NodeChunk *tmp = s.firstChunk;
        if (tmp->next == nullptr)
        {
            delete[] tmp->val;
            delete tmp;
            s.firstChunk = nullptr;
            s.topElt = -1;
        }
        else
        {
            s.firstChunk = s.firstChunk->next;
            delete[] tmp->val;
            delete tmp;
            tmp = s.firstChunk;
            if (tmp != nullptr)
            {
                for (int i = s.chunkSize - 1; i >= 0; i++)
                {
                    if (tmp->val[i] != UNUSED_SLOT)
                    {
                        s.topElt = i;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        s.firstChunk->val[s.topElt] = UNUSED_SLOT;
        s.topElt -= 1;
    }

    // postconditions
    assert(isValidStack(s));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
int size(const Stack &s)
{
    // preconditions
    assert(isValidStack(s));

    // implementation
    if (isEmpty(s))
    {
        return 0;
    }

    if (s.firstChunk->next == nullptr)
    {
        return (s.topElt + 1);
    }
    NodeChunk *tmp = s.firstChunk->next;
    int count = 0;
    while (tmp != nullptr)
    {
        count ++;
        tmp = tmp->next;
    }

    // postconditions
    // return result
    return ((s.topElt + 1) + count * s.chunkSize);
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void swap(Stack &s)
{
    // preconditions
    assert(isValidStack(s));
    assert(size(s) >= 2);

    // implementation
    if (s.topElt == 0)
    {
        string temp = s.firstChunk->val[0];
        s.firstChunk->val[0] = s.firstChunk->next->val[s.chunkSize - 1];
        s.firstChunk->next->val[s.chunkSize - 1] = temp;
    }
    else
    {
        string temp = s.firstChunk->val[s.topElt];
        s.firstChunk->val[s.topElt] = s.firstChunk->val[s.topElt - 1];
        s.firstChunk->val[s.topElt - 1] = temp;
    }

    // postconditions
    assert(isValidStack(s));
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string toString(const Stack &s)
{
    // preconditions
    assert(isValidStack(s));
    if (isEmpty(s)){
        return "[]"; 
    }
    // implementation
    NodeChunk *temp = s.firstChunk;
    string output = "[";
    for (int i = s.topElt; i >= 0; i--)
    {
        if (i == 0)
        {
            output = output + temp->val[i] + "]";
            return output;
        }
        else
        {
            output = output + temp->val[i] + ", ";
        }
    }
    temp = temp->next;

    while (temp->next != nullptr)
    {
        for (int i = s.chunkSize - 1; i >= 0; i--)
        {
            output = output + temp->val[i] + ", ";
        }
        temp = temp->next;
    }

    for (int i = s.chunkSize - 1; i >= 1; i--)
    {
        output = output + temp->val[i] + "]";
    }
    // postconditions
    // return result
    return output; // something so this stub compiles
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
string top(const Stack &s)
{
    // preconditions
    assert(isValidStack(s));
    assert(!isEmpty(s));
    // implementation
    // postconditions
    // return result
    return s.firstChunk->val[s.topElt]; // something so this stub compiles
}

// @TODO: Preconditions, Postconditions, Tests, Implementation (in that order)
void nuke(Stack &s)
{
    // preconditions
    assert(isValidStack(s));
    // implementation
    NodeChunk *current = s.firstChunk;
    while (current != nullptr)
    {
        NodeChunk *next = current->next;
        delete[] current->val;
        delete current;
        current = next;
    }
    
    s.firstChunk = nullptr;
    s.topElt = -1;

    // postconditions
    assert(isValidStack(s));
    assert(isEmpty(s));
}
