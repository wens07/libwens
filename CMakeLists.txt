cmake_minimum_required(VERSION 3.5)
project(wenslib)

set (PROJECT_INCLUDE_DIR
     ./base/include
     ./net/include
     ./multi_thread/include
)



find_package(boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE HEAD_FILES net/include multi_thread/include "*.h")
file(GLOB_RECURSE SOURCE_FILES net "*.cpp")

set(SOURCE_FILES ${HEAD_FILES} main.cpp )

add_executable(wenslib main.cpp)