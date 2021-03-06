# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jibran/GettingAroundSTL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jibran/GettingAroundSTL/build

# Include any dependencies generated for this target.
include CMakeFiles/Astar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Astar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Astar.dir/flags.make

CMakeFiles/Astar.dir/src/challenges/aStar.cpp.o: CMakeFiles/Astar.dir/flags.make
CMakeFiles/Astar.dir/src/challenges/aStar.cpp.o: ../src/challenges/aStar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jibran/GettingAroundSTL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Astar.dir/src/challenges/aStar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astar.dir/src/challenges/aStar.cpp.o -c /home/jibran/GettingAroundSTL/src/challenges/aStar.cpp

CMakeFiles/Astar.dir/src/challenges/aStar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astar.dir/src/challenges/aStar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jibran/GettingAroundSTL/src/challenges/aStar.cpp > CMakeFiles/Astar.dir/src/challenges/aStar.cpp.i

CMakeFiles/Astar.dir/src/challenges/aStar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astar.dir/src/challenges/aStar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jibran/GettingAroundSTL/src/challenges/aStar.cpp -o CMakeFiles/Astar.dir/src/challenges/aStar.cpp.s

CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.o: CMakeFiles/Astar.dir/flags.make
CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.o: ../src/challenges/createWeightedGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jibran/GettingAroundSTL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.o -c /home/jibran/GettingAroundSTL/src/challenges/createWeightedGraph.cpp

CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jibran/GettingAroundSTL/src/challenges/createWeightedGraph.cpp > CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.i

CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jibran/GettingAroundSTL/src/challenges/createWeightedGraph.cpp -o CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.s

# Object files for target Astar
Astar_OBJECTS = \
"CMakeFiles/Astar.dir/src/challenges/aStar.cpp.o" \
"CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.o"

# External object files for target Astar
Astar_EXTERNAL_OBJECTS =

Astar: CMakeFiles/Astar.dir/src/challenges/aStar.cpp.o
Astar: CMakeFiles/Astar.dir/src/challenges/createWeightedGraph.cpp.o
Astar: CMakeFiles/Astar.dir/build.make
Astar: CMakeFiles/Astar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jibran/GettingAroundSTL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Astar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Astar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Astar.dir/build: Astar

.PHONY : CMakeFiles/Astar.dir/build

CMakeFiles/Astar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Astar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Astar.dir/clean

CMakeFiles/Astar.dir/depend:
	cd /home/jibran/GettingAroundSTL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jibran/GettingAroundSTL /home/jibran/GettingAroundSTL /home/jibran/GettingAroundSTL/build /home/jibran/GettingAroundSTL/build /home/jibran/GettingAroundSTL/build/CMakeFiles/Astar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Astar.dir/depend

