//
// Created by raspberry on 2021-01-08.
//

#include "Mission.h"


Mission::Mission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance, int FomrulatedDay) {
    setFormulatedDay(FomrulatedDay);
    setED(ED);
    setCompletedMission(false);
    setMissionDuration(MissionDuration);
    setSignificance(Significance);
    setTargetLocation(TargetLocation);
    setID(ID);

}

Mission::Mission() {
    setCompletedMission(false);
    setMissionDuration(0);
    setSignificance(0);
    setTargetLocation(0);
//        setID(ID);

}

void Mission::Print() const {
    cout<<"In mission "<<"With ID: "<<getID();

}

bool Mission::isFormulationDayStamp() const {
    return FormulationDayStamp;
}

void Mission::setFormulationDayStamp(bool formulationDayStamp) {
    FormulationDayStamp = formulationDayStamp;
}

int Mission::getTargetLocation() const {
    return TargetLocation;
}

void Mission::setTargetLocation(int targetLocation) {
    TargetLocation = targetLocation;
}

int Mission::getMissionDuration() const {
    return MissionDuration;
}

void Mission::setMissionDuration(int missionDuration) {
    MissionDuration = missionDuration;
}

int Mission::getSignificance() const {
    return Significance;
}

void Mission::setSignificance(int significance) {
    Significance = significance;
}

bool Mission::isCompletedMission() const {
    return CompletedMission;
}

void Mission::setCompletedMission(bool completedMission) {
    CompletedMission = completedMission;
}

int Mission::getID() const {
    return ID;
}

void Mission::setID(int id) {
    ID = id;
}

int Mission::getED() const {
    return ED;
}

void Mission::setED(int ed) {
    ED = ed;
}

int Mission::getCompletedDay() const {
    return CompletedDay;
}

void Mission::setCompletedDay(int completedDay) {
    CompletedDay = completedDay;
}

int Mission::getFormulatedDay() const {
    return FormulatedDay;
}

void Mission::setFormulatedDay(int formulatedDay) {
    FormulatedDay = formulatedDay;
}

int Mission::getWaitingDays() const {
    return WaitingDays;
}

void Mission::setWaitingDays(int waitingDays) {
    WaitingDays = waitingDays;
}


