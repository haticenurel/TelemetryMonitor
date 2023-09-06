cmake_minimum_required(VERSION 3.12)
project(TelemetryMonitor CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fprofile-arcs -ftest-coverage")

link_libraries(
    /usr/local/lib/libgtest.a
    /usr/local/lib/libgtest_main.a
    /System/Volumes/Data/opt/homebrew/lib/libfmt.a

    )

# Add the include directories for your project
include_directories(
    /Users/haticenurel/Documents/GitHub/googletest/googletest/include
    /Users/haticenurel/Downloads/fmt-master/include
    ../include
    .
    )

add_library(main
    ../src/main.cpp
)

# Add the test executable
add_executable(telemetry_monitor
    ../src/main.cpp
    ../src/telemetry_monitor.cpp
    
    )

# Enable C++11
target_compile_features(telemetry_monitor PRIVATE cxx_std_11)


