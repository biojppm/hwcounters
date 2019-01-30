project(hwcounters)
cmake_minimum_required(VERSION 3.5)


set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Enable testing of the benchmark library." FORCE)
add_subdirectory(ext/benchmark)

if(WIN32)
    add_executable(pdhtest pdhtest.cpp)
endif()
