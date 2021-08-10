cmake_minimum_required(VERSION 3.0.0)
project(kalah VERSION 0.1.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/functions.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/functions.c
)

set(MAIN
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)

add_executable(Kalah  ${MAIN} ${SOURCE})
target_link_libraries(Kalah ${SDL2_LIBRARIES} SDL2_ttf)

