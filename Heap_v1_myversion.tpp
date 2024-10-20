#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

template <typename T>
/*
IMPORTANT CONCEPTS
* Heap is by default a COMPLETE binary tree so besides the element at index 0, no other elements are NULL

1) Build a heap from an existing vector
    - Combo 1:  (this combo is wrong, consider the case vector1 = {12,11,10,8,9,7,6,5,4};)
        + heapify_myVer1_norecursion(std::vector<T> tree)
        + helper function: void swapOneBubble(heapIndex index)
    - Combo 2:
        + heapify_myVer2_recursionStartFromLastParentNode(std::vector<T> tree)
        + helper function: heapIndex heapifyDown_myVer(heapIndex index)
2) Insert an element to the heap and maintain heap property:
    - void insert(T element)
3) Delete and extract the element at the root/top: 
    - T popTop()

4) Delete any random element in the heap:  
    - void remove_rebuild(T value) (rebuild from scratch with the new vector)
    - void remove_reheapify(T value): replace the deleted value with the last elemetn and reheapify
    !The tutor said: we should only delete the first top element. If we delete any random element, we might as well just build the heap from scratch. 
    !The two methods give two correct answers, which is correct? See example in main.cpp Part 7
5) Heap Sort: 
    - std::vector<T> heapSort(std::vector<T> numList)
*/

//MIN_HEAP
class Heap {
    private:
        typedef std::vector<T> heap; 
        typedef heap::size_type heapIndex;
        heap tree;
        
        heapIndex getLeftChildPosition(heapIndex i) 
        {
            // Left child is at index 2 * i
            return (2 * i);
        }
        
        heapIndex getRightChildPosition(heapIndex i) 
        {
            // Right child is at index (2 * i) + 1
            return (2 * i) + 1;
        }
        
