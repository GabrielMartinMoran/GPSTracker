cmake_minimum_required(VERSION 3.8)

set(This GPSTracker)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(includes include src mockups googletest)

include_directories(${includes})

enable_testing()

add_subdirectory(googletest)
add_subdirectory(test)
add_subdirectory(include)
add_subdirectory(mockups)
add_subdirectory(src)

file(GLOB Sources src/*.cpp)
file(GLOB utils src/utils/*.cpp)
file(GLOB GPS src/GPS/*.cpp)
file(GLOB EX src/exceptions/*.ex)

add_library(${This} STATIC ${Sources} ${utils} ${GPS} ${EX})