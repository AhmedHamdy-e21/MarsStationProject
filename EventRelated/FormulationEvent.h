//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_FORMULATIONEVENT_H
#define MARSSTATIONPROJECT_FORMULATIONEVENT_H
#include "Event.h"
enum type { M, P , E};
class FormulationEvent : public Event
{
private:
    type MissionType;
    int TargetLocation;
    int MissionDuration;
    int Significance;
public:

    FormulationEvent(int ID,int ED,type missionType, int targetLocation, int missionDuration, int significance);

    type getMissionType() const;

    int getTargetLocation() const;

    int getMissionDuration() const;

    int getSignificance() const;

    void setMissionType(type missionType);

    void setTargetLocation(int targetLocation);

    void setMissionDuration(int missionDuration);

    void setSignificance(int significance);

    virtual ~FormulationEvent();

};


#endif //MARSSTATIONPROJECT_FORMULATIONEVENT_H
