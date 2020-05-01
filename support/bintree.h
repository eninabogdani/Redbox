// --------------------------------- bintree.h ---------------------------------
// Enina Bogdani, Rossini Higgins, David Kang, Josiah Zacharias
// Created: 01/19/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This class will define a Binary Tree that stores Movie objects
// -----------------------------------------------------------------------------
// Assumptions:
//  - The Movie objects stored in this BinTree will all have a compareTo() 
//    method which returns an int value representing the comparison between two
//    different movies
//  - An empty bintree will be printed as 0
//  - Leaves are assigned a height of 1
//  - Nodes that do not exist in the tree are assigned a height of 0

#ifndef BINTREE_H
#define BINTREE_H
#include <stdio.h>
#include "../movie/movie.h"


using namespace std;

class BinTree {

    
public:
    // Constructor/Destructor //////////////////////////////////////////////
    
    // BinTree ---------------------------------------------------------
    // Default Constructor : creates an empty BinTree and sets root to NULL
    BinTree();
    
    // BinTree ----------------------------------------------------------
    // Copy Constructor : creates a BinTree and creates a deep copy of the
    // inputTree, setting it to this
    BinTree(const BinTree &);
    
    // ~BinTree ----------------------------------------------------------
    // Destructor : Deallocates all nodes of BinTree and sets root to NULL
    ~BinTree();
    
    
    // Assignment Operators ////////////////////////////////////////////////
    
    // operator= --------------------------------------------------------
    // overloaded =: true if this BinTree != parameter BinTree, false if not
    BinTree& operator=(const BinTree &);
    
    
    // Equality Operators //////////////////////////////////////////////////
    
    // operator== ---------------------------------------------------------
    // overloaded ==: true if this BinTree == parameter BinTree, false if not
    bool operator==(const BinTree &) const;
    
    // operator!= ---------------------------------------------------------
    // overloaded !=: true if this BinTree != parameter BinTree, false if not
    bool operator!=(const BinTree &) const;
    
    // Mutators ////////////////////////////////////////////////////////////
    
    // insert ---------------------------------------------------------------
    // inserts a new Node containing the input newData into the BinTree object
    bool insert(Movie*);
    
    // makeEmpty ------------------------------------------------------------
    // deallocates all nodes of the BinTree object in this and sets root to NULL
    void makeEmpty();

    
    // Accessors ///////////////////////////////////////////////////////////
    
    // retrieve ------------------------------------------------------------
    // returns the bool value of whether data desired is in this tree, modifying
    // the dataRetrieved directly to be NodeData object, if found
    bool retrieve(Movie *, Movie* &);
    
    // getHeight ------------------------------------------------------------
    // returns the height of a general tree of a given value.
    int getHeight (Movie*) const;

    // isEmpty ---------------------------------------------------------------
    // true if tree is empty, otherwise
    bool isEmpty() const;
    
    
    // Output Functions /////////////////////////////////////////////////////
    
    // operator<< -------------------------------------------------------
    // Prints an inorder traversal of the tree
    friend ostream& operator<<(ostream &out, const BinTree &); 
    
private:
    
    // Custom structure for Nodes to be used in BinTree
    struct Node {
        Movie* data;                        // pointer to data object
        Node* left;                            // left subtree pointer
        Node* right;                           // right subtree pointer
    };
    Node* root;                                // root of the tree

    
    // Utility functions //////////////////////////////////////////////
        
    // inorderHelper -----------------------------------------------------
    // helper for operator<< overloaded method by recursively moving through the BinTree
    void inorderHelper(ostream&, Node*) const;
    
    // makeEmptyHelper ----------------------------------------------------
    // helper function for makeEmpty. Deallocates all nodes of the BinTree
    void makeEmptyHelper(Node* &);
    
    // duplicateTree -------------------------------------------------------
    // recursively copies nodes from rhs to lhs, duplicating entire tree
    void duplicateTree(Node* &, Node*);
    
    // equalityHelper -----------------------------------------------------
    // recursively compares rhs nodes to lhs, throughout entire tree
    bool equalityHelper(Node*, Node*) const;
    
    // insertHelper ---------------------------------------------------------
    // Helper function for insert. Recursively inserts a new Node containing
    // the input newData
    bool insertHelper(Node* &, Movie*);
    
    // retrieveHelper -------------------------------------------------------
    // recursive helper function for retrieve function. Returns the bool value
    // of whether data desired is in this tree,modifying the dataRetrieved
    // directly to be NodeData object, if found
    bool retrieveHelper(Node* &, Movie *, Movie* &) const;
    
    // getHeightHelper ----------------------------------------------------
    // recurisve helper function for getHeight. Returns the height of a
    // general tree of a given value. Height of a leaf node is 1, and a value
    // not found is 0.
    int getHeightHelper (Node*, Movie *) const;
    
    // getHeight ----------------------------------------------------------
    // overloaded getHeight recursively returns the height of a general tree
    // of the given node. The height of a leaf node is 1, and cur == NULL
    // returns zero.
    int getHeight (Node*) const;
        
};

#endif
