//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_ROVERLISTS_H
#define MARSSTATIONPROJECT_ROVERLISTS_H

#include "../RoverRelated/MountainousRover.h"
#include "../RoverRelated/PolarRover.h"
#include "../RoverRelated/EmergencyRover.h"
#include "../DataStructure/Queue/LinkedQueue.h"
//#include "../DataStructure/Queue/LinkedQueue.cpp"

#include "../DataStructure/LinkedList/LinkedListMissions.h"
using namespace std;
#include <iostream>

class RoverLists
{
private:
    /////////////Available Rovers
    LinkedQueue<EmergencyRover*> AvailableEmergencyRovers;
    LinkedQueue<PolarRover*> AvailablePolarRovers;
    LinkedQueue<MountainousRover*> AvailableMountainousRovers;
    int NoOfAvailableEmergencyRover=0;
    int NoOfAvailablePolarRover=0;
    int NoOfAvailableMountainousRover=0;
    /////////////InMission Rovers
    LinkedListMissions<EmergencyRover*> InMissionEmergencyRovers;
    LinkedListMissions<PolarRover*> InMissionPolarRovers;
    LinkedListMissions<MountainousRover*> InMissionMountainousRovers;
    int NoOfInMissionEmergencyRover=0;
    int NoOfInMissionPolarRover=0;
    int NoOfInMissionMountainousRover=0;
    /////////////InCheckup Rovers
    LinkedListMissions<EmergencyRover*> InCheckupEmergencyRovers;
    LinkedListMissions<PolarRover*> InCheckupPolarRovers;
    LinkedListMissions<MountainousRover*> InCheckupMountainousRovers;
    int NoOfInCheckupEmergencyRover=0;
    int NoOfInCheckupPolarRover=0;
    int NoOfInCheckupMountainousRover=0;

public:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyRover
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    const LinkedQueue<EmergencyRover *> &getAvailableEmergencyRovers() const;
    int getNoOfAvailableEmergencyRovers() const;
    void addAvailableEmergencyRover(EmergencyRover* ER);// enqueue
    EmergencyRover * getAvailableEmergencyRover();// dequeue
    void addMultipleAvailableEmergencyRovers(int NumberOfEmergencyRovers,int Speed, int CheckupDuration, int NoCheckupMissions ,int ID=0);
    EmergencyRover * peekAvailableEmergencyRover();
    /////////////InMission
     LinkedListMissions<EmergencyRover *> &getInMissionEmergencyRovers() ;
    int getNoOfInMissionEmergencyRovers() const;
    void addInMissionEmergencyRover(EmergencyRover* ER);
    EmergencyRover * getInMissionEmergencyRover();
    /////////////InCheckup
    const LinkedListMissions<EmergencyRover *> &getInCheckupEmergencyRovers() const;
    int getNoOfInCheckupEmergencyRovers() const;
    void addInCheckupEmergencyRover(EmergencyRover* ER);
    EmergencyRover * getInCheckupEmergencyRover();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////PolarRovers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    const LinkedQueue<PolarRover *> &getAvailablePolarRovers() const;
    int getNoOfAvailablePolarRovers() const;
    void addAvailablePolarRover(PolarRover * PR);
    PolarRover * getAvailablePolarRover();
    void addMultipleAvailablePolarRovers(int NumberOfEmergencyRovers,int Speed, int CheckupDuration, int NoCheckupMissions,int ID=0);
    PolarRover * peekAvailablePolarRover();

    /////////////InMission
    int getNoOfInMissionPolarRovers() const;
     LinkedListMissions<PolarRover *> &getInMissionPolarRovers() ;
    void addInMissionPolarRover(PolarRover * PR);
    PolarRover * getInMissionPolarRover();
    /////////////InCheckup
    int getNoOfInCheckupPolarRovers() const;
    const LinkedListMissions<PolarRover *> &getInCheckupPolarRovers() const;
    void addInCheckupPolarRover(PolarRover * PR);
    PolarRover * getInCheckupPolarRover();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyRover
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    int getNoOfAvailableMountainousRovers() const;
    const LinkedQueue<MountainousRover *> &getAvailableMountainousRovers() const;
    void addAvailableMountainousRover(MountainousRover* ER);
    MountainousRover* getAvailableMountainousRover();
    void addMultipleAvailableMountainousRovers(int NumberOfEmergencyRovers,int Speed, int CheckupDuration, int NoCheckupMissions, int ID=0);
    MountainousRover * peekAvailableMountainousRover();

    /////////////InMission
     LinkedListMissions<MountainousRover *> &getInMissionMountainousRovers() ;
    int getNoOfInMissionMountainousRovers() const;
    void addInMissionMountainousRover(MountainousRover* ER);
    MountainousRover* getInMissionMountainousRover();
    /////////////InCheckup
    int getNoOfInCheckupMountainousRovers() const;
    const LinkedListMissions<MountainousRover *> &getInCheckupMountainousRovers() const;
    void addInCheckupMountainousRover(MountainousRover* ER);
    MountainousRover* getInCheckupMountainousRover();
};

#endif //MARSSTATIONPROJECT_ROVERLISTS_H
