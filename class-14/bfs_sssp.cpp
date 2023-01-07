#include<bits/stdc++.h>
using namespace std;

/**
 * TC: O(V + E)
 * Aux space: O(V)
 * SC: O(V + E)
*/

vector<int> sssp_unwieghted(vector<vector<int>> adj, int source) {

    int V = adj.size();
    vector<int> distances(V, 1000000);
    vector<bool> vis(V, false);

    queue<int> q;
    q.push(source);
    distances[source] = 0;
    vis[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i : adj[current]) {
            if (!vis[i]) {
                distances[i] = distances[current] + 1;
                vis[i] = true;
                q.push(i);
            }
        }
    }

    return distances;
}

int main() {

    vector<int> result = sssp_unwieghted({{1, 2},
                                          {0, 3, 4},
                                          {0, 5},
                                          {1},
                                          {1, 5},
                                          {4, 2}}, 0);
    
    for (int i = 0; i < result.size(); i++) {
        cout << i << " -> " << result[i] << endl;
    }
}