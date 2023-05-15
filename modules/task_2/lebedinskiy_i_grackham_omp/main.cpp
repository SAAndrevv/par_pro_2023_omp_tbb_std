// Copyright 2023 Lebedinskiy Ilya
#include "../../../modules/task_2/lebedinskiy_i_grackham_omp/grackham.h"
#include "gtest/gtest.h"
#define THREAD_NUM 4

TEST(grackham_seq, test_size_50) {
    std::vector<std::pair<double, double>> dots;
    int size = 50;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_omp(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

TEST(grackham_seq, test_size_100) {
    std::vector<std::pair<double, double>> dots;
    int size = 100;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_omp(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

TEST(grackham_seq, test_size_1000) {
    std::vector<std::pair<double, double>> dots;
    int size = 1000;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_omp(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

TEST(grackham_seq, test_size_3000) {
    std::vector<std::pair<double, double>> dots;
    int size = 3000;
    dots = gen_dots(size);
    std::vector<std::pair<double, double>> seq_res;
    std::vector<std::pair<double, double>> omp_res;

    seq_res = grackham_seq(dots.begin(), dots.end());
    omp_res = grackham_omp(dots.begin(), dots.end(), THREAD_NUM);

    ASSERT_EQ(seq_res, seq_res);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
