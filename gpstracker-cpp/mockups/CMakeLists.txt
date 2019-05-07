cmake_minimum_required(VERSION 3.8)

set(This mockups)

file(GLOB Mockups *.h)

add_library(${This} ${Mockups})

target_link_libraries(${This} PUBLIC
    GPSTracker
)

