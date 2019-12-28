# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stephen/Documents/Warwick/cs324/3d_tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stephen/Documents/Warwick/cs324/3d_tetris

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.15.5/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.15.5/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/stephen/Documents/Warwick/cs324/3d_tetris/CMakeFiles /Users/stephen/Documents/Warwick/cs324/3d_tetris/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/stephen/Documents/Warwick/cs324/3d_tetris/CMakeFiles 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named coursework

# Build rule for target.
coursework: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 coursework
.PHONY : coursework

# fast build rule for target.
coursework/fast:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/build
.PHONY : coursework/fast

Block.o: Block.cpp.o

.PHONY : Block.o

# target to build an object file
Block.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Block.cpp.o
.PHONY : Block.cpp.o

Block.i: Block.cpp.i

.PHONY : Block.i

# target to preprocess a source file
Block.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Block.cpp.i
.PHONY : Block.cpp.i

Block.s: Block.cpp.s

.PHONY : Block.s

# target to generate assembly for a file
Block.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Block.cpp.s
.PHONY : Block.cpp.s

Button.o: Button.cpp.o

.PHONY : Button.o

# target to build an object file
Button.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Button.cpp.o
.PHONY : Button.cpp.o

Button.i: Button.cpp.i

.PHONY : Button.i

# target to preprocess a source file
Button.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Button.cpp.i
.PHONY : Button.cpp.i

Button.s: Button.cpp.s

.PHONY : Button.s

# target to generate assembly for a file
Button.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Button.cpp.s
.PHONY : Button.cpp.s

Control.o: Control.cpp.o

.PHONY : Control.o

# target to build an object file
Control.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Control.cpp.o
.PHONY : Control.cpp.o

Control.i: Control.cpp.i

.PHONY : Control.i

# target to preprocess a source file
Control.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Control.cpp.i
.PHONY : Control.cpp.i

Control.s: Control.cpp.s

.PHONY : Control.s

# target to generate assembly for a file
Control.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Control.cpp.s
.PHONY : Control.cpp.s

Game.o: Game.cpp.o

.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i

.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s

.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Game.cpp.s
.PHONY : Game.cpp.s

Level.o: Level.cpp.o

.PHONY : Level.o

# target to build an object file
Level.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Level.cpp.o
.PHONY : Level.cpp.o

Level.i: Level.cpp.i

.PHONY : Level.i

# target to preprocess a source file
Level.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Level.cpp.i
.PHONY : Level.cpp.i

Level.s: Level.cpp.s

.PHONY : Level.s

# target to generate assembly for a file
Level.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Level.cpp.s
.PHONY : Level.cpp.s

Scene.o: Scene.cpp.o

.PHONY : Scene.o

# target to build an object file
Scene.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Scene.cpp.o
.PHONY : Scene.cpp.o

Scene.i: Scene.cpp.i

.PHONY : Scene.i

# target to preprocess a source file
Scene.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Scene.cpp.i
.PHONY : Scene.cpp.i

Scene.s: Scene.cpp.s

.PHONY : Scene.s

# target to generate assembly for a file
Scene.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Scene.cpp.s
.PHONY : Scene.cpp.s

Utility.o: Utility.cpp.o

.PHONY : Utility.o

# target to build an object file
Utility.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Utility.cpp.o
.PHONY : Utility.cpp.o

Utility.i: Utility.cpp.i

.PHONY : Utility.i

# target to preprocess a source file
Utility.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Utility.cpp.i
.PHONY : Utility.cpp.i

Utility.s: Utility.cpp.s

.PHONY : Utility.s

# target to generate assembly for a file
Utility.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/Utility.cpp.s
.PHONY : Utility.cpp.s

coursework.o: coursework.cpp.o

.PHONY : coursework.o

# target to build an object file
coursework.cpp.o:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/coursework.cpp.o
.PHONY : coursework.cpp.o

coursework.i: coursework.cpp.i

.PHONY : coursework.i

# target to preprocess a source file
coursework.cpp.i:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/coursework.cpp.i
.PHONY : coursework.cpp.i

coursework.s: coursework.cpp.s

.PHONY : coursework.s

# target to generate assembly for a file
coursework.cpp.s:
	$(MAKE) -f CMakeFiles/coursework.dir/build.make CMakeFiles/coursework.dir/coursework.cpp.s
.PHONY : coursework.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... coursework"
	@echo "... Block.o"
	@echo "... Block.i"
	@echo "... Block.s"
	@echo "... Button.o"
	@echo "... Button.i"
	@echo "... Button.s"
	@echo "... Control.o"
	@echo "... Control.i"
	@echo "... Control.s"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... Level.o"
	@echo "... Level.i"
	@echo "... Level.s"
	@echo "... Scene.o"
	@echo "... Scene.i"
	@echo "... Scene.s"
	@echo "... Utility.o"
	@echo "... Utility.i"
	@echo "... Utility.s"
	@echo "... coursework.o"
	@echo "... coursework.i"
	@echo "... coursework.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

