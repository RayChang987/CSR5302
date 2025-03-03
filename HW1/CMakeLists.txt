
cmake_minimum_required(VERSION 3.10)


project(HW1)

# 設置 C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 啟用所有編譯警告
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

# 添加可執行文件 (目標名稱 和 源文件)
add_executable(main src/main.cpp)
