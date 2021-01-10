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
//    vector<T> vect={EmergencyMission(-1,-1,-1,-1,-1)};
    EmergencyMission * M=new EmergencyMission(-1,-1,-1,-1,-1);
    vector<EmergencyMission*>vect={M};

    /// Functions the position of the parent
    int p(int i) {return i>>1;}; // i/2
    int l( int i ) {return i<<1;}; // i*2
    int r(int i) {return (i<<1)+1;}; // i *2 +1

public:


    MaxHeap();


    vector<T> getVect()
    {
        if (size==0)
        {
            cout<<"\nThe vector is empty You might get en error if you're trying to access any member\n";
        }
        return vect;
    }

    void maxHeapify();

    bool isEmpty() const { return size== 0;};
    T getMax() const { return vect[0];};
    void insertItem(T value);
    void shiftUp(int i);  // index of the item that we're inserting
    T extractMax();  // to popping up an item from the vector // replace with the smallest element and then eliminate
    void shiftDown(int i);
//    void printHeap() const
//    {
//        for (auto it = begin (vect); it != end (vect); ++it) {
//            cout<<*it<< ' ';
//        }
//    }
    void printHeap() const ;

    //this is just for misison

};

//
//
//template <typename T>
//class MaxHeapMission<T>
//{
//
//};
//void MaxHeap<Mission>::printHeap() const {
//    for (auto it = begin(vect); it != end(vect); ++it) {
//        it->Print();
//    }
//}

//}

