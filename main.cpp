#include "DocumentManager.h"
#include <iostream>

int main()
{
    DocumentManager docMag;

    docMag.addDocument("Document1",1,3);
    docMag.addDocument("Document2",2,4);
    docMag.addDocument("Document3",3,2);
    docMag.addDocument("Document4",4,1);

    docMag.addPatron(100);
    docMag.addPatron(101);
    docMag.addPatron(102);

    docMag.borrowDocument(2, 100); 
    docMag.borrowDocument(3, 101); 
    docMag.borrowDocument(4, 102); 

    docMag.returnDocument(2, 100); 
    docMag.returnDocument(4, 102);


}