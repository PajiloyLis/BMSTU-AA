cmake_minimum_required(VERSION 3.2)
project(bis22u145)

set(CMAKE_CXX_STANDARD 20)

SET(COVERAGE_COMPILE_FLAGS "-ftest-coverage" "-fprofile-arcs" "-g")
SET(COVERAGE_LINK_FLAGS "-lgcov" "--coverage")

include_directories(/code)

add_executable(lab_2
        code/algo.cpp
        code/data_generator.cpp
        code/main.cpp
        code/comparisons_measures.cpp
)

set_target_properties(lab_2 PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
)

add_executable(unit_tests code/unit_tests.cpp code/algo.cpp)

target_compile_options(unit_tests PUBLIC ${COVERAGE_COMPILE_FLAGS})
target_link_options(unit_tests PUBLIC ${COVERAGE_LINK_FLAGS})

target_link_libraries(unit_tests gtest pthread)

