#include "RecursiveBinarySearch.h"

/*
* In recursive binary search, the parameter list should include a sorted list of elements, an element to be searched, a starting point and an ending point.
* consider how you will implement this approach while still providing the interface to the user that only requires the list and item to be searched for.

When we search, we examine the middle element of our array. If we find the element we are looking for, return the index of the element. If the element we are looking for has value less than the middle element, call binary search with the same starting point and an ending point one position less than the current middle index. If the element we are looking for has a value greater than the middle element, call binary search with the same ending point and a starting point one greater than the current middle index.

*/

/*
*Method 1
binarySearchRecursive: This function performs the actual recursive binary search. It takes the array (arr), target element (target), left and right indices of the search space.
The function calculates the mid index and compares the element at the middle with the target.
If the target is found, it returns the index. Otherwise, it recursively calls itself on the left or right half of the array based on the target value.
binarySearch: This is a wrapper function that initiates the recursive binary search by calling binarySearchRecursive with initial parameters.


// Recursive Binary Search Function 
int binarySearchRecursive(const std::vector<int>& arr, int target, int left, int right) { 
    if (left <= right) { 
        int mid = left + (right - left) / 2; 
 
        // If the target is at the middle 
        if (arr[mid] == target) { 
            return mid; 
        } 
 
        // If the target is in the left half 
        if (arr[mid] > target) { 
            return binarySearchRecursive(arr, target, left, mid - 1); 
        } 
 
        // If the target is in the right half 
        return binarySearchRecursive(arr, target, mid + 1, right); 
    } 
 
    // If the target is not present in the array 
    return -1; 
} 
 
// Wrapper function for binary search 
int binarySearch(const std::vector<int>& arr, int target) { 
    return binarySearchRecursive(arr, target, 0, arr.size() - 1); 
} 

*/

bool binarySearchRecursive(const std::vector<int>& arr, int target, int start, int end) { 
    if (start <= end) { 
        int mid = start + (end - start) / 2; 
 
        // If the target is at the middle 
        if (arr[mid] == target) { 
            return true; 
        } 
 
        // If the target is in the left half 
        if (arr[mid] > target) { 
            return binarySearchRecursive(arr, target, start, mid - 1); 
        } 
 
        // If the target is in the right half 
        return binarySearchRecursive(arr, target, mid + 1, end); 
    } 
 
    // If the target is not present in the array 
    return false; 
} 


bool RecursiveBinarySearch::search(std::vector<int> vect, int target)
{
    //this is used to determine whether a number belongs to the list or not, not returning index
    return binarySearchRecursive(vect, target, 0, vect.size() - 1); 

}