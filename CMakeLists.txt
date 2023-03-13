#

#  Author: Yannis STEFANELLI

#  Creation Date: 06-03-2023 11:43:39

#  Description :

#

cmake_minimum_required(VERSION 3.25)

# Executable name
set(PROJECT_NAME
    out
)

project(${PROJECT_NAME} CXX)

# Source files
file(GLOB SOURCES "src/*.cpp")

## Libs locations
set( SFML_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1
)

set( THOR_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/Thor
)

set( AURORA_DIR
    ${THOR_DIR}/extlibs/aurora/
)
##

include_directories(
    ${SFML_DIR}/include
    ${THOR_DIR}/include
    ${AURORA_DIR}/include
)

link_directories(
    ${SFML_DIR}/lib
    ${THOR_DIR}/build/src
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Linker rules
target_link_libraries(
    ${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
    thor
)

# Compiler optimization options
add_compile_options( Ofast )