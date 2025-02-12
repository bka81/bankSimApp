/* 
 * BankSimApp.cpp
 *
 * Description: An event-driven simulation of a bank.
 *
 * Class Invariant:  The arrival events and departure events are sorted by the time of the event based on priority.
 * 
 * Author: Beyzanur Kuyuk
 * Last Modification: July 19, 2024
 *
 */  

#include <iostream>
#include <iomanip>
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;
using std::cin;
using std::setw;

void processArrival(const Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable, int& currentTime);
void processDeparture(const Event& departureEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable, int& currentTime, double& totalWaitingTime);

int main()
{
    //empty Queue for the bank line:
    Queue<Event> bankLine;

    //empty Priority Queue for the event list:
    PriorityQueue<Event> eventPriorityQueue;

    bool tellerAvailable = true;
    int totalCustomers = 0;
    double totalWaitingTime = 0;

    //Read input
    int arrivalTime, transactionTime;
    while(cin >> arrivalTime >> transactionTime)
    {
        Event newArrivalEvent('A', arrivalTime, transactionTime);
        eventPriorityQueue.enqueue(newArrivalEvent);
        totalCustomers++;
    }

    //Event loop

    cout<<"Simulation Begins"<<endl;

    while(!eventPriorityQueue.isEmpty())
    {
        Event newEvent = eventPriorityQueue.peek();
        //Get current time
        int currentTime = newEvent.getTime();

        if(newEvent.getType() == 'A')
        {
            processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
        }
        else
        {
            processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime, totalWaitingTime);
        }
    }

    double avgWaitingTime = (totalWaitingTime / totalCustomers);
    cout<<"Simulation Ends"<<endl<<endl;

    //Statistics:
    cout<<"Final Statistics:"<<endl<<endl;
    cout<<"    Total number of people processed: "<< totalCustomers << endl;
    cout<<"    Average amount of time spent waiting: " << avgWaitingTime << endl;

    return 0;
}

void processArrival(const Event& arrivalEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable, int& currentTime)
{
    //Remove this event from the event queue
    eventPriorityQueue.dequeue();
    Event customer = arrivalEvent;

    cout<<"Processing an arrival event at time: " << setw(5) << arrivalEvent.getTime() << endl;

    if(bankLine.isEmpty() && tellerAvailable)
    {
        int departureTime = currentTime + customer.getLength();
        Event newDepartureEvent('D', departureTime);
        eventPriorityQueue.enqueue(newDepartureEvent);
        tellerAvailable = false;
    }
    else
    {
        bankLine.enqueue(customer);
    }
}

void processDeparture(const Event& departureEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable, int& currentTime, double& totalWaitingTime)
{
    //Remove this event from the event queue
    eventPriorityQueue.dequeue();

    cout << "Processing a departure event at time: " << setw(4) << departureEvent.getTime() << endl;

    if(!bankLine.isEmpty())
    {
        //Customer at front of line begins transaction
        Event customer = bankLine.peek();
        bankLine.dequeue();
        int departureTime = currentTime + customer.getLength();
        Event newDepartureEvent('D', departureTime);
        eventPriorityQueue.enqueue(newDepartureEvent);

        totalWaitingTime += (currentTime - customer.getTime());
    }
    else
    {
        tellerAvailable = true;
    }

}