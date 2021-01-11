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
    setAutoP(AutoP);


    RLs.addMultipleAvailableMountainousRovers(M,SM,CM,N);

    RLs.addMultipleAvailablePolarRovers(P,SP,CP,N);

    RLs.addMultipleAvailableEmergencyRovers(E,SE,CE,N);
    // This is to initialize the Available Emergency Rovers.
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

// If smaller than or equal the current day
bool MarsStation::assignTodaysMission(int CurrentDay)
{
    //// First check will be on the Emergency
    // Then Mountainous.
    // Then Polar.
    // So the assign function must be generic for all types
    // It'll be large and huge.
    // So I need to think how I can discretize it in order to trace errors later.
    // Firstly peek to check whether there is Polar mission today

//// //// There should be a loop here not just if

//// The emergency mission need to be loaded firstly in this day. In order to be ordered in the heap

    while (EVs.peekFormulationEvent()->getEventDay()==CurrentDay||EVs.peekFormulationEvent()->getEventDay()<CurrentDay)
    {

        FormulationEvent* FE;
        FE=EVs.getFormulationEvent();
        if(FE->getMissionType()=='E')
        {
            // add emergency mission. first. Because you are not sure whether there is an available rover or not
            // I need a constructor that initialized by the mission.


            EmergencyMission* EM=new EmergencyMission(FE);
            MLs.addEmergencyMission(EM);
            // I can recurrsively call the add here
            assignTodaysMission(CurrentDay); //// This recurrsive call should add all emergency mission first then It'll proceed.
            //// But I don't know how it'll perform on the other missions. I think this is okay
            // Then I need to check for rover availablility


            if(assignEmergencyMission())
            {
                EM=MLs.getEmergencyMission();
                MLs.addInExecutionEmergency(EM);// I need to keep the history. I may keep it as a member in the mission itself.

            }

        }
        else if(FE->getMissionType()=='M')
        {
            // Don't forget to set the autoP
            MountainousMission* MM=new MountainousMission(FE,getAutoP());
            MLs.addMountainousMission(MM);
            if(assignMountainousMission())
            {
                MM=MLs.getMountainousMission();
                MLs.addInExecutionMountainous(MM);//
            }

        }
        else if(FE->getMissionType()=='P')
        {
            PolarMission* PM=new PolarMission(FE);
            MLs.addPolarMission(PM);
            if(assignPolarMission())
            {
                PM=MLs.getPolarMission();
                MLs.addInExecutionPolar(PM);
            }
        }
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

int MarsStation::getAutoP() const
{
    return AutoP;
}

void MarsStation::setAutoP(int autoP) {
    AutoP = autoP;
}

const MissionLists &MarsStation::getMLs() const {
    return MLs;
}

const RoverLists &MarsStation::getRLs() const {
    return RLs;
}

const EventLists &MarsStation::getEVs() const {
    return EVs;
}

bool MarsStation::cancelTodaysMission(int CurrentDay) {
    return false;
}

bool MarsStation::promoteTodaysMission(int CurrentDay) {
    return false;
}
