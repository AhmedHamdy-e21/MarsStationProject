#include "EmergencyRover.h"

EmergencyRover::EmergencyRover(int Speed, int CheckupDuration, int NoCheckupMissions,int ID)
: Rover(Speed, CheckupDuration,NoCheckupMissions,ID)
{
}

void EmergencyRover::Print() {
        cout << "\n This is an emergency rover, my ID is: " << getID() << ", and my speed is:  " << this->getSpeed() << " , my number of missions before doing a checkup is: " << this->getNoCheckupMissions() << " , and finally my checkup duration is: "
        <<this->getCheckupDuration()<<endl;
}

EmergencyRover::EmergencyRover(EmergencyRover* PR) :Rover(PR->getSpeed(), PR->getCheckupDuration(),
                                                          PR->getNoCheckupMissions(),PR->getID())

{
    setNoOfExecutedMissions(PR->getNoOfExecutedMissions());

}

EmergencyRover::~EmergencyRover() {

}


