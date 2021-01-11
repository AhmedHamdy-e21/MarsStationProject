//
// Created by raspberry on 2021-01-10.
//

#include "FormulationEvent.h"

void FormulationEvent::setMissionType(char missionType) {
    MissionType = missionType;
}

void FormulationEvent::setTargetLocation(int targetLocation) {
    TargetLocation = targetLocation;
}

void FormulationEvent::setMissionDuration(int missionDuration) {
    MissionDuration = missionDuration;
}

void FormulationEvent::setSignificance(int significance) {
    Significance = significance;
}

char FormulationEvent::getMissionType() const {
    return MissionType;
}

int FormulationEvent::getTargetLocation() const {
    return TargetLocation;
}

int FormulationEvent::getMissionDuration() const {
    return MissionDuration;
}

int FormulationEvent::getSignificance() const {
    return Significance;
}

FormulationEvent::FormulationEvent(int ID,int ED,char missionType, int targetLocation, int missionDuration, int significance):Event(ED, ID)
          {
              setMissionType(missionType), setTargetLocation(targetLocation), setMissionDuration(missionDuration),
                      setSignificance(significance);

          }

FormulationEvent::~FormulationEvent() {

}

void FormulationEvent::Print() {
    cout << "This is Formulation Event with ID: " << getID()<<" , Event Day is on: "<<getEventDay()<<", Mission type is: "<<getMissionType()<<", Target Location to: "<<getTargetLocation()<<", The mission duration is: "
    <<getMissionDuration()<<", and mission significance is "<<getSignificance()<<endl;

}

