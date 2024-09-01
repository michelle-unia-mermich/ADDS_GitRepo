#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list)
{
    //!Question 1: No need to pass by reference here? Ans: Yes
    for (int i=list.size()-1; i>0; i--) //!Question 2: should not pass i>1, but i>0 or i>=1
    {
        for (int j=0; j<i; j++)
        {
            if (list.at(j)>list.at(j+1))
            {
                //swap the 2 elements
                int temporary=list.at(j);
                list.at(j)=list.at(j+1);
                list.at(j+1)=temporary;
            }
        }
    }
    //since this is not passed by references, list outside the function is not affected
    return list;
}