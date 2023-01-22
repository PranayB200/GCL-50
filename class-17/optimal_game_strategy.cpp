#include<bits/stdc++.h>
using namespace std;

/*
TC: O(n^2)
Aux space: O(n^2)
*/

vector<vector<int>> memo;
int max_score_helper(vector<int> &coins, int i, int j) {
    if (i > j) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j]; 
    }

    // try choosing the i-th coin
    int score1 = coins[i] + min(max_score_helper(coins, i + 2, j),    
                                max_score_helper(coins, i + 1, j - 1));

    // try choosing the j-th coin
    int score2 = coins[j] + min(max_score_helper(coins, i + 1, j - 1),    
                                max_score_helper(coins, i, j - 2));

    return memo[i][j] = max(score1, score2);
}


int max_score(vector<int> coins) {
    int n = coins.size();
    memo = vector<vector<int>> (n, vector<int> (n, -1));
    return max_score_helper(coins, 0, coins.size() - 1);
}

int main() {

    cout << max_score({5, 3, 7, 10}) << endl;
    cout << max_score({8, 15, 3, 7}) << endl;
}