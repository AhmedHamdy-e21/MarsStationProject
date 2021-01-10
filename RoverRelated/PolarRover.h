#include"Rover.h"

class PolarRover: public Rover
{
public:
    PolarRover(int Speed, int CheckupDuration, int NoCheckupMissions) : Rover(Speed, CheckupDuration, NoCheckupMissions) {};

    void Print() override
    {
        cout<<"\n I'm Polar "<< this->getSpeed()<< this->getCheckupDuration(); //Make sure in gitkraken
    }

};