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
    /////////////Waiting Missions
    MaxHeap<EmergencyMission*> WaitingEmergencyMissionHeap;
    LinkedQueue<PolarMission*> WaitingPolarMissionQueue;
    LinkedListMissions<MountainousMission*> WaitingMountainousMissionList;
    int NoOfWaitingEmergencyMission;
    int NoOfWaitingPolarMission;
    int NoOfWaitingMountainousMission;
    /////////////IsExecuting Missions
    LinkedListMissions<MountainousMission*> InExecutionMountainous;
    LinkedListMissions<EmergencyMission*> InExecutionEmergency;
    LinkedListMissions<PolarMission*> InExecutionPolar;
    int NoOfInExecutionMountainous;
    int NoOfInExecutionEmergency;
    int NoOfInExecutionPolar;
    /////////////Completed Missions, ##### I dont' think that I need to store them, I just keep their numbers.
    int NoOfCompletedPolar;
    int NoOfCompletedEmergency;
    int NoOfCompletedMountainous;

    /////// NOTE THAT, I need to keep the history of each mission. in terms of all dates.
    ////// I can keep this class that cute and the history is stored in the MarsStation class.
    // The Mountaneous mission can be implemented either in a linked list or a heap. I just add or delete mission so I doesn't need a heap.
    // It can be just a linked list

public:
    MissionList();

    // I need to check to the special cases when there isn't missions available
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Waiting
    const MaxHeap<EmergencyMission*> getWaitingEmergencyMissionHeap() const;
    void addEmergencyMission(EmergencyMission* EMission);
    EmergencyMission* getEmergencyMission();
    int getNoOfWaitingEmergencyMission() const;
    /////////////Completed
    void setNoOfCompletedEmergency(int noOfCompletedEmergency);
    int getNoOfCompletedEmergency() const;
    /////////////IsExecuting
    const LinkedListMissions<EmergencyMission *> &getInExecutionEmergency() const;
    void addInExecutionEmergency(EmergencyMission* EMission);
    void deleteInExecutionEmergency(int ID);
    int getNoOfInExecutionEmergency() const;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////PolarMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Waiting
    const LinkedQueue<PolarMission*> getWaitingPolarMissionQueue() const;
    void addPolarMission(PolarMission* PMission);
    PolarMission* getPolarMission();
    int getNoOfWaitingPolarMission() const;
    /////////////Completed
    int getNoOfCompletedPolar() const;
    void setNoOfCompletedPolar(int noOfCompletedPolar);
    /////////////IsExecuting
    const LinkedListMissions<PolarMission *> &getInExecutionPolar() const;
    void addInExecutionPolar(PolarMission* EMission);
    void deleteInExecutionPolar(int ID);
    int getNoOfInExecutionPolar() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////MountainousMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Waiting
    void addMountainousMission( MountainousMission* MMission);
    MountainousMission* getMountainousMission();
    const LinkedListMissions<MountainousMission*> getWaitingMountainousMissionList() const;
    void cancelMountainousMission(int ID);
    int getNoOfWaitingMountainousMission() const;
    /////////////Completed
    int getNoOfCompletedMountainous() const;
    void setNoOfCompletedMountainous(int noOfCompletedMountainous);
    /////////////IsExecuting
    const LinkedListMissions<MountainousMission *> &getInExecutionMountainous() const;
    void addInExecutionMountainous(MountainousMission* EMission);
    void deleteInExecutionMountainous(int ID);
    int getNoOfInExecutionMountainous() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ~MissionList();




    };