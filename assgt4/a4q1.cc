#include<iostream>
#include<string>
#include<cassert>
using namespace std;

struct Qnode {
    std::string val;
    Qnode* next;
};
struct Queue {
    Qnode* first;
    Qnode* last;
};

// Implement these using a linked list, using your class notes
void Q_init (Queue& q) { }
bool Q_isEmpty (const Queue& q) { }
int Q_size (const Queue& q) { }
void Q_enter (Queue& q, std::string val) { }
std::string Q_first (const Queue& q) { 
    cerr << "Error, queue is empty." << endl;
}
void Q_leave (Queue& q) {
    cerr << "Error, queue is empty." << endl;
}
void Q_print (const Queue& q) { } 
void Q_nuke (Queue& q) { } 


// Now onto the PQ stuff, which makes use of the above Queue routines
struct PQnode {
    int priority;
    Queue q;
    PQnode* next;
};
typedef PQnode* PQ;

void PQ_init (PQ& pq) { 
    pq = nullptr;
}

// Now implement these yourself.
bool PQ_isEmpty (const PQ& pq) {}
void PQ_enter (PQ& pq, std::string val, int priority) {}
std::string PQ_first (const PQ& pq) {
    cerr << "Error, priority queue is empty." << endl;
}
void PQ_leave (PQ& pq) {
    cerr << "Error, priority queue is empty." << endl;
}
int PQ_size (const PQ& pq) {}
int PQ_sizeByPriority (const PQ& pq, int priority) {}
int PQ_numPriorities (const PQ& pq) {}
void PQ_nuke (PQ & pq) {}
