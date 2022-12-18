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

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    add_undirected_edge(adj, 0, 1);
    add_undirected_edge(adj, 0, 4);
    add_undirected_edge(adj, 1, 4);
    add_undirected_edge(adj, 1, 3);
    add_undirected_edge(adj, 3, 4);
    add_undirected_edge(adj, 1, 2);
    add_undirected_edge(adj, 2, 3);

    print_adj_list(adj);
}
