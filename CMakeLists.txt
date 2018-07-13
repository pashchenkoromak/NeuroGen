cmake_minimum_required(VERSION 2.8.12)

add_library(NeuroWeb include/NeuroWeb/Neuron.hpp include/NeuroWeb/NeuroWeb.hpp src/NeuroWeb/Neuron.cpp src/NeuroWeb/NeuroWeb.cpp)
add_library(Genetic include/Genetic/Evolve.hpp src/Genetic/Evolve.cpp)

project(NeuroGen)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} NeuroWeb Genetic)
