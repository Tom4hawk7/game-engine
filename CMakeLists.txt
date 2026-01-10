# define minimum version and project name
cmake_minimum_required(VERSION 3.24)
project(game-engine)

# enable compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# specify c++ standard to use
# set(CMAKE_CXX_STANDARD 23)
# set (CMAKE_CXX_STANDARD_REQUIRED True)

# find libraries
find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)

# add executable target and link its source file
add_executable(${PROJECT_NAME} src/main.cpp)

# link libraries to target
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
