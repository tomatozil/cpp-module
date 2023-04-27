cmake_minimum_required(VERSION 3.23)
project(Module09)

set(CMAKE_CXX_STANDARD 98)

add_executable(btc
        ex00/main.cpp
#        ex00/BitCoinChange.cpp
#        ex00/BitCoinChange.hpp
#        ex00/data.csv
        ex00/tmp.csv
        )

add_executable(test
        test.cpp)
