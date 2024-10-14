//Testing Heap
#include "Heap_v1_myversion.tpp"
#include <iostream>

int main()
{
    {
        //Test 1: test Heapify
        //See visualisation of this part: https://file.notion.so/f/f/6ccd7bd5-f555-4d21-bbb4-25943c701075/fbe7e63f-7dcb-4e17-9478-4c1d4a3d816a/2_ways_to_create_vector_from_Heap_visualisation_2.pdf?table=block&id=11fd9901-0b59-801a-8642-cc6f5cfe5445&spaceId=6ccd7bd5-f555-4d21-bbb4-25943c701075&expirationTimestamp=1729036800000&signature=kNuRkZ61GBPHNxQLPuoTafGS_xLtmzCwPYxgg7m-TRw&downloadName=2+ways+to+create+vector+from+Heap+visualisation+2.pdf
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
    * Important concept: in the heap, the rest of the vector might not be thoroughly sorted, but the first element is always the minimum (for min heap)
    ! right?
    */
    heap.printVector(vector1); //print elements of the vector
    heap.heapify_lecturerVer(vector1);
    std::cout<<"The heap created by function heapify_lecturerVer: "<<std::endl;
    heap.printHeap(); //print elements of the heap
    /*
    !wrong: why is the heapify function from the lecturers wrong?
    The result is: [ 2, 3, 4, 7, 6, 5, 8, 9, 10, 1 ]
    *Note that when adding a vector as a heap, the rest of the elements are not sorted in order BUT THE FIRST ELEMENT IS ALWAYS THE MINIMUM (for min heap).
    The result prints out the first element as 2, so that is wrong.

    */
    std::cout<<"The heap created by function heapify_myVer1_norecursion: "<<std::endl;
    heap.heapify_myVer1_norecursion(vector1);
    heap.printHeap();

    std::cout<<"The heap created by function heapify_myVer2_recursionStartFromLastParentNode: "<<std::endl;
    heap.heapify_myVer2_recursionStartFromLastParentNode(vector1);
    heap.printHeap();
    }
    
    {
        //Note that the Heap is by default complte binary tree, but in this test case: test if our structure can also handle "non-complete heap"
        //Test 2: test if the heap can handle non-full, non-complete heaps (vector contains NULL elements)
        std::cout<<"==============Part 2============== "<<std::endl;
        int test_null = (int)NULL; //NULL object is casted to 0 in (int) casting
        Heap<int> heap = Heap<int>();
        std::vector<int> vector1 = {10,9,8,0,6,5,4,3,2,1};
        heap.printVector(vector1); //number 0 is not printed out
        //!can we build a non-complete, non-full tree? We must add NULL objects to empty node positions. 
        //!Does this mean this heap cannot handle number 0? It treats zero as a null object
        //!Is there a better way to add NULL objects to the array for empty nodes, but still handling zero?
        //! eg. this raises error: std::vector<int> vector2 = {1,3,7,NULL,NULL,2,5,NULL,NULL,NULL,NULL,9,10,NULL,NULL, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,8};
        //!A lot of functions just check for index<tree.size() without checkingn whether the tree.at(index) is different from NULL - the current heap assumes only the element at index 0 is NULL object
    }
    {
    /*
    Note that the Heap is by default complte binary tree, but in this test case: test if our structure can also handle "non-complete heap"
    Now ASSUME that our heap cannot handle number 0 and treats number 0 as NULL object
    If the node does not have an element, append NULL object to the vector.

    We will create this heap and test several functions:
                1                                           
               / \
              3   7    
                 / \   
                2   5   
               / \
              9   10
             / \
            8
    */
   std::cout<<"==============Part 3============== "<<std::endl;
   std::vector<int> vector2 = {1,3,7,(int)NULL,
   (int)NULL,2,5,(int)NULL,(int)NULL,(int)NULL,(int)NULL,9,10,
   (int)NULL,(int)NULL, (int)NULL,(int)NULL,(int)NULL,(int)NULL,(int)NULL,
   (int)NULL,(int)NULL,(int)NULL,8};
   Heap<int> heap = Heap<int>();
    heap.heapify_myVer2_recursionStartFromLastParentNode(vector2);
    heap.printHeap();
    heap.heapify_myVer1_norecursion(vector2);
    heap.printHeap();
    }
    {       
   /*
   Test 1: heapifyDown
            
            Example1: Vector: 1st node swaps with 2nd node; new child (1st node) has no smaller value (no swapping); but the nodes after that needs swapping
            vector starts with 1
                1                                           
               / \
              3   7    ----heapifyDown(3) (element 7)----------------->  
                 / \   (heapfiy starting from 7 going down)
                2   5   return minchildindex 4
               / \
              9   10
             / \
            8
            
                1
               / \
              3   2    ----heapifyDown(6) (element 7)----------------->  
                 / \   (heapfiy staring from 3 going down)
                7   5   return this->tree.size()
               / \       Recursion ends because  if(this->tree.at(minValueChildIndex) < this->tree.at(index)) is FALSE
              9   10     minValueChildIndex=12
             /
            8
            Final product: the tree is not yet sorted (9 is still larger than 8)
                1
               / \
              3   2    
                 / \   
                7   5   
               / \
              9   10
             /
            8
            Note: element 9's index is 12; and element 8's index is 24
            *Why does calling heapifyDown one time at index 7 in this example not give a correct heap in the end like when we call this function starting from the last parent node going up to the first parent node at the root?
            *Because when we call from the last parent node go up to the root, all parent nodes below a certain node eg. all parent nodes below node 7 are already correct ie. the 8 is already above the 9
   */
  std::cout<<"==============Part 4============== "<<std::endl;
  Heap<int> heap = Heap<int>();
  std::vector<int> vector2 = {1,3,7,(int)NULL,
   (int)NULL,2,5,(int)NULL,(int)NULL,(int)NULL,(int)NULL,9,10,
   (int)NULL,(int)NULL, (int)NULL,(int)NULL,(int)NULL,(int)NULL,(int)NULL,
   (int)NULL,(int)NULL,(int)NULL,8};
  typedef std::vector<int>::size_type heapIndex;

  //set the heap in the object to be the vector (not yet reformed to heap)
  heap.setTreeHeap(vector2);
  heap.printHeap();
   std::cout << std::endl;

  heap.heapifyDown_myVer((heapIndex)3);
  heap.printHeap();
  std::cout << std::endl;

heap.setTreeHeap(vector2);
  heap.heapifyDown((heapIndex)3);
  heap.printHeap();
  std::cout << std::endl;
  /*
            Example 2: from the tree above, heapify down from element 9 at index 12
                1                                           
               / \
              3   7    ----heapifyDown(12) (element 9)----------------->  
                 / \   return minchildindex 24
                2   5   However:
               / \      - left child index = 24
              9   10    - right child index = std::numeric_limits<T>::min()
             / \        - minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex = right child index = std::numeric_limits<T>::min() 
            8           //! see, why is it std::numeric_limits<T>::min()? must be max?
                        - if(minValueChildIndex < this->tree.size()) -> If True'
                        - if(this->tree.at(minValueChildIndex) < this->tree.at(index)) : this->tree.at(minValueChildIndex) does not exit, so False
                        - return this->tree.size(), recursion ends, 8 is not swapped with 9
                1                                           
               / \
              3   7    ----heapifyDown(24) (element 9) (heapify at the LEAF NODE case)----------------->  
                 / \   return minchildindex 24
                2   5   - left child index = std::numeric_limits<T>::min()
               / \      - right child index = td::numeric_limits<T>::min()
              8   10    - minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex = ?? what would be the value if they are equal?
             / \        - return this->tree.size(), recursion ends, no swapping
            9
  */
    heap.setTreeHeap(vector2);
  heap.heapifyDown_myVer((heapIndex)12); //correct [ 1, 3, 7, 2, 5, 8, 10, 9 ]
  heap.printHeap();
  std::cout << std::endl;

heap.setTreeHeap(vector2);
  heap.heapifyDown((heapIndex)12); //not correct
  /*
  Why does it give incorrect answer [ 1, 3, 7, 2, 5, 9, 10, 8 ]?
  heapifyDown at index 12
  leftChildIndex =24 (element 8)
  rightChildIndex=25 (out of range of vector)
  T rightChild=std::numeric_limits<T>::min();
   T leftChild= 8
   minValueChildIndex = 25 is out of range
   So not comparison between if(this->tree.at(minValueChildIndex) < this->tree.at(index)) is done, no swapping is done.
   *This is why for min heap, must set to td::numeric_limits<T>::max();
   If we set to min, the chosen child node is always the empty node and there will be no comparison between the parent node and this node (if this node is out of vector index)
   If this empty node is in the vector range, it is even worse because the value 9 at parent node will be compared with (T)NULL, which is casted to 0 if T is int. Then 0 will replace the position of 9, even though there is no zero in the heap. (example below)
  */
  heap.printHeap();
  std::cout << std::endl;

//Example for: If this empty node is in the vector range, it is even worse because the value 9 at parent node will be compared with (T)NULL, which is casted to 0 if T is int. Then 0 will replace the position of 9, even though there is no zero in the heap.
  std::cout<<"==============Part 4a============== "<<std::endl;
  std::vector<int> vector3 = {1,3,7,(int)NULL,
   (int)NULL,2,5,(int)NULL,(int)NULL,(int)NULL,(int)NULL,9,10,
   (int)NULL,(int)NULL, (int)NULL,(int)NULL,(int)NULL,(int)NULL,(int)NULL,
   (int)NULL,(int)NULL,(int)NULL,8, (int)NULL};
   heap.printHeap();
heap.setTreeHeap(vector3);
  heap.heapifyDown((heapIndex)12); //not correct
  heap.printHeap();
  std::cout << " (element 0 between 5 and 10 is not printed)"<< std::endl;
  std::cout << std::endl;

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
    {
        std::cout<<"==============Part 8:Test Heap Sort============== "<<std::endl;
        Heap<int> heap;
        std::vector<int> vector1 = {12,11,10,8,9,7,6,5,4};
        std::vector<int> vector2 = heap.heapSort(vector1);

    }


    return 0;
}