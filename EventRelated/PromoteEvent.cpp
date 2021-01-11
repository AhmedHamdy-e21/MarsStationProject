//
// Created by raspberry on 2021-01-10.
//

#include "PromoteEvent.h"

PromoteEvent::PromoteEvent(int ED, int ID): Event(ED, ID) {}

void PromoteEvent::Print() {
    cout << "This is Promotion Event with ID: " << getID()<<" and Event Day is on: "<<getEventDay();

}
