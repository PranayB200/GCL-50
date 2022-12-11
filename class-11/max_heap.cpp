#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(H) = O(log(n))
 * Aux space: O(H) = O(log(n))
 * SC: O(n)
*/
void top_down_heapify(vector<int> &heap, int index) {

    int left_index = 2*index + 1;
    int right_index = 2*index + 2;

    int largest = index;
    if (left_index < heap.size() and heap[left_index] > heap[largest]) {
        largest = left_index;
    }
    if (right_index < heap.size() and heap[right_index] > heap[largest]) {
        largest = right_index;
    }

    // `largest` is the index of the largest value among heap[index], heap[left_index] and heap[right_index]

    // the node that we are heapifying cannot be moved further down.
    if (largest == index) {
        return;
    }

    swap(heap[index], heap[largest]);
    top_down_heapify(heap, largest);
}

void delete_from_heap(vector<int> &heap) {

}

int main() {

    vector<int> heap = {4, 9, 10, 2, 1, 5, 1};
    top_down_heapify(heap, 0);

    for (int i : heap) {
        cout << i << " ";
    }
}