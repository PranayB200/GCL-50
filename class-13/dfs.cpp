#include<bits/stdc++.h>
using namespace std;

void add_undirected_edge(vector<vector<int>> &adj, int u, int v) {
    if (u < 0 or u >= adj.size() or v < 0 or v >= adj.size()) {
        return;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print_adj_list(vector<vector<int>> &adj) {

    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/**
 * TC: O(V + E)
 * Aux space: O(V)
 * SC: O(V + E)
*/

void dfs_helper(vector<vector<int>> &adj, int cur, vector<int> &result, vector<bool> &visited) {

    result.push_back(cur);
    visited[cur] = true;

    // explore all the adjacent nodes to `cur` and traverse the unvisted adjacent nodes
    for (int neighbour: adj[cur]) {
        if (!visited[neighbour]) {
            dfs_helper(adj, neighbour, result, visited);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj, int source) {

    vector<int> result;
    int V = adj.size();
    vector<bool> visited(V, false);
    dfs_helper(adj, source, result, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs_helper(adj, i, result, visited);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> adj(9);
    add_undirected_edge(adj, 1, 2);
    add_undirected_edge(adj, 1, 3);
    add_undirected_edge(adj, 1, 4);
    add_undirected_edge(adj, 2, 5);
    add_undirected_edge(adj, 2, 6);
    add_undirected_edge(adj, 3, 7);
    add_undirected_edge(adj, 4, 8);
    add_undirected_edge(adj, 8, 0);

    // print_adj_list(adj);

    vector<int> result = dfs(adj, 1);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    vector<vector<int>> adj2(6);
    add_undirected_edge(adj2, 0, 1);
    add_undirected_edge(adj2, 0, 2);
    add_undirected_edge(adj2, 2, 3);
    add_undirected_edge(adj2, 4, 5);
    vector<int> result2 = dfs(adj2, 0);
    for (int i : result2) {
        cout << i << " ";
    }
}