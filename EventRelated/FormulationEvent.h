//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_FORMULATIONEVENT_H
#define MARSSTATIONPROJECT_FORMULATIONEVENT_H
#include "Event.h"

class FormulationEvent : public Event
{
private:
    char MissionType;
    int TargetLocation;
    int MissionDuration;
    int Significance;

public:

    FormulationEvent(int ID,int ED,char missionType, int targetLocation, int missionDuration, int significance);

    char getMissionType() const;

    int getTargetLocation() const;

    int getMissionDuration() const;

    int getSignificance() const;

    void setMissionType(char missionType);

    void setTargetLocation(int targetLocation);

    void setMissionDuration(int missionDuration);

    void setSignificance(int significance);
    void Print() override;

    virtual ~FormulationEvent();

};


#endif //MARSSTATIONPROJECT_FORMULATIONEVENT_H
