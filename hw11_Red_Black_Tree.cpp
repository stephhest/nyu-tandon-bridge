// sh7245_hw11.cpp - Stephanie Hestilow
//
// HOMEWORK 11
/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) 
{
    return (c==0)?1:0; // If color is RED, return BLACK (and vice versa)
}

/* ***************************************** */
/* ************** NODE CLASS *************** */
/* ***************************************** */
template <class T>
class RBTNode 
{
    RBTNode<T> *parentPtr, *leftChildPtr, *rightChildPtr;
    T data;
    int color;

public:
    RBTNode(T data) : data(data), color(RED), parentPtr(nullptr),
    leftChildPtr(nullptr), rightChildPtr(nullptr) {}

    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);

    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const 
{
    int left_h = 0;
    if (leftChildPtr != nullptr) 
        left_h = leftChildPtr->height();

    int rightChildPtr_h = 0;
    if (rightChildPtr != nullptr) 
        rightChildPtr_h = rightChildPtr->height();
    
    return 1 + max(left_h, rightChildPtr_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const 
{
    if (rightChildPtr != nullptr) 
        rightChildPtr->prettyPrint(indent + 1);
    
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) 
        cout << '\t';
    
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) 
        cout << '\t';
    
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl; // IF color is red, print RED otherwise print BLACK
    if (leftChildPtr != nullptr) 
        leftChildPtr->prettyPrint(indent + 1);
}

template <class T>
void swapColor(RBTNode<T> *node) 
{
    if (node != nullptr) 
        node->color = swapColor(node->color);
}

// getColor handles null nodes (which are black)
template <class T>
int getColor(RBTNode<T> *node) 
{
    if (node != nullptr) 
        return node->color;
    return BLACK;
}

/* ***************************************** */
/* *************** RBT CLASS *************** */
/* ***************************************** */
template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&grandparent);
    void doubleCR(RBTNode<T> *&grandparent);
    void singleCR(RBTNode<T> *&grandparent);
    void doubleCCR(RBTNode<T> *&grandparent);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parentPtr);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&grandparent) // RIGHT the LEFT
{
    singleCR(grandparent); 
    singleCCR(grandparent);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&grandparent) // LEFT then RIGHT
{
    singleCCR(grandparent);
    singleCR(grandparent);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&grandparent) // RIGHT rotation
{
    // RBTNode<T> *grandparentPtr = point;
    RBTNode<T> *parent = grandparent->leftChildPtr;
    // TODO: ADD ROTATION CODE HERE

    grandparent->leftChildPtr = parent->rightChildPtr;

    if(grandparent->leftChildPtr)
        grandparent->leftChildPtr->parentPtr = grandparent;

    parent->parentPtr = grandparent->parentPtr;

    if (!grandparent->leftChildPtr)
        root = parent;
    else if (grandparent == grandparent->parentPtr->leftChildPtr)
        grandparent->parentPtr->leftChildPtr = parent;
    else
        grandparent->parentPtr->rightChildPtr = parent;

    parent->rightChildPtr = grandparent;
    grandparent->parentPtr = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&grandparent) // LEFT rotation
{
    // RBTNode<T> *grandparentPtr = point;
    RBTNode<T> *parent = grandparent->rightChildPtr;
    // TODO: ADD ROTATION CODE HERE

    grandparent->rightChildPtr = parent->leftChildPtr;

    if(grandparent->rightChildPtr)
        grandparent->rightChildPtr->parentPtr = grandparent;

    parent->parentPtr = grandparent->parentPtr;

    if (!grandparent->parentPtr)
        root = parent;
    else if (grandparent == grandparent->parentPtr->leftChildPtr)
        grandparent->parentPtr->leftChildPtr = parent;
    else
        grandparent->parentPtr->rightChildPtr = parent;

    parent->leftChildPtr = grandparent;
    grandparent->parentPtr = parent;
}

