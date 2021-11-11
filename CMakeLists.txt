cmake_minimum_required(VERSION 3.20)
project(SDL_project)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(SDL_project main.cpp timer/LTimer.cpp timer/LTimer.h render/SDL/Render.cpp render/SDL/Render.h objects/Square.cpp objects/Square.h events/Keys.cpp events/Keys.h engine/Init.cpp engine/Init.h engine/State.cpp engine/State.h objects/Object.cpp objects/Object.h objects/Moveable.cpp objects/Moveable.h)
target_link_libraries(SDL_project ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})