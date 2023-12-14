cmake_minimum_required(VERSION 3.26)
project(Labb2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Labb2 main.cpp
        DataGenerate.cpp
        DataGenerate.h
        InsertionSort.cpp
        InsertionSort.h
        SelectionSort.cpp
        SelectionSort.h
        QuickSort.cpp
        QuickSort.h
        QuickSortMOT.cpp
        QuickSortMOT.h
)
