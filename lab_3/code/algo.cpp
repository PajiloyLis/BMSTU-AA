#include "algo.h"

vector<vector<int>> std_mtrx_mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b[0].size(); ++j)
            for (int k = 0; k < b.size(); ++k)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

void extract_submtrx(const vector<vector<int>> &a, vector<vector<int>> &a11, vector<vector<int>> &a12,
                     vector<vector<int>> &a21, vector<vector<int>> &a22) {
    int v = a11.size();
    for (int i = 0; i < v; ++i) {
        a11[i].assign(a[i].begin(), a[i].begin() + v);
        a12[i].assign(a[i].begin() + v, a[i].end());
        a21[i].assign(a[v + i].begin(), a[v + i].begin() + v);
        a22[i].assign(a[v + i].begin() + v, a[v + i].end());
    }
}

inline vector<vector<int>> sum_mtrx(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    vector<vector<int>> res(a.size(), vector<int>(a[0].size()));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

inline vector<vector<int>> sub_mtrx(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    vector<vector<int>> res(a.size(), vector<int>(a[0].size()));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
    return res;
}

int upper_two_pow(int n) {
    int new_size = 1;
    for (; new_size < n; new_size <<= 1) {}
    return new_size;
}

void mtrx_alignment(vector<vector<int>> &a, int new_size) {

    if (new_size == a.size())
        return;
    for (int j = 0; j < a.size(); ++j) {
        a[j].resize(new_size, 0);
    }
    a.resize(new_size, vector<int>(new_size, 0));
}


//vector<vector<int>> strassen(const vector<vector<int>> &a, const vector<vector<int>> &b) {
////    if (a.size() <= 64)
////        return std_mtrx_mul(a, b);
//    if (a.size() == 1)
//        return {1, vector<int>(1, a[0][0] * b[0][0])};
//    vector<vector<int>> c(a.size(), vector<int>(b.size()));
//    int n = a.size() >> 1;
//    vector<vector<int>> a11(n), a12(n), a21(n), a22(n), b11(n), b12(n), b21(n), b22(n);
//    extract_submtrx(a, a11, a12, a21, a22);
//    extract_submtrx(b, b11, b12, b21, b22);
////    vector<vector<int>> s1 = sub_mtrx(b12, b22),
////            s2 = sum_mtrx(a11, a12), s3 = sum_mtrx(a21, a22),
////            s4 = sub_mtrx(b21, b11), s5 = sum_mtrx(a11, a22),
////            s6 = sum_mtrx(b11, b22), s7 = sub_mtrx(a12, a22),
////            s8 = sum_mtrx(b21, b22), s9 = sub_mtrx(a11, a21),
////            s10 = sum_mtrx(b11, b12);
//    vector<vector<int>> p1 = strassen(a11, sub_mtrx(b12, b22)),
//            p2 = strassen(sum_mtrx(a11, a12), b22),
//            p3 = strassen(sum_mtrx(a21, a22), b11),
//            p4 = strassen(a22, sub_mtrx(b21, b11)),
//            p5 = strassen(sum_mtrx(a11, a22), sum_mtrx(b11, b22)),
//            p6 = strassen(sub_mtrx(a12, a22), sum_mtrx(b21, b22)),
//            p7 = strassen(sub_mtrx(a11, a21), sum_mtrx(b11, b12));
//    vector<vector<int>> c11 = sum_mtrx(sub_mtrx(sum_mtrx(p5, p4), p2), p6),
//            c12 = sum_mtrx(p1, p2),
//            c21 = sum_mtrx(p3, p4),
//            c22 = sub_mtrx(sub_mtrx(sum_mtrx(p5, p1), p3), p7);
//    for (int i = 0; i < a.size(); ++i) {
////        for (int j = 0; j < a.size(); ++j)
////            if (i < n && j < n)
////                c[i][j] = c11[i][j];
////            else if (i < n && j >= n)
////                c[i][j] = c12[i][j - n];
////            else if (i >= n && j < n)
////                c[i][j] = c21[i - n][j];
////            else
////                c[i][j] = c22[i - n][j - n];
//        copy(c12[i].begin(), c12[i].end(), c[i].begin() + n);
//        copy(c11[i].begin(), c11[i].end(), c[i].begin());
//        copy(c21[i].begin(), c21[i].end(), c[i + n].begin());
//        copy(c22[i].begin(), c22[i].end(), c[i + n].begin() + n);
//    }
//    return c;
//}

vector<vector<int>> winograd(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size(), m = b.size(), r = b[0].size();
    vector<int> row_sum(n);
    vector<int> col_sum(r);
    vector<vector<int>> c(n, vector<int>(r));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m / 2; ++j)
            row_sum[i] = row_sum[i] + a[i][2 * j] * a[i][2 * j + 1];
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < m / 2; ++j)
            col_sum[i] = col_sum[i] + b[2 * j][i] * b[2 * j + 1][i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < r; ++j) {
            c[i][j] = -row_sum[i] - col_sum[j];
            for (int k = 0; k < m / 2; ++k)
                c[i][j] = c[i][j] + (a[i][2 * k + 1] + b[2 * k][j]) * (a[i][2 * k] + b[2 * k + 1][j]);
        }
    if (m % 2)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < r; ++j)
                c[i][j] = c[i][j] + a[i][m - 1] * b[m - 1][j];
    return c;
}

vector<vector<int>> winograd_optimized(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size(), m = b.size(), r = b[0].size();
    vector<int> row_sum(n);
    vector<int> col_sum(r);
    vector<vector<int>> c(n, vector<int>(r));
    for (int i = 0; i < n; ++i) {
        row_sum[i] = a[i][0] * a[i][1];
        for (int j = 2; j < m - 1; j += 2) {
            row_sum[i] += a[i][j] * a[i][j + 1];
        }
    }
    for (int i = 0; i < r; ++i) {
        col_sum[i] = b[0][i] * b[1][i];
        for (int j = 2; j < m - 1; j += 2) {
            col_sum[i] += b[j][i] * b[j + 1][i];
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < r; ++j) {
            c[i][j] = (a[i][1] + b[0][j]) * (a[i][0] + b[1][j]) - row_sum[i] - col_sum[j];
            for (int k = 2; k < m - 1; k += 2)
                c[i][j] += (a[i][k + 1] + b[k][j]) * (a[i][k] + b[k + 1][j]);
            if (m & 1)
                c[i][j] += a[i][m - 1] * b[m - 1][j];
        }
    return c;
}