//
// Created by raspberry on 2021-01-10.
//

#include "Event.h"

Event::Event(int eventDay, int id) : EventDay(eventDay), ID(id) {}

int Event::getID() const {
    return ID;
}

void Event::setEventDay(int eventDay) {
    EventDay = eventDay;
}

void Event::setId(int id) {
    ID = id;
}

int Event::getEventDay() const {
    return EventDay;
}

void Event::Print()
{
    cout << "This is Event with ID: " << getID()<<" and Event Day is on: "<<getEventDay();
}
