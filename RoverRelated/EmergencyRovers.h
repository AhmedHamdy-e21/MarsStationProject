#include"Rover.h"

class EmergencyRovers : public Rover
{
public:
    EmergencyRovers(int Speed, int CheckupDuration, int NoCheckupMissions) : Rover(Speed, CheckupDuration, NoCheckupMissions) {};

  
    void Print() override  //Make sure in gitkraken
    {
        cout<<"\n I'm Emergency "<< this->getSpeed()<< this->getCheckupDuration();
    }


};