//
// Created by raspberry on 2021-01-08.
//

#ifndef _NODE
#define _NODE
template <typename T>
class NodeQ
{
private:
    T item; // A data item
    NodeQ<T>* next; // Pointer to next node
public :
    NodeQ();
    NodeQ(const T & r_Item);
    NodeQ(const T & r_Item, NodeQ<T>* nextNodePtr);
    void setItem(const T & r_Item);
    void setNext(NodeQ<T>* nextNodePtr);
    T getItem() const ;
    NodeQ<T>* getNext() const ;
}; // end NodeQ
#endif
