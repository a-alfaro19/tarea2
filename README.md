# tarea2

## Description

This project is a tool for testing and plotting the results of different algorithms. It uses Qt for chart visualization and C++ for algorithm implementation.

## Requirements

- Qt 5.15 or higher
- CMake 3.10 or higher
- A compiler compatible with C++11 (e.g., GCC or Clang)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/a-alfaro19/tarea2.git
    cd tarea2
    ```

2. Create a build directory and navigate to it:
    ```sh
    mkdir build
    cd build
    ```

3. Configure the project with CMake:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    make
    ```

## Usage

To run the program, use the following command from the `build` directory:

```sh
./tarea2 <Algorithm> <Test Case>
```

Where `<Algorithm>` is the algorithm to test and `<Test Case>` is the test case to use. The available algorithms are:

## Accepted Algorithms

- BUBBLE_SORT
- SELECTION_SORT
- MERGE_SORT
- LINKED_LIST_SEARCH
- BS_TREE_INSERTION

## Accepted Test Cases

- BEST_CASE
- AVG_CASE
- WORST_CASE