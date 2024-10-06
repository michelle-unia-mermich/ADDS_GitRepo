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

Autocomplete::Autocomplete()
{
    //root = nullptr;
    //!Why must we initiate root pointer to point to a TrieNode, but not allowing it to be a nullptr? Answer: if it is a nullptr, it does not point to any TrieNode and we have no staring letter of any words.
    /*
    because 
                                            TrieNode* root
                                                    |
                                                    |points to a TrieNode object
                                                    |
                first Trie Node object: has (1) a map that can contains maximum 26 letters (however at one time it only contains the first letter of every word being added to the TrieNode structure) 
                                            (2) a boolean value of whether the word going from root to this node (since this is the first node, first level, the word is itself - the one letter) is a complete word or not
                        The map is like a vector, but instead of having the index as numbers, we can have the index as anything (we call the 'key',in our case up to 26 chars (can be represented as char or string) the node stands for. *Note that one node does not represent one single value, but can represent up to 26 keys of char in the map*) The values are the TrieNode* pointers. 
        |       |       |       |       |       |.......|       |       |       |       |       |
        |       |       |       |       |       |       |       |       |       |       |       |each points to a TrieNode object (max 26 edges here)
        |       |       |       |       |       |       |       |       |       |       |       |    

        The last TrieNode object that has no children (eg. the map does not contain any TrieNode* pointers that point to a TrieNode object) is called a LEAF.

        Let's say we have 3 words, 'be' and 'bet' and 'ball'. All are meaningful words.
        If so then if the root pointer points to the first node (node1) (which is a TrideNode object).
        
        First, add "be" to the trie tree. 
        First, iterate at the char 'b'.
        Since the map of the first node is empty, no key of 'b' is found. 
        Since no key of 'b' is found, add a pair (key,value)=('b',pointer1) to the map. pointer1 points to a new TrieNode object - let call this node2.
        Next, iterate at the char 'e'. Find if the map of node2 has 'e'. If not, add a pair (key,value)=('e',pointer2) to the map of node2. pointer2 points to a new TrieNode object-let call this node3. Since 'be' is a word, the isWord in this object is true.

        Second, add "bet" to the trie tree.
        Iterate at 'b': search if the map of node 1 has 'b'. Yes. Go to the pointer1 that is paired up with 'b' that poitns to node2. Go to node2.
        Iterate at 'e': search if the map of node 2 has 'e'. Yes. Go to the pointer2 that is paired up with 'e' that points to node3. Go to node3.
        Iterate at 't': search if the map of node 3 has 't'. No. Right now the map of node3 is empty, just that isWord of node3 is true. Thus add a new pair ('t',pointer3) to the empty map of node3. pointer3 points to a new TrieNode object node4. Since 'bet' is a word, the isWord of 'bet' is True.

        Third, add "ball" to the trie tree.
        Iterate at 'b': search if the map of node 1 has 'b'. Yes. Go to the pointer1 that is paired up with 'b' that poitns to node2. Go to node2.
        Iterate at 'a': search if the map of node 2 has 'a'. Right now the map of node2 only has 'e'. Thus add a new pair to map ('a':pointer2a). pointer 2a points to another node, node3a. Go to node3a.
        Iterate at 'l': search of the map of node 3a has 'l'. No. Add a pair of ('l':pointer4a) to the map of node3a. Go to the TrieNode object that pointer4a points to.
        Iterate at 'l': And so on.

        the node object that has an empty map (thus has no children) and has isWord set to True is a leaf. 
        ?Is this correct? or the node before this the leaf? But we know the leaf is the node that has no children, so it must be the TrieNode object that contains no TrieNode* pointers pointing to any other objects.

        To see exactly how the Trie Structure works and how insertion in Trie works, see: https://www.youtube.com/watch?v=AXjmTQ8LEoI&ab_channel=TusharRoy-CodingMadeSimple


    */
    root = new TrieNode();

}

TrieNode* Autocomplete::tryGetToAWord(std::string prefix, std::string& travelledUntil, std::vector<std::string>& parentWork)
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

void Autocomplete::insert(std::string word)
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
void Autocomplete::searchAllWordsBelowAPrefix(TrieNode* node, std::string prefix, std::vector<std::string>&results)
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

void Autocomplete::searchAllWordsForPrefix(std::string prefix,std::vector<std::string>&results )
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

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord)
{
    //return the known words that start with partialWord
    std::vector<std::string> returnVector;
    searchAllWordsForPrefix(partialWord,returnVector);
    return returnVector;

}