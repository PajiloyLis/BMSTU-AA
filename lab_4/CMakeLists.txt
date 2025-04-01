cmake_minimum_required(VERSION 3.22)
project(lab_4)

set(CMAKE_CXX_STANDARD 20)

include_directories(code)

add_executable(lab_4 code/main.cpp
        code/algo.cpp
        code/algo.h
        code/time_measures.cpp
        code/time_measures.h
)

target_link_libraries(lab_4 curl)
