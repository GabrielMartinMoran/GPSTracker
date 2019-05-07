cmake_minimum_required(VERSION 3.8)

set(This interfaces)

file(GLOB Interfaces *.h)

add_library(${This} ${Interfaces})

target_link_libraries(${This} PUBLIC
    include
)