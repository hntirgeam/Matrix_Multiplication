#include "CoreClass/Core.hpp"
#include <cstdlib>

void sendUsage()
{
    std::cout << "Usage: ./a.out [numOfThreads] [matrix1_file] [matrix2_file]"
              << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        sendUsage();
    }
    else if (atoi(argv[1]) >= 1)
    {
        Core core(argv[2], argv[3]);
        core.setThreadNumber(atoi(argv[1]));
        core.start();
    }
    else
    {
        sendUsage();
    }

    return 0;
}