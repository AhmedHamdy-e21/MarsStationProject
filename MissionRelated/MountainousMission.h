//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSION_H
#define MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSION_H
#include "Mission.h"

class MountainousMission : public Mission


        {

private:
            int AutoP;

public:
    MountainousMission();
       MountainousMission(int AutoP, int ED, int ID, int TargetLocation, int MissionDuration, int Significance):
       Mission(ED,ID, TargetLocation, MissionDuration,Significance)
       {
               setAutoP(AutoP);


       }

       void setAutoP(int AutoP)
       {
           this->AutoP=AutoP;
       }
        void Print() const override  //Make sure in gitkraken
        {
            cout<<"\nIt's Mountainous mission with  ID: "<<getID()<<" and Target location of "<< this->getTargetLocation()<<endl;
        }
        ~MountainousMission();

        };


#endif //MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSION_H
