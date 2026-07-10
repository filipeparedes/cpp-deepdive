cmake_minimum_required(VERSION 3.15)
set(CMAKE_C_COMPILER /opt/homebrew/bin/gcc-14)
set(CMAKE_CXX_COMPILER /opt/homebrew/bin/g++-14)
project(CppDeepDive LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Force C++20 standard (essential for modern C++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Algorithms
add_executable(two_pointers src/algorithms/01_two_pointers.cpp)
add_executable(binary_search src/algorithms/02_binary_search.cpp)
add_executable(sliding_window src/algorithms/03_sliding_window.cpp)

# Functional
add_executable(templates src/functional/01_templates.cpp)
add_executable(concepts src/functional/02_concepts.cpp)

# Memory related
add_executable(raw_pointers src/memory/01_raw_pointers.cpp)
add_executable(references src/memory/02_references.cpp)
add_executable(unique_ptr src/memory/03_unique_ptr.cpp)
add_executable(shared_ptr src/memory/04_shared_ptr.cpp)
add_executable(weak_ptr src/memory/05_weak_ptr.cpp)

# Multitasking
add_executable(fork src/multitasking/01_fork.cpp)
add_executable(threads src/multitasking/02_threads.cpp)
add_executable(mutex src/multitasking/03_mutex.cpp)
add_executable(atomic src/multitasking/04_atomic.cpp)
add_executable(parallelism src/multitasking/05_parallelism.cpp)

find_package(TBB REQUIRED)
target_link_libraries(parallelism PRIVATE TBB::tbb)
