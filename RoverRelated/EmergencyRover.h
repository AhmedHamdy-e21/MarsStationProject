#include"Rover.h"

class EmergencyRover : public Rover
{
public:
    EmergencyRover(int Speed, int CheckupDuration, int NoCheckupMissions) : Rover(Speed, CheckupDuration, NoCheckupMissions) {};

  
    void Print() override  //Make sure in gitkraken
    {
        cout<<"\n I'm Emergency "<< this->getSpeed()<< this->getCheckupDuration();
    }


};