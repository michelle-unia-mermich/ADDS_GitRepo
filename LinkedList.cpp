#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

int LinkedList::search(int target)
{
	//search for the target and return the position from 0 to n-1
	unsigned int index=0;
	Node* currNode=head;
	while(currNode!=nullptr)
	{
		if((currNode->print_data())==target)
		{
			return index;
		}
		index++;
		currNode = currNode->print_link();
	}
	//if the target is not found at all, return -1
	return -1;
}

Node* LinkedList::traverse(int pos)
{
    unsigned int position = 0; //starting position

    Node* currNode = head; //currNode is the current-traversed-node

    if(pos<0) //checking for out-of-bound index
    {
        return nullptr;
    }

    while (currNode != nullptr && position < pos) { 
        currNode = currNode->link; 
        position++;
        //if currNode==nullptr and position is still < index but not equal index, index is out of range
        if(currNode == nullptr && position < pos)
        {
            return nullptr;
        }

    }

    //else if index is out of bounds
    return currNode; 
}


/////////// your code goes here... DO NOT change the function signatures ///////////

bool LinkedList::swap(int pos1, int pos2) 
{
	Node* node1 = this->traverse(pos1);
	Node* node2 = this->traverse(pos2);
	if ((node1!=nullptr)&&(node2!=nullptr))
	{
		
		//swap 
		int data_node1 = node1->print_data();
		node1->change_data(node2->print_data());
		//now both have node 2 data
		node2->change_data(data_node1);
		

		//std::cout<<node2->print_data()<<" "<<node1->print_data()<<std::endl;
		
		return true;
	}
	else
	{
		//return false without swapping any elements
		return false;

	}

}

bool LinkedList::find_and_delete(int target) 
{
	//searches the list for a node containing target
	//which then deletes it and returns true
	//If target appears multiple times in the list, delete the first occurrence.
	//If target does not exist in the list return false.

	//if the list is empty, the target cannot be found, so return false
	if(head==nullptr)
	{
		return false;
	}
	int pos = this->search(target);
	if(pos>=0)
	{
		//if position is at the front, delete from front
		if(pos==0){
			this->deleteFront();
			return true;
		}
		//if not, check if the index is in bound
		if(this->traverse(pos)==nullptr) return false;

		// previous of node to be deleted
		Node* prev;
		Node* temp = head;
		// Traverse till given position
		for (int i = 0; i != pos; i++) {
			prev = temp; //i=0, prev is the head (node 0); i=1: prev 
			temp = temp->link;//i=0, temp is node 1; i=1, temp is node 2, i=pos-1, temp is node pos
		}
		//after this loop, temp->link is the address of the next node to out to-be-delete node
		//if given position is found, delete node
		if (temp!=nullptr)
		{
			prev->link = temp->link;
			delete temp;
			return true;
		}
		else
		{
			//temp is nullptr, which is wrong
			return false;
			//pos is out of bounds
		}

	}
	else
	{
		return false;
	}

}


    

    