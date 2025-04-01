#include <gtest/gtest.h>
#include "algo.h"

using namespace std;

#define GTEST_LOG_TO_FILE "report.log"

int total_tests = 0;

TEST(ITER_LEV, equal_strings
) {
total_tests++;
string s1 = "abracadabra", s2 = "abracadabra";
int corr_ans = 0, ans = levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(ITER_LEV, empty_string_1
) {
total_tests++;
string s1 = "", s2 = "code";
int corr_ans = 4, ans = levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(ITER_LEV, empty_string_2
) {
total_tests++;
string s1 = "code", s2 = "";
int corr_ans = 4, ans = levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(ITER_LEV, fully_different_strings
) {
total_tests++;
string s1 = "cake", s2 = "bug";
int corr_ans = max(s1.size(), s2.size()), ans = levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(ITER_LEV, substrings
) {
total_tests++;
string s1 = "pancake", s2 = "cake";
int corr_ans = max(s1.size(), s2.size()) - min(s1.size(), s2.size()), ans = levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(ITER_LEV, swapped_letter_strings
)
{
total_tests++;
string s1 = "cap", s2 = "cat";
int corr_ans = 1, ans = levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(ITER_LEV, complex_test_strings
)
{
total_tests++;
string s1 = "fake", s2 = "break";
int corr_ans = 4, ans = levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_LEV, equal_strings
) {
total_tests++;
string s1 = "abracadabra", s2 = "abracadabra";
int corr_ans = 0, ans = levenstein_recursion(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_LEV, empty_string_1
) {
total_tests++;
string s1 = "", s2 = "code";
int corr_ans = 4, ans = levenstein_recursion(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_LEV, empty_string_2
) {
total_tests++;
string s1 = "code", s2 = "";
int corr_ans = 4, ans = levenstein_recursion(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_LEV, fully_different_strings
) {
total_tests++;
string s1 = "cake", s2 = "bug";
int corr_ans = max(s1.size(), s2.size()), ans = levenstein_recursion(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_LEV, substrings
) {
total_tests++;
string s1 = "pancake", s2 = "cake";
int corr_ans = max(s1.size(), s2.size()) - min(s1.size(), s2.size()), ans = levenstein_recursion(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_LEV, swapped_letter_strings
)
{
total_tests++;
string s1 = "cap", s2 = "cat";
int corr_ans = 1, ans = levenstein_recursion(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_LEV, complex_test_strings
)
{
total_tests++;
string s1 = "fake", s2 = "break";
int corr_ans = 4, ans = levenstein_recursion(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_MEM_LEV, equal_strings
) {
total_tests++;
string s1 = "abracadabra", s2 = "abracadabra";
int corr_ans = 0, ans = levenstein_recursion_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_MEM_LEV, empty_string_1
) {
total_tests++;
string s1 = "", s2 = "code";
int corr_ans = 4, ans = levenstein_recursion_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_MEM_LEV, empty_string_2
) {
total_tests++;
string s1 = "code", s2 = "";
int corr_ans = 4, ans = levenstein_recursion_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_MEM_LEV, fully_different_strings
) {
total_tests++;
string s1 = "cake", s2 = "bug";
int corr_ans = max(s1.size(), s2.size()), ans = levenstein_recursion_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_MEM_LEV, substrings
) {
total_tests++;
string s1 = "pancake", s2 = "cake";
int corr_ans = max(s1.size(), s2.size()) - min(s1.size(), s2.size()), ans = levenstein_recursion_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_MEM_LEV, swapped_letter_strings
)
{
total_tests++;
string s1 = "cap", s2 = "cat";
int corr_ans = 1, ans = levenstein_recursion_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(REC_MEM_LEV, complex_test_strings
)
{
total_tests++;
string s1 = "fake", s2 = "break";
int corr_ans = 4, ans = levenstein_recursion_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(LEV_MEM, equal_strings
) {
total_tests++;
string s1 = "abracadabra", s2 = "abracadabra";
int corr_ans = 0, ans = levenstein_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(MEM_LEV, empty_string_1
) {
total_tests++;
string s1 = "", s2 = "code";
int corr_ans = 4, ans = levenstein_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(MEM_LEV, empty_string_2
) {
total_tests++;
string s1 = "code", s2 = "";
int corr_ans = 4, ans = levenstein_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(MEM_LEV, fully_different_strings
) {
total_tests++;
string s1 = "cake", s2 = "bug";
int corr_ans = max(s1.size(), s2.size()), ans = levenstein_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(MEM_LEV, substrings
) {
total_tests++;
string s1 = "pancake", s2 = "cake";
int corr_ans = max(s1.size(), s2.size()) - min(s1.size(), s2.size()), ans = levenstein_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(MEM_LEV, swapped_letter_strings
)
{
total_tests++;
string s1 = "cap", s2 = "cat";
int corr_ans = 1, ans = levenstein_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(MEM_LEV, complex_test_strings
)
{
total_tests++;
string s1 = "fake", s2 = "break";
int corr_ans = 4, ans = levenstein_memoization(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, equal_strings
) {
total_tests++;
string s1 = "abracadabra", s2 = "abracadabra";
int corr_ans = 0, ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, empty_string_1
) {
total_tests++;
string s1 = "", s2 = "code";
int corr_ans = 4, ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, empty_string_2
) {
total_tests++;
string s1 = "code", s2 = "";
int corr_ans = 4, ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, fully_different_strings
) {
total_tests++;
string s1 = "cake", s2 = "bug";
int corr_ans = max(s1.size(), s2.size()), ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, substrings
) {
total_tests++;
string s1 = "pancake", s2 = "cake";
int corr_ans = max(s1.size(), s2.size()) - min(s1.size(), s2.size()), ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, swapped_letter_strings
)
{
total_tests++;
string s1 = "cap", s2 = "cat";
int corr_ans = 1, ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, complex_test_strings
)
{
total_tests++;
string s1 = "fake", s2 = "break";
int corr_ans = 4, ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

TEST(DAM_LEV, transposition_letters_strings
)
{
total_tests++;
string s1 = "cpu", s2 = "cup";
int corr_ans = 1, ans = damerau_levenstein(s1, s2);
ASSERT_EQ(corr_ans, ans
);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    int failed_cnt = RUN_ALL_TESTS();
    cout<<"TESTS_PASSED "<<total_tests-failed_cnt<<'\n'<<"TESTS_FAILED "<<failed_cnt<<'\n';
}
