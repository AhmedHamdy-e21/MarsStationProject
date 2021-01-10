//
// Created by raspberry on 2020-11-30.
//

#include "MissionList.h"


MissionList::MissionList()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EmergencyMission *MissionList::getEmergencyMission() {
    EmergencyMission *Em = WaitingEmergencyMissionHeap.extractMax();;
    return Em;
}
const MaxHeap<EmergencyMission*> MissionList::getWaitingEmergencyMissionHeap() const
{
    return WaitingEmergencyMissionHeap;
}
void MissionList::addEmergencyMission(EmergencyMission *EMission)
{
    WaitingEmergencyMissionHeap.insertItem(EMission);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const LinkedQueue<PolarMission*> MissionList::getWaitingPolarMissionQueue() const
{
    return WaitingPolarMissionQueue;
}
void MissionList::addPolarMission(PolarMission *PMission)
{

    WaitingPolarMissionQueue.enqueue(PMission);
}
PolarMission *MissionList::getPolarMission() {
    PolarMission * P;
    WaitingPolarMissionQueue.dequeue(P);
    return P;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const LinkedListMissions<MountainousMission*> MissionList::getWaitingMountainousMissionList() const
{
    return WaitingMountainousMissionList;
}
void MissionList::addMountainousMission( MountainousMission *MMission)
{
        WaitingMountainousMissionList.InsertBeg(MMission);
}
MountainousMission *MissionList::getMountainousMission() {
    MountainousMission * M=WaitingMountainousMissionList.getHead()->getItem();
    WaitingMountainousMissionList.DeleteFirst();
    return M;
}
void MissionList::cancelMountainousMission(int ID)
{
    WaitingMountainousMissionList.DeleteNode(ID);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





MissionList::~MissionList() {

}

int MissionList::getNoOfCompletedPolar() const {
    return NoOfCompletedPolar;
}

int MissionList::getNoOfCompletedEmergency() const {
    return NoOfCompletedEmergency;
}

int MissionList::getNoOfCompletedMountainous() const {
    return NoOfCompletedMountainous;
}

void MissionList::setNoOfCompletedPolar(int noOfCompletedPolar) {
    NoOfCompletedPolar = noOfCompletedPolar;
}

void MissionList::setNoOfCompletedEmergency(int noOfCompletedEmergency) {
    NoOfCompletedEmergency = noOfCompletedEmergency;
}

void MissionList::setNoOfCompletedMountainous(int noOfCompletedMountainous) {
    NoOfCompletedMountainous = noOfCompletedMountainous;
}

const LinkedListMissions<MountainousMission *> &MissionList::getInExecutionMountainous() const {
    return InExecutionMountainous;
}

const LinkedListMissions<EmergencyMission *> &MissionList::getInExecutionEmergency() const {
    return InExecutionEmergency;
}

const LinkedListMissions<PolarMission *> &MissionList::getInExecutionPolar() const {
    return InExecutionPolar;
}

void MissionList::addInExecutionEmergency(EmergencyMission *EMission)
{
    InExecutionEmergency.InsertBeg(EMission);
}

void MissionList::deleteInExecutionEmergency(int ID)
{
    InExecutionEmergency.DeleteNode(ID);
}

void MissionList::addInExecutionPolar(PolarMission *EMission)
{
    InExecutionPolar.InsertBeg(EMission);
}

void MissionList::deleteInExecutionPolar(int ID)
{
    InExecutionPolar.DeleteNode(ID);
}

void MissionList::addInExecutionMountainous(MountainousMission *EMission)
{
    InExecutionMountainous.InsertBeg(EMission);

}

void MissionList::deleteInExecutionMountainous(int ID)
{
    InExecutionMountainous.DeleteNode(ID);

}

int MissionList::getNoOfWaitingEmergencyMission() const {
    return WaitingEmergencyMissionHeap.getSize();
}

int MissionList::getNoOfWaitingPolarMission() const {
    return WaitingPolarMissionQueue.getSize();
}

int MissionList::getNoOfWaitingMountainousMission() const {
    return WaitingMountainousMissionList.getCount();
}

int MissionList::getNoOfInExecutionMountainous() const {
    return InExecutionMountainous.getCount();
}

int MissionList::getNoOfInExecutionEmergency() const {
    return InExecutionEmergency.getCount();
}

int MissionList::getNoOfInExecutionPolar() const {
    return InExecutionPolar.getCount();
}




