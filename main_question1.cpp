#include <iostream>
#include <math.h>    
#include <vector> 

int main()
{
    int d=4; //1 1+2 1+2+2
    int r=-5; //1 1*3 1*3*3
    int n=6;
    std::cout <<arithmetic(d,n)<<std::endl;

    //printing out elements of question1
    std::vector<int> vector = question1(d, r, n);
    for (auto& number: vector)
    {
        std::cout <<number << " ";
    }
    std::cout<< std::endl;
    return 0;
}

