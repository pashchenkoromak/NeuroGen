cmake_minimum_required(VERSION 2.8.12)

add_library(NeuroWeb include/NeuroWeb/Neuron.hpp include/NeuroWeb/NeuroWeb.hpp src/NeuroWeb/Neuron.cpp src/NeuroWeb/NeuroWeb.cpp)
target_include_directories(NeuroWeb PUBLIC include)
add_library(Genetic include/Genetic/Evolution.hpp src/Genetic/Evolution.cpp)
target_link_libraries(Genetic NeuroWeb)
target_include_directories(Genetic PUBLIC include)
add_library(Game include/Game/Game.hpp src/Game/Game.cpp)
target_include_directories(Game PUBLIC include)
project(NeuroGen)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} NeuroWeb Game Genetic)
target_include_directories(${PROJECT_NAME} PUBLIC include)
