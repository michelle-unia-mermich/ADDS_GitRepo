#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include "TrieNode.h"

class PrefixMatcher //is a Trie Node in the Trie data structure
{
    private:
       TrieNode* root; //a pointer pointing to a Trie node (the root)
       std::unordered_map<std::string,int> routerAddress;

    public:
        PrefixMatcher();
        TrieNode* tryGetToAWord(std::string prefix, std::string& travelledUntil, std::vector<std::string>& parentWork);
        void insert(std::string word) ;
        void searchAllWordsBelowAPrefix(TrieNode* node, std::string prefix, std::vector<std::string>&results);
        void searchAllWordsForPrefix(std::string prefix,std::vector<std::string>&results );
        std::string findLongestPrefixMatchingString(std::string word);
        void insert(std::string address, int routerNumber);
        int selectRouter(std::string networkAddress);
        
};
#endif