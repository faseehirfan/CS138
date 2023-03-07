#include <iostream>
#include <string>
#include <cassert>
#include "a4p3.h"
using namespace std;

// You'll want to insert (and adapt) the code for queues & BSTs here
// so that you can use it in your SBL functions.



// Now implement the SBL functions
void SBL_init (SBL& sbl) { } 
int SBL_size (const SBL& sbl){ } 
void SBL_arrive (SBL& sbl, std::string name) { } 
void SBL_leave (SBL& sbl){ 
    cerr << "Error, SBL is empty." << endl;
    assert(false);
} 
std::string SBL_first (const SBL& sbl) { 
    cerr << "Error, SBL is empty." << endl;
    assert(false);
} 
bool SBL_has (const SBL& sbl, std::string name) { } 
std::string SBL_toArrivalOrderString (const SBL& sbl) { }
std::string SBL_toLexicographicalOrderString (const SBL& sbl) { }
void SBL_nuke (SBL& sbl) { }
