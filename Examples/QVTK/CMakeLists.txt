cmake_minimum_required(VERSION 2.8)

PROJECT(Corals)
 
# Clang/llvm compiler
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_C_COMPILER "/usr/bin/clang")

# include UseVTK.cmake
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#include UseQT4.cmake
find_package(Qt4 REQUIRED)
SET(QT_USE_QTOPENGL 1)
include(${QT_USE_FILE})
 
# Set source and header files here
SET(CoralsSourceFiles HistogramViewItem.cpp)
SET(CoralHeaderFiles HistogramViewItem.h)
 
QT4_WRAP_CPP(MOCSrcs ${CoralHeaderFiles})

SOURCE_GROUP("Generated" FILES ${MOCSrcs})

#if(VTK_LIBRARIES)
#    target_link_libraries(Corals ${VTK_LIBRARIES})
#else()
#    target_link_libraries(Corals vtkHybrid )
#endif()

# executables and libraries
add_executable(Corals ${CoralsSourceFiles} ${MOCSrcs})
target_link_libraries(Corals ${QT_LIBRARIES} ${VTK_LIBRARIES} QVTK)
