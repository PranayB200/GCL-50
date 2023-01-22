#include<bits/stdc++.h>
using namespace std;

vector<int> dijsktra(vector<vector<pair<int, int>>> adj, int source) {

    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    dist[source] = 0;
    set<pair<int, int>> tbp;
    tbp.insert({0, source}); // inseting {dist, node value} pair in the set

    while (!tbp.empty()) {

        pair<int, int> current = *(tbp.begin());
        tbp.erase(tbp.begin()); // popping the pair with the shortest distance

        int u = current.second;
        int d = current.first;

        for (pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int wt = neighbor.second;

            if (dist[v] > dist[u] + wt) {
                // erasing the current redundant entry of the current node (if present).
                if (tbp.find({dist[v], v}) != tbp.end()) {
                    tbp.erase(tbp.find({dist[v], v}));
                }

                dist[v] = dist[u] + wt;
                tbp.insert({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    vector<int> dist = 
        dijsktra({{{1, 4}, {7, 8}},
              {{0, 4}, {7, 11}, {2, 8}},
              {{1, 8}, {8, 2}, {5, 4}, {3, 7}},
              {{2, 7}, {5, 14}, {4, 9}},
              {{3, 9}, {5, 10}},
              {{4, 10}, {3, 14}, {2, 4}, {6, 2}},
              {{5, 2}, {8, 6}, {7, 1}},
              {{6, 1}, {8, 7}, {1, 11}, {0, 8}},
              {{2, 2}, {6, 6}, {7, 7}}}, 0);

    for (int i = 0; i < dist.size(); i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}