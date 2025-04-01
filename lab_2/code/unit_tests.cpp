#include <gtest/gtest.h>
#include "algo.h"
#include <iostream>
#include<vector>

using namespace std;

int total_tests = 0;

TEST(LINEAR, elem_first) {
    total_tests++;
    vector<int> a= {1, 2, 3, 4, 5};
    int elem_to_find = 1;
    int corr_ans = 0, cmp_corr_ans = 1;
    pair<int, int> ans = linear_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(LINEAR, elem_last) {
    total_tests++;
    vector<int> a= {1, 2, 3, 4, 5};
    int elem_to_find = 5;
    int corr_ans = 4, cmp_corr_ans = 5;
    pair<int, int> ans = linear_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(LINEAR, elem_mid)
{
    total_tests++;
    vector<int> a= {1, 2, 3, 4, 5};
    int elem_to_find = 3;
    int corr_ans = 2, cmp_corr_ans = 3;
    pair<int, int> ans = linear_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(LINEAR, elem_out) {
    total_tests++;
    vector<int> a= {1, 2, 3, 4, 5};
    int elem_to_find = -1;
    int corr_ans = -1, cmp_corr_ans = 5;
    pair<int, int> ans = linear_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(LINEAR, array_empty) {
    total_tests++;
    vector<int> a(0);
    int elem_to_find = 5;
    int corr_ans = -1, cmp_corr_ans = 0;
    pair<int, int> ans = linear_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(BINARY, elem_first) {
    total_tests++;
    vector<int> a={1, 2, 3, 4, 5};
    int elem_to_find = 1;
    int corr_ans = 0, cmp_corr_ans = 3;
    pair<int, int> ans = binary_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(BINARY, elem_last) {
    total_tests++;
    vector<int> a={1, 2, 3, 4, 5};
    int elem_to_find = 5;
    int corr_ans = 4, cmp_corr_ans = 5;
    pair<int, int> ans = binary_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(BINARY, elem_mid)
{
    total_tests++;
    vector<int> a= {1, 2, 3, 4, 5};
    int elem_to_find = 3;
    int corr_ans = 2, cmp_corr_ans = 1;
    pair<int, int> ans = binary_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(BINARY, elem_out) {
    total_tests++;
    vector<int> a= {1, 2, 3, 4, 5};
    int elem_to_find = -1;
    int corr_ans = -1, cmp_corr_ans = 4;
    pair<int, int> ans = binary_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

TEST(BINARY, array_empty) {
    total_tests++;
    vector<int> a(0);
    int elem_to_find = 5;
    int corr_ans = -1, cmp_corr_ans = 0;
    pair<int, int> ans = binary_search(a, elem_to_find);
    ASSERT_EQ(corr_ans, ans.first);
    ASSERT_EQ(cmp_corr_ans, ans.second);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    int failed_cnt = RUN_ALL_TESTS();
    cout<<"TESTS_PASSED "<<total_tests-failed_cnt<<'\n'<<"TESTS_FAILED "<<failed_cnt<<'\n';
    return failed_cnt;
}