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
//For each element of an array arr[] we create a node in a linked list and insert it at the end. 

// Function to insert node at the end
void LinkedList::insertEnd(int newNum)
{
    //Create a new node
    Node* new_node = new Node(newNum, nullptr);

    //Case 1: the linked list is empty, make the new node as the head
    if (head==nullptr)
    {
        head=new_node;
    }
    else
    {
        //Case 2: 
        //store the head in a temporary variable
        Node* current_traversed_head = head;
        //traverse till last node
        while( current_traversed_head->link != nullptr)
        {
            current_traversed_head = current_traversed_head->link;
        }
        //now current_traversed_head is the last pointer, as current_traversed_head->link = nullptr
        //make this last pointer points to the new node
        current_traversed_head->link=new_node;
    }
}

LinkedList::LinkedList(int* array, int len)
{
    head = nullptr;
    for (int i = 0; i < len; i++) 
    {
        insertEnd(array[i]);
    }
}

void LinkedList::printList() 
{
    //prints the data of all the nodes in the list, separated by spaces and encapsulated by '[' and ']'. In the case of an empty list, it prints nothing.
    if(head==nullptr)
    {
        return; //print nothing
    }
    else
    {
        Node* currNode = head; 
        std::cout<<"[";
        while (currNode != nullptr) 
        {
            if(currNode->link!=nullptr)
            {
                //if not the last node
                std::cout << currNode->data <<" "; 
                currNode = currNode->link; 
            }
            else
            {
                //the last node
                std::cout << currNode->data; 
                currNode = currNode->link; 
            }
            
        } 
        std::cout<<"]"<<std::endl;
        
    } 
}

void LinkedList::deleteFromFront() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->link;
    delete temp;
}

Node* LinkedList::traverse(unsigned int index) { //to reach a particular node using node index
    //a traverse function to move to any arbitrary positive-index node in our linked list
    //*upgrade version: if index if out of bounds eg. <1 or greater than len of list, return nullptr

    unsigned int position = 1;
    Node* currNode = head; //currNode is the current-traversed-node

    if(index<=0)
    {
        return nullptr;
    }

    while (currNode != nullptr && position < index) { 
        currNode = currNode->link; 
        position++;
        //if currNode==nullptr and position is still < index but not equal index, index is out of range
        if(currNode == nullptr && position < index)
        {
            return nullptr;
        }

    }

    //else if index is out of bounds
    return currNode; 
}

void LinkedList::insertPosition(int pos, int newNum) //method to insert a new node containing the number newNum into the pos position.
{
    //elements in the list are indexed from 1 to length
    //A pos of 1 (or less) places a new node at the front of the list.
    //A pos that exceeds the size of the list should add the node to the end of the list.

    //To insert a new node at a specific position, we need to traverse the list to position – 1. 
    //If the position is valid, we adjust the pointers similarly such that the next pointer of the new node points to the next of current nod and next pointer of current node points to the new node.

    // if adding in front of the current head (including if the list is empty)
    if (pos<=1) 
    {
        Node* new_first_node = new Node(newNum, nullptr); //set null ptr for random, change later
        //head right now is the pointer pointing to the first node of the linked list. We want to the new first_node to point to the next node which is the current first node
        new_first_node->link=head;
        //the head is now the pointer to this new_first_node
        head= new_first_node;
        return; //since there is nothing left to be done
    }
    
    // if inserting between two nodes; i.e. [A, C] -> [A, B, C]
    Node* prevNode = traverse(pos-1);

    // if inserting out of bounds, add the node to the end of the list
    if (prevNode == nullptr) {
        insertEnd(newNum);
        return;
    }

    Node* newNode  = new Node(newNum, prevNode->link);
    prevNode->link = newNode;
}

bool LinkedList::deletePosition(int pos)
{
    //method to remove the node at position pos from the list and delete it. 
    //If it successfully deletes the node, it should return true. 
    //If pos is out-of-bounds, it should return false.

    /*
    Step by step approach
    1. If list is empty (head == NULL), returns the head.
    2. If the position to delete is 1 (the head node): DeleteFromFront
    3. Else, Traverse the list until reaching the desired position
        * Initialize prev to keep track of the previous node.
        * Move temp through the list until the position is reached.
        * Check for Valid Position:
        * If temp becomes NULL, it means the position exceeds the number of nodes in the list.
        * If the node to delete is found: Set prev->next to temp->next, effectively skipping over the node to be deleted.
    */

    if (head == nullptr) {
        //list is empty
        return true; //?or false here
    }

    if(pos==1)
    {
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
    }



    // Case 3: Node to be deleted is in middle

    //check if the index is in bound
    if(traverse(pos)==nullptr) return false;

    // previous of node to be deleted
    Node* prev;
    Node* temp = head;
    // Traverse till given position
    for (int i = 1; i != pos; i++) {
        prev = temp;
        temp = temp->link;
    }
    //after this loop, temp->link is the address of the node at the wanted pos
    //if given position is found, delete node
    if (temp!=nullptr)
    {
        prev->link = temp->link;
        delete temp;
        return true;
    }
    else
    {
        return false;
        //pos is out of bounds
    }
    

   /*
   WHY IS THIS WRONG?
   Node* target_node_tobedeleted = traverse(pos);
   Node* previous_node=traverse(pos-1);
   if(target_node_tobedeleted!=nullptr)
   {
    //pos is in range;
    previous_node=target_node_tobedeleted->link;
    delete target_node_tobedeleted;
    return true;

   }
   else
   {
    //pos is not in range
    return false;
   }
   */

}

int LinkedList::get(int pos)
{
    //method that returns pos's Node's data member variable. 
    //If pos is out-of-bounds, it should return std::numeric_limits < int >::max()
    Node* desired_node = traverse(pos);
    //if out of bounds, this pointer is null
    if(desired_node!=nullptr)
    {
        return desired_node->data;
    }
    else
    {
        return std::numeric_limits < int >::max(); //maximum finite value
    }
}

//int search(int target) which searches the list for the first occurrence of target in the list and returns the index of where target is. If target does not exist in the list, return -1.
int LinkedList::search(int target)
{
    /*
    Initialize a node pointer, curr = head.
    Do following while current is not NULL
    If the current value (i.e., curr->key) is equal to the key being searched return true.
    Otherwise, move to the next node (curr = curr->next).
    If the key is not found, return false 
    */

   Node* curr = head;
   unsigned int count =0;
    // Iterate over all the nodes
    while (curr != NULL) 
    {
        count++;
        // If the current node's value is equal to key,
        if (curr->data == target)
            return count;
        // Move to the next node
        curr = curr->link;
    }

    // If there is no node with value as target, return -1
    return -1;

}