# cmake_minimum_required(VERSION <specify CMake version here>)

cmake_minimum_required(VERSION 3.5)
project(enumStateMachine)

# enable the ctest framework
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " -O2 -DNDEBUG -Wall -Wextra")
find_package(Boost 1.70 REQUIRED COMPONENTS program_options container thread filesystem regex unit_test_framework system log)


add_executable(enumStateMachine main.cpp)
add_subdirectory(test)