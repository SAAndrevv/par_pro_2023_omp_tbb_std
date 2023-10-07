// Copyright 2023 Sudomoykin Andrey

#include "Matrix.h"


Matrix::Matrix(): rows(0), cols(0) {
}

Matrix::Matrix(int rows_, int cols_, const std::vector<double>& vlaues) :
    rows(rows_), cols(cols_), data(vlaues) {}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.resize(rows * cols);
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = static_cast<double>(std::rand() / RAND_MAX);
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

double Matrix::getValue(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return data[row * cols + col];
    } else {
        throw  "Error: Invalid row or column index.";
    }
}

std::vector<double> Matrix::getValues() const {
    return data;
}

void Matrix::setValue(int row, int col, double value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row * cols + col] = value;
    } else {
        throw "Error: Invalid row or column index.";
    }
}

Matrix Matrix::submatrix(int startRow, int startCol,
    int numRows, int numCols) const {
    if (startRow < 0 || startCol < 0 || numRows <= 0 || numCols <= 0 ||
        startRow + numRows > rows || startCol + numCols > cols) {
        throw "Error: Invalid submatrix dimensions or indices.";
    }

    Matrix submatrix(numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            submatrix.setValue(i, j, getValue(startRow + i, startCol + j));
        }
    }
    return submatrix;
}

void Matrix::copySubmatrix(const Matrix& submatrix, int destRow, int destCol) {
    int subRows = submatrix.getRows();
    int subCols = submatrix.getCols();

    if (destRow < 0 || destCol < 0 || destRow + subRows > rows ||
        destCol + subCols > cols) {
        throw "Error: Invalid destination position for copying submatrix.";
    }

    for (int i = 0; i < subRows; ++i) {
        for (int j = 0; j < subCols; ++j) {
            setValue(destRow + i, destCol + j, submatrix.getValue(i, j));
        }
    }
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw "Error: Matrix dimensions are not compatible for multiplication.";
    }

    int n = getRows();
    int m = getCols();
    int p = other.getCols();

    if (n == 1 && m == 1 && p == 1) {
        double resultValue = getValue(0, 0) * other.getValue(0, 0);
        return Matrix(1, 1, { resultValue });
    }

    int newSize = n / 2;
    Matrix A11 = submatrix(0, 0, newSize, newSize);
    Matrix A12 = submatrix(0, newSize, newSize, m - newSize);
    Matrix A21 = submatrix(newSize, 0, n - newSize, newSize);
    Matrix A22 = submatrix(newSize, newSize, n - newSize, m - newSize);

    Matrix B11 = other.submatrix(0, 0, newSize, newSize);
    Matrix B12 = other.submatrix(0, newSize, newSize, p - newSize);
    Matrix B21 = other.submatrix(newSize, 0, p - newSize, newSize);
    Matrix B22 = other.submatrix(newSize, newSize, p - newSize, p - newSize);

    Matrix C11 = (A11 * B11) + (A12 * B21);
    Matrix C12 = (A11 * B12) + (A12 * B22);
    Matrix C21 = (A21 * B11) + (A22 * B21);
    Matrix C22 = (A21 * B12) + (A22 * B22);

    Matrix result(n, p);
    result.copySubmatrix(C11, 0, 0);
    result.copySubmatrix(C12, 0, newSize);
    result.copySubmatrix(C21, newSize, 0);
    result.copySubmatrix(C22, newSize, newSize);

    return result;
}

Matrix Matrix::strassenMultiplyOmp(const Matrix& other) const {
    int n = getRows();
    int m = getCols();
    int p = other.getCols();

    if (n == 1 && m == 1 && p == 1) {
        double resultValue = getValue(0, 0) * other.getValue(0, 0);
        return Matrix(1, 1, { resultValue });
    }

    Matrix A11, A12, A21, A22, B11, B12, B21, B22, C11, C12,
        C21, C22, result(n, p);

    int newSize = n / 2;
#pragma omp parallel
#pragma omp sections
        {
#pragma omp section
            {
                A11 = submatrix(0, 0, newSize, newSize);
            }

#pragma omp section
            {
                A12 = submatrix(0, newSize, newSize, m - newSize);
            }

#pragma omp section
            {
                A21 = submatrix(newSize, 0, n - newSize, newSize);
            }

#pragma omp section
            {
                A22 = submatrix(newSize, newSize, n - newSize, m - newSize);
            }

#pragma omp section
            {
                B11 = other.submatrix(0, 0, newSize, newSize);
            }

#pragma omp section
            {
                B12 = other.submatrix(0, newSize, newSize, p - newSize);
            }

#pragma omp section
            {
                B21 = other.submatrix(newSize, 0, p - newSize, newSize);
            }

#pragma omp section
            {
                B22 = other.submatrix(newSize, newSize,
                p - newSize, p - newSize);
            }
        }

#pragma omp parallel default(none) shared(A11, A12, A21, A22, B11, B12,
B21, B22)
#pragma omp sections
        {
#pragma omp section
            {
                C11 = (A11 * B11) + (A12 * B21);
            }

#pragma omp section
            {
                C12 = (A11 * B12) + (A12 * B22);
            }

#pragma omp section
            {
                C21 = (A21 * B11) + (A22 * B21);
            }

#pragma omp section
            {
                C22 = (A21 * B12) + (A22 * B22);
            }
        }

#pragma omp parallel
#pragma omp sections
        {
#pragma omp section
            {
                result.copySubmatrix(C11, 0, 0);
            }

#pragma omp section
            {
                result.copySubmatrix(C12, 0, newSize);
            }

#pragma omp section
            {
                result.copySubmatrix(C21, newSize, 0);
            }

#pragma omp section
            {
                result.copySubmatrix(C22, newSize, newSize);
            }
        }

    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    int n = getRows();
    int m = getCols();

    if (n != other.getRows() || m != other.getCols()) {
        throw "Error: Matrix dimensions are not compatible for addition.";
    }

    Matrix result(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double sum = getValue(i, j) + other.getValue(i, j);
            result.setValue(i, j, sum);
        }
    }

    return result;
}
