#include "data_generator.h"

string generate_string(int n) {
    string ans;
    for (int i = 0; i < n; ++i) {
        ans += static_cast<char>('a' + rand() % 26);
    }
    return ans;
}

void generate_tests() {
    ofstream out;
    for (int i = 0; i < (MAX_LEN - MIN_LEN) / STEP + 1; ++i) {
        out.open("./tests/str" + to_string(MIN_LEN + i * STEP) + ".txt", ios::out);
        for (int j = 0; j < REPEATS; ++j) {
            out << generate_string((i + 1) * STEP) << '\n';
        }
        out.close();
    }
}


void read_test_string_file(vector<string> &strings, const string &filename) {
    ifstream in;
    in.open(filename, ios::in);
    for (int i = 0; i < COUNT; ++i)
        in >> strings[i];
    in.close();
}