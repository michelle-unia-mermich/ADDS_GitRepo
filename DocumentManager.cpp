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
    
 }