#include<bits/stdc++.h>
using namespace std;

// TC: O(n * W)
// Aux space: O(n * W)

vector<vector<int>> memo;
int max_value_helper(vector<int> &values, vector<int> &wts, int i, int W) {
    if (i == values.size()) { // no items present
        return 0;
    }
    if (W == 0) { // if the knapsack cannot hold anything more
        return 0;
    }

    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    int result = 0;

    // let's try to include the item in the knapsack if possible
    if (W >= wts[i]) {
        result = max_value_helper(values, wts, i + 1, W - wts[i]) + values[i];
    }

    // option-2: exclude the current item from the knapsack.
    result = max(result, max_value_helper(values, wts, i + 1, W));

    return memo[i][W] = result;
}

int max_value(vector<int> values, vector<int> wts, int W) {

    int n = values.size();
    memo = vector<vector<int>> (n + 1, vector<int> (W + 1, -1));
    return max_value_helper(values, wts, 0, W);
}


int max_value_bottomUp(vector<int> values, vector<int> wts, int W) {

    int n = values.size();

    vector<vector<int>> dp(n + 1, vector<int> (W + 1));

    // accommodate the base cases.
    for (int i = 0; i <= n; i++) { // if capacity is zero.
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++) { // if no items are present
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < wts[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - wts[i - 1]] + values[i - 1], // include the current item
                               dp[i - 1][j]);                             // exclude the current item
            }
        }
    }

    return dp[n][W];
}


int main() {

    cout << max_value({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value_bottomUp({60, 100, 120}, {10, 20, 30}, 50) << endl;
}