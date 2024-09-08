#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {

    //my own singly linked list class 
    //*(note: elements in the list are indexed from 1 to length)
    
    Node* head;

public:
    //LinkedList() - A default constructor that creates an empty list.
    LinkedList();

    //~LinkedList() - A destructor that deletes all nodes from the list.
    ~LinkedList();

    //LinkedList(int* array, int len) - A constructor that creates a list of from a C-array of length len.
    LinkedList(int* array, int len);

    //insert position:
    /*
    void insertPosition(int pos, int newNum) - method to insert a new node containing the number newNum into the pos position.
    A pos of 1 (or less) places a new node at the front of the list.
    A pos that exceeds the size of the list should add the node to the end of the list.
    */
   void insertPosition(int pos, int newNum){};

   //bool deletePosition(int pos) - method to remove the node at position pos from the list and delete it. If it successfully deletes the node, it should return true. If pos is out-of-bounds, it should return false.
   bool deletePosition(int pos){};

   //int get(int pos) - method that returns pos's Node's data member variable. If pos is out-of-bounds, it should return std::numeric_limits < int >::max()
   int get(int pos){};

   //int search(int target) which searches the list for the first occurrence of target in the list and returns the index of where target is. If target does not exist in the list, return -1.
   int search(int target){};

    // void printList() - method that prints the data of all the nodes in the list, separated by spaces and encapsulated by '[' and ']'. In the case of an empty list, it prints nothing.
    void printList();

    // deletes the front node from the list
    void deleteFromFront();
};

#endif