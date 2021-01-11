//
// Created by raspberry on 2021-01-11.
//

#include "LinkedQueue.h"

template <typename T>
bool LinkedQueue<T>:: peek(T& frntEntry) const
{
    if(isEmpty())
        return false;
    frntEntry = frontPtr->getItem();
    return true;
}

#include <iostream>
template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    T temp;
    while(dequeue(temp));

}

template<typename T>
int LinkedQueue<T>::getSize() const {
    return size;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
    return (frontPtr==nullptr);
}

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
    backPtr=nullptr;
    frontPtr=nullptr;
    size=0;

}

template <typename T>
bool LinkedQueue<T>::enqueue( const T& newEntry)
{
    NodeQ<T>* newNodePtr = new NodeQ<T>(newEntry);
    // Insert the new node
    if (isEmpty())	//special case if this is the first node to insert
        frontPtr = newNodePtr; // The queue is empty
    else
        backPtr->setNext(newNodePtr); // The queue was not empty

    backPtr = newNodePtr; // New node is the last node now
    size++;
    return true ;
} // end enqueue


template <typename T>
bool LinkedQueue<T>:: dequeue(T& frntEntry)
{
    if(isEmpty())
        return false;

    NodeQ<T>* nodeToDeletePtr = frontPtr;
    frntEntry = frontPtr->getItem();
    frontPtr = frontPtr->getNext();
    // Queue is not empty; remove front
    if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
        backPtr = nullptr ;

    // Free memory reserved for the dequeued node
    nodeToDeletePtr = nullptr;
    ///// Here i did memory leak on purpose.
    //// As i actually need the mission to be passed to another data structure by just pointing to it.
    //// More clearly, when mission is assigned, it moves from waiting to inexecution. so I just make inexecution list
    //// points to its register, and the waiting list points to null.
    //// So by doing this , there is no memory leak.

    //// But then when it moves to the inexecution list. it's a linked list which deals with freeing the memory.
    //// And for other usage of the queue, I'll always keep in mind to pass the same pointers till the end of the program
    //// I'll store this in the history and then delete it in the final destructor.


    //// THE REASON that I implemented it that way, because i think it's faster in compilation as I don't need at each time
    //// to delete and create obj of the same data. so I just point to the same obj each time. I think this is more efficient maybe.


    //// Also in order to avoid obj slicing, I need to always deal with pointers in order for the polymorphism to work correctly.


//    delete [] nodeToDeletePtr;
//    free( nodeToDeletePtr);
    size--;
    return true;
}