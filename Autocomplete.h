#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

class Autocomplete //is a Trie Node in the Trie data structure
{
    //pointer array to (potential) 26 child nodes representing letters
    Autocomplete* child[26];
    
    //is the ending of a word or not
    bool isWord;

    Autocomplete()
    {
        //isWord is false
        //every child node in the "child" array to NULL
        isWord=false;
        for(int i=0;i<26;i++)
        {
            child[i]=nullptr; //is a nullptr
        }

    }

};
#endif