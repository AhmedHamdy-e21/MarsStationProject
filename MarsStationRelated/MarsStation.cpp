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
//    else
//    {
////        cout << "I open the file now" << endl;
//    }
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
//    this->IDDictionary.insert({-1,-1});
}

MarsStation::~MarsStation() {
}

bool MarsStation::assignMountainousMission(int & ID)
{
    if(RLs.peekAvailableMountainousRover())
    {
        MountainousRover* MR;
        MR=RLs.getAvailableMountainousRover();
        RLs.addInMissionMountainousRover(MR);
        ID= MR->getID();
        return true;
    }
    else if(RLs.peekAvailableEmergencyRover())
    { // add to the Emergency if there isn't Mountainous one
        EmergencyRover* ER;
        ER=RLs.getAvailableEmergencyRover();
        RLs.addInMissionEmergencyRover(ER);
        ID= ER->getID();
        return true;
    }
    else return false;
}

//// So the assign polar just take a mission and assign it if there is an available rovers.
//// The other assignment large function will check the type of events and create the corresponding missions.
//// Then just call the subroutine assign to switch the status.

bool MarsStation::assignPolarMission(int &ID)
{
    // peak function is redundut because the get either return a rover or null. So I don't need to peak rover.
    // But I'll continue and check like make it as if isAvailable function.
    if (RLs.peekAvailablePolarRover())
    {
        // So there is a polar rover available.
        PolarRover* PR;
        PR=RLs.getAvailablePolarRover();
        RLs.addInMissionPolarRover(PR);
        ID= PR->getID();
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
        int MissionID;
        int RoverID;
        if(FE->getMissionType()=='E')
        {
            // add emergency mission. first. Because you are not sure whether there is an available rover or not
            // I need a constructor that initialized by the mission.


            EmergencyMission* EM=new EmergencyMission(FE, CurrentDay);
            MLs.addEmergencyMission(EM);
            // I can recurrsively call the add here
            assignTodaysMission(CurrentDay); //// This recurrsive call should add all emergency mission first then It'll proceed.
            //// But I don't know how it'll perform on the other missions. I think this is okay
            // Then I need to check for rover availablility



            MissionID=EM->getED();
            if(assignEmergencyMission(RoverID))
            {
                EM=MLs.getEmergencyMission();
                MLs.addInExecutionEmergency(EM);// I need to keep the history. I may keep it as a member in the mission itself.
                insertIDPair(MissionID,RoverID);// This is to keep both IDs
            }

        }
        else if(FE->getMissionType()=='M')
        {
            // Don't forget to set the autoP
            MountainousMission* MM=new MountainousMission(FE,getAutoP(), CurrentDay);
            MLs.addMountainousMission(MM);
            MissionID=MM->getED();

            if(assignMountainousMission(RoverID))
            {
                MM=MLs.getMountainousMission();
                MLs.addInExecutionMountainous(MM);//
                insertIDPair(MissionID,RoverID);
            }

        }
        else if(FE->getMissionType()=='P')
        {
            PolarMission* PM=new PolarMission(FE, CurrentDay);
            MLs.addPolarMission(PM);
            MissionID=PM->getED();

            if(assignPolarMission(RoverID))
            {
                PM=MLs.getPolarMission();
                MLs.addInExecutionPolar(PM);
                insertIDPair(MissionID,RoverID);
            }
        }
    }

}

