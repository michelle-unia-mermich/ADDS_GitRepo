//
//  Heap.cpp
//  Heap - Implementation of a Min-Heap data structure
//

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

template <typename T>

//MIN_HEAP
class Heap {
    private:
        // Define an alias for the underlying data structure (vector) and its size type
        typedef std::vector<T> heap; //heap is a vector any data type
        typedef heap::size_type heapIndex;
        //heap::size_type is std::vector<T>::size_type //I would read it as "declare x as a variable of a type suitable for holding the size of a vector". The vector defines its own type for its length, and it's always cleanest to use that if possible, rather than "guessing" and using int, unsigned int, long, unsigned long or size_t etc directly as you'd otherwise need to do.
        
        // Internal storage for the heap elements
        heap tree;
        
        // Helper functions to calculate child and parent node positions based on index
        heapIndex getLeftChildPosition(heapIndex i) {
            // Left child is at index 2 * i
            return (2 * i);
        }
        
        heapIndex getRightChildPosition(heapIndex i) {
            // Right child is at index (2 * i) + 1
            return (2 * i) + 1;
        }
        
        heapIndex getParentPosition(heapIndex i) {
            // Parent is at floor((i - 1) / 2) using integer division
            //*note the formula is different since our vector starts from 1, not 0
            return (heapIndex) std::floor(i / 2);
        }
        
