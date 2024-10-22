//
// Heap.tpp
// My final clean version
//

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

template <typename T>
class Heap {
    private:
        // Define an alias for the underlying data structure (vector) and its size type
        typedef std::vector<T> heap;
        typedef typename heap::size_type heapIndex;
        
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
            return (heapIndex) std::floor(i / 2);
        }
        
        // Function to maintain the min-heap property by swapping elements down the tree
        heapIndex heapifyDown(heapIndex index) {
            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            T leftChild = (leftChildIndex < this->tree.size())? this->tree.at(leftChildIndex) : std::numeric_limits<T>::max();
            
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            T rightChild = (rightChildIndex < this->tree.size())? this->tree.at(rightChildIndex) : std::numeric_limits<T>::max();
            
            // Find the child with the larger value
            heapIndex minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex;
            
            // If a child has a larger value, swap it with the parent and recursively heapify down
            if(minValueChildIndex < this->tree.size()){
                if(this->tree.at(minValueChildIndex) < this->tree.at(index)) {
                    std::cout << "Swap positions " << minValueChildIndex << "(" << this->tree.at(minValueChildIndex) << ") and" << index << "(" << this->tree.at(index) << ")." << std::endl;
                    std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
                    // Recursively fix the heap property
                    this->heapifyDown(minValueChildIndex);
                    return minValueChildIndex;
                }
            }
            // Reached a leaf node or no child has a larger value, return the current index
            return this->tree.size();
        }
    
    public:
        // Default constructor - creates an empty heap with a dummy element at index 0
        Heap() {
            this->tree.push_back((T) NULL);
        }
        
        // Constructor that builds a min-heap from an existing vector
        Heap(std::vector<T> tree) {
            this->heapify(tree);
        }
        
        // Check if the heap is empty
        bool isHeapEmpty() {
            return this->tree.size() <= 1;
        }
        
        // Print the contents of the heap
        void printHeap() {
            this->printVector(this->tree);
        }
        
        // Build a min-heap from an existing vector
        void heapify(std::vector<T> tree) {
            // Insert a dummy element at the beginning to simplify calculations
            tree.insert(tree.begin(), (T) NULL);
            
            this->tree = tree;
            
            // Start from the last non-dummy element and work backwards to maintain the heap property
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
        
        // Remove the minimum element from the heap
        T popTop() {
            if(this->isHeapEmpty()) {
                // Return a minimum value if the heap is empty
                return std::numeric_limits<T>::min(); //return a dummy element, does not matter min or max
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
                tree1.insert(numList[index]); //can also use heapify() heapify from a vector
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
        // !my method is the optimal one
        void insert(T element) {
            //1-step 1: add the new element to the end of the vector
            this->tree.push_back(element);
            //index of this element
            heapIndex index = (heapIndex) (this->tree.size()-1);
            //2-find the parent of this element, swap if the new element is larger than the parent element
            //3-find the parent of the new parent element, swap if the new parent is larger then grand parent
            //doing all the way until the index decreases back to 1, the first element (until index >0)
            heapIndex parent = this->getParentPosition(index);
            //not sure if I can compare with zero in data type std::vector<int>::size_type; how to remove the case when minValueChildIndex=0
            while (parent>0) //* Important notice: when do we use while loop instead of for loop? when we don't know how many iterations but we know the loop stops when a condition is no longer true.
            {
                //no need to check if the object of parent is !=NULL or if parent < tree.size() because from getParentPosition(index); it indeed is
                this->swapOneBubble(parent);
                //get new parent index 
                //in the last loop when parent =1; then we change parent to this->getParentPosition(1)=floor(1/2)=0 -> ends the loop
                parent = this->getParentPosition(parent);
            }
        }

        //function for a single step of heapifyDown, only check at one parent node and its 2 children, no recursion:
        void swapOneBubble(heapIndex index) //function: checks the 2 direct children of the input index and swap with the smallest one if needed
        {
            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            bool leftChildIndexInRange_andNonNullNode = (leftChildIndex < this->tree.size())&& (leftChildIndex>=1)&&(this->tree.at(leftChildIndex)!=(T)NULL);
            bool rightChildIndexInRange_andNonNullNode = (rightChildIndex < this->tree.size())&& (rightChildIndex>=1)&&(this->tree.at(rightChildIndex)!=(T)NULL);
            T leftChild = leftChildIndexInRange_andNonNullNode ? this->tree.at(leftChildIndex) : std::numeric_limits<T>::max();
            T rightChild = rightChildIndexInRange_andNonNullNode ? this->tree.at(rightChildIndex) : std::numeric_limits<T>::max();
            heapIndex minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex;


            bool minValueChildIndex_InRange_NonNullNode = (minValueChildIndex < this->tree.size())&&(minValueChildIndex >=1)&&(this->tree.at(minValueChildIndex)!=(T)NULL);
            if (minValueChildIndex_InRange_NonNullNode)
            {
                if(this->tree.at(minValueChildIndex)<this->tree.at(index))
                {
                    std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
                }
            }
        }
        
        // Remove an element from the heap
        // Both removing methods are correct, can result in 2 different resultant heaps
        void remove(T value) {
                //1-Create a new std::vector<T> with no such input value
            std::vector<T> new_tree;
            //logic to loop from printVector
            for(heapIndex index = 0; index < this->tree.size(); index++) 
            {
                // Print only non-dummy elements
                if((this->tree.at(index) != value) && (this->tree.at(index) != (T)NULL)) 
                {
                    new_tree.push_back(this->tree.at(index));
                    //!this method is wrong if there is duplicate values. Just use vector.erase(vector.begin()+position)
                }
            }

            //2-heapfiy it and assign back to this->tree
            heapify(new_tree);
        }
        
        void remove_v2(T value) {
            //change the value at the position and remove the last element
            //TODO: is there a better way to find the vector index of T value?
            for(heapIndex index = 0; index < this->tree.size(); index++) 
            {
                // Print only non-dummy elements
                if((this->tree.at(index) == value) && (this->tree.at(index) != (T)NULL)) 
                {
                    //T theDeletedElement = this->tree.at(index);
                    this->tree.at(index) = this->tree.at(this->tree.size() - 1);
                    this->tree.pop_back(); //remove the last element out
                }
            }

            //reheapify starting from the last parent node
            heapIndex lastParentNodeIndex = std::floor((this->tree.size()-1)/2);
            for(heapIndex index = lastParentNodeIndex; index >= 1; index--)
            {
                if (this->tree.at(index)!=(T)NULL)
                {
                    this->heapifyDown(index);
                }
            }

        }
        // Get the minimum element (in this case, the maximum element of the max-heap)
        T getMin() 
        {
            return this->tree.at(1);
        }
};

#endif /* Tree_hpp */
