cmake_minimum_required(VERSION 3.16)
project(demo_c_plus_plus)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_subdirectory(string)

add_executable(demo_c_plus_plus main.cpp)
add_executable(thread_with_param pthread_with_param.cpp)
add_executable(thread_join pthread_join.cpp)
add_executable(thread_std thread_std.cpp)
add_executable(unique_ptr unique_ptr.cpp)
add_executable(shared_ptr shared_ptr.cpp)
add_executable(weak_ptr weak_ptr.cpp)