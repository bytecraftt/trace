cmake_minimum_required(VERSION 3.0)

project(trace)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDES 
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Trace.cpp)

include_directories(${INCLUDES})

add_library(tracelib STATIC ${SOURCES})
link_libraries(tracelib)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/trace.cpp)