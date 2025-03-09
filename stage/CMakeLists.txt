cmake_minimum_required(VERSION 3.31.5)


project(Stage)

add_executable(${PROJECT_NAME} src/Stage.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE HaraEngine)
target_include_directories(${PROJECT_NAME} PRIVATE "../engine/src")

install(FILES $<TARGET_RUNTIME_DLLS:Stage> TYPE DESTINATION ${CMAKE_SOURCE_DIR}/build/stage/${CMAKE_BUILD_TYPE} CONFIGURATIONS ${CMAKE_BUILD_TYPE})

add_custom_command(TARGET Stage POST_BUILD COMMAND cmake --install ./ --config Debug --prefix ${CMAKE_SOURCE_DIR})