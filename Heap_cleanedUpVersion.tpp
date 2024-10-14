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
            //!if both are equal what will minValueChildIndex be?
            
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
        
        //can also do this but heapify from every node, not only parent node
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

        std::vector<T> heapSort(std::vector<T> numList) 
        {
            //Descriptin: a function that takes in an input vector andn return a sorted input vector in ascending order
            
            // Sort an input vector using the heap sort algorithm
            Heap<T> tree1;

            // Build a min-heap from the input vector
            for(typename std::vector<T>::size_type index = 0; index < numList.size(); index++) {
                tree1.insert(numList[index]);
            }
            //!why using insert repeatedly but don't use heapify()?
            
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
            //!not sure if I can compare with zero in data type std::vector<int>::size_type; how to remove the case when minValueChildIndex=0
            while (parent>0) //* Important notice: when do we use while loop instead of for loop? when we don't know how many iterations but we know the loop stops when a condition is no longer true.
            {
                //no need to check if the object of parent is !=NULL or if parent < tree.size() because from getParentPosition(index); it indeed is
                swapOneBubble(parent);
                //get new parent index 
                //in the last loop when parent =1; then we change parent to this->getParentPosition(1)=floor(1/2)=0 -> ends the loop
                parent = this->getParentPosition(parent);
            }

        }
        
        //! two remove functions return two correct results
        void remove_rebuild(T value) 
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
                if((this->tree.at(index) != value) && (this->tree.at(index) != (T)NULL)) 
                {
                    new_tree.push_back(this->tree.at(index));
                }
            }

            //2-heapfiy it and assign back to this->tree
            heapify_myVer2_recursionStartFromLastParentNode(new_tree);
        }

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
        
        T getMin() 
        {
           return this->tree.at(1);
        }
};
#endif


