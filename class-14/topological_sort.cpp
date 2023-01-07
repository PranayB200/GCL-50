#include<bits/stdc++.h>
using namespace std;

/**
 * TC: O(V + E)
 * Aux space: O(V)
 * SC: O(V + E)
*/

void dfsUtilForTopoSort(vector<vector<int>> &adj, int cur, vector<bool> &vis, stack<int> &helper) {
    if (vis[cur]) {
        return;
    }
    vis[cur] = true;

    for (int i : adj[cur]) {
        dfsUtilForTopoSort(adj, i, vis, helper);
    }

    helper.push(cur);
}

vector<int> topoSort(vector<vector<int>> adj) {

    int V = adj.size();
    vector<bool> vis(V, false);
    stack<int> helper;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtilForTopoSort(adj, i, vis, helper);
        }
    }

    vector<int> result;
    while (!helper.empty()) {
        result.push_back(helper.top());
        helper.pop();
    }
    return result;
}

int main() {

    vector<int> topo = topoSort({{},
                                 {3},
                                 {3},
                                 {},
                                 {0, 1},
                                 {0, 2}});

    for (int i : topo) {
        cout << i << " ";
    }
}