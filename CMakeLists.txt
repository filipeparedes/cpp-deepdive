cmake_minimum_required(VERSION 3.15)
project(CppDeepDive LANGUAGES CXX)

# Force C++20 standard (essential for modern C++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Memory related
add_executable(raw_pointers src/memory/01_raw_pointers.cpp)
add_executable(references src/memory/02_references.cpp)
add_executable(unique_ptr src/memory/03_unique_ptr.cpp)
add_executable(shared_ptr src/memory/04_shared_ptr.cpp)
add_executable(weak_ptr src/memory/05_weak_ptr.cpp)

# Algorithms
add_executable(two_pointers src/algorithms/01_two_pointers.cpp)

# Multitasking
add_executable(fork src/multitasking/01_fork.cpp)
add_executable(threads src/multitasking/02_threads.cpp)