#include "Reverser.h"
#include <cmath>

int Reverser::reverseDigit( int value)
{ 
    //takes in a non-negative int value and reverses the digits using recursion. reverseDigit() should return -1 when invalid input is given. 
    if (value >=0)
    {
        int remaining_length_ofdigits = ((int) log10(value) ) +1 ;
        //The number of digits of a positive integer n written in base 10 is ⌊log10n⌋+1. cast (int) will round down

        if (remaining_length_ofdigits==1) //base case, if value is only one digit
        {
            return value;
        }
        else
        {
            //eg. value is 54321
            int last_digit = value%10; //last_digit is 1

            value = (value - last_digit)/10;
            //value is the remaining number eg. value is now 5432
            return ( last_digit*pow(10,(remaining_length_ofdigits-1)) + reverseDigit(value) );
        }
    }
    else
    {
        return -1;
    }
}

std::string Reverser::reverseString(std::string characters)
{ 
    // function takes in a std::string and returns the reversed string. reverseString() should return “ERROR” when invalid input is given
    //!How to check for invalid input
    int length_remainingstring = characters.length();
    if (length_remainingstring==1)
    {
        //base class
        return characters;
    }
    else
    {
        //eg. "abc", length=3
        /*
        string substr (size_t pos = 0, size_t len = npos) const;
        - pos: Position of the first character to be copied as a substring.
        - len: Number of characters to include in the substring (if the string is shorter, as many characters as possible are used).
        */
        //get the last char of the string
        std::string last_char =  characters.substr(length_remainingstring-1,1);
        //get the remaining portion of the string from beginning to second last char
        characters = characters.substr(0,length_remainingstring-1);
        //concatenate two string
        return last_char + reverseString(characters);

    }

}