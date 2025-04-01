#include <iostream>
#include <algorithm>
#include "algo.h"
#include "comparisons_measures.h"

using namespace std;

void solve();

int main(int argc, char *argv[]) {
    if (argc == 1)
        solve();
    else if (argc == 2 && string(argv[1]) == "-m") {
        measure_algorithms({{"linear", linear_search},
                            {"binary", binary_search}});
        system("python3 ./code/plots.py ./measures/binary.txt ./measures/linear.txt");
    }
    else{
        cout << "Error: unexpected args: ";
        for (int i = 1; i < argc; ++i)
            cout << argv[i] << " ";
        cout << '\n';
        return 1;
    }
    return 0;
}

void solve() {
    int n;
    cout << "Input array size:\n";
    cin >> n;
    vector<int> a(n);
    cout << "Input " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int c;
    cout << "Input number to find:\n";
    cin >> c;
    pair<int, int> ans = linear_search(a, c);
    cout << "Linear search:\n";
    if (ans.first == -1)
        cout << "\tElement " << c << " not found in " << ans.second << " comparisons\n";
    else
        cout << "\tElement " << c << " was found by index " << ans.first << " in " << ans.second << " comparisons\n";
    ans = binary_search(a, c);
    cout << "Binary search:\n";
    if (ans.first == -1)
        cout << "\tElement " << c << " not found in " << ans.second << " comparisons\n";
    else
        cout << "\tElement " << c << " was found by index " << ans.first << " in " << ans.second << " comparisons\n";
}