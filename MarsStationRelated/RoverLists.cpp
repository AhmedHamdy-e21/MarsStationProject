//
// Created by raspberry on 2021-01-10.
//

#include "RoverLists.h"
#include "../DataStructure/Queue/LinkedQueue.cpp"
const LinkedQueue<EmergencyRover *> &RoverLists::getAvailableEmergencyRovers() const {
    return AvailableEmergencyRovers;
}

const LinkedQueue<PolarRover *> &RoverLists::getAvailablePolarRovers() const {
    return AvailablePolarRovers;
}

const LinkedQueue<MountainousRover *> &RoverLists::getAvailableMountainousRovers() const {
    return AvailableMountainousRovers;
}

int RoverLists::getNoOfAvailableEmergencyRovers() const {
    return AvailableEmergencyRovers.getSize();
}

int RoverLists::getNoOfAvailablePolarRovers() const {
    return AvailablePolarRovers.getSize();
}

int RoverLists::getNoOfAvailableMountainousRovers() const {
    return AvailableMountainousRovers.getSize();
}

const LinkedListMissions<EmergencyRover *> &RoverLists::getInMissionEmergencyRovers() const {
    return InMissionEmergencyRovers;
}

const LinkedListMissions<PolarRover *> &RoverLists::getInMissionPolarRovers() const {
    return InMissionPolarRovers;
}

const LinkedListMissions<MountainousRover *> &RoverLists::getInMissionMountainousRovers() const {
    return InMissionMountainousRovers;
}

int RoverLists::getNoOfInMissionEmergencyRovers() const {
    return InMissionEmergencyRovers.getCount();
}

int RoverLists::getNoOfInMissionPolarRovers() const {
    return InMissionPolarRovers.getCount();
}

int RoverLists::getNoOfInMissionMountainousRovers() const {
    return InMissionMountainousRovers.getCount();
}

const LinkedListMissions<EmergencyRover *> &RoverLists::getInCheckupEmergencyRovers() const {
    return InCheckupEmergencyRovers;
}

const LinkedListMissions<PolarRover *> &RoverLists::getInCheckupPolarRovers() const {
    return InCheckupPolarRovers;
}

const LinkedListMissions<MountainousRover *> &RoverLists::getInCheckupMountainousRovers() const {
    return InCheckupMountainousRovers;
}

int RoverLists::getNoOfInCheckupEmergencyRovers() const {
    return InCheckupEmergencyRovers.getCount();
}

int RoverLists::getNoOfInCheckupPolarRovers() const {
    return InCheckupPolarRovers.getCount();
}

int RoverLists::getNoOfInCheckupMountainousRovers() const {
    return InCheckupMountainousRovers.getCount();
}

void RoverLists::addAvailableEmergencyRover(EmergencyRover *ER)
{
    AvailableEmergencyRovers.enqueue(ER);

}



void RoverLists::addAvailablePolarRover(PolarRover *PR)
{
    AvailablePolarRovers.enqueue(PR);

}


void RoverLists::addAvailableMountainousRover(MountainousRover *ER)
{
    AvailableMountainousRovers.enqueue(ER);

}

MountainousRover *RoverLists::getAvailableMountainousRover()
{
    bool isAvailable;
    MountainousRover* M;
    isAvailable=AvailableMountainousRovers.dequeue(M);
    if(isAvailable)
    {
        return M;
    }
    return nullptr;
}

PolarRover *RoverLists::getAvailablePolarRover()
{
    bool isAvailable;
    PolarRover* M;
    isAvailable=AvailablePolarRovers.dequeue(M);
    if(isAvailable)
    {
        return M;
    }
    return nullptr;
}

EmergencyRover *RoverLists::getAvailableEmergencyRover()
{
    bool isAvailable;
    EmergencyRover* M;
    isAvailable=AvailableEmergencyRovers.dequeue(M);
    if(isAvailable)
    {
        return M;
    }
    return nullptr;
}

void RoverLists::addInMissionEmergencyRover(EmergencyRover *ER)
{
    InMissionEmergencyRovers.InsertBeg(ER);
}

EmergencyRover *RoverLists::getInMissionEmergencyRover()
{
    EmergencyRover * ReturnedObj=(InMissionEmergencyRovers.DeleteFirst());
    return ReturnedObj;
}

void RoverLists::addInCheckupEmergencyRover(EmergencyRover *ER)
{
   InCheckupEmergencyRovers.InsertBeg(ER);


}

