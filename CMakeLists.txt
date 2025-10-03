cmake_minimum_required(VERSION 4.0)
project(Hoffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hoffman main.cpp
        Nodo.cpp
        Nodo.h
        Huffman.cpp
        Huffman.h)
