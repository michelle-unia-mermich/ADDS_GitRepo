#include <iostream>
#include <vector>
#include <queue>
/*
* Priority queues are a type of container
* its first element is always the greatest of the elements it contains
* similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).
! what does it mean? only the max heap element can be retrieved?
! what does this mean "from the heap, we can only remove the single element (min or max) at the root if we don't want to remake the heap again"

*/

int kth_largest(std::vector<int> values, int k)
{
    /*
        Several ways to create a priority queue from a vector
    1) Use the push command of priority_queue
        - priority_queue::push() 	Adds the element ‘g’ at the end of the queue.
        - regardless of the order you push in elements, the top value is always the largest (by default, if using max heap priority queue)
        - example: loop through each element of the vector and this->tree.push(element);
    2) To create max_heap from vector: 
        - std::priority_queue<T> max_heap_1{values.begin(), values.end()};
        OR
        - std::priority_queue max_heap_2(std::less<T>(), this->tree);
        see more at https://stackoverflow.com/questions/68427246/vectors-to-priority-queue-in-stl-c
    */

   /*
        Functions of priority_queue]
    1) priority_queue::push() 	Adds the element at the end of the queue.
        eg. priority_queue<int> gquiz;
            gquiz.push(10);
    2) priority_queue::pop()	Deletes the first element of the queue. The element removed is the one with the highest value.
        eg. gquiz.pop();
        - void pop()
        - return no value
        *Note that after popping out, the rest of the priority queue rearranges to keep the heap property
        for example
        ```
        std::priority_queue<int> mypq;
        mypq.push(30);
        mypq.push(100);
        mypq.push(25);
        mypq.push(40);
        //print out in desxcending order
        while (!mypq.empty())
        {
            std::cout << ' ' << mypq.top();
            mypq.pop();
        }
        ```
    3) priority_queue::top()	Returns a reference to the topmost element of the queue.
    4) priority_queue::size() 	Returns the size of the queue.
    5) priority_queue::empty()	Returns whether the queue is empty.
   
   */

    //convert to max_heap
    std::priority_queue<int> max_pq{values.begin(), values.end()};

    //pop k-1 elements out so the top element will be the kth largest
    for (int i=0; i<(k-1); i++)
    {
        max_pq.pop();
    }

    return max_pq.top();
}