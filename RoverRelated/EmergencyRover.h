#include"Rover.h"

class EmergencyRover : public Rover
{
public:
    EmergencyRover(int Speed, int CheckupDuration, int NoCheckupMissions,int ID);
    void Print() override;
};