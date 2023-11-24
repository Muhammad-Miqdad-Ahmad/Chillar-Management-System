cmake_minimum_required(VERSION 3.26)
project(Chillar_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chillar_Management_System main.cpp
        Person.cpp
        Prisoners.cpp
        hierarchy.cpp
        admin.h
        Visitor.cpp
        Functions.cpp
        admin.cpp
        admin.cpp)
