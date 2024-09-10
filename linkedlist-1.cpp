#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while(head != nullptr) {
        deleteFromFront();
    }
}

void LinkedList::printList() {
    Node* currNode = head; 

    while (currNode != nullptr) { 
        std::cout << currNode->data << std::endl; 
        currNode = currNode->link; 
    } 
    std::cout << std::endl; 
}

Node* LinkedList::traverse(unsigned int index) { //to reach a particular node using node
    //a traverse function to move to any arbitrary positive-index node in our linked list
    unsigned int position = 0;
    Node* currNode = head; 

    while (currNode != nullptr && position < index) { 
        currNode = currNode->link; 
        position++;
    } 
    
    return currNode;
}

void LinkedList::insertAtPosition(int item, unsigned int index) {
    // if adding in front of the current head (including if the list is empty)
    if (index == 0) {
        head = new Node(item, head);
        return;
    }

    // if inserting between two nodes; i.e. [A, C] -> [A, B, C]
    Node* prevNode = traverse(index-1);

    // if inserting out of bounds, abort
    if (prevNode == nullptr) {
        return;
    }

    Node* newNode  = new Node(item, prevNode->link);
    prevNode->link = newNode;
}

void LinkedList::deleteFromFront() {
    //remove the first node
    if (head == nullptr) {
        return;
    }

    Node* temp = head; //1-save the address of the node we want to delete
    head = head->link; //2-the head pointer is now the `link` pointer in the first node. update head of the list to be the pointer pointing to the next node that the to-be-deleted node ties to
    //now both our target node and the head points to the next node. Now just delete the target node.
    delete temp;
}