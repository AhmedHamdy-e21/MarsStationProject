//
// Created by raspberry on 2021-01-11.
//

#ifndef MARSSTATIONPROJECT_EVENTLISTS_H
#define MARSSTATIONPROJECT_EVENTLISTS_H
#include "../DataStructure/Queue/LinkedQueue.h"
//#include "../DataStructure/Queue/NodeQ.cpp"
#include "../EventRelated/FormulationEvent.h"
#include "../EventRelated/CancelEvent.h"
#include "../EventRelated/PromoteEvent.h"

class EventLists
{
private:

    LinkedQueue<FormulationEvent*> FormulationEventList;
    LinkedQueue<CancelEvent*> CancellationEventList;
    LinkedQueue<PromoteEvent*> PromotionEventList;

public:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Formulation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const LinkedQueue<FormulationEvent *> &getFormulationEventList() const;
    void addFormulationEvent(int ID,int ED,char missionType, int targetLocation, int missionDuration, int significance);
    FormulationEvent * getFormulationEvent();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Cancellation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const LinkedQueue<CancelEvent *> &getCancellationEventList() const;
    void addCancellationEvent(int ID,int ED);
    CancelEvent * getCancellationEvent();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////Promotion
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const LinkedQueue<PromoteEvent *> &getPromotionEventList() const;
    void addPromotionEvent(int ED, int ID);
    PromoteEvent * getPromotionEvent();
};


#endif //MARSSTATIONPROJECT_EVENTLISTS_H
