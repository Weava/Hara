cmake_minimum_required(VERSION 3.30.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(ImGui_DIR "vendor/imgui/lib/cmake")

list(APPEND CMAKE_PREFIX_PATH ${ImGui_DIR})

add_definitions( -DHARA_BUILD_DLL=${HARA_BUILD_DLL} )

project(HaraEngine)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLAD_GL "" )

add_subdirectory("vendor/glfw")
add_subdirectory("vendor/spdlog")
add_subdirectory("vendor/imgui")

include_directories("${GLFW_SOURCE_DIR}/deps")
set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )

list(APPEND SOURCE_FILES src/core/Application.cpp src/core/Log.cpp src/core/Layer.cpp src/core/LayerStack.cpp src/gui/GuiLayer.cpp)

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

option(PLATFORM_WINDOWS "Build for windows?" ON)

if(PLATFORM_WINDOWS)
    list(APPEND COMPILE_DEFINITIONS "PLATFORM_WINDOWS")
    list(APPEND SOURCE_FILES src/platform/windows/MSWindow.cpp)
else()
endif()

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE src/hpch.h)

target_link_libraries(${PROJECT_NAME} ${OPEN_GL_LIBRARIES} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
target_link_libraries(imgui PRIVATE glfw )

set_target_properties(HaraEngine PROPERTIES LINKER_LANGUAGE CXX)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${COMPILE_DEPS} PUBLIC PROJECT_DIR="${PROJECT_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})
target_link_options(${PROJECT_NAME} PUBLIC -static -static-libgcc -static-libstdc++)
