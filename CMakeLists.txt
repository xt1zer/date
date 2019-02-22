cmake_minimum_required(VERSION 3.13)
project(date)

set(CMAKE_CXX_STANDARD 17)

add_executable(date main.cpp Employee.cpp Date/Date.cpp String/String.cpp)