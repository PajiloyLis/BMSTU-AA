#include "algo.h"

pair<int, int> linear_search(const vector<int> &a, int elem_to_find) {
    int i, cnt = 1;
    for (i = 0; i < a.size() && a[i] != elem_to_find; ++i, cnt++) {}
    return {(i == a.size() ? -1 : i), (i == a.size() ? cnt - 1 : cnt)};
}

pair<int, int> binary_search(const vector<int> &a, int elem_to_find) {
    int l = -1, r = a.size(), m, cnt = 0;
    while (r - l > 1) {
        m = (r + l) / 2;
        if (a[m] == elem_to_find) {
            ++cnt;
            return {m, cnt};
        } else if (a[m] > elem_to_find) {
            cnt += 2;
            r = m;
        } else {
            cnt += 2;
            l = m;
        }
    }
    return {-1, cnt};
}