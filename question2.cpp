#include "question2.h"
#include <iostream>
#include <string>
#include <vector>

BagOfHolding::BagOfHolding()
{

}

BagOfHolding::~BagOfHolding()
{

}

std::vector<std::string> BagOfHolding::getItems() 
{
    return itemList;
}
//return all items in the bag

void BagOfHolding::addItem(std::string item)
{
    //add an item in the bag
    itemList.push_back(item);
}

std::string BagOfHolding::removeItem(std::string item)
{
    //remove a specific item value from the bag
    // erase the 6th element
    std::string result = "";
    if(!itemList.empty())
    {
        for(int i=0;i< itemList.size();i++)
        {
            if(itemList.at(i)==item)
            {
                result=itemList.at(i);
                itemList.erase(itemList.begin()+i);
            }
        }
    }
    return result;
}


std::string BagOfHolding::remove(int index)
{
    //remove a item at specific index from the bag
    std::string result = "";
    if((index>=0)&&(index<=itemList.size()))
    {
        result=itemList.at(index);
        itemList.erase(itemList.begin()+index);
    }
    return result;
}


std::string BagOfHolding::remove()
{
    //removes a item randomly from the bag
    std::string result = "";
    int randIndex=rand() % itemList.size(); 
    result=itemList.at(randIndex); 
    itemList.erase(itemList.begin()+randIndex);  
    return result;
} 


