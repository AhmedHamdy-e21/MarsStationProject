cmake_minimum_required(VERSION 3.17)
project(MarsStationProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(MarsStationProject main.cpp

        ##################################################################
        # Data Structure Inclusion
        ##################################################################
        DataStructure/LinkedList/LinkedListMissions.cpp
        DataStructure/LinkedList/LinkedListMissions.h
        DataStructure/LinkedList/NodeMission.cpp
        DataStructure/LinkedList/NodeMission.h
        DataStructure/MaxHeap/MaxHeap.h
        DataStructure/MaxHeap/MaxHeap.cpp
        DataStructure/Queue/LinkedQueue.h
        DataStructure/Queue/NodeQ.cpp
        DataStructure/Queue/NodeQ.h
        DataStructure/Queue/QueueADT.h


        ##################################################################
        #Mission Related Inclusion
        ##################################################################
        MissionRelated/Mission.cpp
        MissionRelated/Mission.h
        MissionRelated/EmergencyMission.cpp
        MissionRelated/EmergencyMission.h
        MissionRelated/MountainousMission.cpp
        MissionRelated/MountainousMission.h
        MissionRelated/PolarMission.cpp
        MissionRelated/PolarMission.h

        ##################################################################
        #Mars Station Related
        ##################################################################
        MarsStationRelated/MissionList.cpp
        MarsStationRelated/MissionList.h
        MarsStationRelated/UIClass.cpp
        MarsStationRelated/UIClass.h
        MarsStationRelated/MarsStation.h
        MarsStationRelated/MarsStation.cpp
        ##################################################################
        #Rover Related
        ##################################################################
        RoverRelated/MountainousRover.cpp
        RoverRelated/MountainousRover.h
        RoverRelated/PolarRover.cpp
        RoverRelated/PolarRover.h
        RoverRelated/EmergencyRover.h
        RoverRelated/EmergencyRover.cpp


        MarsStationRelated/RoverList.cpp MarsStationRelated/RoverList.h)