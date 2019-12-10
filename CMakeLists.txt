cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(sst-template)
find_package(pybind11 REQUIRED)

add_library(my_lib SHARED src/my_lib.cpp)
target_include_directories(my_lib PUBLIC include)

pybind11_add_module(my_lib_module src/pybind/my_lib_module.cpp)
target_link_libraries(my_lib_module PRIVATE my_lib)
