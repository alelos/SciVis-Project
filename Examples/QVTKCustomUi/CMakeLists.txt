cmake_minimum_required(VERSION 2.8)
 
PROJECT(Testing)

SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_C_COMPILER "/usr/bin/clang")
 
FIND_PACKAGE(VTK)
INCLUDE(${VTK_USE_FILE}) # include UseVTK.cmake
 
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})  # include UseQt4.cmake
 
# support for out-of-source build
INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_BINARY_DIR} #this is where ui_SimpleViewUI.h is generated
  ${CMAKE_CURRENT_SOURCE_DIR}
)
 
# Set your files and resources here
SET(TestingSrcs main.cpp mainWindow.cpp)
SET(TestingHeaders mainWindow.h)
 
QT4_WRAP_CPP(MOCSrcs ${TestingHeaders} )
 
 
SOURCE_GROUP("Generated" FILES
  ${MOCSrcs}
)
 
ADD_EXECUTABLE( Testing ${TestingSrcs} ${MOCSrcs})
TARGET_LINK_LIBRARIES( Testing QVTK )
