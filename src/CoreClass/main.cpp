#include "CoreClass/Core.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./a.out [numOfThreads] [matrix1_file] [matrix2_file]" // вывод информации 
                  << std::endl;
    }
    else
    {
        Core core(argv[2], argv[3]);            // создаётся объект Core в конструктор которого передаётся местоположение файлов с матрицами
        core.setThreadNumber(atoi(argv[1]));    // через сеттер устанавливается кол-во потоков
        core.start();                           // запускается выполнение (дальше в Core.cpp)
    }
    return 0;
}