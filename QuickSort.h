#include "Sort.h"

#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort: Sort
{
    public:
        std::vector<int> sort(std::vector<int> list) override;
        //std::vector<int> sortAnna(std::vector<int> list);

};

#endif