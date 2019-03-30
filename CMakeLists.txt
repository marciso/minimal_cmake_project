cmake_minimum_required(VERSION 3.6)
project(project_name)

set(CMAKE_CXX_STANDARD 17)

option(USE_GTEST "Enable testing" ON)
option(USE_BENCHMARK "Enable benchmarking" ON)

if(USE_GTEST OR USE_BENCHMARK)
    enable_testing()
endif()

if(USE_GTEST)
    include(gtest.cmake)
endif()

if(USE_BENCHMARK)
    include(benchmark.cmake)
endif()

add_subdirectory(src)
add_subdirectory(test)
