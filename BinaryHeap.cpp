/* 
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 * 
 * Author: Beyzanur Kuyuk
 * Last Modification: July 12, 2024
 *
 */  

#include <iostream>
#include <cmath>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;

// Description: Constructor
template<class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
   elements = new ElementType[INITIAL_CAPACITY];
}

// Description: Copy constructor
template<class ElementType>
BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap<ElementType>& rhs)
{
   deepCopy(rhs);
}

// Description: Assignment operator
template<class ElementType>
BinaryHeap<ElementType>& BinaryHeap<ElementType>::operator=(const BinaryHeap<ElementType>& rhs)
{
   if(this != &rhs)
   {
      delete[] elements;
      elements = nullptr;
      deepCopy(rhs);
   }
   return *this;
}

// Description: Private method for deep copying Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::deepCopy(const BinaryHeap<ElementType>& rhs)
{
   elementCount = rhs.elementCount;
   capacity = rhs.capacity;

   elements = new ElementType[capacity];
   for(unsigned int i = 0; i < elementCount; i++)
   {
      elements[i] = rhs.elements[i];
   }
}

// Description: Desctructor  
template<class ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
   delete[] elements;
   elements = nullptr;
}

// Description: Resizes the internal array to the new capacity. 
// Copies the elements from the old array to the new array 
// in the same order.
// Precondition: newCapacity >= elementCount
template<class ElementType>
void BinaryHeap<ElementType>::resize(unsigned int newCapacity)
{
   ElementType* newElements = new ElementType[newCapacity];
   for(unsigned int i = 0; i < elementCount; i++)
   {
      newElements[i] = elements[i];
   }
   delete[] elements;
   elements = newElements;
   capacity = newCapacity;
}

// Description: Returns the number of element in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1).
template<class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount()const
{
   return elementCount;
}


//Description: Inserts "newElement" into the Binary Heap.
//             It returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement)
{
   if(elementCount == capacity)
   {
      resize(capacity * 2);
   }
   elements[elementCount] = newElement;
   reHeapUp(elementCount);
   elementCount++;
   return true;
}

// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom)
{
   // if the element has a parent
   if(indexOfBottom > 0)
   {
      unsigned int indexOfParent = floor((indexOfBottom - 1) / 2);

      if(!(elements[indexOfParent] <= elements[indexOfBottom]))
      {
         //swap the element with its parent
         ElementType temp = elements[indexOfParent];
         elements[indexOfParent] = elements[indexOfBottom];
         elements[indexOfBottom] = temp;
         reHeapUp(indexOfParent);
      }
   }
   return;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(isEmpty()) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   
   // No need to call reheapDown() if we have just removed the only element
   if ( elementCount > 0 ) 
   {
      reHeapDown(0);
   }
   if(elementCount < (capacity/4) && (capacity/2) >= INITIAL_CAPACITY)
   {
      resize(capacity/2);
   }

   return;   
}

// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = (2 * indexOfRoot) + 1;
   unsigned int indexOfRightChild = (2 * indexOfRoot) + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template<class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const
{
   if(isEmpty())
   {
      throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
   }
   return elements[0];
}

// Description: Returns true if this Binary Heap is empty, otherwise false.
// Postcondition: This Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool BinaryHeap<ElementType>::isEmpty() const
{
   return elementCount == 0;
}

// Description: Prints the contents of the BinaryHeap (For testing purposes)   
template <class ElementType>
void BinaryHeap<ElementType>::printHeap() const
{
  for(unsigned int i = 0; i < elementCount; i++)
  {
    cout<<elements[i]<<endl;
  }
}
//end of BinaryHeap.cpp


