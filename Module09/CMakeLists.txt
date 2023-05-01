cmake_minimum_required(VERSION 3.23)
project(Module09)

set(CMAKE_CXX_STANDARD 98)

add_executable(btc
        ex00/main.cpp
        ex00/BitCoinChange.cpp
        ex00/BitCoinChange.hpp
        ex00/data.csv
        input.txt)

add_executable(rpn
        ex01/main.cpp
        ex01/RPN.hpp
        ex01/RPN.cpp)

add_executable(test
        test.cpp)
