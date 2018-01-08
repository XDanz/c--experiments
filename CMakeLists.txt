cmake_minimum_required(VERSION 3.5)
project(c--experiments)

find_package(Threads REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


add_subdirectory(sort)
add_subdirectory(classes)