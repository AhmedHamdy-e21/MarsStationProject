//
// Created by raspberry on 2020-11-30.
//
#pragma once
#include "../MissionRelated/Mission.h"
#include "../MissionRelated/EmergencyMission.h"
#include "../MissionRelated/PolarMission.h"
#include "../MissionRelated/MountainousMission.h"
#include "../DataStructure/LinkedList/LinkedListMissions.h"
#include "../DataStructure/MaxHeap/MaxHeap.cpp"

#include "../DataStructure/Queue/NodeQ.h"
#include "../DataStructure/Queue/NodeQ.cpp"
#include "../DataStructure/Queue/LinkedQueue.h"
#include "../DataStructure/Queue/QueueADT.h"


class MissionList
{
private:
    MaxHeap<EmergencyMission*> EmergencyMissionHeap;
    LinkedQueue<PolarMission*> PolarMissionQueue;
    LinkedListMissions<MountainousMission*> MountainousMissionList;
    // The Mountaneous mission can be implemented either in a linked list or a heap. I just add or delete mission so I doesn't need a heap.
            // It can be just a linked list
public:
    MissionList();

    // I need to check to the special cases when there isn't missions available
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const MaxHeap<EmergencyMission*> getEmergencyMissionHeap() const;
    void addEmergencyMission(EmergencyMission* EMission);
    EmergencyMission* getEmergencyMission();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////PolarMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const LinkedQueue<PolarMission*> getPolarMissionQueue() const;
    void addPolarMission(PolarMission* PMission);
    PolarMission* getPolarMission();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////MountainousMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void addMountainousMission( MountainousMission* MMission);
    MountainousMission* getMountainousMission();
    const LinkedListMissions<MountainousMission*> getMountainousMissionList() const;
    void cancelMountainousMission(int ID);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ~MissionList();


    };