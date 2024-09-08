#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while(head != nullptr) {
        deleteFromFront();
    }
}

//LinkedList(int* array, int len) - A constructor that creates a list of from a C-array of length len.
LinkedList::LinkedList(int* array, int len)
{
    
}

void LinkedList::printList() {
    Node* currNode = head; 

    while (currNode != nullptr) { 
        std::cout << currNode->data << std::endl; 
        currNode = currNode->link; 
    } 
    std::cout << std::endl; 
}


void LinkedList::deleteFromFront() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->link;
    delete temp;
}