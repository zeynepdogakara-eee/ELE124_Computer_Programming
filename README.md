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
 ### Homework 3: Embedded Device Log Parser
* **Description:** A C program that acts as a simple monitoring system for embedded devices. The program reads structured log entries line-by-line from an external text file, parses each log into distinct components (ID, status, and message), and filters the records to output only the failing devices.
* **Key Technical Concepts Used:** * File I/O and Stream Processing
  * String Tokenization: Utilizing `strtok` to split delimited string data (`:`) into discrete memory buffers.
  * String Manipulation & Comparison: Using `strcpy` for safe variable assignments and `strcmp` for exact status evaluation.
  * Data Sanitization: Calculating string lengths to dynamically detect and remove trailing newline characters from input streams.
### Homework 4: Image Steganography and File I/O
* **Description:** A C program that demonstrates basic steganography by hiding a secret text message within a generated 300x300 grayscale image (`.pgm` format). The program creates a random noise matrix, embeds a string into the initial pixels by utilizing ASCII values, writes the data to an external image file, and subsequently reads the file back to decode and reveal the hidden message.
* **Key Technical Concepts Used:** * File I/O and Format Handling
  * Reading and Writing Structured Files: Using `fopen`, `fprintf`, and `fscanf` to create and parse specific file headers (P2 format) and large datasets.
  * **Implicit Type Casting (ASCII):** Leveraging C's native handling of characters as integers to seamlessly embed text into an integer matrix and extract it using `%c` format specifiers.
  * 2D Array Manipulation: Populating, traversing, and modifying a 300x300 matrix to represent 8-bit image pixels.
  * Random Number Generation: Utilizing `rand() % 256` to simulate grayscale pixel noise for perfect data camouflage.
## How to Run

1. Download the `.c` files.
2. Open them in Dev-C++, Code::Blocks, or any standard C compiler (e.g., GCC).
3. Compile and run the executable.

**Author:** Zeynep Doga Kara
