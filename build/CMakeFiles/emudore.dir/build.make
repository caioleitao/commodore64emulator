# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.20.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.20.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kyle/Desktop/Projects/commodore64emulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kyle/Desktop/Projects/commodore64emulator/build

# Include any dependencies generated for this target.
include CMakeFiles/emudore.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/emudore.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/emudore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/emudore.dir/flags.make

CMakeFiles/emudore.dir/src/c64.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/c64.cpp.o: ../src/c64.cpp
CMakeFiles/emudore.dir/src/c64.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/emudore.dir/src/c64.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/c64.cpp.o -MF CMakeFiles/emudore.dir/src/c64.cpp.o.d -o CMakeFiles/emudore.dir/src/c64.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/c64.cpp

CMakeFiles/emudore.dir/src/c64.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/c64.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/c64.cpp > CMakeFiles/emudore.dir/src/c64.cpp.i

CMakeFiles/emudore.dir/src/c64.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/c64.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/c64.cpp -o CMakeFiles/emudore.dir/src/c64.cpp.s

CMakeFiles/emudore.dir/src/cpu.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/cpu.cpp.o: ../src/cpu.cpp
CMakeFiles/emudore.dir/src/cpu.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/emudore.dir/src/cpu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/cpu.cpp.o -MF CMakeFiles/emudore.dir/src/cpu.cpp.o.d -o CMakeFiles/emudore.dir/src/cpu.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/cpu.cpp

CMakeFiles/emudore.dir/src/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/cpu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/cpu.cpp > CMakeFiles/emudore.dir/src/cpu.cpp.i

CMakeFiles/emudore.dir/src/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/cpu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/cpu.cpp -o CMakeFiles/emudore.dir/src/cpu.cpp.s

CMakeFiles/emudore.dir/src/memory.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/memory.cpp.o: ../src/memory.cpp
CMakeFiles/emudore.dir/src/memory.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/emudore.dir/src/memory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/memory.cpp.o -MF CMakeFiles/emudore.dir/src/memory.cpp.o.d -o CMakeFiles/emudore.dir/src/memory.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/memory.cpp

CMakeFiles/emudore.dir/src/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/memory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/memory.cpp > CMakeFiles/emudore.dir/src/memory.cpp.i

CMakeFiles/emudore.dir/src/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/memory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/memory.cpp -o CMakeFiles/emudore.dir/src/memory.cpp.s

CMakeFiles/emudore.dir/src/cia1.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/cia1.cpp.o: ../src/cia1.cpp
CMakeFiles/emudore.dir/src/cia1.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/emudore.dir/src/cia1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/cia1.cpp.o -MF CMakeFiles/emudore.dir/src/cia1.cpp.o.d -o CMakeFiles/emudore.dir/src/cia1.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/cia1.cpp

CMakeFiles/emudore.dir/src/cia1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/cia1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/cia1.cpp > CMakeFiles/emudore.dir/src/cia1.cpp.i

CMakeFiles/emudore.dir/src/cia1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/cia1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/cia1.cpp -o CMakeFiles/emudore.dir/src/cia1.cpp.s

CMakeFiles/emudore.dir/src/cia2.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/cia2.cpp.o: ../src/cia2.cpp
CMakeFiles/emudore.dir/src/cia2.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/emudore.dir/src/cia2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/cia2.cpp.o -MF CMakeFiles/emudore.dir/src/cia2.cpp.o.d -o CMakeFiles/emudore.dir/src/cia2.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/cia2.cpp

CMakeFiles/emudore.dir/src/cia2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/cia2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/cia2.cpp > CMakeFiles/emudore.dir/src/cia2.cpp.i

CMakeFiles/emudore.dir/src/cia2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/cia2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/cia2.cpp -o CMakeFiles/emudore.dir/src/cia2.cpp.s

CMakeFiles/emudore.dir/src/vic.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/vic.cpp.o: ../src/vic.cpp
CMakeFiles/emudore.dir/src/vic.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/emudore.dir/src/vic.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/vic.cpp.o -MF CMakeFiles/emudore.dir/src/vic.cpp.o.d -o CMakeFiles/emudore.dir/src/vic.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/vic.cpp

CMakeFiles/emudore.dir/src/vic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/vic.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/vic.cpp > CMakeFiles/emudore.dir/src/vic.cpp.i

CMakeFiles/emudore.dir/src/vic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/vic.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/vic.cpp -o CMakeFiles/emudore.dir/src/vic.cpp.s

