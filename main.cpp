#include "RecursiveBinarySearch.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include <iostream>
#include <string>

int main()
{
    BubbleSort bubblesort;
    QuickSort quicksort;
    RecursiveBinarySearch recursiveBinarySearch;

    //Create a main function that takes in a list of integers (one line, separated by space) int1 int2 int3 ... intn.
    //!Question: how to type inputs in one line that terminates when the user presses enter? is my way the right way - to detect the enter key?

    std::vector<int> input;
    while (std::cin.get() != '\n')
    {
        int temporary_element;
        std::cin>>temporary_element;
        input.push_back(temporary_element);
    }
    std::cout << std::endl;
    
    std::vector<int> sorted_vect = quicksort.sort(input);
    std::string answer = recursiveBinarySearch.search(sorted_vect,1) ? "true" : "false";
    std::cout<<answer<< " "; //printing the answer true or false
    for(auto element: sorted_vect)
    {
        std::cout<< element<< " ";
    }
    std::cout << std::endl;
    
    
    
    

    
    
    return 0;
}