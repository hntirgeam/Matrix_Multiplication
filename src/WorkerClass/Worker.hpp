#include "MatrixClass/Matrix.hpp"
#include <thread>
#include <functional>

class Worker
{
public:
    Worker(size_t threadAmount, const Matrix &_m1, const Matrix &_m2, const Matrix &_tmp) : t_num(threadAmount), m1(_m1), m2(_m2), tmp(_tmp) {}
    ~Worker() {}

    Matrix calculate();

private:
    void multi();
    // std::thread calc[4];

    Matrix m1, m2;
    Matrix tmp;

    size_t m_dim; //  matrix dimension
    size_t t_num; // thread amount
    size_t step_i = 0;
};

Matrix Worker::calculate()
{
    std::thread threads1[t_num];

    // std::function<void()> func;
    pthread_t threads[t_num];

    std::function<void*(void *arg)> func = [this]() {
        int core = step_i++;
        for (int i = core * m_dim / t_num; i < (core + 1) * m_dim / t_num; i++)
        {
            for (int j = 0; j < m_dim; j++)
            {
                for (int k = 0; k < m_dim; k++)
                {
                    tmp(i, j) += m1(i, k) * m2(k, j);
                }
            }
        }
    };

    for (int i = 0; i < t_num; i++)
    {
        int *p;
        pthread_create(&threads[i], NULL, func, (void *)(p));
    }

    // th.join();
    return tmp;
}

void Worker::multi()
{
}