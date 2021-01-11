//
// Created by raspberry on 2020-11-30.
//

#include "MountainousMission.h"

MountainousMission::~MountainousMission() {

}

MountainousMission::MountainousMission() {

}

MountainousMission::MountainousMission(int AutoP, int ED, int ID, int TargetLocation, int MissionDuration,
                                       int Significance) { setAutoP(AutoP);

}

void MountainousMission::setAutoP(int AutoP) {this->AutoP=AutoP;

}

void MountainousMission::Print() const {
    cout<<"\nIt's Mountainous mission with  ID: "<<getID()<<" and Target location of "<< this->getTargetLocation()<<endl;

}

MountainousMission::MountainousMission(FormulationEvent *EV,int AutoP, int Day):Mission(
        Day, EV->getID(), EV->getTargetLocation(),EV-> getMissionDuration(), EV->getSignificance(),EV->getEventDay()) {
    setAutoP(AutoP);

}

