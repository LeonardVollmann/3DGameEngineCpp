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

src/engine/components/camera_component.o: src/engine/components/camera_component.cpp.o
.PHONY : src/engine/components/camera_component.o

# target to build an object file
src/engine/components/camera_component.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/camera_component.cpp.o
.PHONY : src/engine/components/camera_component.cpp.o

src/engine/components/camera_component.i: src/engine/components/camera_component.cpp.i
.PHONY : src/engine/components/camera_component.i

# target to preprocess a source file
src/engine/components/camera_component.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/camera_component.cpp.i
.PHONY : src/engine/components/camera_component.cpp.i

src/engine/components/camera_component.s: src/engine/components/camera_component.cpp.s
.PHONY : src/engine/components/camera_component.s

# target to generate assembly for a file
src/engine/components/camera_component.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/camera_component.cpp.s
.PHONY : src/engine/components/camera_component.cpp.s

src/engine/components/free_look.o: src/engine/components/free_look.cpp.o
.PHONY : src/engine/components/free_look.o

# target to build an object file
src/engine/components/free_look.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/free_look.cpp.o
.PHONY : src/engine/components/free_look.cpp.o

src/engine/components/free_look.i: src/engine/components/free_look.cpp.i
.PHONY : src/engine/components/free_look.i

# target to preprocess a source file
src/engine/components/free_look.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/free_look.cpp.i
.PHONY : src/engine/components/free_look.cpp.i

src/engine/components/free_look.s: src/engine/components/free_look.cpp.s
.PHONY : src/engine/components/free_look.s

# target to generate assembly for a file
src/engine/components/free_look.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/free_look.cpp.s
.PHONY : src/engine/components/free_look.cpp.s

src/engine/components/free_move.o: src/engine/components/free_move.cpp.o
.PHONY : src/engine/components/free_move.o

# target to build an object file
src/engine/components/free_move.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/free_move.cpp.o
.PHONY : src/engine/components/free_move.cpp.o

src/engine/components/free_move.i: src/engine/components/free_move.cpp.i
.PHONY : src/engine/components/free_move.i

# target to preprocess a source file
src/engine/components/free_move.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/free_move.cpp.i
.PHONY : src/engine/components/free_move.cpp.i

src/engine/components/free_move.s: src/engine/components/free_move.cpp.s
.PHONY : src/engine/components/free_move.s

# target to generate assembly for a file
src/engine/components/free_move.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/free_move.cpp.s
.PHONY : src/engine/components/free_move.cpp.s

src/engine/components/mesh_renderer.o: src/engine/components/mesh_renderer.cpp.o
.PHONY : src/engine/components/mesh_renderer.o

# target to build an object file
src/engine/components/mesh_renderer.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/mesh_renderer.cpp.o
.PHONY : src/engine/components/mesh_renderer.cpp.o

src/engine/components/mesh_renderer.i: src/engine/components/mesh_renderer.cpp.i
.PHONY : src/engine/components/mesh_renderer.i

# target to preprocess a source file
src/engine/components/mesh_renderer.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/mesh_renderer.cpp.i
.PHONY : src/engine/components/mesh_renderer.cpp.i

src/engine/components/mesh_renderer.s: src/engine/components/mesh_renderer.cpp.s
.PHONY : src/engine/components/mesh_renderer.s

# target to generate assembly for a file
src/engine/components/mesh_renderer.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/components/mesh_renderer.cpp.s
.PHONY : src/engine/components/mesh_renderer.cpp.s

src/engine/core/core_engine.o: src/engine/core/core_engine.cpp.o
.PHONY : src/engine/core/core_engine.o

# target to build an object file
src/engine/core/core_engine.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/core_engine.cpp.o
.PHONY : src/engine/core/core_engine.cpp.o

src/engine/core/core_engine.i: src/engine/core/core_engine.cpp.i
.PHONY : src/engine/core/core_engine.i

# target to preprocess a source file
src/engine/core/core_engine.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/core_engine.cpp.i
.PHONY : src/engine/core/core_engine.cpp.i

