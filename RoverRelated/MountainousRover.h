#include"Rover.h"

class MountainousRover : public Rover
{

	public:
    MountainousRover(int Speed, int CheckupDuration, int NoCheckupMissions) : Rover(Speed, CheckupDuration, NoCheckupMissions) {};
    void Print() override    //Make sure in gitkraken
    {
        cout<<"\n I'm Mountanous "<< this->getSpeed()<< this->getCheckupDuration();
    }


};