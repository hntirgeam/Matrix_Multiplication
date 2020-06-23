#include "MatrixClass/Matrix.hpp"

int main(int argc, char *argv[])
{
    std::string matrixPath;

    if (argc < 3)
    {
        std::cout << "Pass me more arguments" << std::endl;
    }
    else
    {
        Matrix m1;
        m1.load(argv[1]);
        std::cout << m1 << std::endl;

        std::cout << "==========" << std::endl;

        Matrix m2;
        m2.load(argv[2]);
        std::cout << m2 << std::endl;

        std::cout << "==========" << std::endl;

        Matrix m3;
        m3 = m1 * m2;
        std::cout << m3 << std::endl; 


    }
    return 0;
}
