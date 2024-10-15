//Testing Heap
#include "Heap_final_clean.tpp"
#include <iostream>

int main()
{
    {
    Heap<int> heap = Heap<int>(); //or simply Heap<int> heap;
    // Build a min-heap from an existing vector
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
    */
    heap.printVector(vector1); //print elements of the vector
    heap.heapify(vector1);
    std::cout<<"The heap created: "<<std::endl;
    heap.printHeap(); //print elements of the heap
    }

    
    {
    std::cout<<"==============Part 2: Insert a new element============== "<<std::endl;
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
    heap.heapify(vector1);
    heap.printHeap();
    heap.insert(1);
    heap.printHeap();
    }

    {
    std::cout<<"==============Part 3: Pop out the top element============== "<<std::endl;
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
    heap.heapify(vector1);
    heap.printHeap();
    std::cout<< "The min/top value is : "<<heap.getMin()<<std::endl;
    std::cout<< "Popping the top value : "<<heap.popTop()<<std::endl;
    std::cout<< "The heap is: ";
    heap.printHeap();
    }

    {
    std::cout<<"==============Part 4:Remove any element============== "<<std::endl;
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
    
    Method 2: Remove element of value 5, convert to a vector and rebuild:
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
   
   //Remove 1: Method 2 shown above: result: [ 4, 6, 8, 9, 7, 10, 11, 12 ]
    heap.heapify(vector1);
    heap.printHeap();
    heap.remove(5);
    heap.printHeap();

    //Remove 2: Method 1 shown above: result: [ 4, 8, 6, 11, 9, 7, 10, 12 ]
    heap.heapify(vector1);
    heap.remove_v2(5);
    heap.printHeap();

    }

    {
        std::cout<<"==============Part 5:Test Heap Sort============== "<<std::endl;
        Heap<int> heap;
        std::vector<int> vector1 = {12,11,10,8,9,7,6,5,4};
        std::vector<int> vector2 = heap.heapSort(vector1);

    }


    return 0;
}