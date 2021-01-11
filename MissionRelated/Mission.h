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
public:
    void setCompletedDay(int completedDay) {
        CompletedDay = completedDay;
    }

    void setFormulatedDay(int formulatedDay) {
        FormulatedDay = formulatedDay;
    }

    void setWaitingDays(int waitingDays) {
        WaitingDays = waitingDays;
    }

private:
    int FormulatedDay;
    int WaitingDays;
public:
    int getCompletedDay() const {
        return CompletedDay;
    }

    int getFormulatedDay() const {
        return FormulatedDay;
    }

    int getWaitingDays() const {
        return WaitingDays;
    }

public:

    Mission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance, int FomrulatedDay)
    {
        setFormulatedDay(FomrulatedDay);

        setED(ED);

        setCompletedMission(false);
        setMisisonDuration(MissionDuration);
        setSignificance(Significance);
        setTargetLocation(TargetLocation);
        setID(ID);
    }
    Mission()
    {
        setCompletedMission(false);
        setMisisonDuration(0);
        setSignificance(0);
        setTargetLocation(0);
//        setID(ID);

    };


    virtual int getID()const
    {
        return ID;
    }


    virtual void setID(int ID)
    {
        this->ID = ID;
    }


    virtual void setED(int ED)// i'm not sure the event day on the miission or on the or on the event
    {
        this->ED=ED;
    }
    virtual int getED()
    {
        return this->ED;
    }

    void setTargetLocation(int TargetLocation)
    {
        this->TargetLocation=TargetLocation;
    }
    int getTargetLocation() const
    {
        return this->TargetLocation;
    }

    int getMissionDuration() const
    {
        return this->MissionDuration;
    }
    void setMisisonDuration(int MissionDuration)
    {
        this->MissionDuration=MissionDuration;
    }

    void setSignificance(int Significance)
    {
        this->Significance=Significance;
    }
    int getSignificance()
    {
        return this->Significance;
    }

    // Calculate completed missions according to ..
    void setCompletedMission(bool BOOL)
    {
        CompletedMission=BOOL;

    }
    bool getCompletedMission()
    {
        return CompletedMission;
    }

    virtual void Print() const
    {
        cout<<"In mission "<<"With ID: "<<getID();
    }



};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
