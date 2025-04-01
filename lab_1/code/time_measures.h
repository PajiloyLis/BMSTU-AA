#ifndef LAB_1_TIME_MEASURES_H
#define LAB_1_TIME_MEASURES_H

#include<ctime>
#include"algo.h"
#include"data_generator.h"
#include<fstream>
#include <vector>

#define MAX_LEN 10
#define STEP 1
#define REPEATS 50
#define MIN_LEN 1
#define COUNT (MAX_LEN-MIN_LEN)/STEP+1

using func = int (*)(const string &, const string &);

void measure_algorithms(const vector <pair<string, func>> &algos);

vector <pair<string, double>> measure_algorithms(const vector <pair<string, func>> &algos, string &s1, string &s2);

#endif //LAB_1_TIME_MEASURES_H
