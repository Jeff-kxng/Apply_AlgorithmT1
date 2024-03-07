cmake_minimum_required(VERSION 3.27)
project(Apply_Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(Apply_Algorithm maze.cpp
        RMQ.cpp
)
add_executable(new_target RMQ.cpp)
add_executable(new_target1 Largestblacksubrectangle.cpp)
add_executable(new_target2 Telco.cpp)
