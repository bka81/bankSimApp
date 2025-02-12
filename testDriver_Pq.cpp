// testDriver_PQ.cpp
#include <iostream>
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;

int main() {
    try {
        // Test constructor
        PriorityQueue<int> pq;
        cout << "PriorityQueue created." << endl;

        // Test isEmpty
        cout << "PriorityQueue is empty: " << std::boolalpha << pq.isEmpty() << endl;

            // Enqueueing integers
        int a = 40;
        int b = 10;
        int c = 4;
        int d = 30;
        int e = 20;

        // Test enqueue
        pq.enqueue(a);
        pq.enqueue(b);
        pq.enqueue(c);
        pq.enqueue(d);
        pq.enqueue(e);

        cout << "Enqueued 40, 10, 4, 30, 20." << endl;
        cout << "PriorityQueue is empty: " << std::boolalpha << pq.isEmpty() << endl;


        // Test peek
        cout << "Peek: " << pq.peek() << endl;

        cout << "Original PriorityQueue: "<<endl;
        pq.printPQ();

        // Test dequeue
        pq.dequeue();
        cout << "Dequeued one element." << endl;
        cout << "Peek: " << pq.peek() << endl;


        // Test copy constructor
        PriorityQueue<int> pqCopy(pq);
        cout << "PriorityQueue copy created using copy constructor." << endl;
        cout << "Peek of copied PriorityQueue: " << pqCopy.peek() << endl;

        // Test dequeue
        pq.dequeue();
        cout << "Dequeued one element from the original." << endl;
        cout << "Peek: " << pq.peek() << endl;

        // Test assignment operator
        PriorityQueue<int> pqAssign;
        pqAssign = pq;
        cout << "PriorityQueue assigned using assignment operator." << endl;
        cout << "Peek of assigned PriorityQueue: " << pqAssign.peek() << endl;
        
        // Test dequeue
        pq.dequeue();
        cout << "Dequeued one element from the original." << endl;
        cout << "Peek: " << pq.peek() << endl;

        // Test print (for testing purposes only)
        cout << "Original PriorityQueue: "<<endl;
        pq.printPQ();
        cout << "Copied PriorityQueue: "<<endl;
        pqCopy.printPQ();
        cout << "Assigned PriorityQueue: "<<endl;
        pqAssign.printPQ();
        
        // Test destructor implicitly
    } catch (const EmptyDataCollectionException& e) {
        cout << e.what() << endl;
    }

    return 0;
}