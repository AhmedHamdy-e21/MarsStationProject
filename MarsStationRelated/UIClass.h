//
// Created by raspberry on 2021-01-08.
//
#include<unistd.h>
#ifndef MARS_MISSIONS_MANAGEMENT_UICLASS_H
#define MARS_MISSIONS_MANAGEMENT_UICLASS_H
using namespace std;
#include <iostream>
class UIClass
{
private:
    int mode;
public:
    int getProgramMode();
    void printString(string text);
    void waitForUser();// needed in the interactive mode to wait the user input
    static void sleep(int milliseconds);// block the program for some time needed in the step by step
    void addToWaitingString(string text);// add to the string of the waiting missions it's like// Waiting missiont// In-Execution etc
};
#endif //MARS_MISSIONS_MANAGEMENT_UICLASS_H
