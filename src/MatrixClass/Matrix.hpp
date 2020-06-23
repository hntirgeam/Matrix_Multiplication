#pragma once

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
    void write();
};