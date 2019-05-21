cmake_minimum_required(VERSION 3.8)

set(This EX)

file(GLOB EX *.ex)

add_library(${This} ${EX})

target_link_libraries(${This} PUBLIC
    src
)