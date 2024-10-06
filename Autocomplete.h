#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "TrieNode.h"

class Autocomplete //is a Trie Node in the Trie data structure
{
    private:
       TrieNode* root; //a pointer pointing to a Trie node (the root)

    public:
        Autocomplete();
        TrieNode* tryGetToAWord(std::string prefix, std::string& travelledUntil, std::vector<std::string>& parentWork);
        void insert(std::string word);
        void searchAllWordsBelowAPrefix(TrieNode* node, std::string prefix, std::vector<std::string>&results);
        void searchAllWordsForPrefix(std::string prefix,std::vector<std::string>&results );
        std::vector<std::string> getSuggestions(std::string partialWord);
         //Note that usually for a Node programm, we need to ensure (1) extraction (searching, or searching and deleting, or searching something and return something), (2) insertion, (3) traversal: all 3 things must be meaningful and efficient first before doing other functions

};
#endif