#include <iostream>
#include <vector>
#include "times_measures.h"
#include "algo.h"

using namespace std;

void solve();

signed main(signed argc, char **argv) {
    if (argc == 1) {
        solve();
    } else if (argc == 2 && argv[1] == string("-t")) {
        srand(time(0));
        generate_tests();
        cout << "Tests generated..." << endl;
        measure_algorithms({{"Standard_worst",           std_mtrx_mul},
                            {"Winograd_worst",           winograd},
                            {"Winograd_optimized_worst", winograd_optimized}});
        system("python3 ./code/plots.py");
    } else {
        cout << "Error: unexpected args: ";
        for (int i = 1; i < argc; ++i)
            cout << argv[i] << " ";
        cout << '\n';
        return 1;

    }
}

void solve() {
    int n;
    cout << "Input matrix size:\n";
    cin >> n;
    cout << "Input first matrix row by row:\n";
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    cout << "Input second matrix row by row:\n";
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    vector<vector<int>> c = std_mtrx_mul(a, b);
    cout << "Standard result is:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << c[i][j] << " ";
        cout << '\n';
    }
    cout << "Winograd result:\n";
    vector<vector<int>> c_2 = winograd(a, b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << c_2[i][j] << " ";
        cout << '\n';
    }
    cout << "Winograd optimized result:\n";
    vector<vector<int>> c_3 = winograd_optimized(a, b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << c_3[i][j] << " ";
        cout << '\n';
    }
//    mtrx_alignment(a);
//    mtrx_alignment(b);
//    cout << "Strassen result:\n";
//    vector<vector<int>> c_1 = strassen(a, b);
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j)
//            cout << c_1[i][j] << " ";
//        cout << '\n';
//    }
}