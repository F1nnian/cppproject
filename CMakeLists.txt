cmake_minimum_required(VERSION 3.10)  # Minimum CMake version required

# Project name and languages
project(CPPProject CXX)

# Include Raylib
set(RAYLIB_DIR "C:/raylib")  # Specify the path to Raylib
include_directories(${RAYLIB_DIR}/raylib/src)
add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES IMPORTED_LOCATION "C:/raylib/raylib/src/libraylib.a")

# Add executable target
file(GLOB SOURCES "src/*.cpp")
add_executable(cppproject ${SOURCES})  # main.cpp is your main source file

# Link Raylib with your executable
target_link_libraries(cppproject raylib)
target_link_libraries(cppproject winmm)
