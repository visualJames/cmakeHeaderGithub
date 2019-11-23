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



#https://stackoverflow.com/questions/11783932/how-do-i-add-a-linker-or-compile-flag-in-a-cmake-file
#wie man Compiler-Flags anhängt
SET(G++_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic -Werror -std=c++14 -fPIC")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${G++_COVERAGE_COMPILE_FLAGS}")



add_executable(prog aufgabe13.cpp)
add_executable(prog12 aufgabe12.cpp)
add_executable(catch catchLibary.cpp)
