cmake_minimum_required(VERSION 3.10)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(${PROJECT_NAME} main.cpp SortingSystem.cpp SortingSystem.hpp GraphicsSystem.cpp GraphicsSystem.hpp)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
