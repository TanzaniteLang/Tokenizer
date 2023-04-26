cmake_minimum_required(VERSION 3.26)

project(
    TanzatineTokenizer
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++) 

add_library(
    tokenizer
    src/utils.cpp
    src/utils.hpp
)

add_executable(test main.cpp)
target_link_libraries(test PRIVATE tokenizer)
