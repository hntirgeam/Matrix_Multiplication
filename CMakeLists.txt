cmake_minimum_required(VERSION 3.16)

project(MatrixMultiplication)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

set(SRCS
    src/CoreClass/Core.cpp
    src/CoreClass/Core.hpp
    src/MatrixClass/Matrix.cpp
    src/MatrixClass/Matrix.hpp
    src/WorkerClass/Worker.cpp
    src/WorkerClass/Worker.hpp)

include_directories(src)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")
add_executable(matrix.out ${SRCS} src/CoreClass/main.cpp)
