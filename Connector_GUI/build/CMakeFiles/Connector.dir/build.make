# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Applications/CMake 2.8-4.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-4.app/Contents/bin/cmake" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-4.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alelos/Desktop/SciVis-Project/Connector_GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build

# Include any dependencies generated for this target.
include CMakeFiles/Connector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Connector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Connector.dir/flags.make

CMakeFiles/Connector.dir/mainWindow.cpp.o: CMakeFiles/Connector.dir/flags.make
CMakeFiles/Connector.dir/mainWindow.cpp.o: ../mainWindow.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Connector.dir/mainWindow.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Connector.dir/mainWindow.cpp.o -c /Users/alelos/Desktop/SciVis-Project/Connector_GUI/mainWindow.cpp

CMakeFiles/Connector.dir/mainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Connector.dir/mainWindow.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/alelos/Desktop/SciVis-Project/Connector_GUI/mainWindow.cpp > CMakeFiles/Connector.dir/mainWindow.cpp.i

CMakeFiles/Connector.dir/mainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Connector.dir/mainWindow.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/alelos/Desktop/SciVis-Project/Connector_GUI/mainWindow.cpp -o CMakeFiles/Connector.dir/mainWindow.cpp.s

CMakeFiles/Connector.dir/mainWindow.cpp.o.requires:
.PHONY : CMakeFiles/Connector.dir/mainWindow.cpp.o.requires

CMakeFiles/Connector.dir/mainWindow.cpp.o.provides: CMakeFiles/Connector.dir/mainWindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/Connector.dir/build.make CMakeFiles/Connector.dir/mainWindow.cpp.o.provides.build
.PHONY : CMakeFiles/Connector.dir/mainWindow.cpp.o.provides

CMakeFiles/Connector.dir/mainWindow.cpp.o.provides.build: CMakeFiles/Connector.dir/mainWindow.cpp.o

CMakeFiles/Connector.dir/Connector.cpp.o: CMakeFiles/Connector.dir/flags.make
CMakeFiles/Connector.dir/Connector.cpp.o: ../Connector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Connector.dir/Connector.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Connector.dir/Connector.cpp.o -c /Users/alelos/Desktop/SciVis-Project/Connector_GUI/Connector.cpp

CMakeFiles/Connector.dir/Connector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Connector.dir/Connector.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/alelos/Desktop/SciVis-Project/Connector_GUI/Connector.cpp > CMakeFiles/Connector.dir/Connector.cpp.i

CMakeFiles/Connector.dir/Connector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Connector.dir/Connector.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/alelos/Desktop/SciVis-Project/Connector_GUI/Connector.cpp -o CMakeFiles/Connector.dir/Connector.cpp.s

CMakeFiles/Connector.dir/Connector.cpp.o.requires:
.PHONY : CMakeFiles/Connector.dir/Connector.cpp.o.requires

CMakeFiles/Connector.dir/Connector.cpp.o.provides: CMakeFiles/Connector.dir/Connector.cpp.o.requires
	$(MAKE) -f CMakeFiles/Connector.dir/build.make CMakeFiles/Connector.dir/Connector.cpp.o.provides.build
.PHONY : CMakeFiles/Connector.dir/Connector.cpp.o.provides

CMakeFiles/Connector.dir/Connector.cpp.o.provides.build: CMakeFiles/Connector.dir/Connector.cpp.o

CMakeFiles/Connector.dir/main.cpp.o: CMakeFiles/Connector.dir/flags.make
CMakeFiles/Connector.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Connector.dir/main.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Connector.dir/main.cpp.o -c /Users/alelos/Desktop/SciVis-Project/Connector_GUI/main.cpp

CMakeFiles/Connector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Connector.dir/main.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/alelos/Desktop/SciVis-Project/Connector_GUI/main.cpp > CMakeFiles/Connector.dir/main.cpp.i

CMakeFiles/Connector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Connector.dir/main.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/alelos/Desktop/SciVis-Project/Connector_GUI/main.cpp -o CMakeFiles/Connector.dir/main.cpp.s

CMakeFiles/Connector.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/Connector.dir/main.cpp.o.requires

CMakeFiles/Connector.dir/main.cpp.o.provides: CMakeFiles/Connector.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Connector.dir/build.make CMakeFiles/Connector.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Connector.dir/main.cpp.o.provides

CMakeFiles/Connector.dir/main.cpp.o.provides.build: CMakeFiles/Connector.dir/main.cpp.o

CMakeFiles/Connector.dir/moc_mainWindow.cxx.o: CMakeFiles/Connector.dir/flags.make
CMakeFiles/Connector.dir/moc_mainWindow.cxx.o: moc_mainWindow.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Connector.dir/moc_mainWindow.cxx.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Connector.dir/moc_mainWindow.cxx.o -c /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_mainWindow.cxx

CMakeFiles/Connector.dir/moc_mainWindow.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Connector.dir/moc_mainWindow.cxx.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_mainWindow.cxx > CMakeFiles/Connector.dir/moc_mainWindow.cxx.i

CMakeFiles/Connector.dir/moc_mainWindow.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Connector.dir/moc_mainWindow.cxx.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_mainWindow.cxx -o CMakeFiles/Connector.dir/moc_mainWindow.cxx.s

CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.requires:
.PHONY : CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.requires

CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.provides: CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.requires
	$(MAKE) -f CMakeFiles/Connector.dir/build.make CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.provides.build
