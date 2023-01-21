#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

// Returns the LCS of s1[i...] and s2[j...]
int lcs_helper(string &s1, int i, string &s2, int j) {

    // base-cases??
    if (i == s1.length() or j == s2.length()) {
        return 0;
    }

    // if the value is computed already, return immediately.
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // if we have a match, we will always consider it in lcs
    if (s1[i] == s2[j]) {
        return memo[i][j] = 1 + lcs_helper(s1, i + 1, s2, j + 1);
    }

    // store the result and return.
    return memo[i][j] = max(lcs_helper(s1, i + 1, s2, j),
                            lcs_helper(s1, i, s2, j + 1));
}

int lcs(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();
    memo = vector<vector<int>>(n + 1, vector<int> (m + 1, -1));
    return lcs_helper(s1, 0, s2, 0);
}


int lcs_bottomUp(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // accommodate the base case of empty strings (by filling the 0th row and column with 0).
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][m];
}

int main() {

    cout << lcs("ABCDGH", "AEDFHR") << endl;
    cout << lcs_bottomUp("ABCDGH", "AEDFHR") << endl;
}