/* 
 * PriorityQueue.h
 *
 * Description: Priority Queue ADT class. Its underlying data structure
 *              is a Minimum Binary Heap. 
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 * 
 * Author: Beyzanur Kuyuk
 * Last Modification: July 19, 2024
 *
 */  

 #ifndef PRIORITYQUEUE_H
 #define PRIORITYQUEUE_H

 #include "BinaryHeap.h"
 #include "EmptyDataCollectionException.h"

 template <class ElementType>
 class PriorityQueue {

    private:

    BinaryHeap<ElementType> underlyingHeap; //Binary Heap used for Priority Queue.
    unsigned int size = 0;

    public: 

    // Description: Constructor
    PriorityQueue();

    // Description: Copy constructor
    PriorityQueue(const PriorityQueue<ElementType>& rhs);

    // Description: Assignment operator
    PriorityQueue& operator=(const PriorityQueue<ElementType>& rhs);

    // Description: Desctructor  
    ~PriorityQueue(); 
    
    /******* Start of Binary Heap  Public Interface *******/	

    // Description: Returns true if this Priority Queue is empty, otherwise false.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;
    

   // Description: Inserts "newElement" in this Priority Queue and 
   //              returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   bool enqueue(ElementType & newElement);

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   void dequeue();
   
   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;

   void printPQ() const; //for testing purposes
   
   /*******  End of Priority Queue Public Interface *******/

 };
 #include "PriorityQueue.cpp"
 #endif