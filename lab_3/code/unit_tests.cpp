#include <gtest/gtest.h>
#include "algo.h"
#include <vector>

using namespace std;

int total_tests = 0;

TEST(TWO_BY_TWO, std_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2},
                              {3, 4}}, m2 = {{2, 3},
                                             {4, 5}};
    vector<vector<int>> corr_ans = {{10, 13},
                                    {22, 29}}, ans = std_mtrx_mul(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

TEST(THREE_BY_THREE, std_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}}, m2 = {{1, 2, 3},
                                                {3, 2, 1},
                                                {2, 1, 3}};
    vector<vector<int>> corr_ans = {{13, 9,  14},
                                    {31, 24, 35},
                                    {49, 39, 56}}, ans = std_mtrx_mul(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

TEST(DIFFERENT_SIZE, std_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2},
                              {3, 3},
                              {2, 1}}, m2 = {{1, 3, 2},
                                             {4, 2, 2}};
    vector<vector<int>> corr_ans = {{9,  7,  6},
                                    {15, 15, 12},
                                    {6,  8,  6}}, ans = std_mtrx_mul(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

//TEST(TWO_BY_TWO, strassen_mul) {
//    total_tests++;
//    vector<vector<int>> m1 = {{1, 2},
//                              {3, 4}}, m2 = {{2, 3},
//                                             {4, 5}};
//    vector<vector<int>> corr_ans = {{10, 13},
//                                    {22, 29}}, ans = strassen(m1, m2);
//    ASSERT_EQ(corr_ans.size(), ans.size());
//    for (int i = 0; i < corr_ans.size(); ++i) {
//        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
//        for (int j = 0; j < corr_ans[i].size(); ++j)
//            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
//    }
//}
//
//TEST(OTHER, true_upper_two_pow) {
//    total_tests++;
//    int n = 3, corr_ans = 4, ans = upper_two_pow(n);
//    ASSERT_EQ(corr_ans, ans);
//}
//
//TEST(OTHER, equal_upper_two_pow) {
//    total_tests++;
//    int n = 4, corr_ans = 4, ans = upper_two_pow(n);
//    ASSERT_EQ(corr_ans, ans);
//}
//
//TEST(THREE_BY_THREE, mtrx_alignment) {
//    total_tests++;
//    vector<vector<int>> mtrx = {{1, 2, 3},
//                                {1, 2, 3},
//                                {1, 2, 3}};
//    vector<vector<int>> corr_ans = {{1, 2, 3, 0},
//                                    {1, 2, 3, 0},
//                                    {1, 2, 3, 0},
//                                    {0, 0, 0, 0}};
//    mtrx_alignment(mtrx, upper_two_pow(max(mtrx.size(), mtrx[0].size())));
//    ASSERT_EQ(corr_ans.size(), mtrx.size());
//    for (int i = 0; i < corr_ans.size(); ++i) {
//        ASSERT_EQ(corr_ans[i].size(), mtrx[i].size());
//        for (int j = 0; j < corr_ans[i].size(); ++j)
//            ASSERT_EQ(corr_ans[i][j], mtrx[i][j]);
//    }
//}
//
//TEST(TWO_BY_TWO, mtrx_alignment) {
//    total_tests++;
//    vector<vector<int>> mtrx = {{1, 2},
//                                {1, 2}};
//    vector<vector<int>> corr_ans = {{1, 2},
//                                    {1, 2}};
//    mtrx_alignment(mtrx, upper_two_pow(max(mtrx.size(), mtrx[0].size())));
//    ASSERT_EQ(corr_ans.size(), mtrx.size());
//    for (int i = 0; i < corr_ans.size(); ++i) {
//        ASSERT_EQ(corr_ans[i].size(), mtrx[i].size());
//        for (int j = 0; j < corr_ans[i].size(); ++j)
//            ASSERT_EQ(corr_ans[i][j], mtrx[i][j]);
//    }
//}
//
//TEST(THREE_BY_THREE, strassen_mul) {
//    total_tests++;
//    vector<vector<int>> m1 = {{1, 2, 3, 0},
//                              {4, 5, 6, 0},
//                              {7, 8, 9, 0},
//                              {0, 0, 0, 0}}, m2 = {{1, 2, 3, 0},
//                                                   {3, 2, 1, 0},
//                                                   {2, 1, 3, 0},
//                                                   {0, 0, 0, 0}};
//    vector<vector<int>> corr_ans = {{13, 9,  14, 0},
//                                    {31, 24, 35, 0},
//                                    {49, 39, 56, 0},
//                                    {0,  0,  0,  0}}, ans = strassen(m1, m2);
//    ASSERT_EQ(corr_ans.size(), ans.size());
//    for (int i = 0; i < corr_ans.size(); ++i) {
//        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
//        for (int j = 0; j < corr_ans[i].size(); ++j)
//            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
//    }
//}
//
//TEST(DIFFERENT_SIZE, strassen_mul) {
//    total_tests++;
//    vector<vector<int>> m1 = {{1, 2},
//                              {3, 3},
//                              {2, 1}}, m2 = {{1, 3, 2},
//                                             {4, 2, 2}};
//    vector<vector<int>> corr_ans = {{9,  7,  6,  0},
//                                    {15, 15, 12, 0},
//                                    {6,  8,  6,  0},
//                                    {0,  0,  0,  0}};
//    int new_size = upper_two_pow(max(m1.size(), max(m2.size(), m2[0].size())));
//    mtrx_alignment(m1, new_size);
//    mtrx_alignment(m2, new_size);
//    vector<vector<int>> ans = strassen(m1, m2);
//    ASSERT_EQ(corr_ans.size(), ans.size());
//    for (int i = 0; i < corr_ans.size(); ++i) {
//        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
//        for (int j = 0; j < corr_ans[i].size(); ++j)
//            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
//    }
//}

TEST(TWO_BY_TWO, winograd_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2},
                              {3, 4}}, m2 = {{2, 3},
                                             {4, 5}};
    vector<vector<int>> corr_ans = {{10, 13},
                                    {22, 29}}, ans = winograd(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

TEST(THREE_BY_THREE, winograd_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}}, m2 = {{1, 2, 3},
                                                {3, 2, 1},
                                                {2, 1, 3}};
    vector<vector<int>> corr_ans = {{13, 9,  14},
                                    {31, 24, 35},
                                    {49, 39, 56}}, ans = winograd(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

TEST(DIFFERENT_SIZE, winograd_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2},
                              {3, 3},
                              {2, 1}}, m2 = {{1, 3, 2},
                                             {4, 2, 2}};
    vector<vector<int>> corr_ans = {{9,  7,  6},
                                    {15, 15, 12},
                                    {6,  8,  6}}, ans = winograd(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

TEST(TWO_BY_TWO, winograd_opt_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2},
                              {3, 4}}, m2 = {{2, 3},
                                             {4, 5}};
    vector<vector<int>> corr_ans = {{10, 13},
                                    {22, 29}}, ans = winograd_optimized(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

TEST(THREE_BY_THREE, winograd_opt_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}}, m2 = {{1, 2, 3},
                                                {3, 2, 1},
                                                {2, 1, 3}};
    vector<vector<int>> corr_ans = {{13, 9,  14},
                                    {31, 24, 35},
                                    {49, 39, 56}}, ans = winograd_optimized(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

TEST(DIFFERENT_SIZE, winograd_opt_mul) {
    total_tests++;
    vector<vector<int>> m1 = {{1, 2},
                              {3, 3},
                              {2, 1}}, m2 = {{1, 3, 2},
                                             {4, 2, 2}};
    vector<vector<int>> corr_ans = {{9,  7,  6},
                                    {15, 15, 12},
                                    {6,  8,  6}}, ans = winograd_optimized(m1, m2);
    ASSERT_EQ(corr_ans.size(), ans.size());
    for (int i = 0; i < corr_ans.size(); ++i) {
        ASSERT_EQ(corr_ans[i].size(), ans[i].size());
        for (int j = 0; j < corr_ans[i].size(); ++j)
            ASSERT_EQ(corr_ans[i][j], ans[i][j]);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    int failed_cnt = RUN_ALL_TESTS();
    cout << "TESTS_PASSED " << total_tests - failed_cnt << '\n' << "TESTS_FAILED " << failed_cnt << '\n';
}
