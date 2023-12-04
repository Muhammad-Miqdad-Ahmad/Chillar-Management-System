cmake_minimum_required(VERSION 3.24)
project(Chillar_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chillar_Management_System main.cpp hierarchy.cpp Functions.cpp Convicted.cpp Prisoners.cpp Visitor.cpp admin.cpp Person.cpp)
