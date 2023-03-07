#include <iostream>
#include <string>
#include <cassert>
#include "a4p2.h"

using namespace std;

void BST_init (BST& root) {
    root = nullptr;
}

bool BST_isEmpty (const BST& root) {
    return nullptr == root;
}

bool BST_has (const BST& root, std::string key) {
    if (nullptr == root) {
	    return false;
    } else if (root->key == key) {
	    return true;
    } else if (root->key > key) {
	    return BST_has (root->left, key);
    } else {
	    return BST_has (root->right, key);
    }
}

void BST_insert (BST& root, std::string key) {
    if (nullptr == root) {
        root = new BST_Node; 
        root->key = key; 
        root->left = nullptr; 
        root->right = nullptr;
    } else if (key < root->key) {
	    BST_insert(root->left, key);
    } else {
	    BST_insert(root->right, key);
    } 
}

void BST_print (const BST& root) {
    if (nullptr != root) {
        BST_print (root->left);
        cout << root->key << endl;
        BST_print (root->right);
    }
}

// Now you do this one ...
void BST_remove (BST& root, std::string key) { 
    cerr << "Error, couldn't find \"" << key << "\" in the BST\n";
    assert(false);
}

// ... and this one too
void BST_nuke (BST & root) {
    // TODO
}
