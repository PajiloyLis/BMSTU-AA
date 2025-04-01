#ifndef BIS22U145_ALGO_H
#define BIS22U145_ALGO_H

#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <random>

#define INF 1e9
#define EPS 1e-9

using namespace std;

pair<double, vector<int>> complete_bust(const vector<vector<double>> &g);

pair<double, vector<int>>
ant_algorithm(const vector<vector<double>> &g, int days_cnt = 100, double a = 0.1, double b = 0.9,
              double r = 0.1, int elite_cnt = 4);

bool check_connectivity(const vector<vector<double>> &g);

double calc_q(const vector<vector<double>> &g);

//double calc_q(const vector<vector<pair<double, int>>> &g);

#endif //BIS22U145_ALGO_H
