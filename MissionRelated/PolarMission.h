//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#define MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#include "Mission.h"
#include "../EventRelated/FormulationEvent.h"
class PolarMission : public Mission
{
public:
    PolarMission();
    PolarMission(FormulationEvent* EV, int Day);
//    PolarMission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance):
//    Mission(ED, ID, TargetLocation, MissionDuration,Significance){};

    void Print() const override;

    ~PolarMission();
   
};


#endif //MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
