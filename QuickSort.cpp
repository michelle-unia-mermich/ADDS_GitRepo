#include "QuickSort.h"

/*

void swap(int& a, int & b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int partition(std::vector<int> &vec, int low, int high) {

    // Selecting the last element as the pivot
    int pivot = vec[high];

    // Index of element just before the last element, is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec.at(i), vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}
*/

/*

void quicksort(std::vector<int>& array, int start, int end)
{
    //base case
    if (start>=end)
    {
        return;
    }
    //Select the last element as pivot
    int pivot = array.at(end);

    int pivot_index = start;
    for (int i= start; i<end; i++)
    {
        if(array.at(i)<pivot)
        {
            //swap the ith element and element at pivot index
            std::swap(array.at(i),array.at(pivot_index));
        }
    }
    //swap the pivot_index element and pivot
    std::swap(array.at(pivot),array.at(pivot_index));

    //call sort for subarrays
    quicksort(array, start, pivot_index-1);
    quicksort(array, pivot_index+1, end);

}

std::vector<int> QuickSort::sortAnna(std::vector<int> list)
{
    quicksort(list,0,(list.size()-1));
    return list;
}
*/

std::vector<int> QuickSort::sort(std::vector<int> list)
{


    //introducing the base case
    if (list.size()<=1) //! should be <=1 and not ==1, if not there will be an out-of-range error
        return list;

    //even though the pivot can be anything, for this quetion, As a requirement, for the pivot selection, 
    //when the list is of length at least 3, please always chose the third value in the list
    int pivot = 0;
    if (list.size()<3)
    {
         pivot=list.at(list.size()-1);
    }
    else
    {
        pivot=list.at(2);
    }

    std::vector<int> l;
    std::vector<int> e;
    std::vector<int> m;

    for(int item: list)
    {
        if(item<pivot)
            l.push_back(item);
        else if(item==pivot)
            e.push_back(item);
        else
            m.push_back(item);
    }
    l=this->sort(l); //use control+command to select and edit multiple elements at the same time
    m=this->sort(m);

    //concatenate the vectors
    std::vector<int> o;
    for(int item:l) 
    {
        o.push_back(item);
    }
    for(int item:e) o.push_back(item);
    for(int item:m) o.push_back(item);

    return o;
}