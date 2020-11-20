cmake_minimum_required(VERSION 3.10)

project(Something VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("src")
include_directories("include")

add_executable(engine src/main.cc)
target_link_libraries(engine main sfml-graphics sfml-window sfml-system)
