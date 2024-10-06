#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include "TrieNode.h"

class PrefixMatcher //is a Trie Node in the Trie data structure
{
    private:
       TrieNode* root; //a pointer pointing to a Trie node (the root)
       std::unordered_map<std::string,int> routerAddress;

    public:
        PrefixMatcher()
        {
            root = new TrieNode();

        }

        TrieNode* tryGetToAWord(std::string prefix, std::string& travelledUntil, std::vector<std::string>& parentWork)
        {
            //try to get to that word. if cannot get to that word, return the best closely matched prefix
            //want to return 3 things, that's why using &
            //2nd parameter: the longest prefix that it could traverse to and can be seen in the tree
            //3rd parameter: store all the meaningful words encountered on the way
            TrieNode* curr = root;
            for(char& c: prefix)
            {
                std::string nodeValue(1,c);
                auto child = curr->childrenMap.find(nodeValue); //using the find function of unordered map
                
                if(child == curr->childrenMap.end())
                {
                    //alr reached the end of the container(the map) and have not found it
                    break;
                }
                else{
                    //the char is found in the childrenMap. Add this char to the string travelledUntil.
                    travelledUntil+=nodeValue;

                    //the find function of unorderd_map gives us a pair: key and value
                    //how to access the key: child->first; the value: child->second
                    curr = child->second;

                    //now we have found the child, check if it is a word. if it is, add to the parentWork vector
                    if(curr->isWord)
                    {
                        parentWork.push_back(travelledUntil);
                    }
                }
            }
            return curr; //which is the node pointing to the best possible string

            /*
            A few things to note regarding this function:
            *1- 
                In function: void searchAllWordsForPrefix(std::string prefix,std::vector<std::string>&results)
                If the word prefix is found in the tree, then traversedUntil(the best possible string that exists in the tree while searching for prefix)=prefix 
            
            *2- Find the longest meaningful word in the three that has the longest matching prefix of an input word.

                Example 1: 
                * find the Router with the 'longest matching prefix' ie the network address that has the most bits in common with the packet destination.*
                For example, we might have several routers whose Internet network addresses are:
                1100110111     Router 1 (consisder a meaningful word)
                110011011       Router 2 (consisder a meaningful word)
                11001101         Router 3 (consisder a meaningful word)
                the incoming packet destination address might be: 110011011001, in this case we would map it to the longest matching prefix and return Router 2.
                in This case all letters of router2 are contained in the input word, but there might be case where not all letters of router2 are contained in the input word
                , but router 2 just has the longest matching prefix.
                
                Example 2:
                5 words exist in the tree:
                Option 1: abcdkmhie
                Option 2: abcdehmn
                Option 3: abcghyi
                Optin 4: abc
                Option 5: abcd
                input word: abcdefg
                If so, then node = tryGetToAWord("abcdefg", travelledUntil, parentWork) will have:
                    parentWork will only contains meaningful words in the tree that we traverse to, so those words are fully contained in the word. -> abc and abcd
                    travelledUntil is Option2: abcdehmn

            */
        } 

        void insert(std::string word) 
        {
            //rationale: keep on traversing. if cannot traverse anymore, create new node
            TrieNode* curr = root;
            for(char&c: word) //&here: if not used &, char is a pointer to char. If we put &, we have converted it to a char.
            {
                std::string nodeValue(1,c); //a method to convert character to string.
                auto child = curr->childrenMap.find(nodeValue);
                if(child == curr->childrenMap.end())
                {
                    //it has gone through the entire map but the child does not exist, so we cannot navigate to it. we willl create it
                    //to create, need to provide a (key,value) pair
                    TrieNode* newPointer = new TrieNode();
                    curr->childrenMap.insert({nodeValue, newPointer});
                    curr=newPointer;
                }
                else
                {
                    curr=child->second;
                }
                
            }
            curr->isWord=true;
        }

        void searchAllWordsBelowAPrefix(TrieNode* node, std::string prefix, std::vector<std::string>&results)
        {
            //need & to do recursion
            //nodeRef is the pointing points to the last letter of the prefix, and we start finding all the words below this node in the Trie tree
            //DFS algorithm: to navigate through every node
            /*
            Description
            - node: the not pointing to the last latter of the prefix
            */

           //base case: if the node indicates a word, it is a word and thus add to results vector
           if(node->isWord)
           {
            results.push_back(prefix);
           }
           //so we don't have to limit the map length/ or specify the length of 26 at anywhere? Answer: yes
           
           //to look for all the words below a prefix, 
           for (auto it=node->childrenMap.begin(); it!=node->childrenMap.end();it++)
           {
                searchAllWordsBelowAPrefix(it->second, prefix+(it->first), results);//the same results as the parameter input in the function
                //* 1st parameter: since it->second is the pointer pointing to the children
                //*2 2nd parameter: update the prefix. In the child, the prefix is the previous prefix + the child value.
           }
        }

        void searchAllWordsForPrefix(std::string prefix,std::vector<std::string>&results )
        {
            //1-Navigate to the word, and check if navigation is succesful (found or not)
            std::string traversedUntil = "";
            std::vector<std::string> parentWords;
            TrieNode* node= tryGetToAWord(prefix,traversedUntil,parentWords);
            
            //if the partialWord/prefix is found in the tree: then traversedUntil=prefix
            if (traversedUntil==prefix)
            {
                searchAllWordsBelowAPrefix(node,prefix,results);
            }
        }
        
       
        std::string findLongestPrefixMatchingString(std::string word)
        {
            /*
            Description of this function: find the longest matching string 
            (the last meaningful word (since it is the last as we traverse down the tree, the string is longer) in parentWords when 
            searching the input "word" in function tryGetToAWord(word,traversedUntil,parentWords))

            For example, we might have several routers whose Internet network addresses are:
            1100110111     Router 1 (consisder a meaningful word)
            110011011       Router 2 (consisder a meaningful word)
            11001101         Router 3 (consisder a meaningful word)
            the incoming packet destination address might be: 110011011001, in this case we would map it to the longest matching prefix and return Router 2. 

            */
            std::string traversedUntil = "";
            std::vector<std::string> parentWords;
            //don't have to get back the Node, so no need to save
            tryGetToAWord(word,traversedUntil,parentWords);
            //if asked to return longest prefix, will return traversedUntil
            //however we are asked to return longest prefix which is a word, so we return the last element of the parentWords
            return parentWords.back();
        }

        void insert(std::string address, int routerNumber) // add a router address
        {
            insert(address);
            routerAddress.insert({address,routerNumber});
        }

        int selectRouter(std::string networkAddress)  // return the router with the longest matching prefix
        {
            std::string resultAdress= findLongestPrefixMatchingString(networkAddress);
            auto findPointer = routerAddress.find(resultAdress);
            int routerNumber = findPointer->second;
            return routerNumber;
        }


};
#endif