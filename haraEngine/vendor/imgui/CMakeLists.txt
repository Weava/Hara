cmake_minimum_required(VERSION 3.30.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(imgui)

list(APPEND IMGUI_SOURCE imgui.cpp imgui_demo.cpp imgui_draw.cpp imgui_tables.cpp imgui_widgets.cpp imgui_impl_opengl3.cpp imgui_impl_glfw.cpp)

add_library(imgui STATIC ${IMGUI_SOURCE})

target_include_directories(imgui PRIVATE .)