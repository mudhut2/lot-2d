cmake_minimum_required(VERSION 3.31)
project(game1)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(game1 src/main.cpp
        src/Player.cpp
        include/Player.h
        include/Tile.h
        src/Tile.cpp
        include/Level.h
        src/Level.cpp)

target_link_libraries(game1 raylib)
