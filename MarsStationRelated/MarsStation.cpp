//
// Created by raspberry on 2021-01-10.
//

#include "MarsStation.h"
void MarsStation::loadFile(string FileName)
{
    ifstream inputFile;

    inputFile.open(FileName);
    // Check for Error:
    if (inputFile.fail()) {
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "I open the file now" << endl;
    }
    int M, P, E, SM, SP, SE, N, CM, CP, CE, AutoP, EV, ED, ID, TLOC, MIDUR, SIG;
    char F, TYP;
    inputFile >> M;
    inputFile >> P;
    inputFile >> E; //number of events
    inputFile >> SM;
    inputFile >> SP;
    inputFile >> SE;
    inputFile >> N;
    inputFile >> CM;
    inputFile >> CP;
    inputFile >> CE;
    inputFile >> AutoP;
    RLs.addMultipleAvailableEmergencyRovers(E,SE,CE,N);// This is to initialize the Available Emergency Rovers.
    RLs.addMultipleAvailableMountainousRovers(M,SM,CM,N);
    RLs.addMultipleAvailablePolarRovers(P,SP,CP,N);
    inputFile >> EV;
    for (int j = 0; j < EV; j++)
    {
        string type;
        inputFile >> type;
        if (type == "F")
        {
            inputFile >> TYP;
            inputFile >> ED;
            inputFile >> ID;
            inputFile >> TLOC;
            inputFile >> MIDUR;
            inputFile >> SIG;
            EVs.addFormulationEvent(ID,ED,TYP,TLOC,MIDUR,SIG); // It's loading correctly, I check it in the debugging mode
        }
        else if (type == "X")
        {
            inputFile >> ED;
            inputFile >> ID;
            EVs.addCancellationEvent(ID,ED);
        }
        else if (type == "P")
        {
            inputFile >> ED;
            inputFile >> ID;
            EVs.addPromotionEvent(ED,ID);
        }
    }
    inputFile.close();
}

MarsStation::MarsStation() {

}

MarsStation::~MarsStation() {

}

bool MarsStation::assignMountainousMission()
{
    if(RLs.peekAvailableMountainousRover())
    {
        MountainousRover* MR;
        MR=RLs.getAvailableMountainousRover();
        RLs.addInMissionMountainousRover(MR);
        return true;
    }
    else if(RLs.peekAvailableEmergencyRover())
    { // add to the Emergency if there isn't Mountainous one
        EmergencyRover* ER;
        ER=RLs.getAvailableEmergencyRover();
        RLs.addInMissionEmergencyRover(ER);
        return true;
    }
    else false;
}

//// So the assign polar just take a mission and assign it if there is an available rovers.
//// The other assignment large function will check the type of events and create the corresponding missions.
//// Then just call the subroutine assign to switch the status.

bool MarsStation::assignPolarMission()
{
    // peak function is redundut because the get either return a rover or null. So I don't need to peak rover.
    // But I'll continue and check like make it as if isAvailable function.
    if (RLs.peekAvailablePolarRover())
    {
        // So there is a polar rover available.
        PolarRover* PR;
        PR=RLs.getAvailablePolarRover();
        RLs.addInMissionPolarRover(PR);
        return true;
    }
    else return false;
}

bool MarsStation::assignTodaysMission(int CurrentDay)
{
    //// First check will be on the Emergency
    // Then Mountainous.
    // Then Polar.


    // So the assign function must be generic for all types
    // It'll be large and huge.
    // So I need to think how I can discretize it in order to trace errors later.

    // Firstly peek to check whether there is Polar mission today
    if (EVs.peekFormulationEvent()->getEventDay()==CurrentDay)
    {
        // check the type of mission and add it accordingly
        // add polar mission.
        PolarMission* PM;
        MLs.addPolarMission();
        // Check for the availability of rovers
        if(RLs.peekAvailablePolarRover())

        // Assign the mission to the rover.
        // get the mission into in execution status
        // get the robot into in mission status

    }

}

bool MarsStation::assignEmergencyMission()
{
    if(RLs.peekAvailableEmergencyRover())
    { // add to the Emergency if there isn't Mountainous one
        EmergencyRover* ER;
        ER=RLs.getAvailableEmergencyRover();
        RLs.addInMissionEmergencyRover(ER);
        return true;
    }
    else if(RLs.peekAvailableMountainousRover())
    {
        MountainousRover* MR;
        MR=RLs.getAvailableMountainousRover();
        RLs.addInMissionMountainousRover(MR);
        return true;
    }
    else if (assignPolarMission())
    {
        return true;
    }
    return false;


}