src/engine/core/core_engine.s: src/engine/core/core_engine.cpp.s
.PHONY : src/engine/core/core_engine.s

# target to generate assembly for a file
src/engine/core/core_engine.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/core_engine.cpp.s
.PHONY : src/engine/core/core_engine.cpp.s

src/engine/core/entity.o: src/engine/core/entity.cpp.o
.PHONY : src/engine/core/entity.o

# target to build an object file
src/engine/core/entity.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/entity.cpp.o
.PHONY : src/engine/core/entity.cpp.o

src/engine/core/entity.i: src/engine/core/entity.cpp.i
.PHONY : src/engine/core/entity.i

# target to preprocess a source file
src/engine/core/entity.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/entity.cpp.i
.PHONY : src/engine/core/entity.cpp.i

src/engine/core/entity.s: src/engine/core/entity.cpp.s
.PHONY : src/engine/core/entity.s

# target to generate assembly for a file
src/engine/core/entity.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/entity.cpp.s
.PHONY : src/engine/core/entity.cpp.s

src/engine/core/input.o: src/engine/core/input.cpp.o
.PHONY : src/engine/core/input.o

# target to build an object file
src/engine/core/input.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/input.cpp.o
.PHONY : src/engine/core/input.cpp.o

src/engine/core/input.i: src/engine/core/input.cpp.i
.PHONY : src/engine/core/input.i

# target to preprocess a source file
src/engine/core/input.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/input.cpp.i
.PHONY : src/engine/core/input.cpp.i

src/engine/core/input.s: src/engine/core/input.cpp.s
.PHONY : src/engine/core/input.s

# target to generate assembly for a file
src/engine/core/input.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/input.cpp.s
.PHONY : src/engine/core/input.cpp.s

src/engine/core/math.o: src/engine/core/math.cpp.o
.PHONY : src/engine/core/math.o

# target to build an object file
src/engine/core/math.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/math.cpp.o
.PHONY : src/engine/core/math.cpp.o

src/engine/core/math.i: src/engine/core/math.cpp.i
.PHONY : src/engine/core/math.i

# target to preprocess a source file
src/engine/core/math.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/math.cpp.i
.PHONY : src/engine/core/math.cpp.i

src/engine/core/math.s: src/engine/core/math.cpp.s
.PHONY : src/engine/core/math.s

# target to generate assembly for a file
src/engine/core/math.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/core/math.cpp.s
.PHONY : src/engine/core/math.cpp.s

src/engine/rendering/basic_shader.o: src/engine/rendering/basic_shader.cpp.o
.PHONY : src/engine/rendering/basic_shader.o

# target to build an object file
src/engine/rendering/basic_shader.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/basic_shader.cpp.o
.PHONY : src/engine/rendering/basic_shader.cpp.o

src/engine/rendering/basic_shader.i: src/engine/rendering/basic_shader.cpp.i
.PHONY : src/engine/rendering/basic_shader.i

# target to preprocess a source file
src/engine/rendering/basic_shader.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/basic_shader.cpp.i
.PHONY : src/engine/rendering/basic_shader.cpp.i

src/engine/rendering/basic_shader.s: src/engine/rendering/basic_shader.cpp.s
.PHONY : src/engine/rendering/basic_shader.s

# target to generate assembly for a file
src/engine/rendering/basic_shader.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/basic_shader.cpp.s
.PHONY : src/engine/rendering/basic_shader.cpp.s

src/engine/rendering/mesh.o: src/engine/rendering/mesh.cpp.o
.PHONY : src/engine/rendering/mesh.o

# target to build an object file
src/engine/rendering/mesh.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/mesh.cpp.o
.PHONY : src/engine/rendering/mesh.cpp.o

src/engine/rendering/mesh.i: src/engine/rendering/mesh.cpp.i
.PHONY : src/engine/rendering/mesh.i

# target to preprocess a source file
src/engine/rendering/mesh.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/mesh.cpp.i
.PHONY : src/engine/rendering/mesh.cpp.i

