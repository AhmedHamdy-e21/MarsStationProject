//
// Created by raspberry on 2020-11-24.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MISSION_H
#define MARS_MISSIONS_MANAGEMENT_MISSION_H
#include <iostream>
using namespace std;


class Mission
{
private:
    bool FormulationDayStamp;
    int TargetLocation;
    int MissionDuration;
    int Significance;
    bool CompletedMission;
    int ID;
    int ED;
    int CompletedDay;
    int FormulatedDay;
    int WaitingDays;
public:
    bool isFormulationDayStamp() const;

    void setFormulationDayStamp(bool formulationDayStamp);

    int getTargetLocation() const;

    void setTargetLocation(int targetLocation);

    int getMissionDuration() const;

    void setMissionDuration(int missionDuration);

    int getSignificance() const;

    void setSignificance(int significance);

    bool isCompletedMission() const;

    void setCompletedMission(bool completedMission);

    int getID() const;

    void setID(int id);

    int getED() const;

    void setED(int ed);

    int getCompletedDay() const;

    void setCompletedDay(int completedDay);

    int getFormulatedDay() const;

    void setFormulatedDay(int formulatedDay);

    int getWaitingDays() const;

    void setWaitingDays(int waitingDays);

    Mission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance, int FomrulatedDay);

    Mission();



    virtual void Print() const;




};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
