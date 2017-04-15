cmake_minimum_required(VERSION 3.6)
project(GBA-Mandelbrot)

include(cmake/gbafix.cmake)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/cmake/Modules/")
message(STATUS "CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")
find_package(GBA REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp")
target_include_directories(${PROJECT_NAME} PUBLIC ${GBA_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${GBA_LIBRARIES})
gbafix(${PROJECT_NAME} false)
