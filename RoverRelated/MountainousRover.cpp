#include"MountainousRover.h"

void MountainousRover::Print() {
    cout << "\n This is a mountainous rover my ID is: " << getID() << ", and my speed is:  " << this->getSpeed() << " , my number of missions before doing a checkup is: " << this->getNoCheckupMissions() << " , and finally my checkup duration is: "
        <<this->getCheckupDuration()<<endl;
}

MountainousRover::MountainousRover(int Speed, int CheckupDuration, int NoCheckupMissions, int ID) : Rover(Speed,
                                                                                                  CheckupDuration,
                                                                                                  NoCheckupMissions,ID) {

}

MountainousRover::MountainousRover(MountainousRover* PR) :Rover(PR->getSpeed(), PR->getCheckupDuration(),
        PR->getNoCheckupMissions(),PR->getID())

{
setNoOfExecutedMissions(PR->getNoOfExecutedMissions());

}

MountainousRover::~MountainousRover() {

}

