#include "Worker.hpp"

void Worker::multiply(const int &slice)
{

    const int from = (slice * m_dim) / num_thread;
    const int to = ((slice + 1) * m_dim) / num_thread;

    for (int i = from; i < to; i++)
    {
        for (int j = 0; j < m_dim; j++)
        {
            tmp(i, j) = 0; // initialize matrix C
            for (int k = 0; k < m_dim; k++)
                tmp(i, j) += m1(i, k) * m2(k, j);
        }
    }
}

// void Worker::multiply1()
// {
//     std::cout << "m_dim = " << m_dim << std::endl;
//     std::cout << "m1 size = " << m1.getVecSize() << std::endl;
//     std::cout << "m2 size = " << m2.getVecSize() << std::endl;
//     std::cout << "tmp size = " << tmp.getVecSize() << std::endl;

//     for (size_t i = 0; i < m_dim; i++)
//     {
//         for (size_t j = 0; j < m_dim; j++)
//         {
//             tmp(i, j) = 0;
//             for (size_t k = 0; k < m_dim; k++)
//             {
//                 tmp(i, j) += m1(i, k) * m2(k, j);
//             }
//         }
//     }
// }

Matrix Worker::calculate()
{
    // boost::thread threads[t_num];
    // std::function<void()> func;
    // auto func = [this]() {
    //     int core = step_i++;
    //     for (int i = core * m_dim / t_num; i < (core + 1) * m_dim / t_num; i++)
    //     {
    //         for (int j = 0; j < m_dim; j++)
    //         {
    //             for (int k = 0; k < m_dim; k++)
    //             {
    //                 tmp(i, j) += m1(i, k) * m2(k, j);
    //             }
    //         }
    //     }
    // };

    boost::thread_group threads;

    for (int i = 0; i < num_thread; i++)
    {
        threads.create_thread(boost::bind(&Worker::multiply, this, i));
    }

    threads.join_all();

    return tmp;
}