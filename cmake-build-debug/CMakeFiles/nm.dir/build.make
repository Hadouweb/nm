# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /Users/nle-bret/project/nm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nle-bret/project/nm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/nm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nm.dir/flags.make

CMakeFiles/nm.dir/srcs/ft_nm.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/ft_nm.c.o: ../srcs/ft_nm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nm.dir/srcs/ft_nm.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/ft_nm.c.o   -c /Users/nle-bret/project/nm/srcs/ft_nm.c

CMakeFiles/nm.dir/srcs/ft_nm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/ft_nm.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/ft_nm.c > CMakeFiles/nm.dir/srcs/ft_nm.c.i

CMakeFiles/nm.dir/srcs/ft_nm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/ft_nm.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/ft_nm.c -o CMakeFiles/nm.dir/srcs/ft_nm.c.s

CMakeFiles/nm.dir/srcs/ft_nm.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/ft_nm.c.o.requires

CMakeFiles/nm.dir/srcs/ft_nm.c.o.provides: CMakeFiles/nm.dir/srcs/ft_nm.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/ft_nm.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/ft_nm.c.o.provides

CMakeFiles/nm.dir/srcs/ft_nm.c.o.provides.build: CMakeFiles/nm.dir/srcs/ft_nm.c.o


CMakeFiles/nm.dir/srcs/error.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/error.c.o: ../srcs/error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/nm.dir/srcs/error.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/error.c.o   -c /Users/nle-bret/project/nm/srcs/error.c

CMakeFiles/nm.dir/srcs/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/error.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/error.c > CMakeFiles/nm.dir/srcs/error.c.i

CMakeFiles/nm.dir/srcs/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/error.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/error.c -o CMakeFiles/nm.dir/srcs/error.c.s

CMakeFiles/nm.dir/srcs/error.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/error.c.o.requires

CMakeFiles/nm.dir/srcs/error.c.o.provides: CMakeFiles/nm.dir/srcs/error.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/error.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/error.c.o.provides

CMakeFiles/nm.dir/srcs/error.c.o.provides.build: CMakeFiles/nm.dir/srcs/error.c.o


CMakeFiles/nm.dir/srcs/handle_64.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/handle_64.c.o: ../srcs/handle_64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/nm.dir/srcs/handle_64.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/handle_64.c.o   -c /Users/nle-bret/project/nm/srcs/handle_64.c

CMakeFiles/nm.dir/srcs/handle_64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/handle_64.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/handle_64.c > CMakeFiles/nm.dir/srcs/handle_64.c.i

CMakeFiles/nm.dir/srcs/handle_64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/handle_64.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/handle_64.c -o CMakeFiles/nm.dir/srcs/handle_64.c.s

CMakeFiles/nm.dir/srcs/handle_64.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/handle_64.c.o.requires

CMakeFiles/nm.dir/srcs/handle_64.c.o.provides: CMakeFiles/nm.dir/srcs/handle_64.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/handle_64.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/handle_64.c.o.provides

CMakeFiles/nm.dir/srcs/handle_64.c.o.provides.build: CMakeFiles/nm.dir/srcs/handle_64.c.o


CMakeFiles/nm.dir/srcs/handle_32.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/handle_32.c.o: ../srcs/handle_32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/nm.dir/srcs/handle_32.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/handle_32.c.o   -c /Users/nle-bret/project/nm/srcs/handle_32.c

CMakeFiles/nm.dir/srcs/handle_32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/handle_32.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/handle_32.c > CMakeFiles/nm.dir/srcs/handle_32.c.i

CMakeFiles/nm.dir/srcs/handle_32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/handle_32.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/handle_32.c -o CMakeFiles/nm.dir/srcs/handle_32.c.s

CMakeFiles/nm.dir/srcs/handle_32.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/handle_32.c.o.requires

CMakeFiles/nm.dir/srcs/handle_32.c.o.provides: CMakeFiles/nm.dir/srcs/handle_32.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/handle_32.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/handle_32.c.o.provides

CMakeFiles/nm.dir/srcs/handle_32.c.o.provides.build: CMakeFiles/nm.dir/srcs/handle_32.c.o


CMakeFiles/nm.dir/srcs/print_64.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/print_64.c.o: ../srcs/print_64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/nm.dir/srcs/print_64.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/print_64.c.o   -c /Users/nle-bret/project/nm/srcs/print_64.c

CMakeFiles/nm.dir/srcs/print_64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/print_64.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/print_64.c > CMakeFiles/nm.dir/srcs/print_64.c.i

CMakeFiles/nm.dir/srcs/print_64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/print_64.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/print_64.c -o CMakeFiles/nm.dir/srcs/print_64.c.s

