
cmake_minimum_required(VERSION 3.10)


project(HW1)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

add_executable(main src/main.cpp)
