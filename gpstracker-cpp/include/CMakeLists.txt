cmake_minimum_required(VERSION 3.8)

set(This include)

file(GLOB Headers *.h)

add_library(${This} ${Headers})

add_subdirectory(interfaces)

target_link_libraries(${This} PUBLIC
    GPSTracker
)