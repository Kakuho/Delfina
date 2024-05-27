cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(
  Delfina VERSION 1.0
  DESCRIPTION "Cute Differential Equation Solvers"
  LANGUAGES CXX
)

add_executable(
  main 
  src/main.cpp 
  src/ODE/rungekutta.cpp
  src/ODE/solver.cpp
)