CMakeFiles/nm.dir/srcs/print_64.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/print_64.c.o.requires

CMakeFiles/nm.dir/srcs/print_64.c.o.provides: CMakeFiles/nm.dir/srcs/print_64.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/print_64.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/print_64.c.o.provides

CMakeFiles/nm.dir/srcs/print_64.c.o.provides.build: CMakeFiles/nm.dir/srcs/print_64.c.o


CMakeFiles/nm.dir/srcs/print_32.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/print_32.c.o: ../srcs/print_32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/nm.dir/srcs/print_32.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/print_32.c.o   -c /Users/nle-bret/project/nm/srcs/print_32.c

CMakeFiles/nm.dir/srcs/print_32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/print_32.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/print_32.c > CMakeFiles/nm.dir/srcs/print_32.c.i

CMakeFiles/nm.dir/srcs/print_32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/print_32.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/print_32.c -o CMakeFiles/nm.dir/srcs/print_32.c.s

CMakeFiles/nm.dir/srcs/print_32.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/print_32.c.o.requires

CMakeFiles/nm.dir/srcs/print_32.c.o.provides: CMakeFiles/nm.dir/srcs/print_32.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/print_32.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/print_32.c.o.provides

CMakeFiles/nm.dir/srcs/print_32.c.o.provides.build: CMakeFiles/nm.dir/srcs/print_32.c.o


CMakeFiles/nm.dir/srcs/print_type.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/print_type.c.o: ../srcs/print_type.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/nm.dir/srcs/print_type.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/print_type.c.o   -c /Users/nle-bret/project/nm/srcs/print_type.c

CMakeFiles/nm.dir/srcs/print_type.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/print_type.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/print_type.c > CMakeFiles/nm.dir/srcs/print_type.c.i

CMakeFiles/nm.dir/srcs/print_type.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/print_type.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/print_type.c -o CMakeFiles/nm.dir/srcs/print_type.c.s

CMakeFiles/nm.dir/srcs/print_type.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/print_type.c.o.requires

CMakeFiles/nm.dir/srcs/print_type.c.o.provides: CMakeFiles/nm.dir/srcs/print_type.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/print_type.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/print_type.c.o.provides

CMakeFiles/nm.dir/srcs/print_type.c.o.provides.build: CMakeFiles/nm.dir/srcs/print_type.c.o


CMakeFiles/nm.dir/srcs/debug.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/debug.c.o: ../srcs/debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/nm.dir/srcs/debug.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/debug.c.o   -c /Users/nle-bret/project/nm/srcs/debug.c

CMakeFiles/nm.dir/srcs/debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/debug.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/debug.c > CMakeFiles/nm.dir/srcs/debug.c.i

CMakeFiles/nm.dir/srcs/debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/debug.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/debug.c -o CMakeFiles/nm.dir/srcs/debug.c.s

CMakeFiles/nm.dir/srcs/debug.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/debug.c.o.requires

CMakeFiles/nm.dir/srcs/debug.c.o.provides: CMakeFiles/nm.dir/srcs/debug.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/debug.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/debug.c.o.provides

CMakeFiles/nm.dir/srcs/debug.c.o.provides.build: CMakeFiles/nm.dir/srcs/debug.c.o


CMakeFiles/nm.dir/srcs/util.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/util.c.o: ../srcs/util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/nm.dir/srcs/util.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/util.c.o   -c /Users/nle-bret/project/nm/srcs/util.c

CMakeFiles/nm.dir/srcs/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/util.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/util.c > CMakeFiles/nm.dir/srcs/util.c.i

CMakeFiles/nm.dir/srcs/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/util.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/util.c -o CMakeFiles/nm.dir/srcs/util.c.s

CMakeFiles/nm.dir/srcs/util.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/util.c.o.requires

CMakeFiles/nm.dir/srcs/util.c.o.provides: CMakeFiles/nm.dir/srcs/util.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/util.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/util.c.o.provides

CMakeFiles/nm.dir/srcs/util.c.o.provides.build: CMakeFiles/nm.dir/srcs/util.c.o


CMakeFiles/nm.dir/srcs/handle_fat.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/handle_fat.c.o: ../srcs/handle_fat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/nm.dir/srcs/handle_fat.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/handle_fat.c.o   -c /Users/nle-bret/project/nm/srcs/handle_fat.c

CMakeFiles/nm.dir/srcs/handle_fat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/handle_fat.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/handle_fat.c > CMakeFiles/nm.dir/srcs/handle_fat.c.i

CMakeFiles/nm.dir/srcs/handle_fat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/handle_fat.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/handle_fat.c -o CMakeFiles/nm.dir/srcs/handle_fat.c.s

