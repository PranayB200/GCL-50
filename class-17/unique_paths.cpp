#include<bits/stdc++.h>
using namespace std;

/*
TC: O(n * m)
Aux space: O(n * m)
*/
int count_unique_paths(vector<vector<int>> grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> result(n, vector<int> (m));

    // fill the 0th row
    int j = 0;
    while (j < m && grid[0][j] != 1) {
        result[0][j] = 1;
        j++;
    }
    while (j < m) {
        result[0][j] = 0;
        j++;
    }

    // fill the 0th col
    int i = 0;
    while (i < n && grid[i][0] != 1) {
        result[i][0] = 1;
        i++;
    }
    while (i < n) {
        result[i][0] = 0;
        i++;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == 1) {
                result[i][j] = 0;
            } else {
                result[i][j] = result[i][j - 1] + result[i - 1][j];
            }
        }
    }

    return result[n - 1][m - 1];
}

int main() {
    cout << count_unique_paths({{0, 1, 0, 1},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 1, 0}}) << endl;
}