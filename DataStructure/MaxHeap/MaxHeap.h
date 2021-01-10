//
// Created by raspberry on 2020-12-18.
//

#include "../../MissionRelated/EmergencyMission.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
template<typename T>

class MaxHeap
{
private:
    int size;
public:
    int getSize() const;
private:
    EmergencyMission * M=new EmergencyMission(-1,-1,-1,-1,-1);
    vector<EmergencyMission*>vect={M};
    /// Functions the position of the parent
    int p(int i) {return i>>1;}; // i/2
    int l( int i ) {return i<<1;}; // i*2
    int r(int i) {return (i<<1)+1;}; // i *2 +1
public:
    MaxHeap();
    vector<T> getVect();
    void maxHeapify();
    bool isEmpty() const ;
    T getMax() const ;
    void insertItem(T value);
    void shiftUp(int i);  // index of the item that we're inserting
    T extractMax();  // to popping up an item from the vector // replace with the smallest element and then eliminate
    void shiftDown(int i);
    void printHeap() const ;

};

