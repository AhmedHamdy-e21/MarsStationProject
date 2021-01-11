//
// Created by raspberry on 2021-01-10.
//
#ifndef MARSSTATIONPROJECT_MARSSTATION_H
#define MARSSTATIONPROJECT_MARSSTATION_H
#include  "../MarsStationRelated/MissionLists.h"
#include  "../MarsStationRelated/RoverLists.h"
#include "EventLists.h"
#include <fstream>
#include <string>
class MarsStation
{
private:
    MissionLists MLs;
    RoverLists RLs;
    EventLists EVs;
    int AutoP;
public:
    const MissionLists &getMLs() const;

    const RoverLists &getRLs() const;

    const EventLists &getEVs() const;

    void setAutoP(int autoP);

    int getAutoP() const;
    // I need to keep the history of something right here. or in the Mission itself. Anywhere but just remember to do so.
    // Also don't forget to add the signify() function in mission in order to increase the significance of the emergency mission.
    // Then ISA, you're to implement the assign fuctions.

    MarsStation();
    void loadFile(string FileName);
    bool assignMountainousMission();
    bool assignPolarMission();
    bool assignEmergencyMission();
    bool assignTodaysMission(int CurrentDay);

    ~MarsStation();
};
#endif //MARSSTATIONPROJECT_MARSSTATION_H
