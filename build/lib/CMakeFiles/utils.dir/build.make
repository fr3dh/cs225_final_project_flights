# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/cs225_final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/cs225_final/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/utils.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/utils.dir/flags.make

lib/CMakeFiles/utils.dir/utils/utils.cpp.o: lib/CMakeFiles/utils.dir/flags.make
lib/CMakeFiles/utils.dir/utils/utils.cpp.o: ../lib/utils/utils.cpp
lib/CMakeFiles/utils.dir/utils/utils.cpp.o: lib/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/cs225_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/utils.dir/utils/utils.cpp.o"
	cd /workspaces/cs225_final/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/utils.dir/utils/utils.cpp.o -MF CMakeFiles/utils.dir/utils/utils.cpp.o.d -o CMakeFiles/utils.dir/utils/utils.cpp.o -c /workspaces/cs225_final/lib/utils/utils.cpp

lib/CMakeFiles/utils.dir/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/utils.cpp.i"
	cd /workspaces/cs225_final/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/cs225_final/lib/utils/utils.cpp > CMakeFiles/utils.dir/utils/utils.cpp.i

lib/CMakeFiles/utils.dir/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/utils.cpp.s"
	cd /workspaces/cs225_final/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/cs225_final/lib/utils/utils.cpp -o CMakeFiles/utils.dir/utils/utils.cpp.s

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/utils/utils.cpp.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

lib/libutils.a: lib/CMakeFiles/utils.dir/utils/utils.cpp.o
lib/libutils.a: lib/CMakeFiles/utils.dir/build.make
lib/libutils.a: lib/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/cs225_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libutils.a"
	cd /workspaces/cs225_final/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean_target.cmake
	cd /workspaces/cs225_final/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/utils.dir/build: lib/libutils.a
.PHONY : lib/CMakeFiles/utils.dir/build

lib/CMakeFiles/utils.dir/clean:
	cd /workspaces/cs225_final/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/utils.dir/clean

lib/CMakeFiles/utils.dir/depend:
	cd /workspaces/cs225_final/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/cs225_final /workspaces/cs225_final/lib /workspaces/cs225_final/build /workspaces/cs225_final/build/lib /workspaces/cs225_final/build/lib/CMakeFiles/utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/utils.dir/depend
