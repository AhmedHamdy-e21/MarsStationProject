//
// Created by raspberry on 2021-01-08.
//

#include "Mission.h"

void Mission::setCompletedDay(int completedDay) {
    CompletedDay = completedDay;


}

void Mission::setFormulatedDay(int formulatedDay) {
    FormulatedDay = formulatedDay;


}

void Mission::setWaitingDays(int waitingDays) {
    WaitingDays = FormulatedDay-ED;


}

int Mission::getCompletedDay() const {

    return CompletedDay;

}

Mission::Mission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance, int FomrulatedDay) {
    setFormulatedDay(FomrulatedDay);
    setED(ED);
    setCompletedMission(false);
    setMisisonDuration(MissionDuration);
    setSignificance(Significance);
    setTargetLocation(TargetLocation);
    setID(ID);

}

Mission::Mission() {
    setCompletedMission(false);
    setMisisonDuration(0);
    setSignificance(0);
    setTargetLocation(0);
//        setID(ID);

}

int Mission::getID() const {
    return ID;

}

void Mission::setID(int ID) {
    this->ID = ID;


}

void Mission::setED(int ED) {
    this->ED=ED;


}
