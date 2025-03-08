cmake_minimum_required(VERSION 3.31.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


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

include_directories("${GLFW_SOURCE_DIR}/deps")
set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

option(PLATFORM_WINDOWS "Build for windows?" ON)

if(PLATFORM_WINDOWS)
    list(APPEND COMPILE_DEFINITIONS "PLATFORM_WINDOWS")
else()
endif()

list(APPEND SOURCE_FILES src/Hara.h)

add_library(${PROJECT_NAME} SHARED src/core/Application.cpp)

target_link_libraries(${PROJECT_NAME} ${OPEN_GL_LIBRARIES} glfw)

set_target_properties(HaraEngine PROPERTIES LINKER_LANGUAGE CXX)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${COMPILE_DEPS} PUBLIC PROJECT_DIR="${PROJECT_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})
target_link_options(${PROJECT_NAME} PUBLIC -static -static-libgcc -static-libstdc++)
