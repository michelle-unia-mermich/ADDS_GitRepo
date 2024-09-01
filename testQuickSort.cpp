#include "BubbleSort.h"
#include "QuickSort.h"
#include <iostream>

int main()
{
    std::vector<int> input1;
    input1.push_back(2);
    input1.push_back(3);
    input1.push_back(1);

    QuickSort quicksort;
    std::vector<int> result2 = quicksort.sort(input1);
    for(auto element: result2)
    {
        std::cout<< element<< " ";
    }
    std::cout << std::endl;

    std::vector<int> input2;
    input2.push_back(1);
    input2.push_back(3);
    input2.push_back(5);
    input2.push_back(4);
    input2.push_back(-5);
    input2.push_back(100);
    input2.push_back(7777);
    input2.push_back(2014);

    std::vector<int> result4 = quicksort.sort(input2);
    for(auto element: result4)
    {
        std::cout<< element<< " ";
    }
    std::cout << std::endl;
    
    return 0;
}