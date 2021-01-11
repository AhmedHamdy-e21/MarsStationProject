//
// Created by raspberry on 2021-01-11.
//

#include "EventLists.h"

const LinkedQueue<FormulationEvent *> &EventLists::getFormulationEventList() const {
    return FormulationEventList;
}

const LinkedQueue<CancelEvent *> &EventLists::getCancellationEventList() const {
    return CancellationEventList;
}

const LinkedQueue<PromoteEvent *> &EventLists::getPromotionEventList() const {
    return PromotionEventList;
}
