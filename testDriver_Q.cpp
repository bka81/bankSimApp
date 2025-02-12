#include <iostream>
#include "Queue.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;

int main() {
    Queue<int> intQueue;

    // Enqueueing integers
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    
    cout << "Enqueuing integers:" << endl;
    intQueue.enqueue(a);
    intQueue.enqueue(b);
    intQueue.enqueue(c);
    intQueue.enqueue(d);

    // Print the queue contents
    cout << "Queue contents after enqueuing:" << endl;
    intQueue.printQueue();

    // Dequeue an integer
    cout << "\nDequeueing an integer..." << endl;
    intQueue.dequeue();

    // Print the queue contents after dequeuing
    cout << "Queue contents after dequeuing:" << endl;
    intQueue.printQueue();

    // Peek at the front integer
    cout << "\nPeeking at the front integer..." << endl;
    int frontInt = intQueue.peek();
    cout << "Front integer: " << frontInt << endl;
    
    // Dequeue all remaining integers
    cout << "\nDequeueing all remaining integers..." << endl;
    while (!intQueue.isEmpty()) {
        intQueue.dequeue();
        intQueue.printQueue();
    }

    return 0;
}