#include "BubbleSort.h"
#include "QuickSort.h"
#include <iostream>

int main()
{
    std::vector<int> input1;
    input1.push_back(2);
    input1.push_back(3);
    input1.push_back(1);

    BubbleSort bubblesort;
    std::vector<int> result1 = bubblesort.sort(input1);
    for(auto element: result1)
    {
        std::cout<< element<< " ";
    }

    std::vector<int> input2;
    input2.push_back(1);
    input2.push_back(3);
    input2.push_back(5);
    input2.push_back(4);
    input2.push_back(-5);
    input2.push_back(100);
    input2.push_back(7777);
    input2.push_back(2014);

    std::vector<int> result3 = bubblesort.sort(input2);
    for(auto element: result3)
    {
        std::cout<< element<< " ";
    }


    return 0;
}