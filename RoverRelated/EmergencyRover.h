#include"Rover.h"

class EmergencyRover : public Rover
{
public:
    EmergencyRover(int Speed, int CheckupDuration, int NoCheckupMissions);
    void Print() override;
};