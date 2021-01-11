#include"Rover.h"

class MountainousRover : public Rover
{

	public:
    MountainousRover(int Speed, int CheckupDuration, int NoCheckupMissions);
    void Print() override ;
};