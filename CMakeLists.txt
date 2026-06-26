cmake_minimum_required(VERSION 3.15)
project(CppDeepDive LANGUAGES CXX)

# Force C++20 standard (essential for modern C++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(raw_pointers src/memory/01_raw_pointers.cpp)
add_executable(references src/memory/02_references.cpp)