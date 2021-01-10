//
// Created by raspberry on 2020-11-30.
//

#include "MissionLists.h"


MissionLists::MissionLists()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EmergencyMission *MissionLists::getEmergencyMission() {
    EmergencyMission *Em = WaitingEmergencyMissionHeap.extractMax();;
    return Em;
}
const MaxHeap<EmergencyMission*> MissionLists::getWaitingEmergencyMissionHeap() const
{
    return WaitingEmergencyMissionHeap;
}
void MissionLists::addEmergencyMission(EmergencyMission *EMission)
{
    WaitingEmergencyMissionHeap.insertItem(EMission);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const LinkedQueue<PolarMission*> MissionLists::getWaitingPolarMissionQueue() const
{
    return WaitingPolarMissionQueue;
}
void MissionLists::addPolarMission(PolarMission *PMission)
{

    WaitingPolarMissionQueue.enqueue(PMission);
}
PolarMission *MissionLists::getPolarMission() {
    PolarMission * P;
    WaitingPolarMissionQueue.dequeue(P);
    return P;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const LinkedListMissions<MountainousMission*> MissionLists::getWaitingMountainousMissionList() const
{
    return WaitingMountainousMissionList;
}
void MissionLists::addMountainousMission(MountainousMission *MMission)
{
        WaitingMountainousMissionList.InsertBeg(MMission);
}
MountainousMission *MissionLists::getMountainousMission() {
    MountainousMission * M=WaitingMountainousMissionList.getHead()->getItem();
    WaitingMountainousMissionList.DeleteFirst();
    return M;
}
void MissionLists::cancelMountainousMission(int ID)
{
    WaitingMountainousMissionList.DeleteNode(ID);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





MissionLists::~MissionLists() {

}

int MissionLists::getNoOfCompletedPolar() const {
    return NoOfCompletedPolar;
}

int MissionLists::getNoOfCompletedEmergency() const {
    return NoOfCompletedEmergency;
}

int MissionLists::getNoOfCompletedMountainous() const {
    return NoOfCompletedMountainous;
}

void MissionLists::setNoOfCompletedPolar(int noOfCompletedPolar) {
    NoOfCompletedPolar = noOfCompletedPolar;
}

void MissionLists::setNoOfCompletedEmergency(int noOfCompletedEmergency) {
    NoOfCompletedEmergency = noOfCompletedEmergency;
}

void MissionLists::setNoOfCompletedMountainous(int noOfCompletedMountainous) {
    NoOfCompletedMountainous = noOfCompletedMountainous;
}

const LinkedListMissions<MountainousMission *> &MissionLists::getInExecutionMountainous() const {
    return InExecutionMountainous;
}

const LinkedListMissions<EmergencyMission *> &MissionLists::getInExecutionEmergency() const {
    return InExecutionEmergency;
}

const LinkedListMissions<PolarMission *> &MissionLists::getInExecutionPolar() const {
    return InExecutionPolar;
}

void MissionLists::addInExecutionEmergency(EmergencyMission *EMission)
{
    InExecutionEmergency.InsertBeg(EMission);
}

void MissionLists::deleteInExecutionEmergency(int ID)
{
    InExecutionEmergency.DeleteNode(ID);
}

void MissionLists::addInExecutionPolar(PolarMission *EMission)
{
    InExecutionPolar.InsertBeg(EMission);
}

void MissionLists::deleteInExecutionPolar(int ID)
{
    InExecutionPolar.DeleteNode(ID);
}

void MissionLists::addInExecutionMountainous(MountainousMission *EMission)
{
    InExecutionMountainous.InsertBeg(EMission);

}

void MissionLists::deleteInExecutionMountainous(int ID)
{
    InExecutionMountainous.DeleteNode(ID);

}

int MissionLists::getNoOfWaitingEmergencyMission() const {
    return WaitingEmergencyMissionHeap.getSize();
}

int MissionLists::getNoOfWaitingPolarMission() const {
    return WaitingPolarMissionQueue.getSize();
}

int MissionLists::getNoOfWaitingMountainousMission() const {
    return WaitingMountainousMissionList.getCount();
}

int MissionLists::getNoOfInExecutionMountainous() const {
    return InExecutionMountainous.getCount();
}

int MissionLists::getNoOfInExecutionEmergency() const {
    return InExecutionEmergency.getCount();
}

int MissionLists::getNoOfInExecutionPolar() const {
    return InExecutionPolar.getCount();
}




