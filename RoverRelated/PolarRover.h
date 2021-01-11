#include"Rover.h"

class PolarRover: public Rover
{
public:
    PolarRover(int Speed, int CheckupDuration, int NoCheckupMissions);
    void Print() override;
};