cmake_minimum_required(VERSION 3.8)

set(This GPSH)

file(GLOB GPSH *.h)

add_library(${This} ${GPSH})

target_link_libraries(${This} PUBLIC
    include
)