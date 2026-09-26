cmake_minimum_required(VERSION 3.16)

project(BlackHole LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(BlackHole
    src/main.cpp
)

target_link_libraries(BlackHole PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)