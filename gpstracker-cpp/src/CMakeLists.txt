cmake_minimum_required(VERSION 3.8)

set(This src)

file(GLOB src *.cpp)

add_library(${This} ${src})

add_subdirectory(utils)
add_subdirectory(GPS)

target_link_libraries(${This} PUBLIC
    GPSTracker
)