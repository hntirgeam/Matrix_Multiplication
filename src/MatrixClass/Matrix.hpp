#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

class Matrix
{
public:
    Matrix(){};
    Matrix(size_t threadCount);
    Matrix(const Matrix &copy);
    ~Matrix(){};

    void load(const std::string &pathToFile);

    size_t getRow() const;
    size_t getVecSize() { return m_matrix.capacity(); }; // remove later;

    Matrix &operator=(const Matrix &m)
    {
        m_matrix = m.m_matrix;
        return *this;
    }

    int64_t &operator()(int row, int col);

    friend bool operator==(const Matrix &m1, const Matrix &m2);
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

private:
    std::vector<std::vector<int64_t>> m_matrix;
    size_t row, col;
    size_t t_num;

    void write();
};