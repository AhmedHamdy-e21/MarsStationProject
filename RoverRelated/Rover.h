//
// Created by raspberry on 2020-11-24.
//

#include<iostream>
using namespace std;
#pragma once


class Rover {
private:
	int NoCheckupMissions;
    int CheckupDuration;
    float Speed;
    int MissionStartTime;
    int MissionDuration;
public:
    Rover();

    Rover(int Speed, int CheckupDuration,int NoCheckupMissions);

    void setNoCheckupMissions(int noCheckupMissions);

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