EmergencyRover *RoverLists::getInCheckupEmergencyRover() {
    EmergencyRover * ReturnedObj=(InCheckupEmergencyRovers.DeleteFirst());
    return ReturnedObj;
}

void RoverLists::addInMissionPolarRover(PolarRover *PR)
{
    InMissionPolarRovers.InsertBeg(PR);

}

PolarRover *RoverLists::getInMissionPolarRover() {
    PolarRover * ReturnedObj=(InMissionPolarRovers.DeleteFirst());
    return ReturnedObj;
}

void RoverLists::addInCheckupPolarRover(PolarRover *PR)
{
    InCheckupPolarRovers.InsertBeg(PR);


}

PolarRover *RoverLists::getInCheckupPolarRover() {
    PolarRover * ReturnedObj=(InCheckupPolarRovers.DeleteFirst());
    return ReturnedObj;
}

void RoverLists::addInMissionMountainousRover(MountainousRover *ER)
{
    InMissionMountainousRovers.InsertBeg(ER);

}

MountainousRover *RoverLists::getInMissionMountainousRover() {
    MountainousRover * ReturnedObj=(InMissionMountainousRovers.DeleteFirst());
    return ReturnedObj;
}

void RoverLists::addInCheckupMountainousRover(MountainousRover *ER)
{
    InCheckupMountainousRovers.InsertBeg(ER);
}

MountainousRover *RoverLists::getInCheckupMountainousRover() {
    MountainousRover * ReturnedObj=(InCheckupMountainousRovers.DeleteFirst());
    return ReturnedObj;
}

void RoverLists::addMultipleAvailableEmergencyRovers(int NumberOfEmergencyRovers,int Speed, int CheckupDuration, int NoCheckupMissions,int ID)
{
     int i=0;
     int n=getNoOfAvailablePolarRovers()+getNoOfAvailableMountainousRovers();
    for ( i = 0; i <NumberOfEmergencyRovers ; ++i)
    {
        EmergencyRover* ER=new EmergencyRover(Speed,CheckupDuration,NoCheckupMissions,i+n);
        addAvailableEmergencyRover(ER);
    }
//    cout<< "\nAdded "<<AvailableEmergencyRovers.getSize()<<" Emergency Rovers to be Available\n";
//    EmergencyRover* MR;
//    cout<< "My information is: ";AvailableEmergencyRovers.peek(MR);
//    MR->Print();

}

void RoverLists::addMultipleAvailablePolarRovers(int NumberOfPolarRovers,int Speed, int CheckupDuration, int NoCheckupMissions,int ID)
{
    int i=0;
    int n=getNoOfAvailableMountainousRovers(); // This is to generate ids for rovers
    for ( i = 0; i <NumberOfPolarRovers ; ++i)
    {
        PolarRover* PR=new PolarRover(Speed,CheckupDuration,NoCheckupMissions,i+n);
        addAvailablePolarRover(PR);
    }
//    cout<< "\nAdded "<<AvailablePolarRovers.getSize()<<" Polar Rovers to be Available\n";
//    PolarRover* MR;
//    cout<< "My information is: ";AvailablePolarRovers.peek(MR);
//    MR->Print();
}

void RoverLists::addMultipleAvailableMountainousRovers(int NumberOfMountainousRovers,int Speed, int CheckupDuration, int NoCheckupMissions,int ID)
{
    int i=0;
    for ( i = 0; i <NumberOfMountainousRovers ; ++i)
    {
        MountainousRover* MR=new MountainousRover(Speed,CheckupDuration,NoCheckupMissions, i);
        addAvailableMountainousRover(MR);
    }
//    cout<< "\nAdded "<<AvailableMountainousRovers.getSize()<<" Mountainous Rovers to be Available\n";
//    MountainousRover* MR;
//
//    cout<< "My information is: ";AvailableMountainousRovers.peek(MR);
//    MR->Print();
}

EmergencyRover *RoverLists::peekAvailableEmergencyRover()
{
    EmergencyRover* ER;
    AvailableEmergencyRovers.peek(ER);
    return ER;
}

PolarRover *RoverLists::peekAvailablePolarRover()
{
    PolarRover* PR;
    AvailablePolarRovers.peek(PR);
    return PR;
}

MountainousRover *RoverLists::peekAvailableMountainousRover()
{
    MountainousRover* MR;
    AvailableMountainousRovers.peek(MR);
    return MR;
}

