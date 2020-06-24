#include "Matrix.hpp"
#include "WorkerClass/Worker.hpp"

Matrix::Matrix(size_t threadCount) : t_num(threadCount)
{
}

Matrix::Matrix(const Matrix &copy) : m_matrix(copy.m_matrix), row(copy.row), col(copy.col)
{
}

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

// Дописать
void Matrix::write()
{
    std::ofstream file;
    file.open("result");
    if (!file.is_open())
    {
        std::cerr << "Error opening matrix file.\n";
        return;
    }
    else
    {
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
    Matrix tmp;

    tmp.m_matrix.resize(m1.row);
    for (auto &m : tmp.m_matrix)
        m.resize(m1.col);

    Worker w(2, m1, m2, tmp);

    return w.calculate();

    // for (size_t i = 0; i < m1.row; i++)
    // {
    //     for (size_t j = 0; j < m1.row; j++)
    //     {
    //         tmp.m_matrix[i][j] = 0;
    //         for (size_t k = 0; k < m1.row; k++)
    //         {
    //             tmp.m_matrix[i][j] += m1.m_matrix[i][k] * m2.m_matrix[k][j];
    //         }
    //     }
    // }
    // return tmp;
}

int &Matrix::operator()(int row, int col)
{
    return m_matrix[row][col];
}

const int &Matrix::operator()(int row, int col) const
{
    return m_matrix[row][col];
}

int Matrix::getRow() const
{
    return row;
}