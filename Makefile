# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/myproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/myproject

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /root/myproject/CMakeFiles /root/myproject/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /root/myproject/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ./bin/hellomake

# Build rule for target.
./bin/hellomake: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ./bin/hellomake
.PHONY : ./bin/hellomake

# fast build rule for target.
./bin/hellomake/fast:
	$(MAKE) -f CMakeFiles/./bin/hellomake.dir/build.make CMakeFiles/./bin/hellomake.dir/build
.PHONY : ./bin/hellomake/fast

#=============================================================================
# Target rules for targets named log

# Build rule for target.
log: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 log
.PHONY : log

# fast build rule for target.
log/fast:
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/build
.PHONY : log/fast

src/log.o: src/log.cpp.o
.PHONY : src/log.o

# target to build an object file
src/log.cpp.o:
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/src/log.cpp.o
.PHONY : src/log.cpp.o

src/log.i: src/log.cpp.i
.PHONY : src/log.i

# target to preprocess a source file
src/log.cpp.i:
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/src/log.cpp.i
.PHONY : src/log.cpp.i

src/log.s: src/log.cpp.s
.PHONY : src/log.s

# target to generate assembly for a file
src/log.cpp.s:
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/src/log.cpp.s
.PHONY : src/log.cpp.s

src/testlog.o: src/testlog.cpp.o
.PHONY : src/testlog.o

# target to build an object file
src/testlog.cpp.o:
	$(MAKE) -f CMakeFiles/./bin/hellomake.dir/build.make CMakeFiles/./bin/hellomake.dir/src/testlog.cpp.o
.PHONY : src/testlog.cpp.o

src/testlog.i: src/testlog.cpp.i
.PHONY : src/testlog.i

# target to preprocess a source file
src/testlog.cpp.i:
	$(MAKE) -f CMakeFiles/./bin/hellomake.dir/build.make CMakeFiles/./bin/hellomake.dir/src/testlog.cpp.i
.PHONY : src/testlog.cpp.i

src/testlog.s: src/testlog.cpp.s
.PHONY : src/testlog.s

# target to generate assembly for a file
src/testlog.cpp.s:
	$(MAKE) -f CMakeFiles/./bin/hellomake.dir/build.make CMakeFiles/./bin/hellomake.dir/src/testlog.cpp.s
.PHONY : src/testlog.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... ./bin/hellomake"
	@echo "... edit_cache"
	@echo "... log"
	@echo "... rebuild_cache"
	@echo "... src/log.o"
	@echo "... src/log.i"
	@echo "... src/log.s"
	@echo "... src/testlog.o"
	@echo "... src/testlog.i"
	@echo "... src/testlog.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
