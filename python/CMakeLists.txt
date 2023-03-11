cmake_minimum_required(VERSION 3.10)

project(sqpnp_python_bindings)

pybind11_add_module(sqpnp_python sqpnp_python/sqpnp_python.cpp)

message(STATUS "Python Interpreter Version: ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}")

target_link_libraries(sqpnp_python PUBLIC SQPnP)

# fix for clang
# see: https://github.com/pybind/pybind11/issues/1818
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(sqpnp_python PUBLIC -fsized-deallocation)
endif ()

# make sure to output the build file to sqpnp folder
SET_TARGET_PROPERTIES(sqpnp_python
        PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/sqpnp_python"
        )

# copy package __init__.py file
configure_file(sqpnp_python/__init__.py
        ${CMAKE_CURRENT_BINARY_DIR}/sqpnp_python/__init__.py
        )

# copy setup.py file
configure_file(setup.py.in
        ${CMAKE_CURRENT_BINARY_DIR}/setup.py
        )

file(COPY .
     DESTINATION .
     FILES_MATCHING
     PATTERN *.py)