template <class T>
void RBT<T>::insert(const T &dataToInsert, RBTNode<T> *&point, RBTNode<T> *parentPtr) 
{ // Pointer starts at the address of the root
    if (point == nullptr) // LEAF location is found so insert node 
    {   
        point = new RBTNode<T>(dataToInsert); // modifies the pointer itself since *point is passed by ref
        point->parentPtr = parentPtr; 

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        
        // TODO: ADD RBT RULES HERE --> execute rules to maintain RBT properties
        /* 
        1. All nodes are colored red or black (and new nodes are red)
            - If parent is black, we're done!
            - If parent is RED, we have work to do...
                - If uncle  is black (grandparent's other child)
                    - if new node is inside - double rotation
                    - If new node is outside - single rotation
        2. Root node is always black (check for this last)
        3. If a root is node, its children must be black
        4. Every path from the root to the leaves must pass through the same number of black nodes.

        */
        
        RBTNode<T>* parentPtr = nullptr;
        RBTNode<T>* grandparentPtr = nullptr;

        // LOOK FOR INSTANCES WHERE RED NODE HAS RED PARENT
        while ((curr_node != root) && (getColor(curr_node) == RED) && (getColor(curr_node->parentPtr) == RED))
        {
            parentPtr = curr_node->parentPtr; // track the current node's parent 
            grandparentPtr = parentPtr->parentPtr; // track the current node's grandparent

            if (parentPtr == grandparentPtr->leftChildPtr) // if parent is on the LEFT of grandparent
            {
                if (getColor(grandparentPtr->rightChildPtr) == RED) // if uncle is ALSO RED 
                {
                    swapColor(grandparentPtr->rightChildPtr); // change uncle to BLACK
                    swapColor(parentPtr); // change parent to BLACK
                    if (grandparentPtr != nullptr)
                        grandparentPtr->color = RED; // change grandparent to RED
                    curr_node = grandparentPtr; // set curr node pointer to the grandparent and continue upward
                }
                else
                { // Check if double or single rotation needed
                    if (curr_node == parentPtr->rightChildPtr) 
                    { 
                        doubleCR(grandparentPtr); // double rotate LEFT then RIGHT
                        curr_node = parentPtr;
                        parentPtr = curr_node->parentPtr;
                        swapColor(parentPtr);
                        swapColor(grandparentPtr);
                    }
                    else
                    {
                        singleCR(grandparentPtr); // rotate RIGHT ONLY
                        curr_node = parentPtr;
                        swapColor(parentPtr);
                        swapColor(grandparentPtr);
                    }
                }
            }
            else // if parent is on the RIGHT side of grandparent
            {
                if (getColor(grandparentPtr->leftChildPtr) == RED) // if uncle is ALSO RED, do recoloring
                {
                    swapColor(grandparentPtr->leftChildPtr);
                    swapColor(parentPtr);
                    if (grandparentPtr != nullptr)
                        grandparentPtr->color = RED;
                    curr_node = grandparentPtr;
                }
                else
                { // Check if double or single rotation needed
                    if (curr_node == parentPtr->leftChildPtr) 
                    { 
                        doubleCCR(grandparentPtr); // double rotate RIGHT then LEFT
                        curr_node = parentPtr;
                        parentPtr = curr_node->parentPtr;
                        swapColor(parentPtr);
                        swapColor(grandparentPtr);
                    }
                    else
                    {
                        singleCCR(grandparentPtr); // single rotate LEFT ONLY
                        curr_node = parentPtr;
                        swapColor(parentPtr);
                        swapColor(grandparentPtr);
                    }
                }
            }
        }
        if(root != nullptr) 
            root->color = BLACK; // double check the root is still black!!
    }
     
    else if (dataToInsert < point->data) // recurse LEFT down the tree to find correct leaf location
        insert(dataToInsert, point->leftChildPtr, point);

    else // recurse RIGHT down the tree to find correct leaf location
        insert(dataToInsert, point->rightChildPtr, point);
}

template <class T>
void RBT<T>::insert(const T &dataToInsert) 
{
    insert(dataToInsert, root, nullptr);
}


/* ***************************************** */
/* ************* MAIN PROGRAM ************** */
/* ***************************************** */

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}