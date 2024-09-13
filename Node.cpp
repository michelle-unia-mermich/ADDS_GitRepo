#include "Node.h"

Node::Node(int data, Node* link) {
    this->data = data;
    this->link = link;
}

int Node::print_data()
{
    return data;
}

Node* Node::print_link()
{
    return link;
}

void Node::change_data(int new_data)
{
    this->data=new_data;
}
