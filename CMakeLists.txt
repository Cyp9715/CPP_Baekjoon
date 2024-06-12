cmake_minimum_required(VERSION 3.8)

project(CPP_BeakJoon LANGUAGES CXX)

# Set output directories


# Add source to this project's executable.
add_executable (
    CPP_BeakJoon
    "main.cpp"
    "1009.cpp"
    "1019.cpp"
    "1260.cpp"
    "1305.cpp"
    "1343.cpp"
    "2002.cpp"
    "2166.cpp"
    "2292.cpp"
    "3273.cpp"
    "14501.cpp"
    "15649.cpp"
    "19942.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPP_BeakJoon PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
