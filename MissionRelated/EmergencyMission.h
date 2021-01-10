//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
#define MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
#include "Mission.h"

class EmergencyMission : public Mission
{

public:
    EmergencyMission();
    EmergencyMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance): Mission(ED, ID, TargetLocation, MissionDuration, Significance){};

    void Print()  const override //Make sure in gitkraken
    {
        cout<<"It's emergency mission with ID"<< getID()<<" and Target location of "<< this->getTargetLocation()<<endl;
    }

};


#endif //MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSION_H
