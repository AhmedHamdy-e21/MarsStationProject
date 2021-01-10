//
// Created by raspberry on 2021-01-10.
//

#include "RoverList.h"

const LinkedQueue<EmergencyRovers *> &RoverList::getAvailableEmergencyRovers() const {
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

const LinkedListMissions<EmergencyRovers *> &RoverList::getInMissionEmergencyRovers() const {
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

const LinkedListMissions<EmergencyRovers *> &RoverList::getInCheckupEmergencyRovers() const {
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
