//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#define MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#include "Mission.h"

class PolarMission : public Mission
{
public:
    PolarMission();
    PolarMission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance):
    Mission(ED, ID, TargetLocation, MissionDuration,Significance){};

    void PrintMission() const override
    {
        cout<<"\nIt's Polar mission with ID: "<< getID()<<" and Target location of "<< this->getTargetLocation()<<endl;
    }
    ~PolarMission();
   
};


#endif //MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
