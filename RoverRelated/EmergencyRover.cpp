#include "EmergencyRover.h"

EmergencyRover::EmergencyRover(int Speed, int CheckupDuration, int NoCheckupMissions)
: Rover(Speed, CheckupDuration,NoCheckupMissions)
{
}

void EmergencyRover::Print() {
        cout<<"\n This is an emergency rover, my speed is:  "<< this->getSpeed()<<" , my number of missions before doing a checkup is: "<<this->getNoCheckupMissions() <<" , and finally my checkup duration is: "
        <<this->getCheckupDuration()<<endl;
}
