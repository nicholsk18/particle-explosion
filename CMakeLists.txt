cmake_minimum_required(VERSION 3.16)
project(particle_explosion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(${PROJECT_NAME} src/main.cpp src/Screen.cpp src/Screen.h src/Particle.cpp src/Particle.h src/Swarm.cpp src/Swarm.h)

INCLUDE(FindPkgConfig)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})