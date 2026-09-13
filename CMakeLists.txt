cmake_minimum_required(VERSION 3.16)

project(3DRendering)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(SDL)

add_executable(3DRendering
    src/main.cpp
    src/Renderer.cpp
)

target_link_libraries(3DRendering PRIVATE SDL3::SDL3)