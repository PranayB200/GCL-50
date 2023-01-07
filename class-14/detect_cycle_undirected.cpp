#include<bits/stdc++.h>
using namespace std;

/**
 * TC: O(V + E)
 * Aux space: O(V)
 * SC: O(V + E)
*/

// recursive dfs based function
bool isCyclicUtil(vector<vector<int>> &adj, int cur, int parent, vector<bool> &vis) {
    
    vis[cur] = true;
    for (int i : adj[cur]) {
        if (vis[i] && i != parent) {
            return true;
        }
        if (!vis[i] && isCyclicUtil(adj, i, cur, vis)) {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>> adj) {
    int V = adj.size();
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i] && isCyclicUtil(adj, i, -1, vis)) {
            return true;
        }
    }
    return false;
}

int main() {

    cout << isCyclic({{0},
                      {0, 2, 3},
                      {1, 3},
                      {1, 2}}) << endl;
    
    cout << isCyclic({{1},
                      {0},
                      {3},
                      {2},
                      {}}) << endl;
}