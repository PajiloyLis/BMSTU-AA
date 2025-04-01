#ifndef BIS22U145_COMPARISONS_MEASURES_H
#define BIS22U145_COMPARISONS_MEASURES_H

#include <vector>
#include <fstream>
#include "data_generator.h"

using namespace std;

#define ARRAY_LEN 1041

using func = pair<int, int> (*)(const vector<int> &, int);

void measure_algorithms(const vector <pair<string, func>> &algos);

#endif //BIS22U145_COMPARISONS_MEASURES_H
