# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/egemahlec/Documents/code/own/c++/codility

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/egemahlec/Documents/code/own/c++/codility/build

# Include any dependencies generated for this target.
include app/modules/iterations/CMakeFiles/BasicModuleTest.dir/depend.make

# Include the progress variables for this target.
include app/modules/iterations/CMakeFiles/BasicModuleTest.dir/progress.make

# Include the compile flags for this target's objects.
include app/modules/iterations/CMakeFiles/BasicModuleTest.dir/flags.make

app/modules/iterations/CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.o: app/modules/iterations/CMakeFiles/BasicModuleTest.dir/flags.make
app/modules/iterations/CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.o: ../app/modules/iterations/BasicModuleTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/egemahlec/Documents/code/own/c++/codility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/modules/iterations/CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.o"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.o -c /Users/egemahlec/Documents/code/own/c++/codility/app/modules/iterations/BasicModuleTest.cpp

app/modules/iterations/CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.i"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egemahlec/Documents/code/own/c++/codility/app/modules/iterations/BasicModuleTest.cpp > CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.i

app/modules/iterations/CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.s"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egemahlec/Documents/code/own/c++/codility/app/modules/iterations/BasicModuleTest.cpp -o CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.s

# Object files for target BasicModuleTest
BasicModuleTest_OBJECTS = \
"CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.o"

# External object files for target BasicModuleTest
BasicModuleTest_EXTERNAL_OBJECTS =

app/modules/iterations/BasicModuleTest: app/modules/iterations/CMakeFiles/BasicModuleTest.dir/BasicModuleTest.cpp.o
app/modules/iterations/BasicModuleTest: app/modules/iterations/CMakeFiles/BasicModuleTest.dir/build.make
app/modules/iterations/BasicModuleTest: modules/GoogleTest/lib/libgtest.a
app/modules/iterations/BasicModuleTest: modules/GoogleTest/lib/libgmock.a
app/modules/iterations/BasicModuleTest: app/modules/iterations/CMakeFiles/BasicModuleTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/egemahlec/Documents/code/own/c++/codility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BasicModuleTest"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BasicModuleTest.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Unit Tests"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations && /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations/BasicModuleTest

# Rule to build all files generated by this target.
app/modules/iterations/CMakeFiles/BasicModuleTest.dir/build: app/modules/iterations/BasicModuleTest

.PHONY : app/modules/iterations/CMakeFiles/BasicModuleTest.dir/build

app/modules/iterations/CMakeFiles/BasicModuleTest.dir/clean:
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations && $(CMAKE_COMMAND) -P CMakeFiles/BasicModuleTest.dir/cmake_clean.cmake
.PHONY : app/modules/iterations/CMakeFiles/BasicModuleTest.dir/clean

app/modules/iterations/CMakeFiles/BasicModuleTest.dir/depend:
	cd /Users/egemahlec/Documents/code/own/c++/codility/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/egemahlec/Documents/code/own/c++/codility /Users/egemahlec/Documents/code/own/c++/codility/app/modules/iterations /Users/egemahlec/Documents/code/own/c++/codility/build /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/iterations/CMakeFiles/BasicModuleTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/modules/iterations/CMakeFiles/BasicModuleTest.dir/depend

