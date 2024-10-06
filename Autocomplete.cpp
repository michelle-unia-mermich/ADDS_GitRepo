#include "Autocomplete.h"

/*
void Autocomplete::insert(std::string word)
{
    //traverse using the current pointer which is currentNode
    //set this first pointing to the root of Autocomplete
    Trie* currentNode= this->root;

    //iterate across the length of the string
    for (int i = 0; i<word.length(); i++)
    {
        //*1-Check if the node exits for any stored character in the structure
        //convert to int: find the index in the array of 26 letters. eg. if the char is 'a', index is 0 and so on.        int index= word.at(i) - 'a';
        int index=word.at(i)-'a';
        if(currentNode->childArray[index]==NULL)
        {
            //node for the current character does not exist, make a new node
            Trie* newNode = new Trie();
            //push the newly created node to the structure
            currentNode->childArray[index]=newNode;
        }

        //move the current node pointer to the newly created node
        currentNode= currentNode->childArray[index];
    }
}
*/
