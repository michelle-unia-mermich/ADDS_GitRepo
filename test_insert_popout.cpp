//Testing Heap
#include "Heap_v1_myversion.tpp"
#include <iostream>

int main()
{
    
    {
    std::cout<<"==============Part 5: Insert a new element============== "<<std::endl;
    Heap<int> heap;
    std::vector<int> vector1 = {12,11,10,9,8,7,6,5,4,3};
    /*
    Original Heap:
                  12
                /   \
               11   10
              / \   / \
             9   8  7  6
            / \ /
           5  4 3
    Final Correct Heap:
                  3
                /   \
               4     6
              / \   / \
             5   8  7  10
            / \ /
           12 9 11 
    
    Inserting 1: 
                  3
                /   \
               4     6
              / \   / \
             5   8  7  10
            / \ / \
           12 9 11 1
    Final correct Heap:
                  1
                /   \
               3     6
              / \   / \
             5   4  7  10
            / \ / \
           12 9 11 8  
    */
   
   //make the heap
    heap.heapify_myVer1_norecursion(vector1);
    heap.printHeap();
    heap.insert(1);
    heap.printHeap();
   /*
   popTop()
   heapSort(std::vector<T> numList)
   remove(T value) 
   */
    }

    {
    std::cout<<"==============Part 6: Pop out the top element============== "<<std::endl;
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
    Remove top element, replace with element 12
                  12
                /   \
               5     6
              / \   / \
             8   9  7  10
            / 
           11     
    Final correct heap:
                  5
                /   \
               8     6
              / \   / \
             11   9  7  10
            / 
           12 

    */
   
   //make the heap
    heap.heapify_myVer1_norecursion(vector1);
    heap.printHeap();
    std::cout<<"( this means that function heapify_myVer1_norecursion is wrong )"<<std::endl;

    heap.setTreeHeap(vector1);
    heap.heapify_myVer2_recursionStartFromLastParentNode(vector1);
    heap.printHeap();

    std::cout<< "Top value is: "<<heap.popTop()<<std::endl;
    std::cout<< "The heap is: ";
    heap.printHeap();
    std::cout<<"( popTop() by the lecturers is wrong because it uses heapifyDown() which is wrong since it takes min() and not max )"<<std::endl;
    
    heap.setTreeHeap(vector1);
    heap.heapify_myVer2_recursionStartFromLastParentNode(vector1);
    std::cout<< "Top value is: "<<heap.popTop_myVer()<<std::endl;
    std::cout<< "The heap is: ";
    heap.printHeap();
   /*
   heapSort(std::vector<T> numList)
   remove(T value) 
   */
    }

        {
    std::cout<<"==============Part 5: Insert a new element============== "<<std::endl;
    Heap<int> heap;
    std::vector<int> vector1 = {12,11,10,9,8,7,6,5,4,3};
    /*
    Original Heap:
                  12
                /   \
               11   10
              / \   / \
             9   8  7  6
            / \ /
           5  4 3
    Final Correct Heap:
                  3
                /   \
               4     6
              / \   / \
             5   8  7  10
            / \ /
           12 9 11 
    
    Inserting 1: 
                  3
                /   \
               4     6
              / \   / \
             5   8  7  10
            / \ / \
           12 9 11 1
    Final correct Heap:
                  1
                /   \
               3     6
              / \   / \
             5   4  7  10
            / \ / \
           12 9 11 8  
    */
   
   //make the heap
    heap.heapify_myVer1_norecursion(vector1);
    heap.printHeap();
    heap.insert(1);
    heap.printHeap();
   /*
   popTop()
   heapSort(std::vector<T> numList)
   remove(T value) 
   */
    }


    return 0;
}