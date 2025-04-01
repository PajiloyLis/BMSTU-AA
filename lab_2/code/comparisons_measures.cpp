#include "comparisons_measures.h"

void comparisons_measures(string &name, func algo);

void write_measures_to_csv(vector<int> &measures, const string &filename);

void measure_algorithms(const vector<pair<string, func>> &algos) {
    for (auto elem: algos) {
        comparisons_measures(elem.first, elem.second);
    }
}

void comparisons_measures(string &name, func algo) {
    vector<int> measures(ARRAY_LEN + 1);
    vector<int> data = gen_sorted_array_by_length(ARRAY_LEN);
    for (int j = -1; j < ARRAY_LEN; ++j) {
        measures[j+1] = algo(data, j).second;
    }
    write_measures_to_csv(measures, "./measures/" + name + ".txt");
}

void write_measures_to_csv(vector<int> &measures, const string &filename) {
    ofstream out;
    out.open(filename, ios::out);
    for(auto elem : measures)
        out<<elem<<'\n';
    out.close();
}
