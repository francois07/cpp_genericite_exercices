cmake_minimum_required(VERSION 3.0)

project(cartesian_vector_variable_project)

add_library(cartesianvectorvariable SHARED vector.cpp)

add_executable(main main.cpp)

target_link_libraries(main cartesianvectorvariable)