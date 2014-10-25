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
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.12.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.12.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.12.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Leonard/Documents/Programming/C++/GameEngine3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Leonard/Documents/Programming/C++/GameEngine3D

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/2.8.12.2/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/2.8.12.2/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Leonard/Documents/Programming/C++/GameEngine3D/CMakeFiles /Users/Leonard/Documents/Programming/C++/GameEngine3D/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Leonard/Documents/Programming/C++/GameEngine3D/CMakeFiles 0
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
# Target rules for targets named 3D_Game_Engine

# Build rule for target.
3D_Game_Engine: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 3D_Game_Engine
.PHONY : 3D_Game_Engine

# fast build rule for target.
3D_Game_Engine/fast:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/build
.PHONY : 3D_Game_Engine/fast

src/core/core_engine.o: src/core/core_engine.cpp.o
.PHONY : src/core/core_engine.o

# target to build an object file
src/core/core_engine.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/core_engine.cpp.o
.PHONY : src/core/core_engine.cpp.o

src/core/core_engine.i: src/core/core_engine.cpp.i
.PHONY : src/core/core_engine.i

# target to preprocess a source file
src/core/core_engine.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/core_engine.cpp.i
.PHONY : src/core/core_engine.cpp.i

src/core/core_engine.s: src/core/core_engine.cpp.s
.PHONY : src/core/core_engine.s

# target to generate assembly for a file
src/core/core_engine.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/core_engine.cpp.s
.PHONY : src/core/core_engine.cpp.s

src/core/input.o: src/core/input.cpp.o
.PHONY : src/core/input.o

# target to build an object file
src/core/input.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/input.cpp.o
.PHONY : src/core/input.cpp.o

src/core/input.i: src/core/input.cpp.i
.PHONY : src/core/input.i

# target to preprocess a source file
src/core/input.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/input.cpp.i
.PHONY : src/core/input.cpp.i

src/core/input.s: src/core/input.cpp.s
.PHONY : src/core/input.s

# target to generate assembly for a file
src/core/input.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/input.cpp.s
.PHONY : src/core/input.cpp.s

src/core/math.o: src/core/math.cpp.o
.PHONY : src/core/math.o

# target to build an object file
src/core/math.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/math.cpp.o
.PHONY : src/core/math.cpp.o

src/core/math.i: src/core/math.cpp.i
.PHONY : src/core/math.i

# target to preprocess a source file
src/core/math.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/math.cpp.i
.PHONY : src/core/math.cpp.i

src/core/math.s: src/core/math.cpp.s
.PHONY : src/core/math.s

# target to generate assembly for a file
src/core/math.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/core/math.cpp.s
.PHONY : src/core/math.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/rendering/mesh.o: src/rendering/mesh.cpp.o
.PHONY : src/rendering/mesh.o

# target to build an object file
src/rendering/mesh.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/mesh.cpp.o
.PHONY : src/rendering/mesh.cpp.o

src/rendering/mesh.i: src/rendering/mesh.cpp.i
.PHONY : src/rendering/mesh.i

# target to preprocess a source file
src/rendering/mesh.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/mesh.cpp.i
.PHONY : src/rendering/mesh.cpp.i

src/rendering/mesh.s: src/rendering/mesh.cpp.s
.PHONY : src/rendering/mesh.s

# target to generate assembly for a file
src/rendering/mesh.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/mesh.cpp.s
.PHONY : src/rendering/mesh.cpp.s

src/rendering/rendering_engine.o: src/rendering/rendering_engine.cpp.o
.PHONY : src/rendering/rendering_engine.o

# target to build an object file
src/rendering/rendering_engine.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/rendering_engine.cpp.o
.PHONY : src/rendering/rendering_engine.cpp.o

src/rendering/rendering_engine.i: src/rendering/rendering_engine.cpp.i
.PHONY : src/rendering/rendering_engine.i

# target to preprocess a source file
src/rendering/rendering_engine.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/rendering_engine.cpp.i
.PHONY : src/rendering/rendering_engine.cpp.i

src/rendering/rendering_engine.s: src/rendering/rendering_engine.cpp.s
.PHONY : src/rendering/rendering_engine.s

# target to generate assembly for a file
src/rendering/rendering_engine.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/rendering_engine.cpp.s
.PHONY : src/rendering/rendering_engine.cpp.s

src/rendering/shader.o: src/rendering/shader.cpp.o
.PHONY : src/rendering/shader.o

# target to build an object file
src/rendering/shader.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/shader.cpp.o
.PHONY : src/rendering/shader.cpp.o

src/rendering/shader.i: src/rendering/shader.cpp.i
.PHONY : src/rendering/shader.i

# target to preprocess a source file
src/rendering/shader.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/shader.cpp.i
.PHONY : src/rendering/shader.cpp.i

src/rendering/shader.s: src/rendering/shader.cpp.s
.PHONY : src/rendering/shader.s

# target to generate assembly for a file
src/rendering/shader.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/shader.cpp.s
.PHONY : src/rendering/shader.cpp.s

src/rendering/window.o: src/rendering/window.cpp.o
.PHONY : src/rendering/window.o

# target to build an object file
src/rendering/window.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/window.cpp.o
.PHONY : src/rendering/window.cpp.o

src/rendering/window.i: src/rendering/window.cpp.i
.PHONY : src/rendering/window.i

# target to preprocess a source file
src/rendering/window.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/window.cpp.i
.PHONY : src/rendering/window.cpp.i

src/rendering/window.s: src/rendering/window.cpp.s
.PHONY : src/rendering/window.s

# target to generate assembly for a file
src/rendering/window.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/rendering/window.cpp.s
.PHONY : src/rendering/window.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... 3D_Game_Engine"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... src/core/core_engine.o"
	@echo "... src/core/core_engine.i"
	@echo "... src/core/core_engine.s"
	@echo "... src/core/input.o"
	@echo "... src/core/input.i"
	@echo "... src/core/input.s"
	@echo "... src/core/math.o"
	@echo "... src/core/math.i"
	@echo "... src/core/math.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/rendering/mesh.o"
	@echo "... src/rendering/mesh.i"
	@echo "... src/rendering/mesh.s"
	@echo "... src/rendering/rendering_engine.o"
	@echo "... src/rendering/rendering_engine.i"
	@echo "... src/rendering/rendering_engine.s"
	@echo "... src/rendering/shader.o"
	@echo "... src/rendering/shader.i"
	@echo "... src/rendering/shader.s"
	@echo "... src/rendering/window.o"
	@echo "... src/rendering/window.i"
	@echo "... src/rendering/window.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

