# 11320CSR530200  Design automation (Ⅰ) Project-1: Dynamic programming

## Description
Run to solve TSP a problem with maximum of 20 vertices.

## Requirements
- GCC: 14.2.0
- Cmake version 3.30.3



## Build

Create a directory for build files.
```sh
mkdir build
cd build
```

Create a Makefile by cmake
```sh
cmake ..
make
```

## Run
- Execute the program without an output directory.
    ```sh
    ./main <input_directory>
    ``` 
    For example, 
    ```sh
    ./main ../cases/case01.txt
    ```
    The output file would be at the same directory and be named as `<input_directory>_output`

- Execute the program with an output directory.
    ```sh
    ./main <input_directory> <output_directory>
    ``` 




