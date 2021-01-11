//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSION_H
#define MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSION_H
#include "Mission.h"
#include "../EventRelated/FormulationEvent.h"
class MountainousMission : public Mission
{
private:
            int AutoP;
public:
    int getAutoP() const;

public:
        MountainousMission();
        MountainousMission(MountainousMission* EV);
        MountainousMission(FormulationEvent* EV,int AutoP, int Day);
        MountainousMission(int AutoP, int ED, int ID, int TargetLocation, int MissionDuration, int Significance);
        void setAutoP(int AutoP);
         void Print() const override ; //Make sure in gitkraken
         ~MountainousMission();
        };
#endif //MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSION_H
