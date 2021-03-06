//
// Created by raspberry on 2021-01-08.
//

#include "UIClass.h"

PROG_MODE UIClass::getProgramMode()
{
    printString("Please Enter the program mode: \nEnter 1 for Interactive Mode\n Enter 2 for Step-By-Step Mode\n Enter 3 for In Silent Mode\n");
    int Input;
    cin>>Input;
    this->mode=(PROG_MODE)Input;
    return mode;
}

void UIClass::printString(string text)
{
    cout<<"\n"<<text;
}

void UIClass::waitForUser()
{

}

void UIClass::sleep(int milliseconds)
{
    unsigned int microsecond = 1000000;
    sleep(milliseconds * microsecond);//sleeps for 3 second
}

void UIClass::addToWaitingString()
{
    cout<<"\nWaiting Missions:        ";
}

void UIClass::addToInExecutionString()
{
    cout<<"\nInExecution Missions:       ";
}

void UIClass::addToCompletedString()
{
    cout<<"\nCompleted Missions:      ";
}
void UIClass::addToPolarString(int N)
{
    cout<<" ("<<N<<") ";
}
void UIClass::addToEmergencyString(int N)
{
    cout<<" ["<<N<<"] ";
}

UIClass::UIClass() {

}

UIClass::~UIClass() {

}

void UIClass::addToAvailableRoversString()
{

    cout<<"\nAvailable Rovers:      ";
}

void UIClass::addToMountainousString(int N)
{
    cout<<" "<<N<<" ";

}

void UIClass::printCurrentDay(int CurrentDay)
{
    cout<<"\n\n\n"<<"Current Day:       "<<CurrentDay<<endl;

}





