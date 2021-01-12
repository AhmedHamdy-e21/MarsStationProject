//
// Created by raspberry on 2020-11-24.
//

#include<iostream>
using namespace std;
#pragma once


class Rover {
private:
	int NoCheckupMissions;
	int NoOfExecutedMissions=0;
    int CheckupDuration;
    float Speed;
    int MissionStartTime;
    int MissionDuration;
    int ID;
public:
    int getNoOfExecutedMissions() const;

    void setNoOfExecutedMissions(int noOfExecutedMissions);

    void setID(int id);

    int getID() const;

    Rover();

    Rover(int Speed, int CheckupDuration,int NoCheckupMissions,int ID);
    void incrementNoOfExecutedMissions();
    void setNoCheckupMissions(int noCheckupMissions);
    bool isCheckUp();

    void setCheckupDuration(int checkupDuration);

    void setSpeed(float speed);

    void setMissionStartTime(int missionStartTime);

    void setMissionDuration(int missionDuration);

    int getNoCheckupMissions() const;

    int getCheckupDuration() const;

    float getSpeed() const;

    int getMissionStartTime() const;

    int getMissionDuration() const;

	virtual void Print();

	~Rover();

};