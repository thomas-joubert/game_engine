cmake_minimum_required(VERSION 3.10)

project(Something VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wextra -Wall -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -o3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -Og -fsanitize=address")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

# COVERAGE BUILD
if (CMAKE_BUILD_TYPE STREQUAL "Coverage" OR CODE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage -lgcov")
endif()

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build selected, default to release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory("src")
include_directories("include")

# ENGINE
add_executable(engine src/main.cc)
target_link_libraries(engine main sfml-graphics sfml-window sfml-system)

# TESTS
add_subdirectory("tests")
add_executable(check EXCLUDE_FROM_ALL tests/test_main.cc)
target_link_libraries(check main test sfml-graphics sfml-window sfml-system gtest)
