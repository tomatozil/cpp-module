cmake_minimum_required(VERSION 3.23)
project(Module07)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00
        ex00/calculator.hpp
        ex00/main.cpp)

add_executable(ex01
        ex01/iter.hpp
        ex01/main.cpp)

add_executable(ex02
        ex02/Array.hpp
        ex02/Array.tpp
        ex02/main.cpp)