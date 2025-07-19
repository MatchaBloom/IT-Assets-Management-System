cmake_minimum_required(VERSION 3.30)
project(PP_IT_Assets_Management_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(PP_IT_Assets_Management_System
        main.cpp
        TeamProperties/TeamMenu.cpp
        TeamProperties/TeamMenu.h
        TeamProperties/Infrastructure.cpp
        TeamProperties/Infrastructure.h
        TeamProperties/Analytics.cpp
        TeamProperties/Analytics.h
        TeamProperties/Cybersecurity.cpp
        TeamProperties/Cybersecurity.h
        TeamProperties/Engineering.cpp
        TeamProperties/Engineering.h
        TeamProperties/Support.cpp
        TeamProperties/Support.h
        Assets/Assets.cpp
        Assets/Assets.h
        Assets/Server.cpp
        Assets/Server.h
        Assets/Application.cpp
        Assets/Application.h
        Assets/AssetController.cpp
        Assets/AssetController.h
        Additional.cpp
        Additional.h
        )
