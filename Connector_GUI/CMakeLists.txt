cmake_minimum_required(VERSION 2.8)

PROJECT(Connector)

IF(APPLE) 
    SET(PROGNAME Connector)
    SET( MACOSX_BUNDLE_ICON_FILE Icon.icns )
    SET( MACOSX_BUNDLE_SHORT_VERSION_STRING 0.1-beta1 )
    SET( MACOSX_BUNDLE_VERSION 0.1-beta1 )
    SET( MACOSX_BUNDLE_LONG_VERSION_STRING Version 0.1-beta1 )
    #SET( CMAKE_OSX_ARCHITECTURES ppc;i386 ) #Comment out if not universal binary
  ELSE( APPLE )
    SET( PROGNAME speedcrunch )
  ENDIF( APPLE )


# Clang/llvm compiler, comment out if not install
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_C_COMPILER "/usr/bin/clang")

#include UseQT4.cmake
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

# Set source and header files here
SET(ConnectorSourceFiles mainWindow.cpp Connector.cpp main.cpp)
SET(ConnectorHeaderFiles mainWindow.h Connector.h)
 
QT4_WRAP_CPP(MOCSrcs ${ConnectorHeaderFiles})

SOURCE_GROUP("Generated" FILES ${MOCSrcs})

add_executable(Connector MACOSX_BUNDLE ${ConnectorSourceFiles} ${MOCSrcs})
ADD_CUSTOM_COMMAND( TARGET ${PROGNAME} POST_BUILD
      COMMAND mkdir ARGS ${CMAKE_CURRENT_BINARY_DIR}/${PROGNAME}.app/Contents/Resources
      COMMAND cp ARGS ${MACOSX_BUNDLE_ICON_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${PROGNAME}.app/Contents/Resources)
target_link_libraries(Connector ${QT_LIBRARIES} ssh )
