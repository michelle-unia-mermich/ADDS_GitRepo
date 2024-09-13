#include <iostream>
#include "LinkedList.h"

int main()
{

    LinkedList ll;
    ll.insertFront(1);
    ll.insertFront(2);
    ll.insertFront(3);
    ll.insertFront(4);
    ll.printList();
    std::cout<<std::endl;
    std::cout<<"-------------------"<<std::endl;
    Node* node_ptr=ll.traverse(3);
    std::cout<<node_ptr->print_data()<<std::endl;
    //test swap
    ll.swap(0,4);
    ll.printList();
    std::cout<<std::endl;
    std::cout<<"-------------------"<<std::endl;
    //test search
    std::cout<<ll.search(4)<<std::endl;
    std::cout<<(ll.traverse(ll.search(4)))->print_data()<<std::endl;
    //test search_and_delete
    std::cout<<ll.find_and_delete(3)<<std::endl;
    ll.printList();
    std::cout<<std::endl;
    std::cout<<"-------------------"<<std::endl;


    

    
    return 0;
}