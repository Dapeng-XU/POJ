cmake_minimum_required(VERSION 3.6)
project(POJ)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")

set(SOURCE_FILES POJ1573.cpp POJ1488.cpp POJ1182.cpp POJ1611.cpp POJ1703.cpp POJ3349.cpp POJ1328.cpp POJ3278.cpp
        POJ2049.cpp POJ1018.cpp POJ1163.cpp POJ1050.cpp POJ1088.cpp)
add_executable(POJ ${SOURCE_FILES})