#include <iostream>
#include <string>
#include <vector>

#ifndef BAGOFHOLDING_H
#define BAGOFHOLDING_H

class BagOfHolding
{
    private:
        std::vector<std::string> itemList;

    public:
        BagOfHolding();

	    std::vector <std::string> getItems(); //getter function: return all items in the bag

        void addItem(std::string item); //add an item in the bag

        std::string removeItem(std::string item); //remove a specific item value from the bag

        std::string remove(int index); //remove a item at specific index from the bag

        std::string remove(); //removes a item randomly from the bag

        ~BagOfHolding();

};
#endif