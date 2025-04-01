#include <iostream>
#include "algo.h"
#include "time_measures.h"
#include<iomanip>

using namespace std;


int main(int argc, char *argv[]) {
    vector <pair<string, func>> algos = {{"iter_levenstein",             levenstein},
                                         {"recur_levenstein",            levenstein_recursion},
                                         {"iter_mem_levenstein",         levenstein_memoization},
                                         {"recur_mem_levenstein",        levenstein_recursion_memoization},
                                         {"iter_mem_damerau_levenstein", damerau_levenstein}};
    if (argc == 1) {
        string s1, s2;
        cin>>s1>>s2;

        vector <pair<string, double>> times = measure_algorithms(algos, s1, s2);
        for (int i = 0; i < algos.size(); ++i)
            cout << fixed << times[i].first << "\nans: " << algos[i].second(s1, s2) << "\nusecs: " << times[i].second
                 << '\n';
    } else if (argc == 2 && string(argv[1]) == "-t") {
        generate_tests();
        cout << "Tests generated..." << endl;
        measure_algorithms(algos);
        for (auto &elem: algos)
            system((string("python3 ./code/tables.py ") + string("./measures/") + elem.first + string(".csv")).c_str());
    } else {
        cout << "Error: unexpected args: ";
        for (int i = 1; i < argc; ++i)
            cout << argv[i] << " ";
        cout << '\n';
        return 1;
    }
    return 0;
}