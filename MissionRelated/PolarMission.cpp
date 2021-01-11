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

PolarMission::PolarMission(FormulationEvent *EV,int Day):Mission(
        Day, EV->getID(), EV->getTargetLocation(),EV-> getMissionDuration(), EV->getSignificance(),EV->getEventDay()) {

}

PolarMission::PolarMission(PolarMission *EV) :Mission(
        EV->getED(), EV->getID(), EV->getTargetLocation(),EV-> getMissionDuration(), EV->getSignificance(),EV->getFormulatedDay())
{
    setCompletedDay(EV->getCompletedDay());

}
