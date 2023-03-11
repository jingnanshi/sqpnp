cmake_minimum_required (VERSION 3.5)
project (SQPnP)

option(BUILD_PYTHON_BINDINGS "Build Python bindings" ON)

add_subdirectory (sqpnp)
add_subdirectory (examples)

if (BUILD_PYTHON_BINDINGS)
    add_subdirectory(extern/pybind11)
    add_subdirectory(python)
endif()

message(STATUS "===============================================================")
message(STATUS "============= SQPnP Configuration Options =====================")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "BUILD_PYTHON_BINDINGS: ${BUILD_PYTHON_BINDINGS}")
message(STATUS "===============================================================")
