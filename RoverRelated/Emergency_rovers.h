#include"Rover.h"

class Emergency_rovers : public Rover
{
public:
    Emergency_rovers(int Speed,int CheckupDuration,int NoCheckupMissions) : Rover(Speed, CheckupDuration,NoCheckupMissions) {};

  
    void Print() override  //Make sure in gitkraken
    {
        cout<<"\n I'm Emergency "<< this->getSpeed()<< this->getCheckupDuration();
    }


};