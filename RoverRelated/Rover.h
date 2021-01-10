//
// Created by raspberry on 2020-11-24.
//

#include<iostream>
using namespace std;
#pragma once


class Rover {
private:
	int NoCheckupMissions;
	int CheckupDuration; // constant in subclassess,hence, no getters and setters
	float Speed; // constant in subclasses,hence, no getters and setters
	int MissionStartTime;
	int MissionDuration;

public:
	//void Assign_mission(current_time)  // el mafrod akhodha men class tany
	// void checkup( number of missions ) // hatakhod 3adad el missions ely rover 3amltha
	// time WhenAvailable() //should return time that rover will be available in

	void setNoCheckupMissions(int Nomissions);
	int getNoCheckupMissions();
	void setMissionStartTime(int time);
	int getMissionStartTime();
	void setMissionDuration(int duration);
	int getMissionDuration();

	Rover(int Speed, int CheckupDuration,int NoCheckupMissions)
	{
		setSpeed(Speed);
		setCheckupDuration(CheckupDuration);
        setNoCheckupMissions(NoCheckupMissions);
	}


	virtual void setSpeed(int speed)
	{
		this->Speed = speed;
	}

	virtual float getSpeed() const
	{
		return this->Speed;
	}

	virtual void setCheckupDuration(int  check_up_duration)
	{
		this->CheckupDuration = check_up_duration;
	}

	virtual int getCheckupDuration() const   //Make sure in gitkraken
	{
		return this->CheckupDuration;
	}

	virtual void Print()
	{
		cout << "\n I'm a Rover  " << this->Speed << this->CheckupDuration;
	}

};