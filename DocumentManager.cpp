#include "DocumentManager.h"

void DocumentManager::addDocument(std::string docName, int docid, int license_limit)
{
    //add a new key and an empty std::vector<Patron> to docID_PatronObj
    std::vector<int> emptyIntlist={};
    docID_PatronID.insert({docid, emptyIntlist});

    //add a new document to docID_docName (to save time using search if we do search on existingDocuments vector of the Document objects)
    docID_docName.insert({docid,docName});
    
    //add a new document objects
    existingDocuments.push_back(Document(docName,docid,license_limit));
}

 void DocumentManager::addPatron(int patronID)
 {
    existingPatronID.push_back(patronID);
 }

 int DocumentManager::search(std::string name)
 {
    //method 1- search in the keys of the un_map docID_PatronID, go through the document names of all the docID indexes of the un_map, check whether there is a document name with input `name` (too long)
    //method 2- search in un_map docID_docName: search whether an unordered_map contains a value with this name (faster than method 3)
    //method 3- search in vector existingDocuments to check whether there is this name

    //!for method 2, it's only fast to check if a map contains a cetain key, not when the map contains a certain value
    
    //method 3:
    for (auto document: existingDocuments)
    {
        if ((document.document_name)==name)
        {
            return document.docid;
        }
    }
    return 0;

 }

 bool DocumentManager::borrowDocument(int docid, int patronID)
 {
    //Part 1: only allow borrowing if patronID is inside the saved vector
    //*LEARN: how to check whether a vector contains an element
    if(std::find(existingPatronID.begin(), existingPatronID.end(), patronID) != existingPatronID.end()) 
    {
        /* existingPatronID contains patronID */
        for (auto& map_pair : docID_PatronID)
        {
            
            //*LEARN: how to traverse through an unordered_map
            if ((map_pair.first)==docid)
            {   
                int license_limit =0;
                //find and then compare with the license_limit of this docid
                for (auto document:existingDocuments )
                {
                    if (document.docid==docid)
                    {
                        license_limit = document.license_limit;
                        break;
                    }
                }
                if (map_pair.second.size()<license_limit)
                {
                    //add patronID to the vector if the limit for this document has not been reached
                    map_pair.second.push_back(patronID);
                    //make sure that we push back to the vector in this->docID_PatronID not the shallow copy of map_pair
                    return true;
                }
                break;
            }
        }

    } 
    return false;
 }

 // Function to find the index of an element in a vector
int getIndex(std::vector<int> v, int K)
{
    auto it = std::find(v.begin(), v.end(), K);
    // If element was found
    if (it != v.end()) 
    {
    
        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

 void DocumentManager::returnDocument(int docid, int patronID)
 {
    //note: in the getIndex function, we use: std::find is an STL function that is used to find a particular element in the given range. It returns an iterator to the first occurrence of the given element in the range
    //therefore, each returnDocument function only removes 1 occurence
    //ef. if the personID 100 borrows document 2 2 times, the return Document only removes 1 time of borrowing.
    //however we assume each patron only borrows 1 copy of a document.
    bool isPatronID_in_existingPatronID = std::find(existingPatronID.begin(), existingPatronID.end(), patronID) != existingPatronID.end() ;
    if(isPatronID_in_existingPatronID) 
    {
        /* existingPatronID contains patronID */
        for (auto& map_pair : docID_PatronID)
        {
            //if map_pair key is the doc id and the vector of this value conatins the patronID
            if ((map_pair.first==docid))
            {   
                bool isPatronID_in_vectorOfDocid=(std::find(map_pair.second.begin(), map_pair.second.end(), patronID) != existingPatronID.end());
                if (isPatronID_in_vectorOfDocid)
                {
                    //remove the patronID from the this vector
                    //*LEARN: how to remove a certain value from a vector
                    //find the index of this element
                    int index = getIndex(map_pair.second,patronID);
                    //note if  isPatronID_in_vectorOfDocid is true and index is also different from -1
                    //erase the element at this index
                    if(index!=-1)
                    {
                        map_pair.second.erase(map_pair.second.begin()+index); 

                    }
                    else
                    {
                        std::cout<<"ERROR, index has to be different from -1 but is -1."<<std::endl;
                    }
                }
                break;

            }
        }

    } 
 }