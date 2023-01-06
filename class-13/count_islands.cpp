#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, +0, +0, +1, +1, +1};
int dy[8] = {-1, +0, +1, -1, +1, -1, +0, +1};

void dfs(vector<vector<int>> &arr, int i, int j) {
    if (i < 0 or i >= arr.size() or j < 0 or j >= arr[0].size() or arr[i][j] == 0) {
        return;
    }
    arr[i][j] = 0; // just so that it does not get visited again

    // visit the land patches in all of its 8 adjacent vertices
    for (int k = 0; k < 8; k++) {
        dfs(arr, i + dx[k], j + dy[k]);
    }
}


/**
 * TC: O(n*m)
 * Aux Space: O(n*m)
 * SC: O(n*m)
*/
int count_islands(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                dfs(arr, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    cout << count_islands({{0, 0, 1, 0, 1, 0},
                           {0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 1, 1}}) << endl;

    cout << count_islands({{0, 0, 1, 0, 1, 0},
                           {0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0}}) << endl;
}