/* 
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 * 
 * Author: Beyzanur Kuyuk
 * Last Modification: July 12, 2024
 *
 */  

 #ifndef BINARYHEAP_H
 #define BINARYHEAP_H

 #include "EmptyDataCollectionException.h"

 template<class ElementType>
 class BinaryHeap{
   private:

   constexpr static unsigned int INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
   ElementType * elements = nullptr; //Array to store the elements in the binary heap
   unsigned int elementCount = 0; //Number of elements in the binary heap
   unsigned int capacity = INITIAL_CAPACITY; //Number of cells in the array

   //Description: Private method for deep copying Binary Heap.
   void deepCopy(const BinaryHeap<ElementType>& rhs);
   
   // Description: Resizes the internal array to the new capacity. 
   // Copies the elements from the old array to the new array 
   // in the same order.
   // Precondition: newCapacity >= elementCount
   void resize(unsigned int newCapacity);
   
   // Utility method
   // Description: Recursively put the array back into a Minimum Binary Heap.
   void reHeapUp(unsigned int indexOfBottom);

   // Utility method
   // Description: Recursively put the array back into a Minimum Binary Heap.
   void reHeapDown(unsigned int indexOfRoot);

   public:

   // Description: Constructor
   BinaryHeap();
   
   // Descriptipn: Copy constructor
   BinaryHeap(const BinaryHeap<ElementType>& rhs);

   // Description: Assignment operator
   BinaryHeap& operator=(const BinaryHeap<ElementType>& rhs);

   // Description: Desctructor  
   ~BinaryHeap();

   //Public Interface:
   
   // Description: Returns the number of element in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1).
   unsigned int getElementCount()const;

   //Description: Inserts "newElement" into the Binary Heap.
   //             It returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   bool insert(ElementType & newElement);

   //Description: Removes (but does not return) the necessary element.
   //Precondition: This Binary Heap is not empty.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   void remove();

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
   ElementType & retrieve() const;

  // Description: Returns true if this Binary Heap is empty, otherwise false.
  // Postcondition: This Binary Heap is unchanged by this operation.
  // Time Efficiency: O(1)
  bool isEmpty() const;

  // Description: Prints the contents of the BinaryHeap (For testing purposes)   
  void printHeap() const;

 };
 #include "BinaryHeap.cpp"
 #endif
