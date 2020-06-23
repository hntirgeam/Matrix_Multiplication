#include "CoreClass/Core.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./a.out [numOfThreads] [matrix1_file] [matrix2_file]" 
            << std::endl;
    }
    else
    {
        Core core(atoi(argv[1]), argv[2], argv[3]);
        core.start();
    }
    return 0;
}