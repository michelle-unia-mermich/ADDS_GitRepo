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
    bag.addItem("D");

    //printing element from the bag
    std::vector<std::string> vector = bag.getItems();
    for(auto string: vector)
    {
        std::cout<< string<< " ";
    }
    std::cout<<std::endl;

    std::cout<<bag.removeItem("A")<<
    std::cout<<bag.remove(0);
    std::cout<<bag.remove();

    //printing element from the bag
    std::vector<std::string> vector2 = bag.getItems();
    for(auto string: vector2)
    {
        std::cout<< string<< " ";
    }
    std::cout<<std::endl;




    return 0;
}