#include "question2.h"
#include <iostream>
#include <time.h>  

int main()
{
    /* initialize random seed: */
    srand (time(NULL));

    BagOfHolding bag;
    bag.addItem("A");
    bag.addItem("B");
    bag.addItem("C");

    //printing element from the bag
    std::vector<std::string> vector = bag.getItems();
    for(auto string: vector)
    {
        std::cout<< string<< " ";
    }
    std::cout<<std::endl;

    


    return 0;
}