cmake_minimum_required(VERSION 3.6)

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER /opt/devkitpro/devkitARM/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /opt/devkitpro/devkitARM/bin/arm-none-eabi-g++)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


project(GBA-Mandelbrot)
add_library(libgba STATIC IMPORTED GLOBAL)
set_property(TARGET libgba PROPERTY IMPORTED_LOCATION /opt/devkitpro/libgba/lib/libgba.a)

add_executable(${PROJECT_NAME} "main.cpp")
target_include_directories(${PROJECT_NAME} PUBLIC "/opt/devkitpro/libgba/include/")
target_link_libraries(${PROJECT_NAME} libgba)
