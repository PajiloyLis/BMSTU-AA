#include "data_generator.h"


vector<vector<int>> gen_mtrx(int n) {
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = rand() % MAX_ELEM_VAL;
    return a;
}

void generate_tests() {
    ofstream out;
    for (int i = 0; i < COUNT; ++i) {
        out.open("./tests/mtrx" + to_string(MIN_LEN + i * STEP) + ".txt", ios::out);
        for (int j = 0; j < REPEATS; ++j) {
            vector<vector<int>> a = gen_mtrx(MIN_LEN + i * STEP);
            for (int r = 0; r < a.size(); ++r) {
                for (int c = 0; c < a.size(); ++c)
                    out << a[r][c] << " ";
                out << '\n';
            }
        }
        out.close();
    }
}

void read_test_matrix_file(vector<vector<vector<int>>> &matrices, const string &filename) {
    ifstream in;
    in.open(filename, ios::in);
    int n = matrices[0].size();
    for (int i = 0; i < REPEATS; ++i)
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                in >> matrices[i][r][c];
    in.close();
}