src/engine/rendering/mesh.s: src/engine/rendering/mesh.cpp.s
.PHONY : src/engine/rendering/mesh.s

# target to generate assembly for a file
src/engine/rendering/mesh.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/mesh.cpp.s
.PHONY : src/engine/rendering/mesh.cpp.s

src/engine/rendering/rendering_engine.o: src/engine/rendering/rendering_engine.cpp.o
.PHONY : src/engine/rendering/rendering_engine.o

# target to build an object file
src/engine/rendering/rendering_engine.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/rendering_engine.cpp.o
.PHONY : src/engine/rendering/rendering_engine.cpp.o

src/engine/rendering/rendering_engine.i: src/engine/rendering/rendering_engine.cpp.i
.PHONY : src/engine/rendering/rendering_engine.i

# target to preprocess a source file
src/engine/rendering/rendering_engine.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/rendering_engine.cpp.i
.PHONY : src/engine/rendering/rendering_engine.cpp.i

src/engine/rendering/rendering_engine.s: src/engine/rendering/rendering_engine.cpp.s
.PHONY : src/engine/rendering/rendering_engine.s

# target to generate assembly for a file
src/engine/rendering/rendering_engine.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/rendering_engine.cpp.s
.PHONY : src/engine/rendering/rendering_engine.cpp.s

src/engine/rendering/shader.o: src/engine/rendering/shader.cpp.o
.PHONY : src/engine/rendering/shader.o

# target to build an object file
src/engine/rendering/shader.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/shader.cpp.o
.PHONY : src/engine/rendering/shader.cpp.o

src/engine/rendering/shader.i: src/engine/rendering/shader.cpp.i
.PHONY : src/engine/rendering/shader.i

# target to preprocess a source file
src/engine/rendering/shader.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/shader.cpp.i
.PHONY : src/engine/rendering/shader.cpp.i

src/engine/rendering/shader.s: src/engine/rendering/shader.cpp.s
.PHONY : src/engine/rendering/shader.s

# target to generate assembly for a file
src/engine/rendering/shader.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/shader.cpp.s
.PHONY : src/engine/rendering/shader.cpp.s

src/engine/rendering/texture.o: src/engine/rendering/texture.cpp.o
.PHONY : src/engine/rendering/texture.o

# target to build an object file
src/engine/rendering/texture.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/texture.cpp.o
.PHONY : src/engine/rendering/texture.cpp.o

src/engine/rendering/texture.i: src/engine/rendering/texture.cpp.i
.PHONY : src/engine/rendering/texture.i

# target to preprocess a source file
src/engine/rendering/texture.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/texture.cpp.i
.PHONY : src/engine/rendering/texture.cpp.i

src/engine/rendering/texture.s: src/engine/rendering/texture.cpp.s
.PHONY : src/engine/rendering/texture.s

# target to generate assembly for a file
src/engine/rendering/texture.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/texture.cpp.s
.PHONY : src/engine/rendering/texture.cpp.s

src/engine/rendering/window.o: src/engine/rendering/window.cpp.o
.PHONY : src/engine/rendering/window.o

# target to build an object file
src/engine/rendering/window.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/window.cpp.o
.PHONY : src/engine/rendering/window.cpp.o

src/engine/rendering/window.i: src/engine/rendering/window.cpp.i
.PHONY : src/engine/rendering/window.i

# target to preprocess a source file
src/engine/rendering/window.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/window.cpp.i
.PHONY : src/engine/rendering/window.cpp.i

src/engine/rendering/window.s: src/engine/rendering/window.cpp.s
.PHONY : src/engine/rendering/window.s

# target to generate assembly for a file
src/engine/rendering/window.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/engine/rendering/window.cpp.s
.PHONY : src/engine/rendering/window.cpp.s

src/game/test_game.o: src/game/test_game.cpp.o
.PHONY : src/game/test_game.o

# target to build an object file
src/game/test_game.cpp.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/game/test_game.cpp.o
.PHONY : src/game/test_game.cpp.o

