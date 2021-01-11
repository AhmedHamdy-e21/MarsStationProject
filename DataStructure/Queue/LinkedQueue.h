
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers, 
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The NodeQ: item of type T and a "next" pointer
					------------- 
					| item| next | --->
					-------------
General Queue case:

                 frontPtr																backPtr
					\											   						/		
					 \											  					   /		
					------------- 	  ------------- 	  ------------- 	  ------------- 	  	  
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------	  
		
Empty Case:

                 frontptr	 backptr
						\	 /				
						 \	/				
					---- NULL ------


Single NodeQ Case:
                 frontPtr	 backPtr
					\		/	
					 \	   /			
					----------- 	
					|item| next| -->NULL
					-----------	

*/

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_


#include "NodeQ.h"
#include "QueueADT.h"
using namespace std;
template <typename T>
class LinkedQueue:public QueueADT<T>
{
private :
	NodeQ<T>* backPtr;
	NodeQ<T>* frontPtr;
	int size;
public :
	LinkedQueue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool peek(T& frntEntry)  const;	
	~LinkedQueue();
    int getSize() const;

};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/



template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;
	size=0;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr==nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

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

template <typename T>
bool LinkedQueue<T>:: peek(T& frntEntry) const 
{
	if(isEmpty())
		return false;
	frntEntry = frontPtr->getItem();
	return true;
}
///////////////////////////////////////////////////////////////////////////////////
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

#endif