cmake_minimum_required(VERSION 3.16)

project(GravitySimulator)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(GravitySimulator
        src/main.cpp
        src/Vector2.cpp
        src/Body.cpp
        src/Simulation.cpp
        src/Renderer.cpp
        include/GalaxyGenerator.h
        src/GalaxyGenerator.cpp
        src/GalaxyGenerator.cpp
)

target_link_libraries(GravitySimulator
        sfml-graphics
        sfml-window
        sfml-system
)