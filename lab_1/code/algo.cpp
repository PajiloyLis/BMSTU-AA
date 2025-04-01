#include "algo.h"

#define M_INF -1

int levenstein_recursion_memoization(const string &s1, const string &s2, vector <vector<int>> &dp);

int levenstein(const string &s1, const string &s2) {
    int n = static_cast<int>(s1.size()) + 1,
            m = static_cast<int>(s2.size()) + 1;
    vector <vector<int>> dp(n, vector<int>(m));
    for (int i = 1; i < n; ++i)
        dp[i][0] = i;
    for (int j = 1; j < m; ++j)
        dp[0][j] = j;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return dp[n - 1][m - 1];
}


int levenstein_memoization(const string &s1, const string &s2) {
    int n = static_cast<int>(s1.size()) + 1,
            m = static_cast<int>(s2.size()) + 1;
    vector <vector<int>> dp(2, vector<int>(m));
    for (int j = 1; j < m; ++j)
        dp[0][j] = j;
    int cur = 1, prev = 0;
    for (int i = 1; i < n; ++i) {
        dp[cur][0] = i;
        for (int j = 1; j < m; ++j) {
            dp[cur][j] = min(dp[cur][j - 1], dp[prev][j]) + 1;
            if (s1[i - 1] == s2[j - 1])
                dp[cur][j] = min(dp[cur][j], dp[prev][j - 1]);
            else
                dp[cur][j] = min(dp[cur][j], dp[prev][j - 1] + 1);
        }
        cur ^= 1, prev ^= 1;
    }
    return dp[prev][m - 1];
}

int levenstein_recursion(const string &s1, const string &s2) {
    if (s1.empty())
        return static_cast<int>(s2.size());
    else if (s2.empty())
        return static_cast<int>(s1.size());
    else {
        int ans = min(levenstein_recursion(s1.substr(0, s1.size() - 1), s2),
                      levenstein_recursion(s1, s2.substr(0, s2.size() - 1))) + 1;
        if (s1[s1.size() - 1] == s2[s2.size() - 1])
            return min(ans, levenstein_recursion(s1.substr(0, s1.size() - 1), s2.substr(0, s2.size() - 1)));
        else
            return min(ans, levenstein_recursion(s1.substr(0, s1.size() - 1), s2.substr(0, s2.size() - 1)) + 1);
    }
}

int levenstein_recursion_memoization(const string &s1, const string &s2) {
    int n = static_cast<int>(s1.size()) + 1, m = static_cast<int>(s2.size()) + 1;
    if (s1.empty())
        return static_cast<int>(s2.size());
    else if (s2.empty())
        return static_cast<int>(s1.size());
    else {
        vector <vector<int>> dp(n, vector<int>(m, -1));
        return dp[s1.size()][s2.size()] = levenstein_recursion_memoization(s1, s2, dp);
    }
}

int levenstein_recursion_memoization(const string &s1, const string &s2, vector <vector<int>> &dp) {
    if (dp[s1.size()][s2.size()] == -1) {
        if (s1.empty())
            return static_cast<int>(s2.size());
        else if (s2.empty())
            return static_cast<int>(s1.size());
        else {
            dp[s1.size()][s2.size()] = min(levenstein_recursion_memoization(s1.substr(0, s1.size() - 1), s2, dp),
                                           levenstein_recursion_memoization(s1, s2.substr(0, s2.size() - 1), dp)) +
                                       1;
            if (s1[s1.size() - 1] == s2[s2.size() - 1])
                return dp[s1.size()][s2.size()] = min(dp[s1.size()][s2.size()],
                                                      levenstein_recursion(s1.substr(0, s1.size() - 1),
                                                                           s2.substr(0, s2.size() - 1)));
            else
                return dp[s1.size()][s2.size()] = min(dp[s1.size()][s2.size()],
                                                      levenstein_recursion(s1.substr(0, s1.size() - 1),
                                                                           s2.substr(0, s2.size() - 1)) + 1);
        }
    }
    return dp[s1.size()][s2.size()];
}

int damerau_levenstein(const string &s1, const string &s2) {
    int n = static_cast<int>(s1.size()) + 1, m = static_cast<int>(s2.size()) + 1;
    vector <vector<int>> dp(3, vector<int>(m));
    for (int i = 1; i < m; ++i) {
        dp[0][i] = i;
    }
    int cur = 1, prev = 0, pprev = -1;
    for (int i = 1; i < n; ++i) {
        dp[cur][0] = i;
        for (int j = 1; j < m; ++j) {
            dp[cur][j] = min(dp[prev][j], dp[cur][j - 1]) + 1;
            if (s1[i - 1] == s2[j - 1])
                dp[cur][j] = min(dp[cur][j], dp[prev][j - 1]);
            else
                dp[cur][j] = min(dp[cur][j], dp[prev][j - 1] + 1);
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1])
                dp[cur][j] = min(dp[cur][j], dp[pprev][j - 2] + 1);
        }
        cur = static_cast<int>((cur + 1) % dp.size()),
        prev = static_cast<int>((prev + 1) % dp.size()),
        pprev = static_cast<int>((pprev + 1) % dp.size());
    }
    return dp[prev][m - 1];
}