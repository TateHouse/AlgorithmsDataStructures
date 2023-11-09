# Algorithms and Data Structures <img src="Images/Logo.png" alt="Logo" width="256" height="256" align="right"/>

## Overview

A project for implementing algorithms and data structures. This project is intended to be used as a reference for
implementing algorithms and data structures in C++, particularly with a focus on iterators and templates.

### Algorithms

### Data Structures

- Linked Lists
    - Singly Linked List
    - Doubly Linked List
- Queues
    - Dynamic-Size Array Queue
    - Fixed-Size Array Queue
    - Singly Linked List Queue
- Stacks
    - Dynamic-Size Array Stack
    - Fixed-Size Array Stack
    - Singly Linked List Stack
- Trees
    - BinaryTree
    - Binary Search Tree

## Dependencies

- C++ 23 (Tested with MSVC Version 19.37.32824)
- CMake (Minimum Required Version: 3.26)
- vcpkg
    - Google Test / Google Mock

## Building

1. Clone the repository and extract it to a directory.
2. Open a terminal and navigate to the directory.
3. First, run the following
   command: `cmake -B Build/ -S . -DCMAKE_TOOLCHAIN_FILE="path to vcpkg/scripts/buildsystems/vcpkg.cmake"`
4. Then, run the following command: `cmake --build Build/ --config Config`, where Config is either Debug or Release.

## Running Tests

1. Follow the steps in the Building section above to build the project.
2. The executable for the tests will be located in the `Build/Test/Config/ directory, where Config is either Debug or
   Release.