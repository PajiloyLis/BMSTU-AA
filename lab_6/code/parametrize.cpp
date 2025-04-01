#include "parametrize.h"

#define REPEATS 11
#define ALPHA_STEP 0.1
#define R_MIN 0.1
#define R_STEP 0.1
#define ELITE_MIN 0
#define ELITE_STEP 5
#define ELITE_MAX 20
#define DAYS_MIN 100
#define DAYS_MAX 1000
#define DAYS_STEP 50

#define NANO (int)(1e9)

double average(const vector<double> &deltas);

void parametrize() {
    for (int i = 2; i < 3; ++i) {
        cout << fixed << setprecision(2);
        cout << "GRAPH № " << i + 1 << '\n';
        ifstream in;
        in.open("graph" + to_string(i) + ".txt", ios_base::in);
        int n, m;
        in >> n >> m;
        vector<vector<double>> g_m(n, vector<double>(n, INF));
        int a, b;
        double c;
        double start_q = 0;
        for (int j = 0; j < m; ++j) {
            in >> a >> b >> c;
            --a, --b;
            g_m[a][b] = min(g_m[a][b], c);
            g_m[b][a] = min(g_m[b][a], c);
            start_q += c;
        }
        in.close();
        ofstream out;
        pair<double, vector<int>> ans = complete_bust(g_m);
        cout << ans.first << '\n';
        for (int j = 0; j < ans.second.size(); ++j)
            cout << ans.second[j] << " ";
        cout << '\n';
        out.open("params" + to_string(i) + ".csv", ios_base::out);
        out << fixed << setprecision(2);
        out
                << "days count,greedy coefficient,herding coefficient,evaporation coefficient,elite ants count,maximum,average,median\n";
        cout
                << "days count | greedy coefficient | herding coefficient | evaporation coefficient | elite ants count |   maximum   |   average   |   median   |   minimum   | time nsecs\n";
        vector<double> deltas(REPEATS);
        double alpha = 0.0, beta = 1 - alpha, r = R_MIN;
        int elite_cnt = 0, days_cnt = 10;
        while (alpha < 1 + EPS) {
            beta = 1 - alpha;
            r = R_MIN;
            while (r < 1 + EPS) {
                for (elite_cnt = ELITE_MIN; elite_cnt <= ELITE_MAX; elite_cnt += ELITE_STEP) {
                    for (days_cnt = DAYS_MIN; days_cnt <= DAYS_MAX; days_cnt += DAYS_STEP) {
                        timespec start, end;

                        clock_gettime(CLOCK_MONOTONIC, &start);
                        for (int j = 0; j < REPEATS; ++j) {
                            auto cur_ans = ant_algorithm(g_m, days_cnt, alpha, beta, r, elite_cnt);
                            deltas[j] = ans.first - cur_ans.first;
                        }
                        clock_gettime(CLOCK_MONOTONIC, &end);

                        sort(deltas.begin(), deltas.end());
                        double avg = average(deltas);
                        cout << setw(10) << days_cnt << setw(21) << alpha << setw(22) << beta << setw(26)
                             << r << setw(19) << elite_cnt << setw(14)
                             << max(abs(round(deltas.back() * 100) / 100), abs(round(deltas.front() * 100) / 100))
                             << setw(14) << abs(round(avg * 100)) / 100 << setw(13)
                             << abs(round(deltas[REPEATS / 2] * 100) / 100) << setw(14)
                             << min(abs(round(deltas.back() * 100) / 100), abs(round(deltas.front() * 100) / 100))
                             << setw(13) << (end.tv_sec - start.tv_sec) * NANO + (end.tv_nsec - start.tv_nsec) << '\n';
                        out << days_cnt << "," << alpha << "," << beta << ","
                            << r << "," << elite_cnt << ","
                            << max(abs(round(deltas.back() * 100) / 100), abs(round(deltas.front() * 100) / 100))
                            << "," << abs(round(avg * 100) / 100) << ","
                            << abs(round(deltas[REPEATS / 2] * 100) / 100) << '\n';
                    }
                }
                r += R_STEP;
            }
            alpha += ALPHA_STEP;
        }
        out.close();
    }
}

double average(const vector<double> &deltas) {
    double ans = 0;
    for (double delta: deltas)
        ans += delta;
    return ans / deltas.size();
}
