// Copyright 2023 Sudomoykin Andrey
#include <gtest/gtest.h>
#include "../../../modules/task_1/sudomoikin_a_dense_matrix_multiplication/Matrix.h"

TEST(MatrixTest, TestingRandoxMatrciesMultiplication_64_64) {
    int n = 64;
    Matrix matrix1(n, n);
    Matrix matrix2(n, n);
    // double start, end;
    // start = omp_get_wtime();
    Matrix result = matrix1 * matrix2;
    // end = omp_get_wtime();
    // printf("Work seq took %f seconds\n", end - start);
    // start = omp_get_wtime();
    Matrix resultOmp = matrix1.strassenMultiplyOmp(matrix2);
    // end = omp_get_wtime();
    // printf("Work omp took %f seconds\n", end - start);



    ASSERT_EQ(result.getValues(), resultOmp.getValues());
}

TEST(MatrixTest, TestingRandoxMatrciesMultiplication_4_4) {
    int n = 4;
    Matrix matrix1(n, n);
    Matrix matrix2(n, n);
    // double start, end;
    // start = omp_get_wtime();
    Matrix result = matrix1 * matrix2;
    // end = omp_get_wtime();
    // printf("Work seq took %f seconds\n", end - start);
    // start = omp_get_wtime();
    Matrix resultOmp = matrix1.strassenMultiplyOmp(matrix2);
    // end = omp_get_wtime();
    // printf("Work omp took %f seconds\n", end - start);



    ASSERT_EQ(result.getValues(), resultOmp.getValues());
}

TEST(MatrixTest, TestingRandoxMatrciesMultiplication_8_8) {
    int n = 8;
    Matrix matrix1(n, n);
    Matrix matrix2(n, n);
    // double start, end;
    // start = omp_get_wtime();
    Matrix result = matrix1 * matrix2;
    // end = omp_get_wtime();
    // printf("Work seq took %f seconds\n", end - start);
    // start = omp_get_wtime();
    Matrix resultOmp = matrix1.strassenMultiplyOmp(matrix2);
    // end = omp_get_wtime();
    // printf("Work omp took %f seconds\n", end - start);



    ASSERT_EQ(result.getValues(), resultOmp.getValues());
}

TEST(MatrixTest, TestingRandoxMatrciesMultiplication_16_16) {
    int n = 16;
    Matrix matrix1(n, n);
    Matrix matrix2(n, n);
    // double start, end;
    // start = omp_get_wtime();
    Matrix result = matrix1 * matrix2;
    // end = omp_get_wtime();
    // printf("Work seq took %f seconds\n", end - start);
    // start = omp_get_wtime();
    Matrix resultOmp = matrix1.strassenMultiplyOmp(matrix2);
    // end = omp_get_wtime();
    // printf("Work omp took %f seconds\n", end - start);



    ASSERT_EQ(result.getValues(), resultOmp.getValues());
}

TEST(MatrixTest, TestingRandoxMatrciesMultiplication_32_32) {
    int n = 32;
    Matrix matrix1(n, n);
    Matrix matrix2(n, n);
    // double start, end;
    // start = omp_get_wtime();
    Matrix result = matrix1 * matrix2;
    // end = omp_get_wtime();
    // printf("Work seq took %f seconds\n", end - start);
    // start = omp_get_wtime();
    Matrix resultOmp = matrix1.strassenMultiplyOmp(matrix2);
    // end = omp_get_wtime();
    // printf("Work omp took %f seconds\n", end - start);



    ASSERT_EQ(result.getValues(), resultOmp.getValues());
}
