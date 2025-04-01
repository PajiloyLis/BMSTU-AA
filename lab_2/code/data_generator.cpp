#include "data_generator.h"

vector<int> gen_sorted_array_by_length(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i;
    return a;
}