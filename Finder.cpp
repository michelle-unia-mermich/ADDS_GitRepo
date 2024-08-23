#include "Finder.h"

    using namespace std;

    //purpose of the findSubstrings function: to return a vector that outputs the FIRST occurence index in s1 where each prefix of s2 is found. 
    //If size of s2 is m, there are m prefixes of s2 to be found.
    //Logic
    //1- If the smaller prefix is not found, the larger is not found either
    //2 - prefix 1 is found, finding prefix 2 starts from the position/indexes of prefix 1; and finding prefix 3 starts from the indices of prefix 2

    //However, in C++ there is no easy function to find all indices of occurence of a substring in a long string
    //So the logic will be
    //1- Find the first index of occurence of a smaller prefix
    //2- For the next larger prefix, start from the first index of occurence of the smaller prefix. If the larger prefix is not found, go to the next first instance of the larger prefix
    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result(s2.size(),-1);
        //we can put in an array because we know how many indices will be added to it
        size_t found = 0;

        for(size_t i = 0; i <= (s2.size()-1); i++) 
        {
            size_t found = s1.find(s2.substr(0, i+1),found); //find function returns the index in s1 where substr(0, i) is first found
            //another way: size_t found = s1.find(s2.substr(0, i),found);
            if (found != string::npos) {
                //no need to do push back
                result.at(i)=found;
            } else {
                break; //break out from the for loop
            }
        }
        return result;
    }

   