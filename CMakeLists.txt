cmake_minimum_required(VERSION 3.31.5)

set(HARA_PLATFORM_WINDOWS TRUE)
set(HARA_BUILD_DLL TRUE)

add_definitions( -DHARA_PLATFORM_WINDOWS=${HARA_PLATFORM_WINDOWS} )
add_definitions( -DHARA_BUILD_DLL=${HARA_BUILD_DLL} )

add_subdirectory(engine)
add_subdirectory(stage)

project (Hara)