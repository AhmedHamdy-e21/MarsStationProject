//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_ROVERLISTS_H
#define MARSSTATIONPROJECT_ROVERLISTS_H

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

class RoverLists
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
    /////////////InMission
    int getNoOfInMissionPolarRovers() const;
    const LinkedListMissions<PolarRover *> &getInMissionPolarRovers() const;
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
    /////////////InMission
    const LinkedListMissions<MountainousRover *> &getInMissionMountainousRovers() const;
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
