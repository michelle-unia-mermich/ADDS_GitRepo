#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize)
{
    if (numCrates<=loadSize)
    {
        return 1;
    }
    else
    {
        //divide into two portion
        //1-portion 1: the quotient of numCrates with 2 and the remainder (the odd part when an odd number is divided by 2)
        int portion_one = numTrucks(numCrates/2 + numCrates%2, loadSize);
        //2-portion 2: the even half part
        int portion_two = numTrucks(numCrates/2, loadSize);
        return  portion_one + portion_two;
    }
}

/*
int Truckloads::numTrucks_withconditions(int numCrates, int loadSize)
{
    //!Cannot define another function in a class function. Can move this function numTrucks_noConditions outside
    //int numTrucks_noConditions(int numCrates, int loadSize) {}

    if ((numCrates>=2)&&(numCrates<=10000)&&(loadSize>=1)&&(loadSize<=(numCrates-1))) //no need to check
    {
        return  numTrucks_noConditions( int numCrates, int loadSize);
    }
    else
    {
        //requirements not met
        //undefined behaviour
        return 0; //can we return nothing and quit the function?
    }
}
*/