#ifndef Document_h
#define Document_h

#include <iostream>
#include <string>

class Document
{
    public:
        std::string document_name;
        int docid;
        int license_limit;

        Document(std::string document_name,int docid,int license_limit);
    
};

#endif 
