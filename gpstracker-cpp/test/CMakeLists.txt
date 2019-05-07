cmake_minimum_required(VERSION 3.8)

set(This Tests)

file(GLOB Tests *.cpp)

add_executable(${This} ${Tests})

target_link_libraries(${This} PUBLIC
    gtest_main
    gmock_main
    GPSTracker
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
