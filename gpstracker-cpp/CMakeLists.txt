cmake_minimum_required(VERSION 3.8)

set(This GPSTracker)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
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


#AGREGAR AQUI LOS SRC QUE SON NECESARIOS PARA LOS TESTS
set(Sources

    src/Example.cpp
    src/StringEquals.cpp
    src/WiFiNetwork.cpp
    src/WiFiConfiguration.cpp
    src/StringTokenizer.cpp

)

add_library(${This} STATIC ${Sources})