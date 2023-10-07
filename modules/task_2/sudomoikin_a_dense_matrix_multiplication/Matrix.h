// Copyright 2023 Sudomoykin Andrey

#ifndef MODULES_TASK_2_SUDOMOIKIN_A_DENSE_MATRIX_MULTIPLICATION_MATRIX_H_
#define MODULES_TASK_2_SUDOMOIKIN_A_DENSE_MATRIX_MULTIPLICATION_MATRIX_H_

#include <omp.h>
#include <vector>
#include <ctime>
#include <algorithm>

class Matrix {
 private:
    int rows;
    int cols;
    std::vector<double> data;

    Matrix submatrix(int startRow, int startCol, int numRows,
        int numCols) const;
    void copySubmatrix(const Matrix& submatrix, int destRow, int destCol);


 public:
    Matrix();
    Matrix(int rows_, int cols_, const std::vector<double>& vlaues);

    Matrix(int rows, int cols);

    int getRows() const;
    int getCols() const;

    double getValue(int row, int col) const;

    std::vector<double> getValues() const;

    void setValue(int row, int col, double value);

    Matrix operator*(const Matrix& other) const;

    Matrix strassenMultiplyOmp(const Matrix& B) const;

    Matrix operator+(const Matrix& other) const;
};

#endif  // MODULES_TASK_2_SUDOMOIKIN_A_DENSE_MATRIX_MULTIPLICATION_MATRIX_H_
