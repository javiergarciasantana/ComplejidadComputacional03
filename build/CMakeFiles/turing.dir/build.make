# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/build"

# Include any dependencies generated for this target.
include CMakeFiles/turing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/turing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/turing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/turing.dir/flags.make

CMakeFiles/turing.dir/src/turing_machine_main.cc.o: CMakeFiles/turing.dir/flags.make
CMakeFiles/turing.dir/src/turing_machine_main.cc.o: /Users/javiersantana/INF\ 2024:2025/Complejidad\ Computacional/ComplejidadComputacional03/src/turing_machine_main.cc
CMakeFiles/turing.dir/src/turing_machine_main.cc.o: CMakeFiles/turing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/turing.dir/src/turing_machine_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/turing.dir/src/turing_machine_main.cc.o -MF CMakeFiles/turing.dir/src/turing_machine_main.cc.o.d -o CMakeFiles/turing.dir/src/turing_machine_main.cc.o -c "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/src/turing_machine_main.cc"

CMakeFiles/turing.dir/src/turing_machine_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/turing.dir/src/turing_machine_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/src/turing_machine_main.cc" > CMakeFiles/turing.dir/src/turing_machine_main.cc.i

CMakeFiles/turing.dir/src/turing_machine_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/turing.dir/src/turing_machine_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/src/turing_machine_main.cc" -o CMakeFiles/turing.dir/src/turing_machine_main.cc.s

# Object files for target turing
turing_OBJECTS = \
"CMakeFiles/turing.dir/src/turing_machine_main.cc.o"

# External object files for target turing
turing_EXTERNAL_OBJECTS =

turing: CMakeFiles/turing.dir/src/turing_machine_main.cc.o
turing: CMakeFiles/turing.dir/build.make
turing: CMakeFiles/turing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable turing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/turing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/turing.dir/build: turing
.PHONY : CMakeFiles/turing.dir/build

CMakeFiles/turing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/turing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/turing.dir/clean

CMakeFiles/turing.dir/depend:
	cd "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03" "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03" "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/build" "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/build" "/Users/javiersantana/INF 2024:2025/Complejidad Computacional/ComplejidadComputacional03/build/CMakeFiles/turing.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/turing.dir/depend
