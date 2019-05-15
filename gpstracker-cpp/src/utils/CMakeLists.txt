cmake_minimum_required(VERSION 3.8)

set(This utils)

file(GLOB utils *.cpp)

add_library(${This} ${utils})

target_link_libraries(${This} PUBLIC
    src
)