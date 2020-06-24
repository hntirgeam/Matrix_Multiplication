cmake_minimum_required(VERSION 3.16)

project(MatrixMultiplication)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS thread REQUIRED)

set(SRCS
    src/CoreClass/Core.cpp
    src/CoreClass/Core.hpp
    src/MatrixClass/Matrix.cpp
    src/MatrixClass/Matrix.hpp
    src/WorkerClass/Worker.cpp
    src/WorkerClass/Worker.hpp)

include_directories(src)

add_executable(${PROJECT_NAME} ${SRCS} src/CoreClass/main.cpp)

target_link_libraries(${PROJECT_NAME} Boost::thread)