        heapIndex getParentPosition(heapIndex i) 
        {
            // Parent is at floor((i - 1) / 2) using integer division
            //*note the formula is different since our vector starts from 1, not 0
            return (heapIndex) std::floor(i / 2);
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
       
       /*
       Note: heapifyDown() function should be in private (helper function), but just for testing, we put it in public.
       */

    public:
        Heap() 
        {
            this->tree.push_back((T) NULL);
            //*Note: index of this tree is from 1 (the first element has 1 index). So at index 0, push NULL object so there is no error.
        }
        
        Heap(std::vector<T> tree) 
        {
            // Constructor that builds a min-heap from an existing vector
            this->heapify(tree);
        }

        //For testing: a setter function to set the tree in the heap a non-heap vector
        void setTreeHeap(std::vector<T> tree)
        {
            tree.insert(tree.begin(), (T) NULL);
            this->tree = tree;
        }
        
        
        //heapifyDown the lecturer's version
        heapIndex heapifyDown(heapIndex index) 
        {
            //!function heapifyDown from the lecturer is wrong, and thus heapify_lecturerVer is wrong
            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            //if the index is within range output the object from the vector, if not output the extreme negative number as a dummy number
            T leftChild = (leftChildIndex < this->tree.size())? this->tree.at(leftChildIndex) : std::numeric_limits<T>::min();
            
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            T rightChild = (rightChildIndex < this->tree.size())? this->tree.at(rightChildIndex) : std::numeric_limits<T>::min();
            
            // Find the child with the smaller value
            heapIndex minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex;

            /*
            Of course, since the heap is a complete binary tree so the only time when the rightChild is std::numeric_limits<T>::min() is when the rightChildINdex is out of range of the vector.
            minValueChildIndex = rightChildIndex = out of range, so if statement if(minValueChildIndex < this->tree.size()) is false.

            This is only false when rightChildIndex= minValueChildIndex is in range of this->tree.size() and 
            this->tree.at(minValueChildIndex) is a NULL object in the vector (which cannot happen for complete binary trees.)
            */
            
            //If a child has a smaller value (WE ARE DOING MIN HEAP), swap it with the parent and recursively heapify down
            if(minValueChildIndex < this->tree.size()){
                if(this->tree.at(minValueChildIndex) < this->tree.at(index)) {
                    //std::cout << "Swap positions " << minValueChildIndex << "(" << this->tree.at(minValueChildIndex) << ") and" << index << "(" << this->tree.at(index) << ")." << std::endl;
                    std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
                    // Recursively fix the heap property
                    this->heapifyDown(minValueChildIndex); //swap the new child with its new child (if needed). The returned heapIndex value is not stored anywhere.
                    //*we are checking between the children of the new minvaluenode and check if we need to swap
                    //*all the way until minValueChildIndex is not < this->tree.size() eg. we have reached the end of the vector
                    return minValueChildIndex; //the actual return value of heapifyDown(heapIndex index) if index swaps with a child if we access heapifyDown(heapInde index) from outside the class
                }
            }
            // End Recursion: either (1) Reached a leaf node (when condition on line 58 if(minValueChildIndex < this->tree.size()) is false) or (2) no child has a smaller value (when condition on line 59 if(this->tree.at(minValueChildIndex) < this->tree.at(index)) is false), return the size of the vector
            return this->tree.size(); //the actual return value of heapifyDown(heapIndex index) if there is no swapping, when we access heapifyDown(heapInde index) from outside the class
            // since they want to return a heapIndex value when doing heapifying, they didn't declare this function as void. We could also declare it as void.
        }
        
        heapIndex heapifyDown_myVer(heapIndex index)
        {
            /*
            Differences with the heapifyDown function by the lecturers
                - if the index > tree.size or <=0, the T object is std::numeric maximum (since this is min heap)
            */
            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            bool leftChildIndexInRange_andNonNullNode = (leftChildIndex < this->tree.size())&& (leftChildIndex>=1)&&(this->tree.at(leftChildIndex)!=(T)NULL);
            bool rightChildIndexInRange_andNonNullNode = (rightChildIndex < this->tree.size())&& (rightChildIndex>=1)&&(this->tree.at(rightChildIndex)!=(T)NULL);
            T leftChild = leftChildIndexInRange_andNonNullNode ? this->tree.at(leftChildIndex) : std::numeric_limits<T>::max();
            T rightChild = rightChildIndexInRange_andNonNullNode ? this->tree.at(rightChildIndex) : std::numeric_limits<T>::max();
            heapIndex minValueChildIndex = (leftChild < rightChild)? leftChildIndex: rightChildIndex;
            //if both are equal what will minValueChildIndex be? Answer: both cannot be equal because heap is a complete binary tree.
            
            //need to check the condnition of minValueChildIndex again because we have only checked the conditions to get the the T value at that index
            //for example, if the index is out of range but the minValueChildIndex chosen is out of range, we have only known the T value is std::numeric_limits but we haven't set any conditions for the value itself
            //TODO: another way to improve: just check the condition <size and >=1 once for both

            bool minValueChildIndex_InRange_NonNullNode = (minValueChildIndex < this->tree.size())&&(minValueChildIndex >=1)&&(this->tree.at(minValueChildIndex)!=(T)NULL);
            if (minValueChildIndex_InRange_NonNullNode)
            {
                if(this->tree.at(minValueChildIndex) < this->tree.at(index))
                {
                    std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
                    this->heapifyDown_myVer(minValueChildIndex);
                    return minValueChildIndex; 
                }
            }
            return this->tree.size(); //return any random value. It is not saved.
        }

        bool isHeapEmpty() 
        {

            return this->tree.size() <= 1;
        }
        
        void printHeap() {
            this->printVector(this->tree);
        }
        
        
        // Build a min-heap from an existing vector, and assign this min heahp to the class this->tree
        void heapify_lecturerVer(std::vector<T> tree) 
        {
            //!wrong function due to heapifyDown() min()
            // Insert a dummy element at the beginning of the INPUT VECTOR to simplify calculations
            tree.insert(tree.begin(), (T) NULL);
            //? vec.insert (pos, val); position is tree.begin() instead of 0
            
            //now the input vector is the same size as our vector, assign
            this->tree = tree;
            
            // Start from the last non-dummy element (the rightmost bottommost element of the heap) and work backwards (going up the  heap) to maintain the heap property
            //we only need to heapify down from the parent node. the formula to find the last parent node floow[n/2] (since we start with index 0); 
            //however, we heapifyDown every node, including the last child nodes because this way is cleaner
            //Why is this cleaner than ignoring the last leaf nodes?
            //because, consider the function heapifyDown() at the leaf node, the nodes have no children so the heapifyDown() leftChild and rightChild will always be maximum negative values. so the time to complete heapifyDown() for each leaf node is constant
            for(heapIndex index = this->tree.size() - 1; index >= 1; index--) {
                this->heapifyDown(index);
            }
        }
        
        
        void heapify_myVer1_norecursion(std::vector<T> tree)
        {
            //!function heapify_myVer1_norecursion is wrong: consider example: {12,11,10,8,9,7,6,5,4};
            tree.insert(tree.begin(), (T) NULL);
            this->tree = tree;
            /*
            Description:
                - insert all elements at once
                - starting from the last parent node (in the layer right above the last leaf layer), swap each bubble going up to the first parent node at the root
                - from the first parent node at the root check each bubble at EACH PARENT node going down from the 
            */
           //find the last parent node
           /*
           *Find the last parent node
                - if the first node starts at 0: last parent node is floor(n/2)-1
                - if the first node starts at 1: last parent node is floor(n/2)
           */
          //note that the number of nodes in the vector is this->tree.size()-1 since element NULL at index 0 is included in this->tree.size()
          heapIndex lastParentNodeIndex = std::floor((this->tree.size()-1)/2);
          //on the left of this node are parent nodes; on the right of this node are child nodes
          //check each NON-NULL parent node going back to the root node
          for(heapIndex index = lastParentNodeIndex; index >= 1; index--)
          {
            if (this->tree.at(index)!=(T)NULL)
            {
                swapOneBubble(index);
            }
          }
          for (heapIndex index=1; index<=lastParentNodeIndex; index++)
          {
            if (this->tree.at(index)!=(T)NULL)
            {
                swapOneBubble(index);
            }
            //we are checking the first node twice unnecessarily, but i'll leave that for now
          }

        }
        
        //heapify_myVer2_recursionStartFromLastParentNode is correct
        void heapify_myVer2_recursionStartFromLastParentNode(std::vector<T> tree) 
        {
            tree.insert(tree.begin(), (T) NULL);
            this->tree = tree;
            //same as the lecturer's heapify() version, but only do on the parent nodes, excluding leafnode
            heapIndex lastParentNodeIndex = std::floor((this->tree.size()-1)/2);
            for(heapIndex index = lastParentNodeIndex; index >= 1; index--)
            {
                if (this->tree.at(index)!=(T)NULL)
                {
                    this->heapifyDown_myVer(index);
                }
            }
        }

        void printVector(std::vector<T> numVector) 
        {
            std::cout << "[ ";
            for(heapIndex index = 1; index < numVector.size(); index++) {
                // Print only non-dummy elements
                    std::cout << numVector.at(index);
                    if(index != (numVector.size() - 1)) {
                        std::cout << ", ";
                }
            }
            std:: cout << " ]" << std::endl;
        }
        
        
        //!why returning a minimum value if the min heap is empty? must return a maximum value to make sense?
        T popTop() 
        {
            // Remove the minimum element (at the root) from the heap
            if(this->isHeapEmpty()) {
                // Return a minimum value if the heap is empty
                return std::numeric_limits<T>::min();
            }
            const heapIndex ROOT_INDEX = 1;
            //!popTop is wrong due to heapifyDown() min()
            
            // Replace the root with the last element
            T topElement = this->tree.at(ROOT_INDEX);
            std::cout << "Removed top element: " << topElement << std::endl;
            std::cout << "Placing index: " << (this->tree.size() - 1) << "(" << this->tree.at(this->tree.size() - 1) << ") to the top" << std::endl;
            this->tree.at(ROOT_INDEX) = this->tree.at(this->tree.size() - 1);
            this->tree.pop_back(); //remove the last element out
            
            std::cout << "Checking the if the heap condition is valid after popping out top of heap: " << topElement << std::endl;
            // Restore the heap property by heapifying down from the root
            //*note: to restore the heap property, only need to check the bubbles that involve the newly changed parent node or child node
            /*
            eg. 1
               / \
               2  4
            When we replace 1 with 3
                2
               / \
               3  4
            We continue to check the branch of 3 since there is change involved. no need to check the other sub-branch starting with 4
            */
            heapIndex parent = ROOT_INDEX;
            this->heapifyDown(parent);
            return topElement;
        }
        
        //popTop_myVer is correct
        T popTop_myVer() 
        {
            if(this->isHeapEmpty()) {
                return std::numeric_limits<T>::max();
            }
            const heapIndex ROOT_INDEX = 1;
            
            T topElement = this->tree.at(ROOT_INDEX);
            std::cout << "Removed top element: " << topElement << std::endl;
            std::cout << "Placing index: " << (this->tree.size() - 1) << "(" << this->tree.at(this->tree.size() - 1) << ") to the top" << std::endl;
            this->tree.at(ROOT_INDEX) = this->tree.at(this->tree.size() - 1);
            this->tree.pop_back(); //remove the last element out
            
            std::cout << "Checking the if the heap condition is valid after popping out top of heap: " << topElement << std::endl;
            heapIndex parent = ROOT_INDEX;
            this->heapifyDown_myVer(parent);
            return topElement;
        }

        //!why using insert repeatedly but don't use heapify()?
        std::vector<T> heapSort(std::vector<T> numList) 
        {
            //Descriptin: a function that takes in an input vector andn return a sorted input vector in ascending order
            
            // Sort an input vector using the heap sort algorithm
            Heap<T> tree1;

            // Build a min-heap from the input vector
            for(typename std::vector<T>::size_type index = 0; index < numList.size(); index++) {
                tree1.insert(numList[index]);
            }
            
            std::vector<T> sortedNumList;
            // Extract the minimum elements one by one and add them to the sorted list
            while(!tree1.isHeapEmpty()){
                sortedNumList.push_back(tree1.popTop_myVer());
                //since this is the min Heap, the first element to be pushed in is the min element
                //the second element to be pushed in the vector sortedNumList is the second smallest element
                //Thus, an ascending vector of numbers.
                //after the popTop, the rest of the Heap is rearranged to fulfil the heap requirements
                this->printVector(sortedNumList);
            }
            return sortedNumList;
        }
        
        //!Check again
        // Insert an element into the heap
        void insert(T element) 
        {

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
                swapOneBubble(parent);
                //get new parent index 
                //in the last loop when parent =1; then we change parent to this->getParentPosition(1)=floor(1/2)=0 -> ends the loop
                parent = this->getParentPosition(parent);
            }

        }
        
        //!Check again
        // Remove an (any) element from the heap
        void remove_rebuild(T value) 
        {
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
            }

            //2-heapfiy it and assign back to this->tree
            heapify_myVer2_recursionStartFromLastParentNode(new_tree);
        }

        //!Check again
        void remove_reheapify(T value)
        {
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
                    this->heapifyDown_myVer(index);
                }
            }

        }
        
        // Get the minimum element 
        T getMin() 
        {
           return this->tree.at(1);
        }
};
#endif

/*

O(1) - one set of operation happing in constant time
*/

