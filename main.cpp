#include <iostream>
#include  "MarsStationRelated/MarsStation.h"
#include  "MarsStationRelated/MissionList.h"

int main() {
//    Mission*M3=new Mission(1,2,6,32,5);
    PolarMission*MP=new PolarMission(1,2,6235,32,5);
//    PolarMission* Ms;
    MountainousMission* M3=new MountainousMission(2,1,2,6435,32,5);
    Mission* M4=new Mission(1,3,6,32,5);
    EmergencyMission* M5=new EmergencyMission(1,36,61,32,5);
    MissionList M;
    M.addEmergencyMission(M5);
//    M.getEmergencyMissionHeap().printHeap();
    M.addMountainousMission(M3);
    M.addMountainousMission(M3);
//    M.getMountainousMissionList().PrintList();
    M.addPolarMission(MP);
    M.addPolarMission(MP);
    M.addPolarMission(MP);
    MountainousMission* Mo=M.getMountainousMission();
    Mo->PrintMission();
    PolarMission* Ms=M.getPolarMission();
    Ms->PrintMission();


//    M.getPolarMissionQueue().peek(Ms);
//    Ms->PrintMission();
//    Ms.PrintMission();

    return 0;
}
