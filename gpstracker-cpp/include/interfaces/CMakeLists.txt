cmake_minimum_required(VERSION 3.8)

set(This interfaces)

add_library(${This} ISDManager.h)

target_link_libraries(${This} PUBLIC
    GPSTracker
)