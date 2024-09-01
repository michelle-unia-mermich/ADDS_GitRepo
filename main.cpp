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
    //!Question: should the users key in the number of elements they want to be in the array?
    //!or will they continue typing in until they use a specific key to end the typing of input values?

    std::cout<<"Key in number of elements in the array, then key in the elements: ";
    int n;
    std::cin>>n;
    
    std::vector<int> input;
    for(int i=0;i<n;i++)
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