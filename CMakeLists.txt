cmake_minimum_required(VERSION 3.10)

# set the project name
project(GettingAroundSTL)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(createTree src/challenges/createTree.cpp)
add_executable(Dijkstra src/challenges/Dijkstra.cpp src/challenges/createWeightedGraph.cpp)
add_executable(Astar src/challenges/aStar.cpp src/challenges/createWeightedGraph.cpp)
add_executable(binarySearchSortedArray src/challenges/binarySearchSortedArray.cpp)
