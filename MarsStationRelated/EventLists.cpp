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

void EventLists::addFormulationEvent(FormulationEvent* FE)
{
    FormulationEventList.enqueue(FE);

}

FormulationEvent *EventLists::getFormulationEvent()
{
    FormulationEvent* Ev;
    FormulationEventList.dequeue(Ev);
    return Ev;
}

void EventLists::addCancellationEvent(CancelEvent * CE)
{
    CancellationEventList.enqueue(CE);

}

CancelEvent *EventLists::getCancellationEvent()
{
    CancelEvent* Ev;
    CancellationEventList.dequeue(Ev);
    return Ev;
}

void EventLists::addPromotionEvent(PromoteEvent * PE)
{
    PromotionEventList.enqueue(PE);
}

PromoteEvent *EventLists::getPromotionEvent()
{
    PromoteEvent* Ev;
    PromotionEventList.dequeue(Ev);
    return Ev;
}
