#include "Core.hpp"

void Core::start()
{

    Matrix m1;                              // Создаётся объект 
    m1.load(matrix1path);                   // Парсится файл с матрицей и параметры заносятся в вектор векторов интов 
    std::cout << m1 << std::endl;           // Через перегруженный оператор матрица выводится в консоль

    std::cout << "==========" << std::endl;

    Matrix m2;
    m2.load(matrix2path);
    std::cout << m2 << std::endl;

    std::cout << "==========" << std::endl;

    Matrix m3(m1 * m2);                     // Через перегруженный оператор умножения производится вычисление произведения матрицы
    std::cout << m3 << std::endl;
    // дальше в Matrix.cpp
}
