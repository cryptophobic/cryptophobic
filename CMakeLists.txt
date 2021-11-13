cmake_minimum_required(VERSION 3.20)
project(SDL_project)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(SDL_project main.cpp shared/timer/LTimer.cpp shared/timer/LTimer.h client/render/SDL/Render.cpp client/render/SDL/Render.h shared/objects/Square.cpp shared/objects/Square.h client/events/Keys.cpp client/events/Keys.h client/engine/Init.cpp client/engine/Init.h client/engine/State.cpp client/engine/State.h shared/objects/Object.cpp shared/objects/Object.h shared/objects/Moveable.cpp shared/objects/Moveable.h client/engine/ServerProxy.cpp client/engine/ServerProxy.h server/sync/Approver.cpp server/sync/Approver.h server/Init.cpp server/Init.h server/workers/Worker.cpp server/workers/Worker.h shared/connection/SocketServer.cpp shared/connection/SocketServer.h shared/connection/SocketClient.cpp shared/connection/SocketClient.h)
target_link_libraries(SDL_project ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})