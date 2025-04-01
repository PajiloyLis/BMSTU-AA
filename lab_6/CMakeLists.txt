cmake_minimum_required(VERSION 3.22)
project(bis22u145)

SET(COVERAGE_COMPILE_FLAGS "-ftest-coverage" "-fprofile-arcs" "-g")
SET(COVERAGE_LINK_FLAGS "-lgcov" "--coverage")

set(CMAKE_CXX_STANDARD 20)

include_directories(code)

add_executable(bis22u145
        code/main.cpp
        code/algo.cpp
        code/parametrize.h
        code/parametrize.cpp
        code/time_meaures.cpp
        code/time_meaures.h)
add_executable(unit_tests code/unit_tests.cpp code/algo.cpp)

target_compile_options(unit_tests PUBLIC ${COVERAGE_COMPILE_FLAGS})
target_link_options(unit_tests PUBLIC ${COVERAGE_LINK_FLAGS})

target_link_libraries(unit_tests gtest pthread)
