//
// Created by raspberry on 2020-11-24.
//

#include "Rover.h"

Rover::Rover()
{

}

Rover::Rover(int Speed, int CheckupDuration, int NoCheckupMissions,int ID)
{
    setNoOfExecutedMissions(0);
    setID(ID);
    setSpeed(Speed);
    setCheckupDuration(CheckupDuration);
    setNoCheckupMissions(NoCheckupMissions);
}


void Rover::Print()
{
    cout<<"\n This is the parent rover, my speed is:  "<< this->getSpeed()<<" , my number of missions before doing a checkup is: "<<this->getNoCheckupMissions() <<" , and finally my checkup duration is: "
        <<this->getCheckupDuration()<<endl;
}

int Rover::getNoCheckupMissions() const {
    return NoCheckupMissions;
}

int Rover::getCheckupDuration() const {
    return CheckupDuration;
}

float Rover::getSpeed() const {
    return Speed;
}

int Rover::getMissionStartTime() const {
    return MissionStartTime;
}

int Rover::getMissionDuration() const {
    return MissionDuration;
}

void Rover::setNoCheckupMissions(int noCheckupMissions) {
    NoCheckupMissions = noCheckupMissions;
}

void Rover::setCheckupDuration(int checkupDuration) {
    CheckupDuration = checkupDuration;
}

void Rover::setSpeed(float speed) {
    Speed = speed;
}

void Rover::setMissionStartTime(int missionStartTime) {
    MissionStartTime = missionStartTime;
}

void Rover::setMissionDuration(int missionDuration) {
    MissionDuration = missionDuration;
}

int Rover::getID() const {
    return ID;
}

void Rover::setID(int id) {
    ID = id;
}

int Rover::getNoOfExecutedMissions() const {
    return NoOfExecutedMissions;
}

void Rover::setNoOfExecutedMissions(int noOfExecutedMissions) {
    NoOfExecutedMissions = noOfExecutedMissions;
}

void Rover::incrementNoOfExecutedMissions()
{
    setNoOfExecutedMissions(getNoOfExecutedMissions()+1);
}

bool Rover::isCheckUp()
{
    if (getNoOfExecutedMissions()==getNoCheckupMissions())
    {
        return true;
    }
    return false;
}

Rover::~Rover() {

}