CMakeFiles/nm.dir/srcs/handle_fat.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/handle_fat.c.o.requires

CMakeFiles/nm.dir/srcs/handle_fat.c.o.provides: CMakeFiles/nm.dir/srcs/handle_fat.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/handle_fat.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/handle_fat.c.o.provides

CMakeFiles/nm.dir/srcs/handle_fat.c.o.provides.build: CMakeFiles/nm.dir/srcs/handle_fat.c.o


CMakeFiles/nm.dir/srcs/handle_ar.c.o: CMakeFiles/nm.dir/flags.make
CMakeFiles/nm.dir/srcs/handle_ar.c.o: ../srcs/handle_ar.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/nm.dir/srcs/handle_ar.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nm.dir/srcs/handle_ar.c.o   -c /Users/nle-bret/project/nm/srcs/handle_ar.c

CMakeFiles/nm.dir/srcs/handle_ar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nm.dir/srcs/handle_ar.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/nm/srcs/handle_ar.c > CMakeFiles/nm.dir/srcs/handle_ar.c.i

CMakeFiles/nm.dir/srcs/handle_ar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nm.dir/srcs/handle_ar.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/nm/srcs/handle_ar.c -o CMakeFiles/nm.dir/srcs/handle_ar.c.s

CMakeFiles/nm.dir/srcs/handle_ar.c.o.requires:

.PHONY : CMakeFiles/nm.dir/srcs/handle_ar.c.o.requires

CMakeFiles/nm.dir/srcs/handle_ar.c.o.provides: CMakeFiles/nm.dir/srcs/handle_ar.c.o.requires
	$(MAKE) -f CMakeFiles/nm.dir/build.make CMakeFiles/nm.dir/srcs/handle_ar.c.o.provides.build
.PHONY : CMakeFiles/nm.dir/srcs/handle_ar.c.o.provides

CMakeFiles/nm.dir/srcs/handle_ar.c.o.provides.build: CMakeFiles/nm.dir/srcs/handle_ar.c.o


# Object files for target nm
nm_OBJECTS = \
"CMakeFiles/nm.dir/srcs/ft_nm.c.o" \
"CMakeFiles/nm.dir/srcs/error.c.o" \
"CMakeFiles/nm.dir/srcs/handle_64.c.o" \
"CMakeFiles/nm.dir/srcs/handle_32.c.o" \
"CMakeFiles/nm.dir/srcs/print_64.c.o" \
"CMakeFiles/nm.dir/srcs/print_32.c.o" \
"CMakeFiles/nm.dir/srcs/print_type.c.o" \
"CMakeFiles/nm.dir/srcs/debug.c.o" \
"CMakeFiles/nm.dir/srcs/util.c.o" \
"CMakeFiles/nm.dir/srcs/handle_fat.c.o" \
"CMakeFiles/nm.dir/srcs/handle_ar.c.o"

# External object files for target nm
nm_EXTERNAL_OBJECTS =

nm: CMakeFiles/nm.dir/srcs/ft_nm.c.o
nm: CMakeFiles/nm.dir/srcs/error.c.o
nm: CMakeFiles/nm.dir/srcs/handle_64.c.o
nm: CMakeFiles/nm.dir/srcs/handle_32.c.o
nm: CMakeFiles/nm.dir/srcs/print_64.c.o
nm: CMakeFiles/nm.dir/srcs/print_32.c.o
nm: CMakeFiles/nm.dir/srcs/print_type.c.o
nm: CMakeFiles/nm.dir/srcs/debug.c.o
nm: CMakeFiles/nm.dir/srcs/util.c.o
nm: CMakeFiles/nm.dir/srcs/handle_fat.c.o
nm: CMakeFiles/nm.dir/srcs/handle_ar.c.o
nm: CMakeFiles/nm.dir/build.make
nm: libft/libft.a
nm: CMakeFiles/nm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable nm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nm.dir/build: nm

.PHONY : CMakeFiles/nm.dir/build

CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/ft_nm.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/error.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/handle_64.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/handle_32.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/print_64.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/print_32.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/print_type.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/debug.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/util.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/handle_fat.c.o.requires
CMakeFiles/nm.dir/requires: CMakeFiles/nm.dir/srcs/handle_ar.c.o.requires

.PHONY : CMakeFiles/nm.dir/requires

CMakeFiles/nm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nm.dir/clean

CMakeFiles/nm.dir/depend:
	cd /Users/nle-bret/project/nm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nle-bret/project/nm /Users/nle-bret/project/nm /Users/nle-bret/project/nm/cmake-build-debug /Users/nle-bret/project/nm/cmake-build-debug /Users/nle-bret/project/nm/cmake-build-debug/CMakeFiles/nm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nm.dir/depend

