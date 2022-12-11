#include <bits/stdc++.h>
using namespace std;


/*
class MaxHeap {
    // function to insert
    // function to delete
    // function to get the max element
}
*/

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

/**
 * TC: O(H) = O(log(n))
 * Aux space: O(H) = O(log(n))
 * SC: O(n)
*/
void delete_from_heap(vector<int> &heap) {

    if (heap.size() == 0) {
        return;
    }

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    top_down_heapify(heap, 0);
}



/**
 * TC: O(H) = O(log(n))
 * Aux space: O(H) = O(log(n))
 * SC: O(n)
*/
void bottom_up_heapify(vector<int> &heap, int index) {

    int parent_index = (index - 1) / 2;

    if (heap[index] > heap[parent_index]) {
        swap(heap[index], heap[parent_index]);
        bottom_up_heapify(heap, parent_index);
    }
}

/**
 * TC: O(H) = O(log(n))
 * Aux space: O(H) = O(log(n))
 * SC: O(n)
*/
void insert_in_heap(vector<int> &heap, int value) {
    heap.push_back(value);
    bottom_up_heapify(heap, heap.size() - 1);
}


int main() {

    vector<int> heap = {4, 9, 10, 2, 1, 5, 1};
    top_down_heapify(heap, 0);

    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> heap2 = {10, 5, 3, 2, 4};
    delete_from_heap(heap2);

    for (int i : heap2) {
        cout << i << " ";
    }
    cout << endl;
}
