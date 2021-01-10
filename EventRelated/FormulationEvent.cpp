//
// Created by raspberry on 2021-01-10.
//

#include "FormulationEvent.h"

void FormulationEvent::setMissionType(type missionType) {
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

type FormulationEvent::getMissionType() const {
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

FormulationEvent::FormulationEvent(int ID,int ED,type missionType, int targetLocation, int missionDuration, int significance):Event(ED, ID)
          {
              setMissionType(missionType), setTargetLocation(targetLocation), setMissionDuration(missionDuration),
                      setSignificance(significance);

          }

FormulationEvent::~FormulationEvent() {

}

