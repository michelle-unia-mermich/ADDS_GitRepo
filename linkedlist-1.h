#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList {
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    // print every node's data line-by-line
    void printList();

    // traverse the list until reaching the node at specified position, & return that node's address
    Node* traverse(unsigned int index);
    
    // create a new node with an int of data at the index'th position of the list; inserting out of bounds does nothing
    void insertAtPosition(int item, unsigned int index);

    // deletes the front node from the list
    void deleteFromFront();
};

#endif