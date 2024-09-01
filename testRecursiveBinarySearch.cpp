#include "RecursiveBinarySearch.h"
#include "QuickSort.h"
#include <iostream>
#include <string>

int main()
{
    std::vector<int> input;
    input.push_back(-1);
    input.push_back(3);
    input.push_back(5);
    input.push_back(4);
    input.push_back(-5);
    input.push_back(100);
    input.push_back(7777);
    input.push_back(2014);
    QuickSort quicksort;
    std::vector<int> sorted_vect = quicksort.sort(input);
    std::cout<<"The original vector is: "<<std::endl;
    for(auto element: input)
    {
        std::cout<< element<< " ";
    }
    std::cout << std::endl;
    std::cout<<"The sorted vector is: "<<std::endl;
    for(auto element: sorted_vect)
    {
        std::cout<< element<< " ";
    }
    std::cout << std::endl;
    
    
    RecursiveBinarySearch recursiveBinarySearch;
    
    std::string answer = recursiveBinarySearch.search(sorted_vect,1) ? "true" : "false";
 
    std::cout<<"Whether the vector has 1 or not is: "<<answer<< std::endl;
    
    
    return 0;
}