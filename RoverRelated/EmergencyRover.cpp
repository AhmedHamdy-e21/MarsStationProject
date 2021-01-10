#include "EmergencyRover.h"

EmergencyRover::EmergencyRover(int Speed, int CheckupDuration, int NoCheckupMissions)
: Rover(Speed, CheckupDuration,NoCheckupMissions)
{
}

void EmergencyRover::Print() {
        cout<<"\n I'm Emergency "<< this->getSpeed()<< this->getCheckupDuration();

}
