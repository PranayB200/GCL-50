#include<bits/stdc++.h>
using namespace std;

/**
 * TC: O(V + E)
 * Aux space: O(V)
 * SC: O(V + E)
*/

bool isCyclicUtil(vector<vector<int>> &adj, int cur, vector<bool> &vis, vector<bool> &recStack) {

    vis[cur] = true;
    recStack[cur] = true;

    for (int i : adj[cur]) {
        if (recStack[i]) {
            return true;
        }
        if (!vis[i] && isCyclicUtil(adj, i, vis, recStack)) {
            return true;
        }
    }

    recStack[cur] = false;
    return false;
}

bool isCyclic(vector<vector<int>> adj) {
    int V = adj.size();
    vector<bool> vis(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i] && isCyclicUtil(adj, i, vis, recStack)) {
            return true;
        }
    }
    return false;
}

int main() {

    cout << isCyclic({{2},
                      {3},
                      {1},
                      {2}}) << endl;

    cout << isCyclic({{2},
                      {2, 3},
                      {},
                      {2}}) << endl;
}