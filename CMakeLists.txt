cmake_minimum_required(VERSION 3.30.5)

set(HARA_PLATFORM_WINDOWS TRUE)
set(HARA_BUILD_DLL TRUE)

add_definitions( -DHARA_PLATFORM_WINDOWS=${HARA_PLATFORM_WINDOWS} )

add_subdirectory("vendor/spdlog")
add_subdirectory(haraEngine)
add_subdirectory(stage)

project (Hara)