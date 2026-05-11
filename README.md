# ELE124_Computer_Programming
Hacettepe University ELE 124 Computer Programming Course Assignments

This repository contains my weekly homework for the ELE 124 course.

## Contents

### Homework 1: Autonomous Warehouse Robot Sensor Log
* **Description:** A C program that simulates sensor data collection from an autonomous warehouse robot. The program generates random measurement logs, detects communication faults (represented as `-99`), repairs the corrupted data using previous valid readings, and performs post-repair statistical analysis.
* **Key Technical Concepts Used:** * Custom Pseudo-Random Number Generation (LCG Algorithm)
  * Array manipulation and memory addressing
  * Defensive Programming (using `const` and `unsigned long` to prevent overflows)
  * State tracking without library functions
### Homework 2: String Compression and Recursive Patterns

* **Description:** A C program featuring two distinct functions: one for lossless string compression of consecutive characters and another for generating geometric patterns using recursive logic.
* **Key Technical Concepts Used:** * String Manipulation: Character-by-character processing with `string.h` integration.
    * Run-Length Encoding (RLE) Logic: Detecting consecutive repetitions and flattening data into a character-count format.
    * **Recursion:** Implementing complex output patterns without iterative loops (while/for), focusing on base case and stack management.
    * Memory Awareness: Handling user-provided strings within pre-allocated buffers.
## How to Run

1. Download the `.c` files.
2. Open them in Dev-C++, Code::Blocks, or any standard C compiler (e.g., GCC).
3. Compile and run the executable.

**Author:** Zeynep Doga Kara
