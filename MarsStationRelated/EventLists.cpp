//
// Created by raspberry on 2021-01-11.
//

#include "EventLists.h"

const LinkedQueue<FormulationEvent *> &EventLists::getFormulationEventList() const
{
    return FormulationEventList;
}

const LinkedQueue<CancelEvent *> &EventLists::getCancellationEventList() const
{
    return CancellationEventList;
}

const LinkedQueue<PromoteEvent *> &EventLists::getPromotionEventList() const
{
    return PromotionEventList;
}

void EventLists::addFormulationEvent(int ID,int ED,char missionType, int targetLocation, int missionDuration, int significance)
{
    FormulationEvent* FE=new FormulationEvent(ID,ED,missionType,targetLocation,missionDuration,significance);
    FormulationEventList.enqueue(FE);

}

FormulationEvent *EventLists::getFormulationEvent()
{
    FormulationEvent* Ev;
    FormulationEventList.dequeue(Ev);
    return Ev;
}

void EventLists::addCancellationEvent(int ID,int ED)

{
    CancelEvent* CE=new CancelEvent(ID,ED);
    CancellationEventList.enqueue(CE);

}

CancelEvent *EventLists::getCancellationEvent()
{
    CancelEvent* Ev;
    CancellationEventList.dequeue(Ev);
    return Ev;
}

void EventLists::addPromotionEvent(int ED, int ID)
{
    PromoteEvent* PE=new PromoteEvent(ED,ID);
    PromotionEventList.enqueue(PE);
}

PromoteEvent *EventLists::getPromotionEvent()
{
    PromoteEvent* Ev;
    PromotionEventList.dequeue(Ev);
    return Ev;
}