        // Function to maintain the min-heap property by swapping elements down the tree
        /*
            Understand the core heapifyDown function

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

            Example 2: from the tree above, heapify down from element 9
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
        heapIndex heapifyDown(heapIndex index) {

            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            //if the index is within range output the object from the vector, if not output the extreme negative number as a dummy number
            T leftChild = (leftChildIndex < this->tree.size())? this->tree.at(leftChildIndex) : std::numeric_limits<T>::min();
            
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            T rightChild = (rightChildIndex < this->tree.size())? this->tree.at(rightChildIndex) : std::numeric_limits<T>::min();
            
            // Find the child with the smaller value
            heapIndex minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex;
            
            //! If a child has a smaller value (WE ARE DOING MIN HEAP), swap it with the parent and recursively heapify down
            if(minValueChildIndex < this->tree.size()){
                if(this->tree.at(minValueChildIndex) < this->tree.at(index)) {
                    std::cout << "Swap positions " << minValueChildIndex << "(" << this->tree.at(minValueChildIndex) << ") and" << index << "(" << this->tree.at(index) << ")." << std::endl;
                    std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
                    // Recursively fix the heap property
                    this->heapifyDown(minValueChildIndex); //swap the new child with its new child (if needed). The returned heapIndex value is not stored anywhere.
                    //*we are checking between the children of the new minvaluenode and check if we need to swap
                    //*all the way until minValueChildIndex is not < this->tree.size() eg. we have reached the end of the vector
                    return minValueChildIndex; //!the actual return value of heapifyDown(heapIndex index) if index swaps with a child if we access heapifyDown(heapInde index) from outside the class
                }
            }
            // End Recursion: either (1) Reached a leaf node (when condition on line 58 if(minValueChildIndex < this->tree.size()) is false) or (2) no child has a smaller value (when condition on line 59 if(this->tree.at(minValueChildIndex) < this->tree.at(index)) is false), return the size of the vector
            return this->tree.size(); //!the actual return value of heapifyDown(heapIndex index) if there is no swapping, when we access heapifyDown(heapInde index) from outside the class
            // since they want to return a heapIndex value when doing heapifying, they didn't declare this function as void. We could also declare it as void.
        }

        //!another approach to function heapifyDown() if we do not use recursion to fix all bubbles below, but just fix one bubble at a time. A void function is used.
        void swapOneBubble(heapIndex index) //function: checks the 2 direct children of the input index and swap with the smallest one if needed
        {
            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            T leftChild = (leftChildIndex < this->tree.size())? this->tree.at(leftChildIndex) : std::numeric_limits<T>::max();
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            T rightChild = (rightChildIndex < this->tree.size())? this->tree.at(rightChildIndex) : std::numeric_limits<T>::max();
            heapIndex minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex;

            //if the minValuChildIndex points to a node in the vector
            if ((minValueChildIndex<this->tree.size())&&(minValueChildIndex>0)) //!not sure if I can compare with zero in data type std::vector<int>::size_type; how to remove the case when minValueChildIndex=0
            {
                //swap
                std::cout << "Swap positions in swapOneBubble " << minValueChildIndex << "(" << this->tree.at(minValueChildIndex) << ") and" << index << "(" << this->tree.at(index) << ")." << std::endl;
                std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
            }
        }

        std::vector<T>::iterator findPosition(T value) //find position of a value in the vector
        {
            auto it = std::find(this->tree.begin(), this->tree.end(), value);

            // Check if the element was found

            if (it != this->tree.end()) {
            //element is found
           return std::distance(this->tree.begin(), it);

            } else {
            //element is not found
            //!what should I return here?
            return -1;
        }
        }

    public:
        // Default constructor - creates an empty heap with a dummy element at index 0
        Heap() {
            this->tree.push_back((T) NULL);
            //*Note: index of this tree is from 1 (the first element has 1 index). So at index 0, push NULL object so there is no error.
        }
        
        // Constructor that builds a min-heap from an existing vector
        Heap(std::vector<T> tree) {
            this->heapify(tree);
        }
        
        // Check if the heap is empty 
        //*note that when the heap is empty, it already contains 1 element NULL object at index 0
        bool isHeapEmpty() {
            return this->tree.size() <= 1;
        }
        
        // Print the contents of the heap
        void printHeap() {
            this->printVector(this->tree);
        }
        
        // Build a min-heap from an existing vector
        void heapify(std::vector<T> tree) {
            // Insert a dummy element at the beginning of the INPUT VECTOR to simplify calculations
            tree.insert(tree.begin(), (T) NULL);
            //? vec.insert (pos, val); position is tree.begin() instead of 0
            
            //now the input vector is the same size as our vector, assign
            this->tree = tree;
            
            // Start from the last non-dummy element (the rightmost bottommost element of the heap) and work backwards (going up the  heap) to maintain the heap property
            //we only need to heapify down from the parent node. the formula to find the last parent node floow[n/2] (since we start with index 0); 
            //however, we heapifyDown every node, including the last child nodes because this way is cleaner
            //? Why is this cleaner than ignoring the last leaf nodes?
            //because, consider the function heapifyDown() at the leaf node, the nodes have no children so the heapifyDown() leftChild and rightChild will always be maximum negative values. so the time to complete heapifyDown() for each leaf node is constant
            //!time complexity O(n) for heapfiy?
            for(heapIndex index = this->tree.size() - 1; index >= 1; index--) {
                this->heapifyDown(index);
            }
        }
        
        // Helper function to print the contents of a vector
        void printVector(std::vector<T> numVector) {
            std::cout << "[ ";
            for(heapIndex index = 0; index < numVector.size(); index++) {
                // Print only non-dummy elements
                if(numVector.at(index) != (T) NULL) {
                    std::cout << numVector.at(index);
                    if(index != (numVector.size() - 1)) {
                        std::cout << ", ";
                    }
                }
            }
            std:: cout << " ]" << std::endl;
        }
        
        // Remove the minimum element (at the root) from the heap
        T popTop() {
            if(this->isHeapEmpty()) {
                // Return a minimum value if the heap is empty
                return std::numeric_limits<T>::min();
            }
            const heapIndex ROOT_INDEX = 1;
            
            // Replace the root with the last element
            T topElement = this->tree.at(ROOT_INDEX);
            std::cout << "Removed top element: " << topElement << std::endl;
            std::cout << "Placing index: " << (this->tree.size() - 1) << "(" << this->tree.at(this->tree.size() - 1) << ") to the top" << std::endl;
            this->tree.at(ROOT_INDEX) = this->tree.at(this->tree.size() - 1);
            this->tree.pop_back();
            
            std::cout << "Checking the if the heap condition is valid after popping out top of heap: " << topElement << std::endl;
            // Restore the heap property by heapifying down from the root
            heapIndex parent = ROOT_INDEX;
            this->heapifyDown(parent);
            return topElement;
        }
        
        // Sort a vector using the heap sort algorithm
        std::vector<T> heapSort(std::vector<T> numList) {
            Heap<T> tree1;
            // Build a min-heap from the input vector
            for(typename std::vector<T>::size_type index = 0; index < numList.size(); index++) {
                tree1.insert(numList[index]);
            }
            
            std::vector<T> sortedNumList;
            // Extract the minimum elements one by one and add them to the sorted list
            while(!tree1.isHeapEmpty()){
                sortedNumList.push_back(tree1.popTop());
                this->printVector(sortedNumList);
            }
            return sortedNumList;
        }
        
        // Insert an element into the heap
        void insert(T element) {

            //1-step 1: add the new element to the end of the vector
            this->tree.push_back(element);
            heapIndex index = (heapIndex) (this->tree.size()-1);
            //2-find the parent of this element, swap if the new element is larger than the parent element
            //3-find the parent of the new parent element, swap if the new parent is larger then grand parent
            //doing all the way until the index decreases back to 1, the first element (until index >0)
            heapIndex parent = this->getParentPosition(index);
            //!not sure if I can compare with zero in data type std::vector<int>::size_type; how to remove the case when minValueChildIndex=0
            while (parent>0) //?when do we use while loop instead of for loop? when we don't know how many iterations but we know the loop stops when a condition is no longer true.
            {
                swapOneBubble(parent);
                //get new parent index 
                //in the last loop when parent =1; then we change parent to this->getParentPosition(1)=floor(1/2)=0 -> ends the loop
                parent = this->getParentPosition(parent);
            }

        }
        
        // Remove an (any) element from the heap
        void remove(T value) 
        {
            //O(n)
            //since re-heapifying from the beginning was O(n)
            //delete worst case is O(1)?
            /*
            auto index = findPosition(value);
            if (true) //!check when index is invalid?
            {
                //meaning the value is found in the vector
                // Fetching the iterator to this element
                auto pos = this->tree.begin() + index;

                // Deleting the 3rd element from vector vec1
                this->tree.erase(pos);

                //reset the heap
                this->heapify(this->tree);// Build a min-heap from an existing vector

            }
            */

