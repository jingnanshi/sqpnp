cmake_minimum_required (VERSION 3.5)
project (SQPnP)

option(BUILD_PYTHON_BINDINGS "Build Python bindings" ON)

add_subdirectory (sqpnp)
add_subdirectory (examples)

if (BUILD_PYTHON_BINDINGS)
    add_subdirectory(extern/pybind11)
    add_subdirectory(python)
endif()
