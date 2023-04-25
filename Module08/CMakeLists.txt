cmake_minimum_required(VERSION 3.23)
project(Module08)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00
        ex00/main.cpp
        ex00/easyfind.hpp)

add_executable(ex01
        ex01/main.cpp
        ex01/Span.hpp
        ex01/Span.cpp)

add_executable(ex02
        ex02/MutantStack.hpp
        ex02/main.cpp)