bool MarsStation::assignEmergencyMission(int& ID)
{

    if(RLs.peekAvailableEmergencyRover())
    { // add to the Emergency if there isn't Mountainous one
        EmergencyRover* ER;
        ER=RLs.getAvailableEmergencyRover();
        RLs.addInMissionEmergencyRover(ER);
        ID= ER->getID();
        return true;
    }
    else if(RLs.peekAvailableMountainousRover())
    {
        MountainousRover* MR;
        MR=RLs.getAvailableMountainousRover();
        RLs.addInMissionMountainousRover(MR);
        ID= MR->getID();
        return true;
    }
    else if (assignPolarMission(ID))
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

 MissionLists &MarsStation::getMLs()  {
    return MLs;
}

 RoverLists &MarsStation::getRLs()  {
    return RLs;
}

 EventLists &MarsStation::getEVs()  {
    return EVs;
}

bool MarsStation::cancelTodaysMission(int CurrentDay)
{
    while(EVs.peekCancellationEvent()->getEventDay()==CurrentDay)
    {
        CancelEvent* CE;
        CE=EVs.getCancellationEvent();
        int ID=CE->getID();
        MLs.cancelMountainousMission(ID);// The id must of mountainous mission yaay
        return true;
    }
    return false;
}

bool MarsStation::promoteTodaysMission(int CurrentDay)
{
    while(EVs.peekPromotionEvent()->getEventDay()==CurrentDay)
    {
        PromoteEvent* PE;
        PE=EVs.getPromotionEvent();
        int ID=PE->getID();
        // I  need to cancel the mission and make it Emergency one so I need to get its info first
        MountainousMission* MM=MLs.getWaitingMountainousMissionList().FindID(ID); // constructor in emergency mission to initialize this
        if(MM)// I made it not constant
        {
            EmergencyMission* EM=new EmergencyMission(MLs.getWaitingMountainousMissionList().FindID(ID),CurrentDay);
            MLs.cancelMountainousMission(ID);
            MLs.addEmergencyMission(EM);
        }
    }
    return false;
}

bool MarsStation::isCompletedToday(int CurrentDay)
{
    /// now I have is completed function in each missions that takes the current day
    /// I need to loop on the Inexecution List. O.o I need to trace which robots has which mission
    /// Done Mapping the IDs

    /// I can store them in dictionary like
    //// Don't forget to set the completed Day.
    //// And free the robot,
    //// Then check whether it can go to available or go to checkup

    //// Use the FindCompleted method.

//    MountainousMission* MM=;
//// For some reason when I check for MM in the while loop it doesn't see it as null, because it's now updated within the loop
// I'll call it in each step for now.
while(MLs.getInExecutionMountainous().FindCompleted(CurrentDay))//||MLs.getInExecutionPolar().FindCompleted(CurrentDay)||MLs.getInExecutionEmergency().FindCompleted(CurrentDay)
{
    if(MLs.getInExecutionPolar().FindCompleted(CurrentDay))
    {

        transferInMissionPolarRover(CompletedPolar(MLs.getInExecutionPolar().FindCompleted(CurrentDay),CurrentDay));
    }
     if(MLs.getInExecutionMountainous().FindCompleted(CurrentDay))
    {

        transferInMissionMountainousRover(CompletedMountainous(MLs.getInExecutionMountainous().FindCompleted(CurrentDay),CurrentDay));
    }
    else if(MLs.getInExecutionEmergency().FindCompleted(CurrentDay))
    {

        transferInMissionEmergencyRover(CompletedEmergency(MLs.getInExecutionEmergency().FindCompleted(CurrentDay),CurrentDay));
    }
    MountainousMission* MM=MLs.getInExecutionMountainous().FindCompleted(CurrentDay);
}
return true;

}

void MarsStation::simulate(int CurrentDay)
{
    /// The condition when everything return false
    UIClass UserInterface;
    loadFile("../ConfigurationFile.txt");
    // I need to print and also I need to check when the mission is finished to transfer it to the completed
    // and add the rover to the list.
    int i=0;// This is for just experimenting
    while(i<30)
    {
//        UserInterface.getProgramMode();
        assignTodaysMission(CurrentDay);
        isCompletedToday( CurrentDay);
        cancelTodaysMission(CurrentDay);
        promoteTodaysMission(CurrentDay);
//        cout<<CurrentDay;
        CurrentDay++;
        i++;
    }

    // return when there is nothing to do
    //return;

}

void MarsStation::insertIDPair(int MissionID, int RoverID)
{
    IDDictionary.insert({MissionID,RoverID});
}

void MarsStation::eraseIDPair(int MissionID)
{
    IDDictionary.erase(MissionID);
}

MountainousRover* MarsStation::CompletedMountainous(MountainousMission *MM,int CurrentDay)
{
    int ID;
    ID=MM->getID();
    /// This is the completed Mission
    MountainousMission* M=new MountainousMission(MM);
    M->setCompletedDay(CurrentDay);
    MLs.getInExecutionMountainous().DeleteNode(ID);
    MLs.getCompletedMountainous().InsertBeg(M);
    //// Here I can Delete the pair
    int RoverID=returnRoverID(ID);
    eraseIDPair(ID);
    return RLs.getInMissionMountainousRovers().FindID(RoverID);
    //// Where is the return ??!



}

PolarRover* MarsStation::CompletedPolar(PolarMission *PM,int CurrentDay)
{
    int ID;
    ID=PM->getID();
    /// This is the completed Mission
    PolarMission* M=new PolarMission(PM);
    M->setCompletedDay(CurrentDay);
    MLs.getInExecutionPolar().DeleteNode(ID);
    MLs.getCompletedPolar().InsertBeg(M);
    //// Here I can Delete the pair
    int RoverID=returnRoverID(ID);

    eraseIDPair(ID);
    return RLs.getInMissionPolarRovers().FindID(RoverID);

}

EmergencyRover* MarsStation::CompletedEmergency(EmergencyMission *EM,int CurrentDay)
{
    int ID;
    ID=EM->getID();
    /// This is the completed Mission
    EmergencyMission* M=new EmergencyMission(EM);
    M->setCompletedDay(CurrentDay);
    MLs.getInExecutionEmergency().DeleteNode(ID);
    MLs.getCompletedEmergency().InsertBeg(M);
    //// Here I can Delete the pair
    int RoverID=returnRoverID(ID);
    eraseIDPair(ID);
    return RLs.getInMissionEmergencyRovers().FindID(RoverID);
}

bool MarsStation::transferInMissionMountainousRover(MountainousRover *MR)

{


    //// Firstly, I need to delete it from the InMission status
    //// Then, add it either to Checkup or Available by checking the number of missions before duration
    //// This need to be a function there in the rover parent
    ;// This is to add the number of executing mission first.
    // Then I need to check whether to checkup or not
    //// Don't forget that I need to delete the rover from the Inmission List
    // I can make get function in the linked list, this will be better, or just generating another rover.

    if(MR)
    {
        int ID=MR->getID();
        MR->incrementNoOfExecutedMissions();


        if (MR->isCheckUp()) {

            MountainousRover *NewRover = new MountainousRover(MR);
            RLs.getInMissionMountainousRovers().DeleteNode(ID); /// I need to delete this
            RLs.addInCheckupMountainousRover(NewRover);// This line extract the node and add to the checkup
            return true;
        } else {
            MountainousRover *NewRover = new MountainousRover(MR);
            RLs.getInMissionMountainousRovers().DeleteNode(ID);
            RLs.addAvailableMountainousRover(NewRover);
            return true;
        }
    }

    return false;
}

bool MarsStation::transferInMissionPolarRover(PolarRover *PR)
{

    PR->incrementNoOfExecutedMissions();// This is to add the number of executing mission first.
    // Then I need to check whether to checkup or not
    //// Don't forget that I need to delete the rover from the Inmission List
    // I can make get function in the linked list, this will be better, or just generating another rover.

    if(PR->isCheckUp())
    {
        RLs.addInCheckupPolarRover(RLs.getInMissionPolarRovers().extractNode(PR->getID()));// This line extract the node and add to the checkup
        return true;
    }
    else
    {
        RLs.addAvailablePolarRover(RLs.getInMissionPolarRovers().extractNode(PR->getID()));
        return true;
    }

    return false;
}

bool MarsStation::transferInMissionEmergencyRover(EmergencyRover *EM)
{

    EM->incrementNoOfExecutedMissions();// This is to add the number of executing mission first.
    // Then I need to check whether to checkup or not
    //// Don't forget that I need to delete the rover from the Inmission List
    // I can make get function in the linked list, this will be better, or just generating another rover.

    if(EM->isCheckUp())
    {
        RLs.addInCheckupEmergencyRover(RLs.getInMissionEmergencyRovers().extractNode(EM->getID()));// This line extract the node and add to the checkup
        return true;
    }
    else
    {
        RLs.addAvailableEmergencyRover(RLs.getInMissionEmergencyRovers().extractNode(EM->getID()));
        return true;
    }

    return false;
}

int MarsStation::returnRoverID(int MissionID) {
    return this->IDDictionary[MissionID];
}

void MarsStation::AvailableRoversIDs(vector<int> &AvailableMountainousRoversIDs, vector<int> &AvailablePolarRoversIDs,
                                     vector<int> &AvailableEmergencyRoversIDs, LinkedQueue<MountainousRover *> MRQueue,
                                     LinkedQueue<PolarRover *> PRQueue, LinkedQueue<EmergencyRover *> ERQueue) {
    /// So we will simply dequeue and then get the IDs
    //// This would be better here if I implemented it by linked list maybe. I mean available rover. But it's just good for this function purpose not generally.
    // The IDs is return in the form of vector and I will pop the IDs there in the print function
    bool BoolMountainousID;
    MountainousRover* M;
    BoolMountainousID=MRQueue.dequeue(M);
    while(BoolMountainousID)
    {
        AvailableMountainousRoversIDs.push_back(M->getID());
        BoolMountainousID=MRQueue.dequeue(M);
    }
    bool BoolPolarID;
    PolarRover* P;
    BoolPolarID=PRQueue.dequeue(P);
    while(BoolPolarID)
    {
        AvailablePolarRoversIDs.push_back(P->getID());
        BoolPolarID=PRQueue.dequeue(P);
    }
    bool BoolEmergencyID;
    EmergencyRover* E;
    BoolEmergencyID=ERQueue.dequeue(E);
    while(BoolEmergencyID)
    {
        AvailableEmergencyRoversIDs.push_back(E->getID());
        BoolEmergencyID=ERQueue.dequeue(E);
    }
    ///// So this vector is used in order to get all IDs


}

void
MarsStation::WaitingMissionsIDs(vector<int> &AvailableMountainousMissionsIDs, vector<int> &AvailablePolarMissionsIDs,
                                vector<int> &AvailableEmergencyMissionsIDs, LinkedQueue<MountainousMission *> MMQueue,
                                LinkedQueue<PolarMission *> PMQueue, LinkedQueue<EmergencyMission *> EMQueue)
{
    bool BoolMountainousID;
    MountainousMission* M;
    BoolMountainousID=MMQueue.dequeue(M);
    while(BoolMountainousID)
    {
        AvailableMountainousMissionsIDs.push_back(M->getID());
        BoolMountainousID=MMQueue.dequeue(M);
    }
    bool BoolPolarID;
    PolarMission* P;
    BoolPolarID=PMQueue.dequeue(P);
    while(BoolPolarID)
    {
        AvailablePolarMissionsIDs.push_back(P->getID());
        BoolPolarID=PMQueue.dequeue(P);
    }
    bool BoolEmergencyID;
    EmergencyMission* E;
    BoolEmergencyID=EMQueue.dequeue(E);
    while(BoolEmergencyID)
    {
        AvailableEmergencyMissionsIDs.push_back(E->getID());
        BoolEmergencyID=EMQueue.dequeue(E);
    }

}

void
MarsStation::CompletedMissionsIDs(vector<int> &CompletedMountainousMissionsIDs, vector<int> &CompletedPolarMissionsIDs,
                                  vector<int> &CompletedEmergencyMissionsIDs, LinkedQueue<MountainousMission *> MMList,
                                  LinkedQueue<PolarMission *> PMList, LinkedQueue<EmergencyMission *> EMList)
{

    bool BoolMountainousID;
    MountainousMission* M;
    BoolMountainousID=MMList.dequeue(M);
    while(BoolMountainousID)
    {
        CompletedMountainousMissionsIDs.push_back(M->getID());
        BoolMountainousID=MMList.dequeue(M);
    }
    bool BoolPolarID;
    PolarMission* P;
    BoolPolarID=PMList.dequeue(P);
    while(BoolPolarID)
    {
        CompletedPolarMissionsIDs.push_back(P->getID());
        BoolPolarID=PMList.dequeue(P);
    }
    bool BoolEmergencyID;
    EmergencyMission* E;
    BoolEmergencyID=EMList.dequeue(E);
    while(BoolEmergencyID)
    {
        CompletedEmergencyMissionsIDs.push_back(E->getID());
        BoolEmergencyID=EMList.dequeue(E);
    }
}

void MarsStation::InExecutionMissionsIDs(vector<int> &InExecutionMountainousMissionsIDs,
                                         vector<int> &InExecutionPolarMissionsIDs,
                                         vector<int> &InExecutionEmergencyMissionsIDs,
                                         LinkedQueue<MountainousMission *> MMList, LinkedQueue<PolarMission *> PMList,
                                         LinkedQueue<EmergencyMission *> EMList)
{


    bool BoolMountainousID;
    MountainousMission* M;
    BoolMountainousID=MMList.dequeue(M);
    while(BoolMountainousID)
    {
        InExecutionMountainousMissionsIDs.push_back(M->getID());
        BoolMountainousID=MMList.dequeue(M);
    }
    bool BoolPolarID;
    PolarMission* P;
    BoolPolarID=PMList.dequeue(P);
    while(BoolPolarID)
    {
        InExecutionPolarMissionsIDs.push_back(P->getID());
        BoolPolarID=PMList.dequeue(P);
    }
    bool BoolEmergencyID;
    EmergencyMission* E;
    BoolEmergencyID=EMList.dequeue(E);
    while(BoolEmergencyID)
    {
        InExecutionEmergencyMissionsIDs.push_back(E->getID());
        BoolEmergencyID=EMList.dequeue(E);
    }

}





