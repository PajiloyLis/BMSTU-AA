#ifndef LAB_1_DATA_GENERATOR_H
#define LAB_1_DATA_GENERATOR_H

#include<string>
#include<fstream>
#include"time_measures.h"

using namespace std;

string generate_string(int n);

void generate_tests();

void read_test_string_file(vector<string> &strings, const string &filename);

#endif //LAB_1_DATA_GENERATOR_H
