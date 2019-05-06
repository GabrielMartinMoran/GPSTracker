cmake_minimum_required(VERSION 3.8)

set(This GPSTracker)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB Sources "src/*.cpp")
file(GLOB Headers "include/*.h")

set(Sources
    src/Example.cpp
    src/StringEquals.cpp
    src/GPSControllerMockup.cpp
    src/WiFiNetwork.cpp
)
set(Headers
    include/Example.h
    include/StringEquals.h
    include/GPSControllerMockup.h
    include/WiFiNetwork.h
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(includes include src googletest)

include_directories(${includes})

enable_testing()

add_subdirectory(googletest)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)
