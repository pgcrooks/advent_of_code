cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

ENABLE_TESTING()

project(advent_of_code VERSION 0.1)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(thirdparty)
