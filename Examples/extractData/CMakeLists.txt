

cmake_minimum_required(VERSION 2.8)

project(data)

# Clang/llvm compiler
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_C_COMPILER "/usr/bin/clang")

find_package(GDCM REQUIRED)

SET(dataSrcs main.cpp)
add_executable(data ${dataSrcs} )
target_link_libraries(data gdcmMSFF)
