#include"Rover.h"

class PolarRover: public Rover
{
public:
    PolarRover(int Speed, int CheckupDuration, int NoCheckupMissions,int ID);
    void Print() override;
};