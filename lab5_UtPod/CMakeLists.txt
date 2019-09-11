cmake_minimum_required(VERSION 3.13)
project(lab5_UtPod)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab5_UtPod
        Song.cpp
        Song.h
        UtPod.cpp
        UtPod.h
        UtPodDriver.cpp)
