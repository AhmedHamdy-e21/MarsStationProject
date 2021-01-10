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
        MarsStationRelated/MissionLists.cpp
        MarsStationRelated/MissionLists.h
        MarsStationRelated/UIClass.cpp
        MarsStationRelated/UIClass.h
        ##################################################################
        #Rover Related
        ##################################################################
        RoverRelated/MountainousRover.cpp
        RoverRelated/MountainousRover.h
        RoverRelated/PolarRover.cpp
        RoverRelated/PolarRover.h
        RoverRelated/EmergencyRover.h
        RoverRelated/EmergencyRover.cpp
        RoverRelated/Rover.cpp
        RoverRelated/Rover.h


        MarsStationRelated/RoverLists.cpp MarsStationRelated/RoverLists.h EventRelated/Event.cpp EventRelated/Event.h EventRelated/FormulationEvent.cpp EventRelated/FormulationEvent.h EventRelated/CancelEvent.cpp EventRelated/CancelEvent.h EventRelated/PrompteEvent.cpp EventRelated/PrompteEvent.h MarsStationRelated/MarsStation.cpp MarsStationRelated/MarsStation.h)