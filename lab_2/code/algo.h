#ifndef BIS22U145_ALGO_H
#define BIS22U145_ALGO_H

#include <vector>

using namespace std;

//first - index, second - cnt comparisons
pair<int, int> linear_search(const vector<int> &a, int elem_to_find);

pair<int, int> binary_search(const vector<int> &a, int elem_to_find);

#endif //BIS22U145_ALGO_H
