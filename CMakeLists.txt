cmake_minimum_required(VERSION 3.0)

project(sun_vm)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#set(CMAKE_CXX_FLAGS "-Wall -std=gnu++17 -Wc++17-extensions")
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
set_target_properties(${PROJECT_NAME} PROPERTIES
CXX_STANDARD 17
CXX_FLAGS "-Wc++17-extensions"
CXX_STANDARD_REQUIRED ON
CXX_EXTENSIONS ON)


