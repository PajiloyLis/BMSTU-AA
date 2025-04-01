#include "times_measures.h"

void write_measures_to_csv(vector<double> &measures, const string &filename);

void clock_measures(string &name, func algo);

void measure_algorithms(const vector<pair<string, func>> &algos) {
    for (auto elem: algos) {
        cout << elem.first << " starting measure" << endl;
        clock_measures(elem.first, elem.second);
        cout << elem.first << " measured" << endl;
    }
}

void clock_measures(string &name, func algo) {
    vector<double> measures(COUNT);
    for (int i = 0; i < COUNT; ++i) {
        cout << MIN_LEN + STEP * i << endl;
        vector<vector<vector<int>>> matrices1(REPEATS,
                                              vector<vector<int>>(MIN_LEN + STEP * i,
                                                                  vector<int>(MIN_LEN + STEP * i))), matrices2;
        read_test_matrix_file(matrices1, "./tests/mtrx" + to_string(MIN_LEN + STEP * i) + ".txt");
//        if (name.substr(0, 8) == "Strassen") {
//            for (int j = 0; j < REPEATS; ++j) {
//                mtrx_alignment(matrices1[j]);
//            }
//        }
        matrices2 = matrices1;
        shuffle(matrices1.begin(), matrices1.end(), mt19937(time(0)));
        shuffle(matrices2.begin(), matrices2.end(), mt19937(time(0)));
        cout<<"Starting measure"<<endl;
        clock_t start = clock();
        for (int k = 0; k < REPEATS; ++k) {
            algo(matrices1[k], matrices2[k]);
        }
        clock_t end = clock();
        cout<<"Stop measure"<<endl;
        measures[i] = (double) (end - start) / CLOCKS_PER_SEC;
        cout<<measures[i]<<'\n';
    }
    write_measures_to_csv(measures, "./measures/" + name + ".csv");
}

void write_measures_to_csv(vector<double> &measures, const string &filename) {
    ofstream out;
    out.open(filename, ios::out);
    out << 'n' << "," << 't' << '\n';
    for (int i = 0; i < COUNT; ++i) {
        out <<fixed<< (MIN_LEN + STEP * i) << "," << measures[i] << '\n';
    }
    out.close();
}