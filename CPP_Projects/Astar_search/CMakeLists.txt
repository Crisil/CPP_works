# Set Minimum C Make Version required

cmake_minimum_required(VERSION 3.23.0)
set(CMAKE_CXX_STANDARD 17)

# Project Name
project(RoutePlanner)

# Project execuateble_name, Src files
add_executable(routeplanner src/RoutePlan.cpp)

## How to Run?
## mkdir build
## cd build
## cmake ..
## make 
## ./executable
