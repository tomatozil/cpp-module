cmake_minimum_required(VERSION 3.23)
project(Module06)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00
        ex00/main.cpp
        ex00/ScalarConverter.cpp
        ex00/ScalarConverter.hpp)

add_executable(ex01
        ex01/main.cpp
        ex01/Serializer.cpp
        ex01/Serializer.hpp)

add_executable(ex02
        ex02/main.cpp
        ex02/Base.hpp
        ex02/Base.cpp
        ex02/A.hpp
        ex02/A.cpp
        ex02/B.hpp
        ex02/B.cpp
        ex02/C.hpp
        ex02/C.cpp)
