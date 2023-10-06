// Copyright 2023 Sudomoykin Andrey

#ifndef MODULES_TASK_1_SUDOMOIKIN_A_DENSE_MATRIX_MULTIPLICATION_MATRIX_H_
#define MODULES_TASK_1_SUDOMOIKIN_A_DENSE_MATRIX_MULTIPLICATION_MATRIX_H_

#include <vector>
#include <cstdlib>
#include <ctime>

class Matrix {
 private:
    int rows;
    int cols;
    std::vector<double> data;

    Matrix strassenMultiply(const Matrix& A, const Matrix& B) const;
    Matrix submatrix(int startRow, int startCol, int numRows,
    int numCols) const;
    void copySubmatrix(const Matrix& submatrix, int destRow, int destCol);


 public:
    Matrix(int rows_, int cols_, std::vector<double> vlaues);

    Matrix(int rows, int cols);

    int getRows() const;
    int getCols() const;

    double getValue(int row, int col) const;

    std::vector<double> getValues() const;

    void setValue(int row, int col, double value);

    Matrix operator*(const Matrix& other) const;

    Matrix operator+(const Matrix& other) const;
};

#endif  // MODULES_TASK_1_SUDOMOIKIN_A_DENSE_MATRIX_MULTIPLICATION_MATRIX_H_
