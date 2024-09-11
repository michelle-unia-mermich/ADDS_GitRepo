#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    // build and initialize a linked list object named ll
    int array[5]={1,2,3,4,5};
    LinkedList ll = LinkedList(array, 5);

    // traverse and print the linked list
    ll.printList();             
    std::cout << "---" << std::endl;

    //insert end
    ll.insertEnd(6);
    ll.printList();             
    std::cout << "---" << std::endl;

    //traverse
    int no_to_traverse=7;
    if (ll.traverse(no_to_traverse)!=nullptr) {std::cout << ll.traverse(no_to_traverse)->data<< std::endl;}
    else {std::cout << "The index you traversed is out of range." << std::endl;}
    std::cout << "---" << std::endl;

    //insertPosition
    ll.insertPosition(7,7);
    ll.printList();             
    std::cout << "---" << std::endl;

    //delete Position
    bool deleted_or_not=ll.deletePosition(7);
    if (deleted_or_not)
    {
        std::cout << "Element has been deleted." << std::endl;
        ll.printList();             
        std::cout << "---" << std::endl;
    }
    else
    {
        std::cout << "Index is out of bounds." << std::endl;
    }

    //get
    std::cout << ll.get(0) << std::endl;
    std::cout << "---" << std::endl;

    //search
    int result = ll.search(7);
    std::cout << result << std::endl;
    std::cout << "---" << std::endl;

    

    return 0;
}