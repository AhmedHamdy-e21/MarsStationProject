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
#include <vector>
#include <algorithm>
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
    int returnRoverID(int MissionID);

     MissionLists &getMLs() ;

     RoverLists &getRLs() ;

     EventLists &getEVs() ;

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

    ///////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////UNDER CONSTRUCTION
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //// Check for the completed missions and then transfer them to the completed list.
    MountainousRover* CompletedMountainous(MountainousMission* MM,int CurrentDay);
    PolarRover* CompletedPolar(PolarMission* PM,int CurrentDay);
    EmergencyRover* CompletedEmergency(EmergencyMission* EM,int CurrentDay);
    ///// I need to implement a function that transfer Rovers from Inmission to either Checkup or Avaialble


    bool isCompletedToday(int CurrentDay);

    // Think how you will know whether it's completed or not.
    bool cancelTodaysMission(int CurrentDay);
    bool promoteTodaysMission(int CurrentDay);
    void simulate(int CurrentDay);

//////////////////////////////////////////////////////////////////////////////////////////
//// Now I need to get the rovers from being in mission to either available or In checkup
//// Then After the Checkup I need to add them to available.
bool transferInMissionMountainousRover( MountainousRover* MR);
bool transferInMissionPolarRover(PolarRover* PR);
bool transferInMissionEmergencyRover(EmergencyRover* EM);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////Get Any kind of Data from here
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The data is passed by value in order to copy it and get the availble rovers ids
void AvailableRoversIDs(vector<int>& AvailableMountainousRoversIDs, vector<int>& AvailablePolarRoversIDs, vector<int>& AvailableEmergencyRoversIDs, LinkedQueue<MountainousRover*> MRQueue, LinkedQueue<PolarRover*> PRQueue, LinkedQueue<EmergencyRover*> ERQueue);
void WaitingMissionsIDs(vector<int>& AvailableMountainousMissionsIDs, vector<int>& AvailablePolarMissionsIDs, vector<int>& AvailableEmergencyMissionsIDs, LinkedQueue<MountainousMission*> MMQueue, LinkedQueue<PolarMission*> PMQueue, LinkedQueue<EmergencyMission*> EMQueue);
void InExecutionMissionsIDs(vector<int>& InExecutionMountainousMissionsIDs, vector<int>& InExecutionPolarMissionsIDs, vector<int>& InExecutionEmergencyMissionsIDs, LinkedQueue<MountainousMission*> MMList, LinkedQueue<PolarMission*> PMList, LinkedQueue<EmergencyMission*> EMList);
void CompletedMissionsIDs(vector<int>& CompletedMountainousMissionsIDs, vector<int>& CompletedPolarMissionsIDs, vector<int>& CompletedEmergencyMissionsIDs, LinkedQueue<MountainousMission*> MMList, LinkedQueue<PolarMission*> PMList, LinkedQueue<EmergencyMission*> EMList);
    ~MarsStation();
};
#endif //MARSSTATIONPROJECT_MARSSTATION_H
