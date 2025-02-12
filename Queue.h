/*
 * Queue.h
 * 
 * Description: This is an array based implementation of a Queue ADT class.
 *              
 * Class Invariant: FIFO or LILO order
 * 
 * Author: Beyzanur Kuyuk
 * Date: Last modified: July 12, 2024
 */ 
 #ifndef QUEUE_H
 #define QUEUE_H

 #include "EmptyDataCollectionException.h"

 template<class ElementType>
 class Queue {

    private:
    constexpr static unsigned int INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
    ElementType *elements = nullptr; // pointer to an array of ElementType                  
    unsigned int elementCount = 0;             // Number of elements in the Queue
    unsigned int capacity = INITIAL_CAPACITY;  // Initial capacity of the data structure (number of cells in the array)
    unsigned int frontindex = 0;               // Index of front element (next dequeued/peeked element)
    unsigned int backindex = 0;                // Index of where the next element will be enqueued                     
    
    // Description: Resizes the internal array to the new capacity. 
    // Copies the elements from the old array to the new array 
    // in the same order, starting from the frontindex. 
    // Precondition: newCapacity >= elementCount
    void resize(unsigned int newCapacity);

    // Description: Private method for deep copying.
    void deepCopy(const Queue<ElementType>& rhs);
    
    public:
    // Description: Constructor
    Queue();

    // Description: Destructor 
    ~Queue();

    // Description: Copy constructor
    Queue(const Queue<ElementType>& rhs);

    // Description: Assignment Operator
    Queue& operator=(const Queue<ElementType>& rhs);

    // Description: Inserts "newElement" at the back of this Queue 
    //              (which is not necessarily the back of this Queue's data structure) 
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType& newElement);

    // Description: Removes (but does not return) the element at the front of this Queue 
    //              (which is not necessarily the front of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns (but does not remove) the element at the front of this Queue
    //              (which is not necessarily the front of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType& peek() const;

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Returns the capacity of the array.
    unsigned int getCapacity() const;

    // Description: Returns the number of elements in the Queue.
    unsigned int getElementCount() const;

    // Description: Prints the contents of the Queue (For testing purposes)   
    void printQueue() const;
};
#include "Queue.cpp"
#endif
