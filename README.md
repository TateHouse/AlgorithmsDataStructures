# Algorithms and Data Structures <img src="Images/Logo.png" alt="Logo" width="256" height="256" align="right"/>

## Overview

A project for implementing algorithms and data structures in C++ with a focus on templates and iterators.

While I plan on continually implementing more algorithms and data structures, I do have a few long-term goals I am
considering. These include but are not limited to:

- Implementing a graphics visualizer for the algorithms and data structures.
- Making better use of C++ 23 features, such as concepts and ranges.
- Refactoring data structures to allow for custom allocators.
- Refactoring data structures into thread-safe and non-thread-safe versions.

## Current Features

### Algorithms

- Sorting
    - Bubble Sort
    - Insertion Sort
    - Merge Sort
    - Quick Sort
    - Selection Sort
- Hash Functions
    - Division Method
    - Multiplication Method

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
    - Binary Tree
    - Binary Search Tree
    - AVL Tree
- Hash Tables
    - Separate Chaining Hash Table

## Dependencies

- C++ 23 (Developed with MSVC Version 19.38.33133)
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