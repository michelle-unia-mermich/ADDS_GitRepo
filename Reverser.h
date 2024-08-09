#ifndef REVERSER_H
#define REVERSER_H
#include <iostream>
#include <string>

class Reverser
{
    protected:

    public:
        int reverseDigit( int value); //takes in a non-negative int value and reverses the digits using recursion. reverseDigit() should return -1 when invalid input is given. 
        std::string reverseString(std::string characters); // function takes in a std::string and returns the reversed string. reverseString() should return “ERROR” 

};
#endif
