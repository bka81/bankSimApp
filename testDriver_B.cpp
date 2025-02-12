#include <iostream>
#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;

int main() {
    BinaryHeap<int> intBinaryHeap;

    // Enqueueing integers
    int a = 30;
    int b = 40;
    int c = 10;
    int d = 5;
    
    cout << "Enqueuing integers:" << endl;
    intBinaryHeap.insert(a);
    intBinaryHeap.insert(b);
    intBinaryHeap.insert(c);
    intBinaryHeap.insert(d);

    // Print the queue contents
    cout << "BinaryHeap contents after enqueuing:" << endl;
    intBinaryHeap.printHeap();

    // Dequeue an integer
    cout << "\nRemoving an integer..." << endl;
    intBinaryHeap.remove();

    // Print the queue contents after dequeuing
    cout << "BinaryHeap contents after dequeuing:" << endl;
    intBinaryHeap.printHeap();

    // Peek at the front integer
    cout << "\nPeeking at the front integer..." << endl;
    int frontInt = intBinaryHeap.retrieve();
    cout << "Front integer: " << frontInt << endl;
    
    // Dequeue all remaining integers
    cout << "\nRemoving all remaining integers..." << endl;
    while (!intBinaryHeap.isEmpty()) {
        intBinaryHeap.remove();
        intBinaryHeap.printHeap();
    }

    return 0;
}