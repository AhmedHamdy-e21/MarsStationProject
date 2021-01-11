//
// Created by raspberry on 2021-01-10.
//

#include "MarsStation.h"
void MarsStation::loadFile(string FileName)
{
    ifstream inputFile;

    inputFile.open("../Input Sample.txt");
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
    RLs.addMultipleAvailableEmergencyRovers(E,SE,CE,N);
//    RL.setERoverList(E, SE, CE);
//    RL.setMRoverList(M, SM, CM);
//    RL.setPRoverList(P, SP, CP);

    inputFile >> EV;
//    ML.setMissionList(EV);
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
//            FormulationEvent F_event = FormulationEvent(TYP, TLOC, MIDUR, SIG, ED, ID, &ML, &RL);
//            Events.enqueue(F_event);
//            Formaulation_Event.enqueue(F_event);
            //  ML.AddMission(ED, ID, TLOC, MIDUR, SIG, TYP);
        }

        else if (type == "X")
        {
            inputFile >> ED;
            inputFile >> ID;
//            CancelEvent C_event = CancelEvent(ED, ID, &ML, &RL);
//            Events.enqueue(C_event);
            // ML.CancelMission(ED, ID, CurrentE, CurrentM, CurrentP);;
        }
        else if (type == "P")
        {
            inputFile >> ED;
            inputFile >> ID;

//            PromoteEvent P_event = PromoteEvent(ED, ID,&ML,&RL);
//            Events.enqueue(P_event);
            //ML.PromoteMission(ED, ID);
        }
    }


    inputFile.close();}

MarsStation::MarsStation() {

}

MarsStation::~MarsStation() {

}
