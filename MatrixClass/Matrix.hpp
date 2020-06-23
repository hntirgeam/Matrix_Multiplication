#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

class Matrix
{
public:
    Matrix();
    Matrix(const Matrix &copy);
    ~Matrix();

    void load(const std::string &pathToFile);

    Matrix &operator=(const Matrix &m)
    {
        m_matrix = m.m_matrix;
        return *this;
    }

    friend bool operator==(const Matrix &m1, const Matrix &m2);
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

private:
    std::vector<std::vector<int>> m_matrix;
    int row, col;
};

void Matrix::load(const std::string &pathToFile)
{
    std::ifstream file(pathToFile);
    if (!file.is_open())
    {
        std::cerr << "Error opening matrix file.\n";
        return;
    }

    file >> row >> col;

    if (row < 1 || col < 1)
    {
        std::cerr << "Matrix can't be sized like this.\n";
        return;
    }

    m_matrix.resize(row);

    for (auto &m : m_matrix)
        m.resize(col);

    for (auto &_row : m_matrix)
    {
        for (auto &in : _row)
        {
            file >> in;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
    for (auto const &_row : m.m_matrix)
    {
        for (auto const &in : _row)
        {
            out << in << ' ';
        }
        out << '\n';
    }
    return out;
}

bool operator==(const Matrix &m1, const Matrix &m2)
{
    return m1.col == m2.row ? 1 : 0;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    Matrix mul;
    for (size_t i = 0; i < m1.row; i++)
    {
        for (size_t j = 0; j < m1.col; j++)
        {
            mul.m_matrix[i][j] = 0;
            for (size_t k = 0; k < m1.col; k++)
            {
                mul.m_matrix[i][j] += m1.m_matrix[i][k] * m2.m_matrix[k][j];
            }
        }
    }
    return mul;
}

Matrix::Matrix()
{
}

Matrix::Matrix(const Matrix &copy) : m_matrix(copy.m_matrix)
{
    std::cout << "COPY" << std::endl;
}

Matrix::~Matrix()
{
}
