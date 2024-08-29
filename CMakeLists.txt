cmake_minimum_required(VERSION 3.29)
project(tarea2)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/LinkedList.cpp
    src/main.cpp
)

include_directories(include)

add_executable(tarea2 ${SOURCES})