            //1-Create a new std::vector<T> with no such input value
            std::vector<T> new_tree;
            //logic to loop from printVector
            for(heapIndex index = 0; index < this->tree.size(); index++) 
            {
                // Print only non-dummy elements
                if(this->tree.at(index) != value) 
                {
                    new_tree.push(this->tree.at(index))
                }
            }

            //2-heapfiy it and assign back to this->tree
            this->tree= heapify(new_tree)
        }
        
        // Get the minimum element (in this case, the minimum element of the min-heap)
        T getMin() 
        {
            //only print out the element, make no changes to the vector

            /*
            * There are 2 approaches
            Right now our vector this->heap is a heap, meaning the first element is indeed the smallest element, but the rest of the elements in the vector are not in ascending order.
            If we want to convert our vector to ascending order vector, must use heapSort() function 

            (1) Reorder our vector using heapSort. Useful to find the second smallest, the third smallest value, but not the smallest value
            std::vector<T> sorted_heap = this->heapSort(this->tree); //!does the heapSort() still keep the null object at index 0 after sorting?
            //return the element at index 1 of sorted_heap
            return sorted_heap.at(1);

            (2) Method 2: just return the smallest value which is at the root of the heap
            */
           return this->tree.at(1);
        }
};
#endif /* Tree_hpp */

/*

for the Heapfiy: create  heap from  an existing vector
- have a non-recursive function that swaps between the parent node and the larger child node in one bubble
- apply this non-recursive function iteratively for each parent node in the array (don't have to go through the whole array)
O(1) - one set of operation happing in constant time

*/

