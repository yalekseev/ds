cmake_minimum_required (VERSION 2.6)
project (ds)
set (CMAKE_CXX_COMPILER "g++-5")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
find_package (Threads)
add_executable(test test.cpp)
target_link_libraries (test ${CMAKE_THREAD_LIBS_INIT} atomic)
