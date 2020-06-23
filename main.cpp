#include "MatrixClass/Matrix.hpp"

int main(int argc, char *argv[])
{
    std::string matrixPath;

    if (argc < 3)
    {
        std::cout << "Usage: ./a.out matrix1 matrix2" << std::endl;
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

// void multiply(int mat1[][N],  
//               int mat2[][N],  
//               int res[][N]) 
// { 
//     int i, j, k; 
//     for (i = 0; i < N; i++) 
//     { 
//         for (j = 0; j < N; j++) 
//         { 
//             res[i][j] = 0; 
//             for (k = 0; k < N; k++) 
//                 res[i][j] += mat1[i][k] *  
//                              mat2[k][j]; 
//         } 
//     } 
// } 
// int main() 
// { 
//     int i, j; 
//     int res[N][N]; // To store result 
//     int mat1[N][N] = {{1, 1, 1, 1}, 
//                       {2, 2, 2, 2}, 
//                       {3, 3, 3, 3}, 
//                       {4, 4, 4, 4}}; 
  
//     int mat2[N][N] = {{1, 1, 1, 1}, 
//                       {2, 2, 2, 2}, 
//                       {3, 3, 3, 3}, 
//                       {4, 4, 4, 4}}; 
  
//     multiply(mat1, mat2, res); 
  
//     cout << "Result matrix is \n"; 
//     for (i = 0; i < N; i++) 
//     { 
//         for (j = 0; j < N; j++) 
//         cout << res[i][j] << " "; 
//         cout << "\n"; 
//     } 
  
//     return 0; 
// } 