#include <iostream>
#include <vector>
#include "algo.h"
#include "parametrize.h"
#include "time_meaures.h"

using namespace std;

signed main(int argc, char **argv) {
    if (argc == 2 && string(argv[1]) == "-p") {
        parametrize();
    } else if (argc == 2 && string(argv[1]) == "-t") {
        time_measures();
    } else if (argc == 1) {
        int n, m;
        cin >> n >> m;
        vector<vector<double>> g_m(n, vector<double>(n, INF));
        int a, b;
        double c;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            --a, --b;
            g_m[a][b] = min(g_m[a][b], c);
            g_m[b][a] = min(g_m[b][a], c);
        }
        if (!check_connectivity(g_m)) {
            cout << "No way\n";
            return 0;
        }
        auto ans = complete_bust(g_m);
        cout << ans.first << '\n';
        for (auto elem: ans.second) {
            cout << elem + 1 << " ";
        }
        cout << '\n';
        auto ans_2 = ant_algorithm(g_m);
        cout << ans_2.first << '\n';
        for (auto elem: ans_2.second) {
            cout << elem + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "Error: unexpected args: ";
        for (int i = 1; i < argc; ++i)
            cout << argv[i] << " ";
        cout << '\n';
        return 1;
    }
}
