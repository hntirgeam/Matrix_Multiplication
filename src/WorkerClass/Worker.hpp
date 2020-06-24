#include "MatrixClass/Matrix.hpp"
#include <thread>

class Worker
{
public:
    Worker(size_t threadAmount, size_t matrixDimension) : t_num(threadAmount), m_dim(matrixDimension) {}
    ~Worker() {}

    Matrix calculate(const Matrix &m1, const Matrix &m2, Matrix &tmp);

private:
    void *multi(void *arg);
    // std::thread calc[4];


    size_t m_dim; //  matrix dimension
    size_t t_num; // thread amount
    size_t step_i = 0; asdasdasdasd 
};

Matrix Worker::calculate(const Matrix &m1, const Matrix &m2, Matrix &tmp)
{
    for (size_t i = 0; i < m1.getRow(); i++)
    {
        for (size_t j = 0; j < m1.getRow(); j++)
        {
            tmp(i, j) = 0;
            for (size_t k = 0; k < m1.getRow(); k++)
            {
                tmp(i, j) += m1(i, k) * m2(k, j);
            }
        }
    }
    return tmp;
}

void *Worker::multi(void *arg)
{
    int core = step_i++;

    for (int i = core * m_dim / t_num; i < (core + 1) * m_dim / t_num; i++)
    {
        for (int j = 0; j < m_dim; j++)
        {
            for (int k = 0; k < m_dim; k++)
            {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}