#ifndef BIS22U145_DATA_GENERATOR_H
#define BIS22U145_DATA_GENERATOR_H

#include <vector>
#include <random>
#include "times_measures.h"
using namespace std;

#define MAX_ELEM_VAL 100

void generate_tests();

void read_test_matrix_file(vector<vector<vector<int>>> &matrices, const string &filename);

#endif //BIS22U145_DATA_GENERATOR_H
