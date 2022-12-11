#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n * log(k))
 * Aux space: O(k)
 * SC: O(n)
*/
int kth_largest(vector<int> arr, int k) {

    priority_queue <int, vector<int>, greater<int> > pq; // min-heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {

        // fetch the smallest value from the heap and compare with arr[i]
        if (pq.top() < arr[i]) { // we have a new candidate for k largest elements
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // return the least of the k-largest elements
    return pq.top();
}

int main() {

}