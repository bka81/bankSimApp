/* 
 * Queue.cpp
 *
 * Description: This is an array based implementation of a Queue ADT class.
 *
 * Class Invariant: FIFO or LILO order
 *
 * Author: Beyzanur Kuyuk
 * Date: Last modified: July 12, 2024
 */

 #include "Queue.h"
 #include <iostream>

 using std::cout;
 using std::endl;

 // Description: Constructor
 template <class ElementType>
 Queue<ElementType>::Queue()
 {
   elements = new ElementType[INITIAL_CAPACITY];
 }

 // Description: Destructor 
 template<class ElementType>
 Queue<ElementType>::~Queue()
 {
   delete[] elements;
 }

 // Description: Copy constructor
 template <class ElementType>
 Queue<ElementType>::Queue(const Queue<ElementType>& rhs)
 {
   deepCopy(rhs);
 }

 // Description: Assignment Operator
 template <class ElementType>
 Queue<ElementType>& Queue<ElementType>::operator=(const Queue<ElementType>& rhs)
 {
   if (this != &rhs)
   {
      delete[] elements;
      elements = nullptr;
      deepCopy(rhs);
   }
   return *this;
 }

 //Description: private method for deep copying.
 template <class ElementType>
 void Queue<ElementType>::deepCopy(const Queue<ElementType>& rhs)
 {
   elementCount = rhs.elementCount;
   capacity = rhs.capacity;
   frontindex = rhs.frontindex;
   backindex = rhs.backindex;

   elements = new ElementType[capacity];
   for(unsigned int i = 0 ; i < elementCount; i++)
   {
   elements[(frontindex+i) % capacity] = rhs.elements[(frontindex+i) % capacity] ;
   }
 }

 // Description: Resizes the internal array to the new capacity. 
 // Copies the elements from the old array to the new array 
 // in the same order, starting from the frontindex. 
 // Precondition: newCapacity >= elementCount
 template<class ElementType>
 void Queue<ElementType>::resize(unsigned int newCapacity)
 {
   ElementType* newElements = new ElementType[newCapacity];
   for(unsigned int i = 0; i<elementCount; i++)
   {
      newElements[i] = elements[(frontindex+i) % capacity];
   }
   delete[] elements;
   elements = newElements; 
   frontindex = 0;
   backindex = elementCount; 
   capacity = newCapacity;
 }

 // Description: Inserts "newElement" at the back of this Queue 
 //              (which is not necessarily the back of this Queue's data structure) 
 //              and returns true if successful, otherwise false.
 // Time Efficiency: O(1)
 template<class ElementType>
 bool Queue<ElementType>::enqueue(ElementType& newElement)
 {
   if(elementCount == capacity)
   {
      resize(capacity * 2);
   }
   elements[backindex] = newElement;
   backindex = (backindex + 1) % capacity;  
   elementCount++;
   return true; 
 }

 // Description: Removes (but does not return) the element at the front of this Queue 
 //              (which is not necessarily the front of this Queue's data structure).
 // Precondition: This Queue is not empty.
 // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
 // Time Efficiency: O(1)
 template<class ElementType>
 void Queue<ElementType>::dequeue()
 {
   if(isEmpty())
   {
      throw EmptyDataCollectionException("Queue is empty");
   }
   frontindex = (frontindex + 1) % capacity;
   elementCount--;
   if(elementCount < (capacity/4) && (capacity/2) >= INITIAL_CAPACITY)
   {
      resize(capacity/2);
   }
 }

 // Description: Returns (but does not remove) the element at the front of this Queue
 //              (which is not necessarily the front of this Queue's data structure).
 // Precondition: This Queue is not empty.
 // Postcondition: This Queue is unchanged by this operation.
 // Exception: Throws EmptyDataCollectionException if this Queue is empty.
 // Time Efficiency: O(1)
 template<class ElementType>
 ElementType& Queue<ElementType>::peek() const 
 {
   if(isEmpty())
   {
      throw EmptyDataCollectionException("Queue is empty");
   }
   return elements[frontindex];    
 }

 // Description: Returns true if this Queue is empty, otherwise false.
 // Postcondition: This Queue is unchanged by this operation.
 // Time Efficiency: O(1)
 template<class ElementType>
 bool Queue<ElementType>::isEmpty() const
 {
   return elementCount == 0;
 }

 //Description: Returns the capacity of the array.
 template<class ElementType>
 unsigned int Queue<ElementType>::getCapacity()const
 {
   return capacity;
 }

//Description: Returns the number of elements in the Queue.
template<class ElementType>
unsigned int Queue<ElementType>::getElementCount()const
{
  return elementCount;
}

// Description: Prints the contents of the Queue (For testing purposes)   
template <class ElementType>
void Queue<ElementType>::printQueue() const
{
  for(unsigned int i = 0; i<elementCount; i++)
  {
    cout<<elements[(frontindex + i) % capacity]<<endl;
  }
}
//end of Queue.cpp
