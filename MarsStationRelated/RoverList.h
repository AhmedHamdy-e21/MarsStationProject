//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_ROVERLIST_H
#define MARSSTATIONPROJECT_ROVERLIST_H
#include "../RoverRelated/MountainousRover.h"
#include "../RoverRelated/PolarRover.h"
#include "../RoverRelated/EmergencyRovers.h"
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
    LinkedQueue<EmergencyRovers*> AvailableEmergencyRovers;
    LinkedQueue<PolarRover*> AvailablePolarRovers;
    LinkedQueue<MountainousRover*> AvailableMountainousRovers;
    int NoOfAvailableEmergencyRover;
    int NoOfAvailablePolarRover;
    int NoOfAvailableMountainousRover;
    /////////////InMission Rovers
    LinkedListMissions<EmergencyRovers*> InMissionEmergencyRovers;
    LinkedListMissions<PolarRover*> InMissionPolarRovers;
    LinkedListMissions<MountainousRover*> InMissionMountainousRovers;
    int NoOfInMissionEmergencyRover;
    int NoOfInMissionPolarRover;
    int NoOfInMissionMountainousRover;
    /////////////InCheckup Rovers
    LinkedListMissions<EmergencyRovers*> InCheckupEmergencyRovers;
    LinkedListMissions<PolarRover*> InCheckupPolarRovers;
    LinkedListMissions<MountainousRover*> InCheckupMountainousRovers;
    int NoOfInCheckupEmergencyRover;
    int NoOfInCheckupPolarRover;
    int NoOfInCheckupMountainousRover;
public:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyRovers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    const LinkedQueue<EmergencyRovers *> &getAvailableEmergencyRovers() const;
    int getNoOfAvailableEmergencyRovers() const;
    /////////////InMission
    const LinkedListMissions<EmergencyRovers *> &getInMissionEmergencyRovers() const;
    int getNoOfInMissionEmergencyRovers() const;
    /////////////InCheckup
    const LinkedListMissions<EmergencyRovers *> &getInCheckupEmergencyRovers() const;
    int getNoOfInCheckupEmergencyRovers() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////PolarRovers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    const LinkedQueue<PolarRover *> &getAvailablePolarRovers() const;
    int getNoOfAvailablePolarRovers() const;
    /////////////InMission
    int getNoOfInMissionPolarRovers() const;
    const LinkedListMissions<PolarRover *> &getInMissionPolarRovers() const;
    /////////////InCheckup
    int getNoOfInCheckupPolarRovers() const;
    const LinkedListMissions<PolarRover *> &getInCheckupPolarRovers() const;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////EmergencyRovers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Available
    int getNoOfAvailableMountainousRovers() const;
    const LinkedQueue<MountainousRover *> &getAvailableMountainousRovers() const;
    /////////////InMission
    const LinkedListMissions<MountainousRover *> &getInMissionMountainousRovers() const;
    int getNoOfInMissionMountainousRovers() const;
    /////////////InCheckup
    int getNoOfInCheckupMountainousRovers() const;
    const LinkedListMissions<MountainousRover *> &getInCheckupMountainousRovers() const;
};


#endif //MARSSTATIONPROJECT_ROVERLIST_H
