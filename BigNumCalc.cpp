#include "BigNumCalc.h"

std::list<int> bigNumCalc::buildBigNum(std::string numString)
{
    std::list<int> l = {};
    int length=numString.length();
    for(int i=0; i<length ; i++)
    {
        //*REMEMBER TO CONVERT CHAR TO INT HAVE TO MINUS 48 
        l.push_back( ((int)((char)numString[i])-48) );
    }
    return l;
}