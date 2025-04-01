#ifndef LAB_3_TIME_MEASURES_H
#define LAB_3_TIME_MEASURES_H

#include <ctime>
#include "algo.h"
#include "data_generator.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_LEN 475
#define STEP 50
#define REPEATS 10
#define MIN_LEN 25
#define COUNT (MAX_LEN-MIN_LEN)/STEP+1

using func = vector<vector<int>> (*)(const vector<vector<int>> &, const vector<vector<int>> &);

void measure_algorithms(const vector <pair<string, func>> &algos);

#endif //LAB_3_TIME_MEASURES_H
