# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/deanchoi/CLionProjects/CIS545/Project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/deanchoi/CLionProjects/CIS545/Project2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project2.dir/flags.make

CMakeFiles/Project2.dir/main.c.o: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deanchoi/CLionProjects/CIS545/Project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Project2.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Project2.dir/main.c.o   -c /Users/deanchoi/CLionProjects/CIS545/Project2/main.c

CMakeFiles/Project2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project2.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/deanchoi/CLionProjects/CIS545/Project2/main.c > CMakeFiles/Project2.dir/main.c.i

CMakeFiles/Project2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project2.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/deanchoi/CLionProjects/CIS545/Project2/main.c -o CMakeFiles/Project2.dir/main.c.s

CMakeFiles/Project2.dir/main.c.o.requires:

.PHONY : CMakeFiles/Project2.dir/main.c.o.requires

CMakeFiles/Project2.dir/main.c.o.provides: CMakeFiles/Project2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Project2.dir/build.make CMakeFiles/Project2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Project2.dir/main.c.o.provides

CMakeFiles/Project2.dir/main.c.o.provides.build: CMakeFiles/Project2.dir/main.c.o


# Object files for target Project2
Project2_OBJECTS = \
"CMakeFiles/Project2.dir/main.c.o"

# External object files for target Project2
Project2_EXTERNAL_OBJECTS =

Project2: CMakeFiles/Project2.dir/main.c.o
Project2: CMakeFiles/Project2.dir/build.make
Project2: CMakeFiles/Project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/deanchoi/CLionProjects/CIS545/Project2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Project2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project2.dir/build: Project2

.PHONY : CMakeFiles/Project2.dir/build

CMakeFiles/Project2.dir/requires: CMakeFiles/Project2.dir/main.c.o.requires

.PHONY : CMakeFiles/Project2.dir/requires

CMakeFiles/Project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project2.dir/clean

CMakeFiles/Project2.dir/depend:
	cd /Users/deanchoi/CLionProjects/CIS545/Project2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/deanchoi/CLionProjects/CIS545/Project2 /Users/deanchoi/CLionProjects/CIS545/Project2 /Users/deanchoi/CLionProjects/CIS545/Project2/cmake-build-debug /Users/deanchoi/CLionProjects/CIS545/Project2/cmake-build-debug /Users/deanchoi/CLionProjects/CIS545/Project2/cmake-build-debug/CMakeFiles/Project2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project2.dir/depend
