#pragma once

#include "MatrixClass/Matrix.hpp"
// #include "ThreadClass/Thread.hpp"

class Core
{
public:
    Core(size_t threadNumber, const std::string &matrix1, const std::string &matrix2) : m_threadNumber(threadNumber), matrix1path(matrix1), matrix2path(matrix2)
    {
    }
    ~Core()
    {
    }

    void start();

private:
    size_t m_threadNumber;
    std::string matrix1path, matrix2path;
};
