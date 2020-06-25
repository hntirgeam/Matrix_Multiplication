#include "Core.hpp"

void Core::start()
{

    Matrix m1;
    m1.load(matrix1path);
    std::cout << m1 << std::endl;

    std::cout << "==========" << std::endl;

    Matrix m2;
    m2.load(matrix2path);
    std::cout << m2 << std::endl;

    std::cout << "==========" << std::endl;

    Matrix m3(m1 * m2);
    std::cout << m3 << std::endl;
}
