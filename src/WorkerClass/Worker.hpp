#pragma once

#include "MatrixClass/Matrix.hpp"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <functional>

class Worker
{
public:
    Worker(size_t threadAmount, const Matrix &_m1, const Matrix &_m2, const Matrix &_tmp)
        : num_thread(threadAmount), m1(_m1), m2(_m2), tmp(_tmp), m_dim(m1.getRow())
    {
    }
    ~Worker()
    {
    }

    void multiply(const size_t &slice);

    Matrix calculate();

private:
    Matrix m1, m2;
    Matrix tmp;

    size_t m_dim;      //  matrix dimension
    size_t num_thread; // thread amount
};
