cmake_minimum_required(VERSION 3.12)

project(CPP_BeakJoon LANGUAGES CXX)

# set source directories
set(SOURCE "./Source")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_executable (
    CPP_BeakJoon
    "${SOURCE}/main.cpp"
    "${SOURCE}/1009.cpp"
    "${SOURCE}/1019.cpp"
    "${SOURCE}/1260.cpp"
    "${SOURCE}/1305.cpp"
    "${SOURCE}/1343.cpp"
    "${SOURCE}/2002.cpp"
    "${SOURCE}/2166.cpp"
    "${SOURCE}/2292.cpp"
    "${SOURCE}/3273.cpp"
    "${SOURCE}/14501.cpp"
    "${SOURCE}/15649.cpp"
    "${SOURCE}/19942.cpp"
)

# after add_executable
set_property(TARGET CPP_BeakJoon PROPERTY CXX_STANDARD 20)