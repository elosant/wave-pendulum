cmake_minimum_required(VERSION 3.18.3)

project(pendulum-wave)

include_directories(${PROJECT_SOURCE_DIR})

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} glfw OpenGL::OpenGL GLEW::GLEW)
