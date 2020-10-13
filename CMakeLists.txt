cmake_minimum_required(VERSION 3.6)
project(project_name)

set(CMAKE_CXX_STANDARD 17)

option(USE_CATCH "Enable testing with Catch" ON)
option(USE_GTEST "Enable testing with Gtest" ON)
option(USE_BENCHMARK "Enable benchmarking" ON)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wformat=2 -march=native -O3")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,now")

if(USE_CATCH OR USE_GTEST OR USE_BENCHMARK)
    enable_testing()
endif()

if(USE_GTEST)
    include(cmake/gtest.cmake)
endif()

if(USE_CATCH)
    add_subdirectory(test/Catch2)
endif()

if(USE_BENCHMARK)
    include(cmake/benchmark.cmake)
endif()

add_subdirectory(src)
add_subdirectory(test)
