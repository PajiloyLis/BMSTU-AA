#include <gtest/gtest.h>
#include "algo.h"
#include <vector>

using namespace std;

int total_tests = 0;

TEST(CONNECTIVITY_TEST, UNCONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,  10, INF, INF, INF},
                                {10, 0,  INF, INF, INF},
                                {INF, INF, 0,  15, 12},
                                {INF, INF, 15, 0,  13},
                                {INF, INF, 12, 13, 0}};
    bool corr_ans = false, ans = check_connectivity(g);
    ASSERT_EQ(corr_ans, ans);
}

TEST(CONNECTIVITY_TEST, CONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,  12, 13},
                                {12, 0,  15},
                                {13, 15, 0}};
    bool corr_ans = true, ans = check_connectivity(g);
    ASSERT_EQ(corr_ans, ans);
}

TEST(CALC_Q_CHECK, FULL_CONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,  12, 13},
                                {12, 0,  20},
                                {13, 20, 0}};
    double corr_ans = 10, ans = calc_q(g);
    ASSERT_EQ(corr_ans, ans);
}

TEST(CALC_Q_CHECK, UNCONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,  25, INF, INF, INF},
                                {25, 0,  INF, INF, INF},
                                {INF, INF, 0,  15, 12},
                                {INF, INF, 15, 0,  13},
                                {INF, INF, 12, 13, 0}};
    double corr_ans = 10, ans = calc_q(g);
    ASSERT_EQ(corr_ans, ans);
}

TEST(COMPLETE_BURST, FULL_CONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,  8, 10, 9},
                                {8,  0, 5,  3},
                                {10, 5, 0,  2},
                                {9,  3, 2,  0}};
    double corr_length = 13;
    vector<int> corr_path = {0, 1, 3, 2};
    pair<double, vector<int>> ans = complete_bust(g);
    ASSERT_EQ(corr_length, ans.first);
    ASSERT_EQ(corr_path.size(), ans.second.size());
    for (int i = 0; i < ans.second.size(); ++i) {
        ASSERT_EQ(corr_path[i], ans.second[i]);
    }
}

TEST(COMPLETE_BURST, CONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,   6, INF, 5, INF},
                                {6,   0,   7, 8, INF},
                                {INF, 7,   0, INF, 1},
                                {5,   8, INF, 0,   13},
                                {INF, INF, 1, 13,  0}};
    double corr_length = 19;
    vector<int> corr_path = {3, 0, 1, 2, 4};
    pair<double, vector<int>> ans = complete_bust(g);
    ASSERT_EQ(corr_length, ans.first);
    ASSERT_EQ(corr_path.size(), ans.second.size());
    for (int i = 0; i < ans.second.size(); ++i) {
        ASSERT_EQ(corr_path[i], ans.second[i]);
    }
}

TEST(ANT, FULL_CONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,  8, 10, 9},
                                {8,  0, 5,  3},
                                {10, 5, 0,  2},
                                {9,  3, 2,  0}};
    double corr_length = 13;
    vector<int> corr_path = {0, 1, 3, 2};
    pair<double, vector<int>> ans = complete_bust(g);
    ASSERT_EQ(corr_length, ans.first);
    ASSERT_EQ(corr_path.size(), ans.second.size());
    for (int i = 0; i < ans.second.size(); ++i) {
        ASSERT_EQ(corr_path[i], ans.second[i]);
    }
}

TEST(ANT, CONNECTED) {
    ++total_tests;
    vector<vector<double>> g = {{0,   6, INF, 5, INF},
                                {6,   0,   7, 8, INF},
                                {INF, 7,   0, INF, 1},
                                {5,   8, INF, 0,   13},
                                {INF, INF, 1, 13,  0}};
    double corr_length = 19;
    vector<int> corr_path = {3, 0, 1, 2, 4};
    pair<double, vector<int>> ans = complete_bust(g);
    ASSERT_EQ(corr_length, ans.first);
    ASSERT_EQ(corr_path.size(), ans.second.size());
    for (int i = 0; i < ans.second.size(); ++i) {
        ASSERT_EQ(corr_path[i], ans.second[i]);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    int failed_cnt = RUN_ALL_TESTS();
    cout << "TESTS_PASSED " << total_tests - failed_cnt << '\n' << "TESTS_FAILED " << failed_cnt << '\n';
    return failed_cnt;
}