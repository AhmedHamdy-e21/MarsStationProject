//
// Created by raspberry on 2020-11-30.
//

#include "PolarMission.h"

PolarMission::PolarMission() {

}

PolarMission::~PolarMission() {

}

void PolarMission::Print() const {
    cout<<"\nIt's Polar mission with ID: "<< getID()<<" and Target location of "<< this->getTargetLocation()<<endl;

}

PolarMission::PolarMission(FormulationEvent *EV):Mission(
        EV->getEventDay(), EV->getID(), EV->getTargetLocation(),EV-> getMissionDuration(), EV->getSignificance()) {

}
