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
include app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/depend.make

# Include the progress variables for this target.
include app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/progress.make

# Include the compile flags for this target's objects.
include app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/flags.make

app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.o: app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/flags.make
app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.o: ../app/modules/PermMissingElem/PermMissingElem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/egemahlec/Documents/code/own/c++/codility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.o"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.o -c /Users/egemahlec/Documents/code/own/c++/codility/app/modules/PermMissingElem/PermMissingElem.cpp

app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.i"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egemahlec/Documents/code/own/c++/codility/app/modules/PermMissingElem/PermMissingElem.cpp > CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.i

app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.s"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egemahlec/Documents/code/own/c++/codility/app/modules/PermMissingElem/PermMissingElem.cpp -o CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.s

# Object files for target PermMissingElem
PermMissingElem_OBJECTS = \
"CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.o"

# External object files for target PermMissingElem
PermMissingElem_EXTERNAL_OBJECTS =

app/modules/PermMissingElem/PermMissingElem: app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/PermMissingElem.cpp.o
app/modules/PermMissingElem/PermMissingElem: app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/build.make
app/modules/PermMissingElem/PermMissingElem: modules/GoogleTest/lib/libgtest.a
app/modules/PermMissingElem/PermMissingElem: modules/GoogleTest/lib/libgmock.a
app/modules/PermMissingElem/PermMissingElem: app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/egemahlec/Documents/code/own/c++/codility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PermMissingElem"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PermMissingElem.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running Unit Tests"
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem && /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem/PermMissingElem

# Rule to build all files generated by this target.
app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/build: app/modules/PermMissingElem/PermMissingElem

.PHONY : app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/build

app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/clean:
	cd /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem && $(CMAKE_COMMAND) -P CMakeFiles/PermMissingElem.dir/cmake_clean.cmake
.PHONY : app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/clean

app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/depend:
	cd /Users/egemahlec/Documents/code/own/c++/codility/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/egemahlec/Documents/code/own/c++/codility /Users/egemahlec/Documents/code/own/c++/codility/app/modules/PermMissingElem /Users/egemahlec/Documents/code/own/c++/codility/build /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem /Users/egemahlec/Documents/code/own/c++/codility/build/app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/modules/PermMissingElem/CMakeFiles/PermMissingElem.dir/depend

