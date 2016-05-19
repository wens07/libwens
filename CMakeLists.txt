cmake_minimum_required(VERSION 3.5)
project(wenslib)

set (PROJECT_INCLUDE_DIR
     ./base/include
     ./net/include
)

#set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /usr/local/Cellar)
find_package(boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp base/include/Timer.h  base/Timer.cpp)
add_executable(wenslib ${SOURCE_FILES})