//
// Created by raspberry on 2021-01-10.
//

#include "CancelEvent.h"

CancelEvent::CancelEvent(int ID,int ED):Event(ED,ID)
{}

void CancelEvent::Print() {
    cout << "This is Cancellation Event with ID: " << getID()<<" and Event Day is on: "<<getEventDay();
}
