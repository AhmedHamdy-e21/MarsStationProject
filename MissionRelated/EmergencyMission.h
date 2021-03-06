//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
#define MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
#include "Mission.h"
#include "../EventRelated/FormulationEvent.h"
#include "MountainousMission.h"

class EmergencyMission : public Mission
{
    private:
    int priority;

public:
    EmergencyMission();
    EmergencyMission(FormulationEvent* EV,int FormulationDay);

    EmergencyMission(MountainousMission* EV,int FormulationDay);
    EmergencyMission(EmergencyMission* EV);
    EmergencyMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance,int FomrulatedDay);
    void setPriority();
    int getPriority();
    void Print()  const override ;//Make sure in gitkraken


};


#endif //MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
