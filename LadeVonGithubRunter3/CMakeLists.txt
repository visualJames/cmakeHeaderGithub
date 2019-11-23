# Copyright 2019 André Hodapp
#Um zu bauen:
#cmake -H. -Bbuild && make -C build
#Um nur prog12 zu bauen:
#cmake -H. -B build && make prog12 -C build
#Um das Programm auszuführen
#./build/prog
#Um letztendlich alles zu löschen
#rm -rf build



CMAKE_MINIMUM_REQUIRED(VERSION 3.13)
project(C++Ueben)

set(CMAKE_CXX_STANDARD  14)

#_________________
include(ExternalProject)

ExternalProject_Add(
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
   )

# Expose required variable (CATCH_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(catch source_dir)
set(CATCH_INCLUDE_DIR ${source_dir}/single_include/catch2 CACHE INTERNAL "Path to include folder for Catch")
#_________________



#https://stackoverflow.com/questions/11783932/how-do-i-add-a-linker-or-compile-flag-in-a-cmake-file
#wie man Compiler-Flags anhängt
SET(G++_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic -Werror -std=c++14 -fPIC")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${G++_COVERAGE_COMPILE_FLAGS}")

include_directories (SYSTEM ${CATCH_INCLUDE_DIR})
add_executable(catchTest catchLibary.cpp)
