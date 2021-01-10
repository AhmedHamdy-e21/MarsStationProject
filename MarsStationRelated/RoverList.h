//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_ROVERLIST_H
#define MARSSTATIONPROJECT_ROVERLIST_H
#include "../RoverRelated/MountainousRover.h"
#include "../RoverRelated/PolarRover.h"
#include "../RoverRelated/EmergencyRover.h"
#include "../DataStructure/Queue/NodeQ.h"
#include "../DataStructure/Queue/NodeQ.cpp"
#include "../DataStructure/Queue/LinkedQueue.h"
#include "../DataStructure/Queue/QueueADT.h"
#include "../DataStructure/LinkedList/LinkedListMissions.h"
using namespace std;
#include <iostream>

class RoverList
{
private:
    /////////////Available Rovers
    LinkedQueue<EmergencyRover*> AvailableEmergencyRovers;
    LinkedQueue<PolarRover*> AvailablePolarRovers;
    LinkedQueue<MountainousRover*> AvailableMountainousRovers;
    int NoOfAvailableEmergencyRover;
    int NoOfAvailablePolarRover;
    int NoOfAvailableMountainousRover;
    /////////////InMission Rovers
    LinkedListMissions<EmergencyRover*> InMissionEmergencyRovers;
    LinkedListMissions<PolarRover*> InMissionPolarRovers;
    LinkedListMissions<MountainousRover*> InMissionMountainousRovers;
    int NoOfInMissionEmergencyRover;
    int NoOfInMissionPolarRover;
    int NoOfInMissionMountainousRover;
    /////////////InCheckup Rovers
    LinkedListMissions<EmergencyRover*> InCheckupEmergencyRovers;
    LinkedListMissions<PolarRover*> InCheckupPolarRovers;
    LinkedListMissions<MountainousRover*> InCheckupMountainousRovers;
    int NoOfInCheckupEmergencyRover;
    int NoOfInCheckupPolarRover;
    int NoOfInCheckupMountainousRover;

public:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyRover
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    const LinkedQueue<EmergencyRover *> &getAvailableEmergencyRovers() const;
    int getNoOfAvailableEmergencyRovers() const;
    void addAvailableEmergencyRover(EmergencyRover* ER);// enqueue
    EmergencyRover * getAvailableEmergencyRover();// dequeue
    /////////////InMission
    const LinkedListMissions<EmergencyRover *> &getInMissionEmergencyRovers() const;
    int getNoOfInMissionEmergencyRovers() const;
    /////////////InCheckup
    const LinkedListMissions<EmergencyRover *> &getInCheckupEmergencyRovers() const;
    int getNoOfInCheckupEmergencyRovers() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////PolarRovers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    const LinkedQueue<PolarRover *> &getAvailablePolarRovers() const;
    int getNoOfAvailablePolarRovers() const;
    void addAvailablePolarRover(PolarRover * PR);// enqueue
    PolarRover * getAvailablePolarRover();// dequeue
    /////////////InMission
    int getNoOfInMissionPolarRovers() const;
    const LinkedListMissions<PolarRover *> &getInMissionPolarRovers() const;
    /////////////InCheckup
    int getNoOfInCheckupPolarRovers() const;
    const LinkedListMissions<PolarRover *> &getInCheckupPolarRovers() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyRover
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    int getNoOfAvailableMountainousRovers() const;
    const LinkedQueue<MountainousRover *> &getAvailableMountainousRovers() const;
    void addAvailableMountainousRover(MountainousRover* ER);// enqueue
    MountainousRover* getAvailableMountainousRover();// dequeue
    /////////////InMission
    const LinkedListMissions<MountainousRover *> &getInMissionMountainousRovers() const;
    int getNoOfInMissionMountainousRovers() const;
    /////////////InCheckup
    int getNoOfInCheckupMountainousRovers() const;
    const LinkedListMissions<MountainousRover *> &getInCheckupMountainousRovers() const;
};

#endif //MARSSTATIONPROJECT_ROVERLIST_H
