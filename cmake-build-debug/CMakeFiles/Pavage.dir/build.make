# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\coren\CLionProjects\Pavage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\coren\CLionProjects\Pavage\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pavage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Pavage.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Pavage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pavage.dir/flags.make

CMakeFiles/Pavage.dir/main.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/main.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/main.c.obj: C:/Users/coren/CLionProjects/Pavage/main.c
CMakeFiles/Pavage.dir/main.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Pavage.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/main.c.obj -MF CMakeFiles\Pavage.dir\main.c.obj.d -o CMakeFiles\Pavage.dir\main.c.obj -c C:\Users\coren\CLionProjects\Pavage\main.c

CMakeFiles/Pavage.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\main.c > CMakeFiles\Pavage.dir\main.c.i

CMakeFiles/Pavage.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\main.c -o CMakeFiles\Pavage.dir\main.c.s

CMakeFiles/Pavage.dir/engine/input.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/engine/input.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/engine/input.c.obj: C:/Users/coren/CLionProjects/Pavage/engine/input.c
CMakeFiles/Pavage.dir/engine/input.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Pavage.dir/engine/input.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/engine/input.c.obj -MF CMakeFiles\Pavage.dir\engine\input.c.obj.d -o CMakeFiles\Pavage.dir\engine\input.c.obj -c C:\Users\coren\CLionProjects\Pavage\engine\input.c

CMakeFiles/Pavage.dir/engine/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/engine/input.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\engine\input.c > CMakeFiles\Pavage.dir\engine\input.c.i

CMakeFiles/Pavage.dir/engine/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/engine/input.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\engine\input.c -o CMakeFiles\Pavage.dir\engine\input.c.s

CMakeFiles/Pavage.dir/game/game.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/game/game.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/game/game.c.obj: C:/Users/coren/CLionProjects/Pavage/game/game.c
CMakeFiles/Pavage.dir/game/game.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Pavage.dir/game/game.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/game/game.c.obj -MF CMakeFiles\Pavage.dir\game\game.c.obj.d -o CMakeFiles\Pavage.dir\game\game.c.obj -c C:\Users\coren\CLionProjects\Pavage\game\game.c

CMakeFiles/Pavage.dir/game/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/game/game.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\game\game.c > CMakeFiles\Pavage.dir\game\game.c.i

CMakeFiles/Pavage.dir/game/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/game/game.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\game\game.c -o CMakeFiles\Pavage.dir\game\game.c.s

CMakeFiles/Pavage.dir/engine/window.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/engine/window.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/engine/window.c.obj: C:/Users/coren/CLionProjects/Pavage/engine/window.c
CMakeFiles/Pavage.dir/engine/window.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Pavage.dir/engine/window.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/engine/window.c.obj -MF CMakeFiles\Pavage.dir\engine\window.c.obj.d -o CMakeFiles\Pavage.dir\engine\window.c.obj -c C:\Users\coren\CLionProjects\Pavage\engine\window.c

CMakeFiles/Pavage.dir/engine/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/engine/window.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\engine\window.c > CMakeFiles\Pavage.dir\engine\window.c.i

CMakeFiles/Pavage.dir/engine/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/engine/window.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\engine\window.c -o CMakeFiles\Pavage.dir\engine\window.c.s

CMakeFiles/Pavage.dir/engine/renderer.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/engine/renderer.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/engine/renderer.c.obj: C:/Users/coren/CLionProjects/Pavage/engine/renderer.c
CMakeFiles/Pavage.dir/engine/renderer.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Pavage.dir/engine/renderer.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/engine/renderer.c.obj -MF CMakeFiles\Pavage.dir\engine\renderer.c.obj.d -o CMakeFiles\Pavage.dir\engine\renderer.c.obj -c C:\Users\coren\CLionProjects\Pavage\engine\renderer.c

CMakeFiles/Pavage.dir/engine/renderer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/engine/renderer.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\engine\renderer.c > CMakeFiles\Pavage.dir\engine\renderer.c.i

CMakeFiles/Pavage.dir/engine/renderer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/engine/renderer.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\engine\renderer.c -o CMakeFiles\Pavage.dir\engine\renderer.c.s

CMakeFiles/Pavage.dir/engine/object.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/engine/object.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/engine/object.c.obj: C:/Users/coren/CLionProjects/Pavage/engine/object.c
CMakeFiles/Pavage.dir/engine/object.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Pavage.dir/engine/object.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/engine/object.c.obj -MF CMakeFiles\Pavage.dir\engine\object.c.obj.d -o CMakeFiles\Pavage.dir\engine\object.c.obj -c C:\Users\coren\CLionProjects\Pavage\engine\object.c

CMakeFiles/Pavage.dir/engine/object.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/engine/object.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\engine\object.c > CMakeFiles\Pavage.dir\engine\object.c.i

CMakeFiles/Pavage.dir/engine/object.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/engine/object.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\engine\object.c -o CMakeFiles\Pavage.dir\engine\object.c.s

