# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/p8.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/p8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p8.dir/flags.make

CMakeFiles/p8.dir/main.cpp.obj: CMakeFiles/p8.dir/flags.make
CMakeFiles/p8.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p8.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p8.dir\main.cpp.obj -c "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\main.cpp"

CMakeFiles/p8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p8.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\main.cpp" > CMakeFiles\p8.dir\main.cpp.i

CMakeFiles/p8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p8.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\main.cpp" -o CMakeFiles\p8.dir\main.cpp.s

CMakeFiles/p8.dir/DynamicList.cpp.obj: CMakeFiles/p8.dir/flags.make
CMakeFiles/p8.dir/DynamicList.cpp.obj: ../DynamicList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/p8.dir/DynamicList.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p8.dir\DynamicList.cpp.obj -c "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\DynamicList.cpp"

CMakeFiles/p8.dir/DynamicList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p8.dir/DynamicList.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\DynamicList.cpp" > CMakeFiles\p8.dir\DynamicList.cpp.i

CMakeFiles/p8.dir/DynamicList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p8.dir/DynamicList.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\DynamicList.cpp" -o CMakeFiles\p8.dir\DynamicList.cpp.s

CMakeFiles/p8.dir/Node.cpp.obj: CMakeFiles/p8.dir/flags.make
CMakeFiles/p8.dir/Node.cpp.obj: ../Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/p8.dir/Node.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\p8.dir\Node.cpp.obj -c "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\Node.cpp"

CMakeFiles/p8.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p8.dir/Node.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\Node.cpp" > CMakeFiles\p8.dir\Node.cpp.i

CMakeFiles/p8.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p8.dir/Node.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\Node.cpp" -o CMakeFiles\p8.dir\Node.cpp.s

# Object files for target p8
p8_OBJECTS = \
"CMakeFiles/p8.dir/main.cpp.obj" \
"CMakeFiles/p8.dir/DynamicList.cpp.obj" \
"CMakeFiles/p8.dir/Node.cpp.obj"

# External object files for target p8
p8_EXTERNAL_OBJECTS =

p8.exe: CMakeFiles/p8.dir/main.cpp.obj
p8.exe: CMakeFiles/p8.dir/DynamicList.cpp.obj
p8.exe: CMakeFiles/p8.dir/Node.cpp.obj
p8.exe: CMakeFiles/p8.dir/build.make
p8.exe: CMakeFiles/p8.dir/linklibs.rsp
p8.exe: CMakeFiles/p8.dir/objects1.rsp
p8.exe: CMakeFiles/p8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable p8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\p8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p8.dir/build: p8.exe
.PHONY : CMakeFiles/p8.dir/build

CMakeFiles/p8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\p8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/p8.dir/clean

CMakeFiles/p8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8" "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8" "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug" "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug" "G:\My Drive\University\Semester 2\COS 110\Coding\pracs\p8\cmake-build-debug\CMakeFiles\p8.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/p8.dir/depend

