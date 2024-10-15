//Testing Heap
#include "Heap_v1_myversion.tpp"
#include <iostream>

int main()
{
    {
    std::cout<<"==============Part 7:Remove any element============== "<<std::endl;
    Heap<int> heap;
    std::vector<int> vector1 = {12,11,10,8,9,7,6,5,4};
    heap.printVector(vector1);
    /*
    Original Heap:
                  12
                /   \
               11   10
              / \   / \
             8   9  7  6
            / \ 
           5  4 
    Final Correct Heap:
                  4
                /   \
               5     6
              / \   / \
             8   9  7  10
            / \ 
           11  12

    Method 1: Remove element of value 5 and replace with 12
                  4
                /   \
               12     6
              / \   / \
             8   9  7  10
            /  
           11  
                Final correct heap
                  4
                /   \
               8     6
              / \   / \
             11   9  7  10
            /  
           12 
    
    Method 1: Remove element of value 5, convert to a vector and rebuild:
    new vector: [ 4, 6, 8, 9, 7, 10, 11, 12 ]
                  4
                /    \
               6      8
              / \    /  \
             9   7  10  11
            /  
           12 
        Final correct heap: the same as it is already correct


    */
   
   //Remove 1
    heap.heapify_myVer2_recursionStartFromLastParentNode(vector1);
    heap.printHeap();
    heap.remove_rebuild(5);
    heap.printHeap();

    //Remove 2
    heap.heapify_myVer2_recursionStartFromLastParentNode(vector1);
    heap.remove_reheapify(5);
    heap.printHeap();


   /*
   heapSort(std::vector<T> numList)
   
   */
    }


    return 0;
}