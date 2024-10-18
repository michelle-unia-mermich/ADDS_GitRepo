#include "Document.h"

Document::Document(std::string document_name,int docid,int license_limit)
{
    this->document_name=document_name;
    this->docid=docid;
    this->license_limit=license_limit;
}