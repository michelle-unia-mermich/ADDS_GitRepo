#ifndef TRIENODE_H
#define TRIENODE_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

class TrieNode //is a Trie Node in the Trie data structure
{
    private:
        

    public:

        //pointer array to (potential) 26 child nodes representing letters
        //Trie* childArray = new Trie[26];
        
        //std::string data; //is optional because we store data in the map

        std::unordered_map<std::string, TrieNode*> childrenMap;
        //Can also do this as <char, TrieNode*> instead of string (we can add a char to string later); however, there are some consequences (see to it later)
        //better way is to use unordered_map: we don't have to specify 26 characters at all

        //is the ending of a word or not
        bool isWord;

        TrieNode();

};
#endif