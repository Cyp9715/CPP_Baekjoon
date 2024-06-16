cmake_minimum_required(VERSION 3.12)

project(CPP_BeakJoon LANGUAGES CXX)

# set source directories
set(SOURCE "./Source")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_executable (
    CPP_BeakJoon
    "${SOURCE}/main.cpp"
)

# after add_executable
set_property(TARGET CPP_BeakJoon PROPERTY CXX_STANDARD 20)