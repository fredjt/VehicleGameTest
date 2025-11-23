cmake_minimum_required(VERSION 4.1)
project(UsedCarGame)

set(CMAKE_CXX_STANDARD 26)

add_executable(UsedCarGame base_categories.h compatible_engines.h main.cpp vehicle.h)
