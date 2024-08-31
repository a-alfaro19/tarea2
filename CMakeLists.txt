cmake_minimum_required(VERSION 3.29)
project(tarea2)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Encontrar Qt y Qt Charts
find_package(Qt5 REQUIRED COMPONENTS Widgets Charts)

# Incluir directorios
include_directories(${Qt5_INCLUDE_DIRS})

set(SOURCES
    src/LinkedList.cpp
    src/main.cpp
        src/BinarySearchTree.cpp
        include/BinarySearchTree.h
        src/Algorithms.cpp
        include/Algorithms.h
        src/AlgorithmsTester.cpp
        include/AlgorithmsTester.h
        src/ChartPlotter.cpp
        include/ChartPlotter.h
)

include_directories(include)

add_executable(tarea2 ${SOURCES})

# Links GTK and Cairo libraries
target_link_libraries(tarea2 Qt5::Widgets Qt5::Charts)

