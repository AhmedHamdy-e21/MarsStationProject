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
#include "UIClass.h"
#include <map>
class MarsStation
{
private:
    MissionLists MLs;
    RoverLists RLs;
    EventLists EVs;
    // I need to map the mission ids to the rovers id using map simply


    map<int, int> IDDictionary;

    int AutoP;
public:

    void insertIDPair(int MissionID,int RoverID);
    void eraseIDPair(int MissionID);

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
    bool assignMountainousMission(int & ID);
    bool assignPolarMission(int &ID);
    bool assignEmergencyMission(int& ID);
    bool assignTodaysMission(int CurrentDay);

    //// Check for the completed missions and then transfer them to the completed list.
    Rover* CompletedMountainous(MountainousMission* MM);
    Rover* CompletedPolar(PolarMission* PM);
    Rover* CompletedEmergency(EmergencyMission* EM);
    bool isCompletedToday(int CurrentDay);

    // Think how you will know whether it's completed or not.
    bool cancelTodaysMission(int CurrentDay);
    bool promoteTodaysMission(int CurrentDay);
    void simulate(int CurrentDay);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Get Any kind of Data from here
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






    ~MarsStation();
};
#endif //MARSSTATIONPROJECT_MARSSTATION_H
