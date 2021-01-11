//
// Created by raspberry on 2021-01-10.
//

#ifndef MARSSTATIONPROJECT_CANCELEVENT_H
#define MARSSTATIONPROJECT_CANCELEVENT_H

#include "Event.h"
class CancelEvent:public Event
{
public:
    CancelEvent(int ID,int ED);
    void Print() override;

};


#endif //MARSSTATIONPROJECT_CANCELEVENT_H
