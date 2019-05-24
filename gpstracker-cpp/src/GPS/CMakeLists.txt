cmake_minimum_required(VERSION 3.8)

set(This GPS)

file(GLOB GPS *.cpp)

add_library(${This} ${GPS})

target_link_libraries(${This} PUBLIC
    src
)