#include <iostream>
#include "linkedlist.h"

using namespace std;

int main() {
    // build and initialize a linked list object named ll
    LinkedList ll;

    ll.insertAtPosition(9, 0);    // insert a node into an empty list
    ll.insertAtPosition(3, 0);    // insert a node infront of the only node
    ll.insertAtPosition(6, 1);    // insert a node between our two nodes
    ll.insertAtPosition(12, 10);  // insert a node out of bounds
    ll.insertAtPosition(12, 3);   // insert a node at the end of the list

    // traverse and print the linked list
    ll.printList();               // prints [3, 6, 9]
    std::cout << "---" << std::endl;

    // traverse to specific nodes (0, 1, 2, 3) and print the data at these (handles out of bounds access)
    for (unsigned int i = 0; i < 4; i++) {
        Node* target = ll.traverse(i);
        if (target != nullptr)
            std::cout << target->data << std::endl;
        else
            std::cout << "there is no data here, target = nullptr" << std::endl;
    }

    return 0;
}