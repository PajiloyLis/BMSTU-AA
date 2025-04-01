#ifndef BIS22U145_ALGO_H
#define BIS22U145_ALGO_H

#include <vector>
#include <algorithm>

using namespace std;

int upper_two_pow(int n);

vector<vector<int>> std_mtrx_mul(const vector<vector<int>> &a, const vector<vector<int>> &b);

void mtrx_alignment(vector<vector<int>> &a, int new_size);

//vector<vector<int>> strassen(const vector<vector<int>> &a, const vector<vector<int>> &b);

vector<vector<int>> winograd(const vector<vector<int>> &a, const vector<vector<int>> &b);

vector<vector<int>> winograd_optimized(const vector<vector<int>> &a, const vector<vector<int>> &b);

#endif //BIS22U145_ALGO_H
