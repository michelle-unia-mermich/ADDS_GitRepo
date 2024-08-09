#include <iostream>

#include "Truckloads.h"
#include "TruckloadsTest.h"

#include "Reverser.h"

int main()
{
    TruckloadTest truckload_test_obj; 
    truckload_test_obj.run_test(0);
    truckload_test_obj.run_test(1);
    truckload_test_obj.run_test(2);

    Reverser reverser;
    std::cout<<reverser.reverseDigit(54321) << std::endl;
    std::cout<<reverser.reverseString("abc") << std::endl;
    std::cout<<reverser.reverseString("abdefg") << std::endl;

    
    return 0;
}