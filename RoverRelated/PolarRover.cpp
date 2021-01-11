#include"PolarRover.h"

void PolarRover::Print() {
    cout<<"\n This is a polar rover my ID is: "<<getId() <<", and my speed is:  "<< this->getSpeed()<<" , my number of missions before doing a checkup is: "<<this->getNoCheckupMissions() <<" , and finally my checkup duration is: "
        <<this->getCheckupDuration()<<endl;
}

PolarRover::PolarRover(int Speed, int CheckupDuration, int NoCheckupMissions,int ID) : Rover(Speed, CheckupDuration,
                                                                                      NoCheckupMissions,ID) {

}
