cmake_minimum_required(VERSION 3.8)

set(This src)

set(src
    GPS.cpp
    WiFiNetwork.cpp
    WiFiConfiguration.cpp
    BluetoothServer.cpp
    )

add_library(${This} ${src})

add_subdirectory(utils)

target_link_libraries(${This} PUBLIC
    GPSTracker
)