#include<bits/stdc++.h>
using namespace std;

/**
 * TC: O(k^2 * log(k))
 * Aux space: O(k)
 * SC: O(k^2)
*/

vector<int> merge_k_sorted_arrays(vector<vector<int>> arr) {

    int k = arr.size();
    vector<int> result;

    /*
    {value, {i, j}}
    pair.first = value
    pair.second = {i, j} ->
        pair.second.first = i
        pair.second.second = j
    */
    priority_queue<pair<int, pair<int, int>>> pq; // assume this is a min-heap
 
    // push all the starting elements into the heap so that we have k-pointers ready
    for (int i = 0; i < k; i++) {
        pq.push({-arr[i][0], {i, 0}});
    }

    while (!pq.empty()) {

        pair<int, pair<int, int>> current = pq.top();
        pq.pop();

        result.push_back(-current.first);

        int i = current.second.first;
        int j = current.second.second;

        // now push the element which is at the right of the current element
        if (j + 1 < k) {
            pq.push({-arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {

    vector<int> result = merge_k_sorted_arrays({{1, 7, 10},
                                                {3, 4, 8},
                                                {2, 6, 9}});
    for (int i : result) {
        cout << i << " ";
    }
}