cmake_minimum_required(VERSION 3.22)
project(Pavage C)

set(CMAKE_C_STANDARD 99)

# region SDL2 generic configuration
set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/x64")
    set(SDL2_DYNAMIC_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/bin/x64")
else ()
    set(SDL2_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/x86")
    set(SDL2_DYNAMIC_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/bin/x86")
endif ()

set(SDL2_LIBRARIES SDL2main SDL2)
set(SDL2_DYNAMIC_LIB "SDL2.dll")

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
#endregion

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARIES_DIR})
link_libraries(mingw32 ${SDL2_LIBRARIES})

add_executable(Pavage main.c
        game/constants.h
        engine/input.c
        engine/input.h
        game/game.c
        game/game.h
        engine/window.c
        engine/window.h
        engine/renderer.c
        engine/renderer.h
        engine/object.c
        engine/object.h
        engine/scene.c
        engine/scene.h
        engine/objectdata.h
)

# Copy the right DLL into the cmake-build-debug folder
add_custom_command(TARGET Pavage
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${SDL2_DYNAMIC_LIB_DIR}/${SDL2_DYNAMIC_LIB}" ${CMAKE_BINARY_DIR}/.
)

# Copy resources folder into the cmake-build-debug folder
add_custom_command(TARGET Pavage
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/resources" "${CMAKE_BINARY_DIR}/resources"
)