src/game/test_game.i: src/game/test_game.cpp.i
.PHONY : src/game/test_game.i

# target to preprocess a source file
src/game/test_game.cpp.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/game/test_game.cpp.i
.PHONY : src/game/test_game.cpp.i

src/game/test_game.s: src/game/test_game.cpp.s
.PHONY : src/game/test_game.s

# target to generate assembly for a file
src/game/test_game.cpp.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/game/test_game.cpp.s
.PHONY : src/game/test_game.cpp.s

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

src/static_libs/stb_image.o: src/static_libs/stb_image.c.o
.PHONY : src/static_libs/stb_image.o

# target to build an object file
src/static_libs/stb_image.c.o:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/static_libs/stb_image.c.o
.PHONY : src/static_libs/stb_image.c.o

src/static_libs/stb_image.i: src/static_libs/stb_image.c.i
.PHONY : src/static_libs/stb_image.i

# target to preprocess a source file
src/static_libs/stb_image.c.i:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/static_libs/stb_image.c.i
.PHONY : src/static_libs/stb_image.c.i

src/static_libs/stb_image.s: src/static_libs/stb_image.c.s
.PHONY : src/static_libs/stb_image.s

# target to generate assembly for a file
src/static_libs/stb_image.c.s:
	$(MAKE) -f CMakeFiles/3D_Game_Engine.dir/build.make CMakeFiles/3D_Game_Engine.dir/src/static_libs/stb_image.c.s
.PHONY : src/static_libs/stb_image.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... 3D_Game_Engine"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... src/engine/components/camera_component.o"
	@echo "... src/engine/components/camera_component.i"
	@echo "... src/engine/components/camera_component.s"
	@echo "... src/engine/components/free_look.o"
	@echo "... src/engine/components/free_look.i"
	@echo "... src/engine/components/free_look.s"
	@echo "... src/engine/components/free_move.o"
	@echo "... src/engine/components/free_move.i"
	@echo "... src/engine/components/free_move.s"
	@echo "... src/engine/components/mesh_renderer.o"
	@echo "... src/engine/components/mesh_renderer.i"
	@echo "... src/engine/components/mesh_renderer.s"
	@echo "... src/engine/core/core_engine.o"
	@echo "... src/engine/core/core_engine.i"
	@echo "... src/engine/core/core_engine.s"
	@echo "... src/engine/core/entity.o"
	@echo "... src/engine/core/entity.i"
	@echo "... src/engine/core/entity.s"
	@echo "... src/engine/core/input.o"
	@echo "... src/engine/core/input.i"
	@echo "... src/engine/core/input.s"
	@echo "... src/engine/core/math.o"
	@echo "... src/engine/core/math.i"
	@echo "... src/engine/core/math.s"
	@echo "... src/engine/rendering/basic_shader.o"
	@echo "... src/engine/rendering/basic_shader.i"
	@echo "... src/engine/rendering/basic_shader.s"
	@echo "... src/engine/rendering/mesh.o"
	@echo "... src/engine/rendering/mesh.i"
	@echo "... src/engine/rendering/mesh.s"
	@echo "... src/engine/rendering/rendering_engine.o"
	@echo "... src/engine/rendering/rendering_engine.i"
	@echo "... src/engine/rendering/rendering_engine.s"
	@echo "... src/engine/rendering/shader.o"
	@echo "... src/engine/rendering/shader.i"
	@echo "... src/engine/rendering/shader.s"
	@echo "... src/engine/rendering/texture.o"
	@echo "... src/engine/rendering/texture.i"
	@echo "... src/engine/rendering/texture.s"
	@echo "... src/engine/rendering/window.o"
	@echo "... src/engine/rendering/window.i"
	@echo "... src/engine/rendering/window.s"
	@echo "... src/game/test_game.o"
	@echo "... src/game/test_game.i"
	@echo "... src/game/test_game.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/static_libs/stb_image.o"
	@echo "... src/static_libs/stb_image.i"
	@echo "... src/static_libs/stb_image.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

