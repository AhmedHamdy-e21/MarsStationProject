//
// Created by raspberry on 2020-11-24.
//

#include "Rover.h"

Rover::Rover()
{

}

Rover::Rover(int Speed, int CheckupDuration, int NoCheckupMissions)
{
    setSpeed(Speed);
    setCheckupDuration(CheckupDuration);
    setNoCheckupMissions(NoCheckupMissions);
}


void Rover::Print()
{
    cout << "\n I'm a Rover  " << this->Speed << this->CheckupDuration;


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
