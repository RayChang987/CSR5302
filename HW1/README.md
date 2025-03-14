# 11320CSR530200  Design automation (Ⅰ) Project-1: Dynamic programming

## Description
Run to solve TSP a problem with maximum of 20 vertices.

## Requirements
- GCC: 14.2.0
- Cmake version 3.30.3



## Build

Create a directory for build files:
```sh
mkdir build
cd build
```

Generate a Makefile using CMake:
```sh
cmake ..
make
```

## Run
- A prebuilt executable file is available in the ./bin directory.
- To execute the program without specifying an output directory:
    ```sh
    ./group9_proj1 <input_directory>
    ``` 
    For example:
    ```sh
    ./group9_proj1 ../cases/case01.txt
    ```
    The output file will be created in the same directory as the input file and will be named `<input_directory>_output`

- To execute the program with a specified output directory:
    ```sh
    ./group9_proj1 <input_directory> <output_directory>
    ``` 
    For example: 
    ```sh
    ./group9_proj1 ../cases/case01.txt ../output.txt
    ```




