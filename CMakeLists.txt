# Using https://stackoverflow.com/a/76776269 [1] and https://github.com/Minres/SystemC-Quickstart/blob/master/CMakeLists.txt [2]


cmake_minimum_required( VERSION 3.21 )

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)    # From [2]
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})                  # From [2]

project( gra_fadder VERSION 0.1.0 LANGUAGES CXX )


# From [1]
set(CMAKE_CXX_STANDARD 17) # Edited
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# From [1]
set( TARGET ${PROJECT_NAME} )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )

set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )

file( GLOB_RECURSE HPPS "${INCLUDE_PATH}/*.hpp" )
file( GLOB_RECURSE CPPS "${SOURCE_PATH}/*.cpp" )


# Deps
find_package( SystemC REQUIRED )



add_executable( ${TARGET} ${CPPS} ${HPPS} )

# From [2]

target_link_libraries( ${TARGET} PUBLIC ${SystemC_LIBRARIES} )
target_include_directories( ${TARGET} PUBLIC ${SystemC_INCLUDE_DIRS} ${INCLUDE_PATH} )
target_link_directories( ${TARGET} PUBLIC ${SystemC_LIBRARY_DIRS} )


# target_link_libraries( ${TARGET} PUBLIC ${SCV_LIBRARIES} ${SystemC_LIBRARIES} )
# target_include_directories( ${TARGET} PUBLIC ${SystemC_INCLUDE_DIRS} ${SCV_INCLUDE_DIRS} ${INCLUDE_PATH} )
# target_link_directories( ${TARGET} PUBLIC ${SCV_LIBRARY_DIRS} ${SystemC_LIBRARY_DIRS} )
