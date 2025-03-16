cmake_minimum_required(VERSION 3.30.5)

project(Stage)

include_directories("../vendor/spdlog/include")

add_executable(${PROJECT_NAME} src/Stage.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE "../vendor/spdlog/include")

target_link_libraries(${PROJECT_NAME} PRIVATE HaraEngine)
target_include_directories(${PROJECT_NAME} PRIVATE "../haraEngine/src")

install(FILES $<TARGET_RUNTIME_DLLS:Stage> TYPE DESTINATION ${CMAKE_SOURCE_DIR}/build/stage/${CMAKE_BUILD_TYPE} CONFIGURATIONS ${CMAKE_BUILD_TYPE})

add_custom_command(TARGET Stage POST_BUILD COMMAND cmake --install ./ --config ${CMAKE_BUILD_TYPE} --prefix ${CMAKE_SOURCE_DIR})