CMakeFiles/Pavage.dir/engine/scene.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/engine/scene.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/engine/scene.c.obj: C:/Users/coren/CLionProjects/Pavage/engine/scene.c
CMakeFiles/Pavage.dir/engine/scene.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Pavage.dir/engine/scene.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/engine/scene.c.obj -MF CMakeFiles\Pavage.dir\engine\scene.c.obj.d -o CMakeFiles\Pavage.dir\engine\scene.c.obj -c C:\Users\coren\CLionProjects\Pavage\engine\scene.c

CMakeFiles/Pavage.dir/engine/scene.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/engine/scene.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\engine\scene.c > CMakeFiles\Pavage.dir\engine\scene.c.i

CMakeFiles/Pavage.dir/engine/scene.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/engine/scene.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\engine\scene.c -o CMakeFiles\Pavage.dir\engine\scene.c.s

CMakeFiles/Pavage.dir/engine/file.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/engine/file.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/engine/file.c.obj: C:/Users/coren/CLionProjects/Pavage/engine/file.c
CMakeFiles/Pavage.dir/engine/file.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Pavage.dir/engine/file.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/engine/file.c.obj -MF CMakeFiles\Pavage.dir\engine\file.c.obj.d -o CMakeFiles\Pavage.dir\engine\file.c.obj -c C:\Users\coren\CLionProjects\Pavage\engine\file.c

CMakeFiles/Pavage.dir/engine/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/engine/file.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\engine\file.c > CMakeFiles\Pavage.dir\engine\file.c.i

CMakeFiles/Pavage.dir/engine/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/engine/file.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\engine\file.c -o CMakeFiles\Pavage.dir\engine\file.c.s

CMakeFiles/Pavage.dir/engine/button.c.obj: CMakeFiles/Pavage.dir/flags.make
CMakeFiles/Pavage.dir/engine/button.c.obj: CMakeFiles/Pavage.dir/includes_C.rsp
CMakeFiles/Pavage.dir/engine/button.c.obj: C:/Users/coren/CLionProjects/Pavage/engine/button.c
CMakeFiles/Pavage.dir/engine/button.c.obj: CMakeFiles/Pavage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Pavage.dir/engine/button.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pavage.dir/engine/button.c.obj -MF CMakeFiles\Pavage.dir\engine\button.c.obj.d -o CMakeFiles\Pavage.dir\engine\button.c.obj -c C:\Users\coren\CLionProjects\Pavage\engine\button.c

CMakeFiles/Pavage.dir/engine/button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pavage.dir/engine/button.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\coren\CLionProjects\Pavage\engine\button.c > CMakeFiles\Pavage.dir\engine\button.c.i

CMakeFiles/Pavage.dir/engine/button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pavage.dir/engine/button.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\coren\CLionProjects\Pavage\engine\button.c -o CMakeFiles\Pavage.dir\engine\button.c.s

# Object files for target Pavage
Pavage_OBJECTS = \
"CMakeFiles/Pavage.dir/main.c.obj" \
"CMakeFiles/Pavage.dir/engine/input.c.obj" \
"CMakeFiles/Pavage.dir/game/game.c.obj" \
"CMakeFiles/Pavage.dir/engine/window.c.obj" \
"CMakeFiles/Pavage.dir/engine/renderer.c.obj" \
"CMakeFiles/Pavage.dir/engine/object.c.obj" \
"CMakeFiles/Pavage.dir/engine/scene.c.obj" \
"CMakeFiles/Pavage.dir/engine/file.c.obj" \
"CMakeFiles/Pavage.dir/engine/button.c.obj"

# External object files for target Pavage
Pavage_EXTERNAL_OBJECTS =

Pavage.exe: CMakeFiles/Pavage.dir/main.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/engine/input.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/game/game.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/engine/window.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/engine/renderer.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/engine/object.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/engine/scene.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/engine/file.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/engine/button.c.obj
Pavage.exe: CMakeFiles/Pavage.dir/build.make
Pavage.exe: CMakeFiles/Pavage.dir/linkLibs.rsp
Pavage.exe: CMakeFiles/Pavage.dir/objects1.rsp
Pavage.exe: CMakeFiles/Pavage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable Pavage.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Pavage.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E copy C:/Users/coren/CLionProjects/Pavage/bin/x64/SDL2.dll C:/Users/coren/CLionProjects/Pavage/cmake-build-debug/.
	"C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E copy C:/Users/coren/CLionProjects/Pavage/bin/x64/SDL2_ttf.dll C:/Users/coren/CLionProjects/Pavage/cmake-build-debug/.
	"C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E copy_directory C:/Users/coren/CLionProjects/Pavage/resources C:/Users/coren/CLionProjects/Pavage/cmake-build-debug/resources

# Rule to build all files generated by this target.
CMakeFiles/Pavage.dir/build: Pavage.exe
.PHONY : CMakeFiles/Pavage.dir/build

CMakeFiles/Pavage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Pavage.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Pavage.dir/clean

CMakeFiles/Pavage.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\coren\CLionProjects\Pavage C:\Users\coren\CLionProjects\Pavage C:\Users\coren\CLionProjects\Pavage\cmake-build-debug C:\Users\coren\CLionProjects\Pavage\cmake-build-debug C:\Users\coren\CLionProjects\Pavage\cmake-build-debug\CMakeFiles\Pavage.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Pavage.dir/depend

