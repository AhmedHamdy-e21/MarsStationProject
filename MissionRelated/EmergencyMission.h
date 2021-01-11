//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
#define MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
#include "Mission.h"
#include "../EventRelated/FormulationEvent.h"

class EmergencyMission : public Mission
{
    private:
    int priority;

public:
    EmergencyMission();
    EmergencyMission(FormulationEvent* EV);
    EmergencyMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance);
    void setPriority();
    int getPriority();
    void Print()  const override ;//Make sure in gitkraken


};


#endif //MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
