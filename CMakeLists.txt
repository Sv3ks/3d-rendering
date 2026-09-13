cmake_minimum_required(VERSION 3.16)

project(3DRendering)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(SDL)

add_executable(3DRendering
    src/main.cpp
)

target_link_libraries(3DRendering PRIVATE SDL3::SDL3)

add_custom_command(TARGET 3DRendering POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${SDL_DLL_PATH}
    $<TARGET_FILE_DIR:3DRendering>
)