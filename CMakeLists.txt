cmake_minimum_required(VERSION 3.2.2)
project(leetcode)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES C++/UniqueBinarySearchTrees.cpp)
add_executable(leetcode ${SOURCE_FILES})