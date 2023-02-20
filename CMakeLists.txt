#cmake 最低版本需求
cmake_minimum_required(VERSION 3.13)

# 解决方案
project (Algorithm-Test)


set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Src)

add_executable(algorithm_test src/main.cpp)
