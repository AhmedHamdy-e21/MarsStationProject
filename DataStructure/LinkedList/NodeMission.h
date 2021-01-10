//
// Created by raspberry on 2021-01-09.
//

#ifndef CUSTOMIZED_LINKED_LIST_CLASS_NODEMISSION_H
#define CUSTOMIZED_LINKED_LIST_CLASS_NODEMISSION_H

template<typename T>
class NodeMission {

private :
    T item;	// A data item (can be any complex sturcture)
    NodeMission<T>* next;	// Pointer to next node
public :

    NodeMission( ) //default constructor
    {
        next= nullptr;
    }

    NodeMission( T newItem) //non-default constructor
    {
        item = newItem;
        next= nullptr;

    }

    void setItem( T newItem)
    {
        item = newItem;
    } // end setItem

    void setNext(NodeMission<T>* nextNodePtr)
    {
        next = nextNodePtr;
    } // end setNext

    T getItem() const
    {
        return item;
    } // end getItem

    NodeMission<T>* getNext() const
    {
        return next;
    }
}; // end NodeMission

#endif
