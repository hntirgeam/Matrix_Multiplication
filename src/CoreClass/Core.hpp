#pragma once

#include "MatrixClass/Matrix.hpp"
// #include "ThreadClass/Thread.hpp"

class Core
{
public:
    Core(const std::string &matrix1, const std::string &matrix2)
        : matrix1path(matrix1), matrix2path(matrix2)
    {
    }
    ~Core()
    {
    }

    void start();
    void setThreadNumber(size_t t_num)
    {
        m_threadNumber = t_num;
    }

    static size_t getThreadNumber()
    {
        return m_threadNumber;
    }

private:
    static inline size_t m_threadNumber;
    std::string matrix1path, matrix2path;
};
