#include"Rover.h"

class MountainousRover : public Rover
{

	public:
    MountainousRover(int Speed, int CheckupDuration, int NoCheckupMissions,int ID);
    MountainousRover(MountainousRover* PR);
    ~MountainousRover();
    void Print() override ;
};