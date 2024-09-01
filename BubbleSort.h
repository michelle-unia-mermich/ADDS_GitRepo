#include "Sort.h"

#ifndef SORTBUBBLE_H
#define SORTBUBBLE_H

class BubbleSort: Sort
{
    public:
        std::vector<int> sort(std::vector<int> list) override;

};

#endif