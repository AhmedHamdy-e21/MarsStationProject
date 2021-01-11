//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_EVENT_H
#define MARSSTATIONPROJECT_EVENT_H


using namespace std;
#include <iostream>
class Event
{
private:
    char EvenType;
public:
    void setEvenType(char evenType);

public:
    char getEvenType() const;

private:
    int EventDay;
    int ID;
public:
    Event(int eventDay, int id,char EventType);
    int getEventDay() const;
    int getID() const;
    void setEventDay(int eventDay);
    void setId(int id);
//    virtual char getMissionType()=0;
    virtual void Print();
};


#endif //MARSSTATIONPROJECT_EVENT_H
