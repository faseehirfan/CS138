#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct SBLnode {
    std::string name;
    SBLnode *next;           // for the queue operations
    SBLnode *left, *right;   // for  the BST operations
};
struct Queue {
    SBLnode *first, *last;
};
typedef SBLnode* BST;
struct SBL {
    Queue q;
    BST root; 
    int numElts;
};
typedef SBLnode Q_Node;
typedef SBLnode BST_Node;

// You'll want to insert (and adapt) the code for queues & BSTs here

void SBL_init (SBL& sbl) { } 
int SBL_size (const SBL& sbl){ } 
void SBL_arrive (SBL& sbl, std::string name) { } 
void SBL_leave (SBL& sbl){ 
    cerr << "Error, SBL is empty." << endl;
} 
std::string SBL_first (const SBL& sbl) { 
    cerr << "Error, SBL is empty." << endl;
} 
bool SBL_has (const SBL& sbl, std::string name){ } 
void SBL_printInArrivalOrder (const SBL& sbl) { } 
void SBL_printInLexicographicalOrder (const SBL& sbl) { }
void SBL_nuke (SBL& sbl) {}
