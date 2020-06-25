#include "Matrix.hpp"
#include "WorkerClass/Worker.hpp"
#include "CoreClass/Core.hpp"

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
        exit(2);
        return;
    }

    file >> row >> col;

    if (row < 1 || col < 1)
    {
        std::cerr << "Matrix can't be sized like this.\n";
        exit(1);
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
        for (auto &m : m_matrix)
        {
            for (auto &in : m)
            {
                file << in << ' ';
            }
            file << '\n';
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
    Matrix tmp;

    tmp.m_matrix.resize(m1.row);
    for (auto &m : tmp.m_matrix)
        m.resize(m1.col);
    
    Worker w(Core::getThreadNumber(), m1, m2, tmp);
    
    tmp = w.calculate();
    tmp.write();
    return tmp;
}

int64_t &Matrix::operator()(int row, int col)
{
    return m_matrix[row][col];
}

size_t Matrix::getRow() const
{
    return row;
}