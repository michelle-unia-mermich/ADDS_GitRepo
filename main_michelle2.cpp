#include <iostream>
#include "BigNumCalc.h"

int main()
{
    bigNumCalc bigNumCalc_obj;
    std::list<int> l = bigNumCalc_obj.buildBigNum("12345");
    //iterate through
    for(auto i: l)
    {
        std::cout<<i<<" ";
    }
    

    return 0;
}