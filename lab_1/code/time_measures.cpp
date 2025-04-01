#include "time_measures.h"

void write_measures_to_csv(vector <vector<double>> &measures, const string &filename);

//void clock_gettime_measures(string &name, func algo);

//double clock_gettime_measures(func algo, string &s1, string &s2);

void clock_measures(string &name, func algo);

double clock_measures(func algo, string &s1, string &s2);

void measure_algorithms(const vector <pair<string, func>> &algos) {
    for (auto elem: algos) {
        clock_measures(elem.first, elem.second);
        cout << elem.first << " measured" << endl;
    }
}

vector <pair<string, double>> measure_algorithms(const vector <pair<string, func>> &algos, string &s1, string &s2) {
    vector <pair<string, double>> measures;
    for (auto &elem: algos) {
        measures.push_back({elem.first, clock_measures(elem.second, s1, s2)});
    }
    return measures;
}

void clock_measures(string &name, func algo) {
    vector <vector<double>> measures(COUNT, vector<double>(COUNT));
    vector <string> strings1(REPEATS), strings2(REPEATS);
    for (int i = 0; i < COUNT; ++i) {
        read_test_string_file(strings1, "./tests/str" + to_string(MIN_LEN + STEP * i) + ".txt");
        for (int j = 0; j < COUNT; ++j) {
            read_test_string_file(strings2, "./tests/str" + to_string(MIN_LEN + STEP * j) + ".txt");
            clock_t start = clock();
            for (int k = 0; k < REPEATS; ++k)
                algo(strings1[k], strings2[k]);
            clock_t end = clock();
            measures[i][j] = (end - start) / CLOCKS_PER_SEC;
        }
    }
    write_measures_to_csv(measures, "./measures/" + name + ".csv");
}

double clock_measures(func algo, string &s1, string &s2) {
    double sum = 0;
    for (int i = 0; i < COUNT; ++i) {
        for (int j = 0; j < COUNT; ++j) {
            clock_t start = clock();
            for (int k = 0; k < REPEATS; ++k)
                algo(s1, s2);
            clock_t end = clock();
            sum += (end - start) / CLOCKS_PER_SEC;
        }
    }
    return sum;
}

//void clock_gettime_measures(string &name, func algo) {
//    vector <vector<double>> measures(COUNT, vector<double>(COUNT));
//    vector <string> strings1(REPEATS), strings2(REPEATS);
//    for (int i = 0; i < COUNT; ++i) {
//        read_test_string_file(strings1, "./tests/str" + to_string(MIN_LEN + STEP * i) + ".txt");
//        for (int j = 0; j < COUNT; ++j) {
//            read_test_string_file(strings2, "./tests/str" + to_string(MIN_LEN + STEP * j) + ".txt");
//            timespec start(0, 0), end(0, 0);
//            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
//            for (int k = 0; k < REPEATS; ++k)
//                algo(strings1[k], strings2[k]);
//            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
//            measures[i][j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1e6;
//        }
//    }
//    write_measures_to_csv(measures, "./measures/" + name + ".csv");
//}
//
//double clock_gettime_measures(func algo, string &s1, string &s2) {
//    double sum = 0;
//    for (int i = 0; i < COUNT; ++i) {
//        for (int j = 0; j < COUNT; ++j) {
//            timespec start(0, 0), end(0, 0);
//            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
//            for (int k = 0; k < REPEATS; ++k)
//                algo(s1, s2);
//            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
//            sum += ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1e6;
//        }
//    }
//    return sum;
//}

void write_measures_to_csv(vector <vector<double>> &measures, const string &filename) {
    ofstream out;
    out.open(filename, ios::out);
    out << "n\\m,";
    for (int i = 0; i < COUNT; ++i) {
        out << " " << (i + 1) * STEP;
        if (i != COUNT - 1)
            out << ",";
    }
    out << '\n';
    for (int i = 0; i < COUNT; ++i) {
        out << (i + 1) * STEP << ",";
        for (int j = 0; j < COUNT; ++j) {
            out << " " << measures[i][j];
            if (j != COUNT - 1)
                out << ",";
        }
        out << '\n';
    }
    out.close();
}