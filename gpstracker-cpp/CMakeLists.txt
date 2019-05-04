cmake_minimum_required(VERSION 3.8)

set(This GPSTracker)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB Sources "src/*.cpp")
file(GLOB Headers "include/*.h")
file(GLOB Utils "include/Utils/*.h")
file(GLOB UtilsSRC "src/Utils/*.cpp")
file(GLOB Mockups "include/Mockups/*.h")
file(GLOB MockupsSRC "src/Mockups/*.c")

set(Sources src/Example.cpp)
set(Headers include/Example.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(includes include src googletest src/Utils src/Mockups include/Utils include/Mockups)

include_directories(${includes})

enable_testing()

add_subdirectory(googletest)

add_library(${This} STATIC ${Sources} ${Headers} ${Utils} ${Mockups} ${MockupsSRC})

add_subdirectory(test)
