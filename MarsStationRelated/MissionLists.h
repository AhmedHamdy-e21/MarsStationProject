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
//#include "../DataStructure/Queue/LinkedQueue.h"
#include "../DataStructure/Queue/LinkedQueue.cpp"
#include "../DataStructure/Queue/NodeQ.cpp"

//#include "../DataStructure/Queue/NodeQ.h"

class MissionLists
{
private:
    /////////////Waiting Missions
    MaxHeap<EmergencyMission*> WaitingEmergencyMissionHeap;
    LinkedQueue<PolarMission*> WaitingPolarMissionQueue;
    LinkedListMissions<MountainousMission*> WaitingMountainousMissionList;
    int NoOfWaitingEmergencyMission=0;
    int NoOfWaitingPolarMission=0;
    int NoOfWaitingMountainousMission=0;
    /////////////IsExecution Missions
    LinkedListMissions<MountainousMission*> InExecutionMountainous;
    LinkedListMissions<EmergencyMission*> InExecutionEmergency;
    LinkedListMissions<PolarMission*> InExecutionPolar;
    int NoOfInExecutionMountainous=0;
    int NoOfInExecutionEmergency=0;
    int NoOfInExecutionPolar=0;
    /////////////Completed Missions, ##### I dont' think that I need to store them, I just keep their numbers.
    LinkedListMissions<MountainousMission*> CompletedMountainous;
    LinkedListMissions<EmergencyMission*> CompletedEmergency;
    LinkedListMissions<PolarMission*> CompletedPolar;
    int NoOfCompletedPolar=0;
    int NoOfCompletedEmergency=0;
    int NoOfCompletedMountainous=0;

    /////// NOTE THAT, I need to keep the history of each mission. in terms of all dates.
    ////// I can keep this class that cute and the history is stored in the MarsStation class.
    // The Mountaneous mission can be implemented either in a linked list or a heap. I just add or delete mission so I doesn't need a heap.
    // It can be just a linked list



public:
    MissionLists();

    // I need to check to the special cases when there isn't missions available
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Waiting
     MaxHeap<EmergencyMission*> getWaitingEmergencyMissionHeap() ;
    void addEmergencyMission(EmergencyMission* EMission);
    EmergencyMission* getEmergencyMission();
    int getNoOfWaitingEmergencyMission() const;
    /////////////Completed
    LinkedListMissions<EmergencyMission *> &getCompletedEmergency() ;
    void addCompletedEmergencyMission(EmergencyMission* EMission);

    void setNoOfCompletedEmergency(int noOfCompletedEmergency);
    int getNoOfCompletedEmergency() ;
    /////////////IsExecuting
     LinkedListMissions<EmergencyMission *> &getInExecutionEmergency() ;
    void addInExecutionEmergency(EmergencyMission* EMission);
    void deleteInExecutionEmergency(int ID);
    int getNoOfInExecutionEmergency() const;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////PolarMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Waiting
     LinkedQueue<PolarMission*> getWaitingPolarMissionQueue() ;
    void addPolarMission(PolarMission* PMission);
    PolarMission* getPolarMission();
    int getNoOfWaitingPolarMission() const;
    /////////////Completed
    LinkedListMissions<PolarMission *> &getCompletedPolar() ;
    void addCompletedPolarMission(PolarMission* PMission);

    int getNoOfCompletedPolar() const;
    void setNoOfCompletedPolar(int noOfCompletedPolar);
    /////////////IsExecuting
     LinkedListMissions<PolarMission *> &getInExecutionPolar() ;
    void addInExecutionPolar(PolarMission* EMission);
    void deleteInExecutionPolar(int ID);
    int getNoOfInExecutionPolar() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////MountainousMission
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Waiting
    void addMountainousMission( MountainousMission* MMission);
    MountainousMission* getMountainousMission();
     LinkedListMissions<MountainousMission*> getWaitingMountainousMissionList();
    void cancelMountainousMission(int ID);
    int getNoOfWaitingMountainousMission() const;
    /////////////Completed
    LinkedListMissions<MountainousMission *> &getCompletedMountainous();
    void addCompletedMountainousMission( MountainousMission* MMission);


    int getNoOfCompletedMountainous() const;
    void setNoOfCompletedMountainous(int noOfCompletedMountainous);
    /////////////IsExecuting
     LinkedListMissions<MountainousMission *> &getInExecutionMountainous() ;
    void addInExecutionMountainous(MountainousMission* EMission);
    void deleteInExecutionMountainous(int ID);
    int getNoOfInExecutionMountainous() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ~MissionLists();




    };