.PHONY : CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.provides

CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.provides.build: CMakeFiles/Connector.dir/moc_mainWindow.cxx.o

CMakeFiles/Connector.dir/moc_Connector.cxx.o: CMakeFiles/Connector.dir/flags.make
CMakeFiles/Connector.dir/moc_Connector.cxx.o: moc_Connector.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Connector.dir/moc_Connector.cxx.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Connector.dir/moc_Connector.cxx.o -c /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_Connector.cxx

CMakeFiles/Connector.dir/moc_Connector.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Connector.dir/moc_Connector.cxx.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_Connector.cxx > CMakeFiles/Connector.dir/moc_Connector.cxx.i

CMakeFiles/Connector.dir/moc_Connector.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Connector.dir/moc_Connector.cxx.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_Connector.cxx -o CMakeFiles/Connector.dir/moc_Connector.cxx.s

CMakeFiles/Connector.dir/moc_Connector.cxx.o.requires:
.PHONY : CMakeFiles/Connector.dir/moc_Connector.cxx.o.requires

CMakeFiles/Connector.dir/moc_Connector.cxx.o.provides: CMakeFiles/Connector.dir/moc_Connector.cxx.o.requires
	$(MAKE) -f CMakeFiles/Connector.dir/build.make CMakeFiles/Connector.dir/moc_Connector.cxx.o.provides.build
.PHONY : CMakeFiles/Connector.dir/moc_Connector.cxx.o.provides

CMakeFiles/Connector.dir/moc_Connector.cxx.o.provides.build: CMakeFiles/Connector.dir/moc_Connector.cxx.o

moc_mainWindow.cxx: ../mainWindow.h
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_mainWindow.cxx"
	/Developer/Tools/Qt/moc -I/usr/include -F/Library/Frameworks -I/Library/Frameworks/QtGui.framework/Headers -I/Library/Frameworks/QtCore.framework/Headers -DQT_GUI_LIB -DQT_CORE_LIB -o /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_mainWindow.cxx /Users/alelos/Desktop/SciVis-Project/Connector_GUI/mainWindow.h

moc_Connector.cxx: ../Connector.h
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_Connector.cxx"
	/Developer/Tools/Qt/moc -I/usr/include -F/Library/Frameworks -I/Library/Frameworks/QtGui.framework/Headers -I/Library/Frameworks/QtCore.framework/Headers -DQT_GUI_LIB -DQT_CORE_LIB -o /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/moc_Connector.cxx /Users/alelos/Desktop/SciVis-Project/Connector_GUI/Connector.h

# Object files for target Connector
Connector_OBJECTS = \
"CMakeFiles/Connector.dir/mainWindow.cpp.o" \
"CMakeFiles/Connector.dir/Connector.cpp.o" \
"CMakeFiles/Connector.dir/main.cpp.o" \
"CMakeFiles/Connector.dir/moc_mainWindow.cxx.o" \
"CMakeFiles/Connector.dir/moc_Connector.cxx.o"

# External object files for target Connector
Connector_EXTERNAL_OBJECTS =

Connector.app/Contents/MacOS/Connector: CMakeFiles/Connector.dir/mainWindow.cpp.o
Connector.app/Contents/MacOS/Connector: CMakeFiles/Connector.dir/Connector.cpp.o
Connector.app/Contents/MacOS/Connector: CMakeFiles/Connector.dir/main.cpp.o
Connector.app/Contents/MacOS/Connector: CMakeFiles/Connector.dir/moc_mainWindow.cxx.o
Connector.app/Contents/MacOS/Connector: CMakeFiles/Connector.dir/moc_Connector.cxx.o
Connector.app/Contents/MacOS/Connector: CMakeFiles/Connector.dir/build.make
Connector.app/Contents/MacOS/Connector: CMakeFiles/Connector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Connector.app/Contents/MacOS/Connector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Connector.dir/link.txt --verbose=$(VERBOSE)
	mkdir /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/Connector.app/Contents/Resources
	cp Icon.icns /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/Connector.app/Contents/Resources

# Rule to build all files generated by this target.
CMakeFiles/Connector.dir/build: Connector.app/Contents/MacOS/Connector
.PHONY : CMakeFiles/Connector.dir/build

CMakeFiles/Connector.dir/requires: CMakeFiles/Connector.dir/mainWindow.cpp.o.requires
CMakeFiles/Connector.dir/requires: CMakeFiles/Connector.dir/Connector.cpp.o.requires
CMakeFiles/Connector.dir/requires: CMakeFiles/Connector.dir/main.cpp.o.requires
CMakeFiles/Connector.dir/requires: CMakeFiles/Connector.dir/moc_mainWindow.cxx.o.requires
CMakeFiles/Connector.dir/requires: CMakeFiles/Connector.dir/moc_Connector.cxx.o.requires
.PHONY : CMakeFiles/Connector.dir/requires

CMakeFiles/Connector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Connector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Connector.dir/clean

CMakeFiles/Connector.dir/depend: moc_mainWindow.cxx
CMakeFiles/Connector.dir/depend: moc_Connector.cxx
	cd /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alelos/Desktop/SciVis-Project/Connector_GUI /Users/alelos/Desktop/SciVis-Project/Connector_GUI /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build /Users/alelos/Desktop/SciVis-Project/Connector_GUI/build/CMakeFiles/Connector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Connector.dir/depend

