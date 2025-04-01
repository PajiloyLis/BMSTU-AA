cmake_minimum_required(VERSION 3.22)
project(bis22u145)

set(CMAKE_CXX_STANDARD 20)

include_directories(code)

add_executable(bis22u145
        code/algo.cpp
        code/algo.h
        code/main.cpp
        code/time_measures.cpp
        code/time_measures.h
        code/task_queue.h
        code/tasks.cpp
        code/tasks.h
        code/task_dto.cpp
        code/task_dto.h)
target_link_libraries(bis22u145 gumbo sqlite3)