//
// Created by raspberry on 2021-01-10.
//

#include "RoverList.h"

const LinkedQueue<EmergencyRover *> &RoverList::getAvailableEmergencyRovers() const {
    return AvailableEmergencyRovers;
}

const LinkedQueue<PolarRover *> &RoverList::getAvailablePolarRovers() const {
    return AvailablePolarRovers;
}

const LinkedQueue<MountainousRover *> &RoverList::getAvailableMountainousRovers() const {
    return AvailableMountainousRovers;
}

int RoverList::getNoOfAvailableEmergencyRovers() const {
    return AvailableEmergencyRovers.getSize();
}

int RoverList::getNoOfAvailablePolarRovers() const {
    return AvailablePolarRovers.getSize();
}

int RoverList::getNoOfAvailableMountainousRovers() const {
    return AvailableMountainousRovers.getSize();
}

const LinkedListMissions<EmergencyRover *> &RoverList::getInMissionEmergencyRovers() const {
    return InMissionEmergencyRovers;
}

const LinkedListMissions<PolarRover *> &RoverList::getInMissionPolarRovers() const {
    return InMissionPolarRovers;
}

const LinkedListMissions<MountainousRover *> &RoverList::getInMissionMountainousRovers() const {
    return InMissionMountainousRovers;
}

int RoverList::getNoOfInMissionEmergencyRovers() const {
    return InMissionEmergencyRovers.getCount();
}

int RoverList::getNoOfInMissionPolarRovers() const {
    return InMissionPolarRovers.getCount();
}

int RoverList::getNoOfInMissionMountainousRovers() const {
    return InMissionMountainousRovers.getCount();
}

const LinkedListMissions<EmergencyRover *> &RoverList::getInCheckupEmergencyRovers() const {
    return InCheckupEmergencyRovers;
}

const LinkedListMissions<PolarRover *> &RoverList::getInCheckupPolarRovers() const {
    return InCheckupPolarRovers;
}

const LinkedListMissions<MountainousRover *> &RoverList::getInCheckupMountainousRovers() const {
    return InCheckupMountainousRovers;
}

int RoverList::getNoOfInCheckupEmergencyRovers() const {
    return InCheckupEmergencyRovers.getCount();
}

int RoverList::getNoOfInCheckupPolarRovers() const {
    return InCheckupPolarRovers.getCount();
}

int RoverList::getNoOfInCheckupMountainousRovers() const {
    return InCheckupMountainousRovers.getCount();
}

void RoverList::addAvailableEmergencyRover(EmergencyRover *ER)
{
    AvailableEmergencyRovers.enqueue(ER);

}



void RoverList::addAvailablePolarRover(PolarRover *PR)
{
    AvailablePolarRovers.enqueue(PR);

}


void RoverList::addAvailableMountainousRover(MountainousRover *ER)
{
    AvailableMountainousRovers.enqueue(ER);

}

MountainousRover *RoverList::getAvailableMountainousRover()
{
    bool isAvailable;
    MountainousRover* M;
    isAvailable=AvailableMountainousRovers.dequeue(M);
    if(isAvailable)
    {
        return M;
    }
    return nullptr;
}

PolarRover *RoverList::getAvailablePolarRover()
{
    bool isAvailable;
    PolarRover* M;
    isAvailable=AvailablePolarRovers.dequeue(M);
    if(isAvailable)
    {
        return M;
    }
    return nullptr;
}

EmergencyRover *RoverList::getAvailableEmergencyRover()
{
    bool isAvailable;
    EmergencyRover* M;
    isAvailable=AvailableEmergencyRovers.dequeue(M);
    if(isAvailable)
    {
        return M;
    }
    return nullptr;
}

