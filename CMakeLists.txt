cmake_minimum_required(VERSION 3.26)

project(
    TanzatineTokenizer
    VERSION 1.0
    LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

find_package(LLVM REQUIRED)

if(LLVM_LINK_STATIC)
    # add more llvm components to this function if needed
    llvm_map_components_to_libnames(llvm_libs support core bitreader mcjit native)
else()
    set(llvm_libs LLVM)
endif()

add_executable(test main.cpp)
