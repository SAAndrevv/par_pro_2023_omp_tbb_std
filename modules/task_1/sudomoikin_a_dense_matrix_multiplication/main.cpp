// Copyright 2023 Sudomoykin Andrey
#include <gtest/gtest.h>
#include "../../../modules/task_1/sudomoykin_a_mat_multi_strassen/Matrix.h"

TEST(MatrixTest, ConstructorAndAccessors) {
    int n = 10;
    Matrix mat(n, n);
    EXPECT_EQ(mat.getRows(), n);
    EXPECT_EQ(mat.getCols(), n);

    // Check if values are within the expected range (0 to 1)
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            double value = mat.getValue(i, j);
            EXPECT_GE(value, 0.0);
            EXPECT_LE(value, 1.0);
        }
    }
}

TEST(MatrixTest, SetValueAndGetMatrix) {
    int n = 2;
    Matrix mat(n, n);
    mat.setValue(0, 0, 1.0);
    mat.setValue(0, 1, 2.0);
    mat.setValue(1, 0, 3.0);
    mat.setValue(1, 1, 4.0);

    EXPECT_DOUBLE_EQ(mat.getValue(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(mat.getValue(0, 1), 2.0);
    EXPECT_DOUBLE_EQ(mat.getValue(1, 0), 3.0);
    EXPECT_DOUBLE_EQ(mat.getValue(1, 1), 4.0);
}

TEST(MatrixTest, MultiplicationOperator) {
    int n = 2;
    Matrix mat1(n, n);
    Matrix mat2(n, n);

    mat1.setValue(0, 0, 1.0);
    mat1.setValue(0, 1, 2.0);
    mat1.setValue(1, 0, 3.0);
    mat1.setValue(1, 1, 4.0);

    mat2.setValue(0, 0, 7.0);
    mat2.setValue(0, 1, 8.0);
    mat2.setValue(1, 0, 9.0);
    mat2.setValue(1, 1, 10.0);

    Matrix result = mat1 * mat2;

    EXPECT_EQ(result.getRows(), n);
    EXPECT_EQ(result.getCols(), n);

    EXPECT_DOUBLE_EQ(result.getValue(0, 0), 25.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 1), 28.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 0), 57.0);
    EXPECT_DOUBLE_EQ(result.getValue(1, 1), 64.0);
}

TEST(MatrixTest, InvalidMultiplication) {
    Matrix mat1(2, 3);
    Matrix mat2(4, 4);

    ASSERT_ANY_THROW(mat1 * mat2);
}

TEST(MatrixTest, TestingRandoxMatrciesMultiplication) {
    int n = 64;
    Matrix matrix1(n, n);
    Matrix matrix2(n, n);

    Matrix result = matrix1 * matrix2;

    ASSERT_EQ(result.getCols(), n);
    ASSERT_EQ(result.getRows(), n);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
