#include "Worker.hpp"

void Worker::multiply(const size_t &slice)
{

    const size_t from = (slice * m_dim) / num_thread;
    const size_t to = ((slice + 1) * m_dim) / num_thread;

    for (size_t i = from; i < to; i++)
    {
        for (size_t j = 0; j < m_dim; j++)
        {
            tmp(i, j) = 0;
            for (size_t k = 0; k < m_dim; k++)
                tmp(i, j) += m1(i, k) * m2(k, j);
        }
    }
}

Matrix Worker::calculate()
{
    boost::thread_group threads;
    std::cout << "Calculating on " << num_thread << " thread(s)" << std::endl;
    for (size_t i = 0; i < num_thread; i++)
    {
        threads.create_thread(boost::bind(&Worker::multiply, this, i));
    }

    threads.join_all();

    return tmp;
}