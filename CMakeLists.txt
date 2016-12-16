cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project (Lintcode)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

find_package (Threads)

add_executable(Solution1 ./LeetCode1/Solution1.cpp)  
#add_executable(longestCommonSubstring longestCommonSubstring.cpp)  
