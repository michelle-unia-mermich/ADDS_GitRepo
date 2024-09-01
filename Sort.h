#include <iostream>
#include <vector>

#ifndef SORT_H
#define SORT_H

class Sort
{
    public:
        virtual std::vector<int> sort(std::vector<int> list)=0;

};

#endif