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
            CancelEvent* CV;
            EVs.getCancellationEventList().peek(CV);
            CV->Print();
        }
        else if (type == "P")
        {
            inputFile >> ED;
            inputFile >> ID;
            EVs.addPromotionEvent(ED,ID);
            PromoteEvent* CV;
            EVs.getPromotionEventList().peek(CV);
            CV->Print();
        }
    }


    inputFile.close();
}

MarsStation::MarsStation() {

}

MarsStation::~MarsStation() {

}
