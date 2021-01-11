//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_EVENT_H
#define MARSSTATIONPROJECT_EVENT_H
// I don't think that I need to store the event type here. but anyways lets see
using namespace std;
#include <iostream>
class Event
{
private:
    int EventDay;
    int ID;
public:
    Event(int eventDay, int id);
    int getEventDay() const;
    int getID() const;
    void setEventDay(int eventDay);
    void setId(int id);
    virtual void Print();
};


#endif //MARSSTATIONPROJECT_EVENT_H
