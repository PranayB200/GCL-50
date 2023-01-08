#include<bits/stdc++.h>
using namespace std;

int max_tasks(vector<int> tasks, int T) {
    int n = tasks.size();
    sort(tasks.begin(), tasks.end());

    for (int i = 0; i < n; i++) {
        if (tasks[i] > T) {
            return i;
        }
        T = T - tasks[i];
    }
    return n;
}

int main() {

    cout << max_tasks({4, 2, 1, 2, 5}, 8);
}