#include "algo.h"

void dfs(const vector<vector<double>> &g, vector<bool> &used, int v);

random_device rd;

mt19937 rnd(rd());

bool next_permutation_(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return false;

    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i < 0) {
        std::reverse(nums.begin(), nums.end());
        return false;
    }

    int j = n - 1;
    while (nums[j] <= nums[i]) {
        --j;
    }

    std::swap(nums[i], nums[j]);

    std::reverse(nums.begin() + i + 1, nums.end());

    return true;
}

pair<double, vector<int>> complete_bust(const vector<vector<double>> &g) {
    int n = g.size();
    vector<int> permutation(n);

    vector<int> path;
    double sum = 0, cur_ans = -1;

    for (int i = 0; i < n; ++i)
        permutation[i] = i;

    do {
        for (int i = 1; i < permutation.size(); ++i) {
            sum += g[permutation[i - 1]][permutation[i]];
        }
        if (cur_ans == -1 || cur_ans > sum) {
            path = permutation;
            cur_ans = sum;
        }
        sum = 0;
    } while (next_permutation_(permutation));
    return {cur_ans, path};
}

double calc_q(const vector<vector<double>> &g) {
    double q = 0;
    int count = 0;
    for (const auto &i: g)
        for (double j: i)
            if (j < INF) {
                q += j;
                ++count;
            }
    return q / count;
}


pair<double, vector<int>>
ant_algorithm(const vector<vector<double>> &g, int days_cnt, double a, double b, double r, int elite_cnt) {
    int n = g.size();
    double q = calc_q(g), min_q = 1;
    vector<int> ans(n);
    vector<vector<int>> paths(n, vector<int>(0));
    vector<double> paths_lengths(n, INF);
    vector<vector<double>> pheromones(n, vector<double>(n, min_q));
    vector<bool> visited;
    int visited_cnt, cur_pos;
    vector<double> wishes(n);
    vector<int> cur_path;
    double total_wish, probability, best_path_length, ans_path_length = INF, cur_length;
    for (int t = 0; t < days_cnt; ++t) {
        for (int ant = 0; ant < n; ++ant) {
            cur_path.clear();
            cur_length = 0;
            visited.clear();
            visited.resize(n, false);
            cur_pos = ant;
            cur_path.push_back(ant);
            visited[cur_pos] = true;
            visited_cnt = 1;
            while (visited_cnt < n) {
                total_wish = 0;
                for (int i = 0; i < n; ++i)
                    total_wish += ((visited[i] || g[cur_pos][i] >= INF - EPS) ? 0 : pow(1 / g[cur_pos][i], a) *
                                                                                    pow(pheromones[cur_pos][i], b));
                if (abs(total_wish) < EPS) {
                    cur_length=INF;
                    break;
                }
                for (int i = 0; i < n; ++i)
                    wishes[i] = ((visited[i] || g[cur_pos][i] >= INF - EPS) ? 0 : pow(1 / g[cur_pos][i], a) *
                                                                                  pow(pheromones[cur_pos][i], b) /
                                                                                  total_wish);
                probability = (double) rnd() / rnd.max();
                for (int i = 0; i < n; ++i) {
                    if (probability >= wishes[i])
                        probability -= wishes[i];
                    else {
                        cur_length += g[cur_pos][i];
                        cur_pos = i;
                        cur_path.push_back(cur_pos);
                        visited_cnt++;
                        visited[cur_pos] = true;
                    }
                }
            }
            if (cur_length < paths_lengths[ant]) {
                paths_lengths[ant] = cur_length;
                paths[ant] = cur_path;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pheromones[i][j] *= (1 - r);
                if (pheromones[i][j] < min_q)
                    pheromones[i][j] = min_q;
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 1; j < paths[i].size(); ++j) {
                pheromones[paths[i][j - 1]][paths[i][j]] += q / paths_lengths[i];
                pheromones[paths[i][j]][paths[i][j - 1]] += q / paths_lengths[i];
            }

        best_path_length = paths_lengths[0];
        for (int i = 0; i < n; ++i) {
            best_path_length = min(best_path_length, paths_lengths[i]);
//            if (best_path_length < ans_path_length) {
//                ans_path_length = best_path_length;
//                ans = paths[i];
//            }
        }
        for (int i = 0; i < n; ++i) {
            if (abs(paths_lengths[i] - best_path_length) < EPS) {
                for (int j = 1; j < paths[i].size(); ++j) {
                    pheromones[paths[i][j - 1]][paths[i][j]] += elite_cnt * q / paths_lengths[i];
                    pheromones[paths[i][j]][paths[i][j - 1]] += elite_cnt * q / paths_lengths[i];
                }
            }
        }
    }
    ans_path_length = paths_lengths[0];
    ans = paths[0];
    for (int i = 0; i < n; ++i) {
//        best_path_length = min(best_path_length, paths_lengths[i]);
            if (paths_lengths[i] < ans_path_length) {
                ans_path_length = paths_lengths[i];
                ans = paths[i];
            }
    }
    return {ans_path_length, ans};
}

bool check_connectivity(const vector<vector<double>> &g) {
    vector<bool> used(g.size());
    dfs(g, used, 0);
    for (int i = 0; i < g.size(); ++i)
        if (!used[i])
            return false;
    return true;
}

void dfs(const vector<vector<double>> &g, vector<bool> &used, int v) {
    used[v] = true;
    for (int u = 0; u < g.size(); ++u)
        if (!used[u] && g[v][u] < INF)
            dfs(g, used, u);
}