#ifndef FINDER_H
#define FINDER_H
#include <iostream>
#include <string>
#include <vector>
#include <chrono>


class Finder {
    
    public:
        std::vector<int> findSubstrings(std::string s1, std::string s2);

        std::vector<int> findSubstrings_1(std::string s1, std::string s2);
};

#endif