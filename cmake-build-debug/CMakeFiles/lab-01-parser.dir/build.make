# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab-01-parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab-01-parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab-01-parser.dir/flags.make

CMakeFiles/lab-01-parser.dir/sources/Json.cpp.obj: CMakeFiles/lab-01-parser.dir/flags.make
CMakeFiles/lab-01-parser.dir/sources/Json.cpp.obj: CMakeFiles/lab-01-parser.dir/includes_CXX.rsp
CMakeFiles/lab-01-parser.dir/sources/Json.cpp.obj: ../sources/Json.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab-01-parser.dir/sources/Json.cpp.obj"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab-01-parser.dir\sources\Json.cpp.obj -c C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\sources\Json.cpp

CMakeFiles/lab-01-parser.dir/sources/Json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab-01-parser.dir/sources/Json.cpp.i"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\sources\Json.cpp > CMakeFiles\lab-01-parser.dir\sources\Json.cpp.i

CMakeFiles/lab-01-parser.dir/sources/Json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab-01-parser.dir/sources/Json.cpp.s"
	C:\PROGRA~2\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\sources\Json.cpp -o CMakeFiles\lab-01-parser.dir\sources\Json.cpp.s

# Object files for target lab-01-parser
lab__01__parser_OBJECTS = \
"CMakeFiles/lab-01-parser.dir/sources/Json.cpp.obj"

# External object files for target lab-01-parser
lab__01__parser_EXTERNAL_OBJECTS =

liblab-01-parserd.a: CMakeFiles/lab-01-parser.dir/sources/Json.cpp.obj
liblab-01-parserd.a: CMakeFiles/lab-01-parser.dir/build.make
liblab-01-parserd.a: CMakeFiles/lab-01-parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab-01-parserd.a"
	$(CMAKE_COMMAND) -P CMakeFiles\lab-01-parser.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab-01-parser.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab-01-parser.dir/build: liblab-01-parserd.a

.PHONY : CMakeFiles/lab-01-parser.dir/build

CMakeFiles/lab-01-parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab-01-parser.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab-01-parser.dir/clean

CMakeFiles/lab-01-parser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\cmake-build-debug C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\cmake-build-debug C:\Users\panda\CLionProjects\BootyAss-lab-01-parser-new\cmake-build-debug\CMakeFiles\lab-01-parser.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab-01-parser.dir/depend

