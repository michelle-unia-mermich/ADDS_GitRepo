//Your task is to create a very simplified big number calculator. You can assume all inputs and results are positive integers.
#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H
#include <iostream>
#include <list>
#include <string>

class bigNumCalc {
public:
    std::list<int> buildBigNum(std::string numString);
    //A method that creates a list representing the provided string. For example, a string "12345" would become a list with elements 1,2,3,4, and 5 respectively.

    std::list<int> add(std::list<int> num1, std::list<int> num2);

    std::string convertbacktoString(std::list<int> num);

    std::list<int> sub(std::list<int> num1, std::list<int> num2);

    std::list<int> mul(std::list<int> num1, std::list<int> num2);
    //For simplicity, you can assume num2 will be only 1 digit long.

};

#endif