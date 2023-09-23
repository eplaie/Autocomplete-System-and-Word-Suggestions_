cmake_minimum_required(VERSION 3.12)

project("Autocomplete" VERSION 1.0.0)

add_executable(app "src/main.cpp" "src/hash.cpp" "src/heap.hpp" "src/avl.cpp" "src/bin.cpp" "src/huff.cpp")