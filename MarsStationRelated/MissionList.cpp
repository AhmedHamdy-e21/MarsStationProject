//
// Created by raspberry on 2020-11-30.
//

#include "MissionList.h"


MissionList::MissionList()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EmergencyMission *MissionList::getEmergencyMission() {
    EmergencyMission *Em = EmergencyMissionHeap.extractMax();;
    return Em;
}
const MaxHeap<EmergencyMission*> MissionList::getEmergencyMissionHeap() const
{
    return EmergencyMissionHeap;
}
void MissionList::addEmergencyMission(EmergencyMission *EMission)
{
    EmergencyMissionHeap.insertItem(EMission);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const LinkedQueue<PolarMission*> MissionList::getPolarMissionQueue() const
{
    return PolarMissionQueue;
}
void MissionList::addPolarMission(PolarMission *PMission)
{

    PolarMissionQueue.enqueue(PMission);
}
PolarMission *MissionList::getPolarMission() {
    PolarMission * P;
    PolarMissionQueue.dequeue(P);
    return P;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const LinkedListMissions<MountainousMission*> MissionList::getMountainousMissionList() const
{
    return MountainousMissionList;
}
void MissionList::addMountainousMission( MountainousMission *MMission)
{
        MountainousMissionList.InsertBeg(MMission);
}
MountainousMission *MissionList::getMountainousMission() {
    MountainousMission * M=MountainousMissionList.getHead()->getItem();
    MountainousMissionList.DeleteFirst();
    return M;
}
void MissionList::cancelMountainousMission(int ID)
{
    MountainousMissionList.DeleteNode(ID);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





MissionList::~MissionList() {

}



