#include <iostream>

//#include "RoverRelated/MountainousRover.h"
//#include "RoverRelated/PolarRover.h"
//#include "RoverRelated/EmergencyRover.h"
//#include "DataStructure/Queue/NodeQ.h"
//#include "DataStructure/Queue/NodeQ.cpp"
//#include "DataStructure/Queue/LinkedQueue.h"
//#include "DataStructure/Queue/QueueADT.h"
//#include "DataStructure/LinkedList/LinkedListMissions.h"
//#include "MissionRelated/Mission.h"
//#include "MissionRelated/EmergencyMission.h"
//#include "MissionRelated/PolarMission.h"
//#include "MissionRelated/MountainousMission.h"
//#include "DataStructure/LinkedList/LinkedListMissions.h"
//#include "DataStructure/MaxHeap/MaxHeap.cpp"
//#include "DataStructure/Queue/LinkedQueue.h"
//#include "DataStructure/Queue/NodeQ.cpp"
#include  "MarsStationRelated/MarsStation.h"

int main() {

//    Mission*M3=new Mission(1,2,6,32,5);
//    PolarMission*MP=new PolarMission(1,2,6235,32,5);
////    PolarMission* Ms;
//    MountainousMission* M3=new MountainousMission(2,1,2,6435,32,5);
//    Mission* M4=new Mission(1,3,6,32,5);
//    EmergencyMission* M5=new EmergencyMission(1,36,61,32,5);
//    MissionLists M;
//    M.addEmergencyMission(M5);
////    M.getWaitingEmergencyMissionHeap().printHeap();
//    M.addMountainousMission(M3);
//    M.addMountainousMission(M3);
////    M.getWaitingMountainousMissionList().PrintList();
//    M.addPolarMission(MP);
//    M.addPolarMission(MP);
//    M.addPolarMission(MP);
//    MountainousMission* Mo=M.getMountainousMission();
//    Mo->Print();
//    PolarMission* Ms=M.getPolarMission();
//    Ms->Print();
//    M.addInExecutionPolar(Ms);
//    M.getInExecutionPolar().PrintList();
//
//
//    //////
//    RoverLists RL;
//    EmergencyRover* EM=new EmergencyRover(1,2,3);
//    EmergencyRover* EM4=new EmergencyRover(4,6,7);
//    EmergencyRover* EM1;
//    EmergencyRover* EM2;
//    RL.addAvailableEmergencyRover(EM4);
//    RL.addAvailableEmergencyRover(EM4);
//    RL.addAvailableEmergencyRover(EM4);
//    cout<<"\n The number of Avalable Emergency is "<<RL.getNoOfAvailableEmergencyRovers()<<endl;
//    EM2=RL.getAvailableEmergencyRover();
//    EM2->Print();
//    RL.addInMissionEmergencyRover(EM);
//    RL.addInMissionEmergencyRover(EM);
//    RL.addInMissionEmergencyRover(EM);
//    RL.addInMissionEmergencyRover(EM);
//    RL.addInMissionEmergencyRover(EM);
//    cout<<"\n The number of InMissionEmergencyRover is "<<RL.getNoOfInMissionEmergencyRovers()<<endl;
//
//    RL.getInMissionEmergencyRovers().PrintList();
//    EM1=RL.getInMissionEmergencyRover();
//    EM1->Print();

MarsStation MR;
//MR.loadFile("../ConfigurationFile.txt");

    MR.simulate(1);

/*

MR.assignTodaysMission(1);
MR.assignTodaysMission(2);
MR.assignTodaysMission(3);
MR.assignTodaysMission(5);
MR.assignTodaysMission(6);
MR.assignTodaysMission(18);
MR.assignTodaysMission(25);
//MR.assignTodaysMission(10);
//MR.assignTodaysMission(18);
//MR.assignTodaysMission(2);
cout<<"getNoOfAvailableEmergencyRovers :"<<MR.getRLs().getNoOfAvailableEmergencyRovers()<<endl;
cout<<"getNoOfInMissionEmergencyRovers :"<<MR.getRLs().getNoOfInMissionEmergencyRovers()<<endl;
cout<<"getNoOfInExecutionEmergency :"<<MR.getMLs().getNoOfInExecutionEmergency()<<endl;
cout<<"getNoOfWaitingEmergencyMission :"<<MR.getMLs().getNoOfWaitingEmergencyMission()<<endl;
cout<<endl;

    cout<<"getNoOfAvailablePolarRovers :"<<MR.getRLs().getNoOfAvailablePolarRovers()<<endl;
    cout<<"getNoOfInMissionPolarRovers :"<<MR.getRLs().getNoOfInMissionPolarRovers()<<endl;
    cout<<"getNoOfInExecutionPolar :"<<MR.getMLs().getNoOfInExecutionPolar()<<endl;
    cout<<"getNoOfWaitingPolarMission :"<<MR.getMLs().getNoOfWaitingPolarMission()<<endl;
cout<<endl;

    cout<<"getNoOfAvailableMountainousRovers :"<<MR.getRLs().getNoOfAvailableMountainousRovers()<<endl;
    cout<<"getNoOfInMissionMountainousRovers :"<<MR.getRLs().getNoOfInMissionMountainousRovers()<<endl;
    cout<<"getNoOfInExecutionMountainous :"<<MR.getMLs().getNoOfInExecutionMountainous()<<endl;
    cout<<"getNoOfWaitingMountainousMission :"<<MR.getMLs().getNoOfWaitingMountainousMission()<<endl;
*/


//    enum Throws {R, P, S};
//    int userInput;
//    cout << "What is your throw : ";
//    cin >> userInput;
//    Throws userThrow = (Throws)userInput;
//    cout<<userThrow;
    return 0;
}
