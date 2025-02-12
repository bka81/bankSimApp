/* 
 * PriorityQueue.cpp
 *
 * Description: Priority Queue ADT class. Its underlying data structure
 *              is a Minimum Binary Heap. 
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 * 
 * Author: Beyzanur Kuyuk
 * Last Modification: July 12, 2024
 *
 */  

#include <iostream>
#include "BinaryHeap.h"
#include "PriorityQueue.h"

using std::cout; 
using std::endl;

// Description: Constructor
template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){}

// Description: Copy constructor
template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue(const PriorityQueue<ElementType>& rhs)
{
    underlyingHeap = rhs.underlyingHeap;
    size = rhs.size;
}

// Description: Assignment operator
template<class ElementType>
PriorityQueue<ElementType>& PriorityQueue<ElementType>::operator=(const PriorityQueue<ElementType>& rhs)
{
    if(this != &rhs)
    {
        underlyingHeap = rhs.underlyingHeap;
        size = rhs.size;
    }   
    return *this;
}

// Description: Desctructor 
template<class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
    return underlyingHeap.isEmpty();
}

// Description: Inserts "newElement" in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement)
{
    bool success = underlyingHeap.insert(newElement);
    if(success)
    {
        size++;
    }
    return success;
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void PriorityQueue<ElementType>::dequeue()
{
    if(isEmpty())
    {
        throw EmptyDataCollectionException("dequeue() called with an empty Priority Queue.");
    }
    underlyingHeap.remove();
    size--;
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const
{
    if(isEmpty())
    {
        throw EmptyDataCollectionException("peek() called with an empty Priority Queue.");
    }
    return underlyingHeap.retrieve();
}

template<class ElementType>
void PriorityQueue<ElementType>::printPQ() const //for testing purposes
{
    underlyingHeap.printHeap();
}