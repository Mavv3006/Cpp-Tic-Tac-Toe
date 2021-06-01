cmake_minimum_required(VERSION 3.17)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)
add_executable(tic_tac_toe_run ${SOURCE_FILES})

include_directories(lib)
add_subdirectory(lib)

target_link_libraries(tic_tac_toe_run lib)
add_subdirectory(Catch_tests)