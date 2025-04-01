#ifndef LAB_1_ALGO_H
#define LAB_1_ALGO_H

#include<vector>
#include<string>
#include<iostream>

using namespace std;

int levenstein(const string &s1, const string &s2);

int levenstein_recursion(const string &s1, const string &s2);

int levenstein_memoization(const string &s1, const string &s2);

int damerau_levenstein(const string &s1, const string &s2);

int levenstein_recursion_memoization(const string &s1, const string &s2);

#endif //LAB_1_ALGO_H
