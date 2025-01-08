cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -ggdb ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "-g ${CMAKE_CXX_FLAGS}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(thirdparty)

include_directories(include
${GTEST_INCLUDE_DIRS})

add_subdirectory(problems/1_array)
add_subdirectory(problems/2_list)