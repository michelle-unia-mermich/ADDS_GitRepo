#include "Finder.h"
#include <iostream>
#include <time.h>  



int main()
{
    clock_t  start, end; 
     
    
    Finder finder;
    std::string s1 = "4634554567";
    std::string s2 = "45689";

    start = clock(); 
    // program runs here
    std::vector<int> result = finder.findSubstrings(s1,s2);
    end = clock(); 
    double dblTime = ((double)(end - start)) / CLOCKS_PER_SEC; 

    //Print out the elements in vectorfor (auto element in result)
    std:: cout<< "The elements of the vector are: "<< std::endl;
    for (auto i : result)
    {
        std::cout << i << " ";
    }
    std::cout<< std::endl;

    
     
    // How long it took to run? 
    
    std:: cout<< "The time it took for the program to run is: "<< dblTime << std::endl;

    return 0;
}