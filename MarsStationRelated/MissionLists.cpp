//
// Created by raspberry on 2020-11-30.
//

#include "MissionLists.h"


MissionLists::MissionLists()
{
    setNoOfCompletedEmergency(0);
setNoOfCompletedMountainous(0);
setNoOfCompletedPolar(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EmergencyMission *MissionLists::getEmergencyMission() {
    EmergencyMission *Em = WaitingEmergencyMissionHeap.extractMax();;
    return Em;
}
 MaxHeap<EmergencyMission*> MissionLists::getWaitingEmergencyMissionHeap()
{
    return WaitingEmergencyMissionHeap;
}
void MissionLists::addEmergencyMission(EmergencyMission *EMission)
{
    WaitingEmergencyMissionHeap.insertItem(EMission);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 LinkedQueue<PolarMission*> MissionLists::getWaitingPolarMissionQueue()
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
 LinkedListMissions<MountainousMission*> MissionLists::getWaitingMountainousMissionList()
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
    return CompletedPolar.getCount();
}

int MissionLists::getNoOfCompletedEmergency()  {
    return CompletedEmergency.getCount();
}

int MissionLists::getNoOfCompletedMountainous() const {
    return CompletedMountainous.getCount();
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

 LinkedListMissions<MountainousMission *> &MissionLists::getInExecutionMountainous()  {
    return InExecutionMountainous;
}

 LinkedListMissions<EmergencyMission *> &MissionLists::getInExecutionEmergency()  {
    return InExecutionEmergency;
}

 LinkedListMissions<PolarMission *> &MissionLists::getInExecutionPolar()  {
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

 LinkedListMissions<MountainousMission *> &MissionLists::getCompletedMountainous()  {
    return CompletedMountainous;
}

 LinkedListMissions<EmergencyMission *> &MissionLists::getCompletedEmergency()  {
    return CompletedEmergency;
}

 LinkedListMissions<PolarMission *> &MissionLists::getCompletedPolar()  {
    return CompletedPolar;
}

void MissionLists::addCompletedEmergencyMission(EmergencyMission *EMission)
{
    CompletedEmergency.InsertBeg(EMission);

}

void MissionLists::addCompletedPolarMission(PolarMission *PMission)
{
    CompletedPolar.InsertBeg(PMission);

}

void MissionLists::addCompletedMountainousMission(MountainousMission *MMission)
{
    CompletedMountainous.InsertBeg(MMission);

}




