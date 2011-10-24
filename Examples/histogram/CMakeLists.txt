cmake_minimum_required(VERSION 2.8)

PROJECT(Histo)
 
# Clang/llvm compiler
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_C_COMPILER "/usr/bin/clang")

# include UseVTK.cmake
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

 
# Set source and header files here
SET(HistoSrcs main.cpp)

# executables and libraries
add_executable(Histo ${HistoSrcs} )
target_link_libraries(Histo ${VTK_LIBRARIES} QVTK)
