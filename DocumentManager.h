#ifndef DocumentManager_h
#define DocumentManager_h

//use any of the library containers or algorithms

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>

#include "Document.h"

#include <vector>

/*
        Data structures that are efficient in (1) inserting a new one (2) searching
            - when we are searching for an object with a particular index, and the indexes do not need an order => Use an unordered_map
        Unordered map: every efficient for insertion, deletion, searching/access an element and modification
            - insertion: O(1)
            - deletion: O(1)
            - searching/access an element and modificationL O(1)

*/

class DocumentManager 
{
    private:
        std::unordered_map<int, std::vector<int> > docID_PatronID;
        std::vector<int> existingPatronID; 
        std::vector<Document> existingDocuments; 

        std::unordered_map<int,std::string> docID_docName; //this is to improve the speed of search document function, even though we can still search document in std::vector<Document> existingDocuments;

    public:

        void addDocument(std::string docName, int docid, int license_limit);

        void addPatron(int patronID);

        int search(std::string name);   // returns docid if name is in the document collection or 0 if the name is not in the collection

        bool borrowDocument(int docid, int patronID); 
        // returns true if document is borrowed, 
        //false if it can not be borrowed (invalid patronid or the number of 
        //copies current borrowed has reached the license limit)

        void returnDocument(int docid, int patronID);
    
};

#endif 
