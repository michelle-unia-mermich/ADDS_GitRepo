//Testing Heap
#include "Heap_v1_myversion.tpp"
#include <iostream>

int main()
{
    {

    std::cout<<"==============Part 1: test building heap from a vector ============== "<<std::endl;

    Heap<int> heap = Heap<int>(); //or simply Heap<int> heap;
    std::vector<int> vector1 = {10,9,8,7,6,5,4,3,2,1};
    /*
    Original Heap:
                  10
                /   \
               9     8
              / \   / \
             7   6  5  4
            / \ /
           3  2 1
    Final Correct Heap:
                  1
                /   \
               2     4
              / \   / \
             3   6  5  8
            / \ /
           10 7 9 
    * Important concept: in the heap, the rest of the vector might not be thoroughly sorted, but the first element is always the minimum (for min heap)
    */

    heap.printVector(vector1);
    heap.heapify_lecturerVer(vector1);
    std::cout<<"The heap created by function heapify_lecturerVer: "<<std::endl;
    heap.printHeap(); 
    //why is the heapify function from the lecturers wrong?
    /*
    Because when we call heapifyDown(node with value 6); the minValudChildIndex is of the null-node 
    minValueChildIndex does not take the value of 1 so 1 is not compared with 6.
    so no swapping happens.
    *updated original file Heap.tpp: In this updated Heap.tpp they have changed to std::numeric_limits<T>::max() in heapifyDown function instead of min.
    */

    std::cout<<"The heap created by function heapify_myVer1_norecursion: "<<std::endl;
    heap.heapify_myVer1_norecursion(vector1);
    heap.printHeap();

    std::cout<<"The heap created by function heapify_myVer2_recursionStartFromLastParentNode: "<<std::endl;
    heap.heapify_myVer2_recursionStartFromLastParentNode(vector1);
    heap.printHeap();
    }

    return 0;
}