cmake_minimum_required(VERSION 3.8)

set(This utilsH)

file(GLOB utilsH *.h)

add_library(${This} ${utilsH})

target_link_libraries(${This} PUBLIC
    include
)