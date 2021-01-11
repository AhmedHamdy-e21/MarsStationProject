//
// Created by raspberry on 2020-11-30.
//

#include "EmergencyMission.h"

void EmergencyMission::Print() const {
    {
        cout<<"It's emergency mission with ID"<< getID()<<" and Target location of "<< this->getTargetLocation()<<endl;
    }
}

EmergencyMission::EmergencyMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance,int FomrulatedDay) : Mission(
        ED, ID, TargetLocation, MissionDuration, Significance,FomrulatedDay) {

}

int EmergencyMission::getPriority()
{
    return this->priority;
}

void EmergencyMission::setPriority()
{
    //// when the event day is large it means it can wait longer so the priority is less (negative sign).
    // when the target location is far, it means it has more priority to be assigned first. 0.01 is because
    //// the order of magnitude is 100, and we need to normalize it.
    //// the longer the mission duration, the more significant it is to be assigned first in order to be finished on time.
    //// Significance should be of higher magnitude that the others. so it's multiplied by 3.

    this->priority=((0.01*getTargetLocation())+getMissionDuration()+(3*getSignificance())-getED());
}

EmergencyMission::EmergencyMission(FormulationEvent *EV, int ExecutionDay):Mission(

        ExecutionDay, EV->getID(), EV->getTargetLocation(),EV-> getMissionDuration(), EV->getSignificance(),EV->getEventDay())// The getEventDay is the formulation
{
}

EmergencyMission::EmergencyMission(MountainousMission *EV, int FormulationDay):Mission(
        FormulationDay, EV->getID(), EV->getTargetLocation(), EV-> getMissionDuration(), EV->getSignificance(),EV->getED())
{


}