CMakeFiles/emudore.dir/src/io.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/io.cpp.o: ../src/io.cpp
CMakeFiles/emudore.dir/src/io.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/emudore.dir/src/io.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/io.cpp.o -MF CMakeFiles/emudore.dir/src/io.cpp.o.d -o CMakeFiles/emudore.dir/src/io.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/io.cpp

CMakeFiles/emudore.dir/src/io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/io.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/io.cpp > CMakeFiles/emudore.dir/src/io.cpp.i

CMakeFiles/emudore.dir/src/io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/io.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/io.cpp -o CMakeFiles/emudore.dir/src/io.cpp.s

CMakeFiles/emudore.dir/src/loader.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/loader.cpp.o: ../src/loader.cpp
CMakeFiles/emudore.dir/src/loader.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/emudore.dir/src/loader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/loader.cpp.o -MF CMakeFiles/emudore.dir/src/loader.cpp.o.d -o CMakeFiles/emudore.dir/src/loader.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/loader.cpp

CMakeFiles/emudore.dir/src/loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/loader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/loader.cpp > CMakeFiles/emudore.dir/src/loader.cpp.i

CMakeFiles/emudore.dir/src/loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/loader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/loader.cpp -o CMakeFiles/emudore.dir/src/loader.cpp.s

CMakeFiles/emudore.dir/src/main.cpp.o: CMakeFiles/emudore.dir/flags.make
CMakeFiles/emudore.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/emudore.dir/src/main.cpp.o: CMakeFiles/emudore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/emudore.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/emudore.dir/src/main.cpp.o -MF CMakeFiles/emudore.dir/src/main.cpp.o.d -o CMakeFiles/emudore.dir/src/main.cpp.o -c /Users/kyle/Desktop/Projects/commodore64emulator/src/main.cpp

CMakeFiles/emudore.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emudore.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kyle/Desktop/Projects/commodore64emulator/src/main.cpp > CMakeFiles/emudore.dir/src/main.cpp.i

CMakeFiles/emudore.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emudore.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kyle/Desktop/Projects/commodore64emulator/src/main.cpp -o CMakeFiles/emudore.dir/src/main.cpp.s

# Object files for target emudore
emudore_OBJECTS = \
"CMakeFiles/emudore.dir/src/c64.cpp.o" \
"CMakeFiles/emudore.dir/src/cpu.cpp.o" \
"CMakeFiles/emudore.dir/src/memory.cpp.o" \
"CMakeFiles/emudore.dir/src/cia1.cpp.o" \
"CMakeFiles/emudore.dir/src/cia2.cpp.o" \
"CMakeFiles/emudore.dir/src/vic.cpp.o" \
"CMakeFiles/emudore.dir/src/io.cpp.o" \
"CMakeFiles/emudore.dir/src/loader.cpp.o" \
"CMakeFiles/emudore.dir/src/main.cpp.o"

# External object files for target emudore
emudore_EXTERNAL_OBJECTS =

emudore: CMakeFiles/emudore.dir/src/c64.cpp.o
emudore: CMakeFiles/emudore.dir/src/cpu.cpp.o
emudore: CMakeFiles/emudore.dir/src/memory.cpp.o
emudore: CMakeFiles/emudore.dir/src/cia1.cpp.o
emudore: CMakeFiles/emudore.dir/src/cia2.cpp.o
emudore: CMakeFiles/emudore.dir/src/vic.cpp.o
emudore: CMakeFiles/emudore.dir/src/io.cpp.o
emudore: CMakeFiles/emudore.dir/src/loader.cpp.o
emudore: CMakeFiles/emudore.dir/src/main.cpp.o
emudore: CMakeFiles/emudore.dir/build.make
emudore: /opt/homebrew/lib/libSDL2main.a
emudore: /opt/homebrew/lib/libSDL2.dylib
emudore: CMakeFiles/emudore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable emudore"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emudore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/emudore.dir/build: emudore
.PHONY : CMakeFiles/emudore.dir/build

CMakeFiles/emudore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/emudore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/emudore.dir/clean

CMakeFiles/emudore.dir/depend:
	cd /Users/kyle/Desktop/Projects/commodore64emulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kyle/Desktop/Projects/commodore64emulator /Users/kyle/Desktop/Projects/commodore64emulator /Users/kyle/Desktop/Projects/commodore64emulator/build /Users/kyle/Desktop/Projects/commodore64emulator/build /Users/kyle/Desktop/Projects/commodore64emulator/build/CMakeFiles/emudore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/emudore.dir/depend
