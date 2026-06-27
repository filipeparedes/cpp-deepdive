# cpp-deepdive

A personal repository dedicated to learning and experimenting with modern C++ concepts, from low-level memory management to highly optimized algorithmic patterns. 

---

## Key Concepts Covered

* Memory Ownership: Raw pointers, References and Smart Pointers
* Move Semantics: Transferring ownership safely with std::move
* Algorithmic Patterns: Two Pointers technique for O(n) time complexity optimizations.

---
## What's Inside

This repository is structured by domains of knowledge. It focuses on writing simple, leak-free C++23 code.

### Directory Structure

```text
cpp-deepdive/
├── CMakeLists.txt
├── src/
│   ├── memory/         # Memory Management
│   │   ├── 01_raw_pointers.cpp
│   │   ├── 02_references.cpp
│   │   └── 03_unique_ptr.cpp
│   │
│   └── algorithms/     # Time & Space Optimized Algorithms
│       └── 01_two_pointers.cpp
````

---

## Build Instructions

This "project" uses CMake as its build system. To compile any of th executables, run the following commands from the root directory:

```bash
# 1. Generate the build files
cmake -S . -B build

#. 2. Compile the project
cmake --build buld

# 3. Run a specific executable (Example)
./build/unique_ptr
```

---

## Author

**Filipe Paredes** — [filipeparedes.dev](https://filipeparedes.dev) · [filipeparedes3@gmail.com](mailto:filipeparedes3@gmail.com)

