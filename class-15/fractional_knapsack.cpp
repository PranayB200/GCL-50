#include<bits/stdc++.h>
using namespace std;

/**
 * TC: O(n*log(n))
 * Aux space: O(n)
 * SC: O(n)
*/


// {value, weight}
bool comp(pair<int, int> &a, pair<int, int> &b) {
    // sort on the basis of value/weight
    return (a.first / (double)a.second) > (b.first / (double)b.second);
}

double max_value(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        items[i] = {vals[i], wts[i]};
    }

    sort(items.begin(), items.end(), comp);

    double total_value = 0;
    for (int i = 0; i < n; i++) {
        if (items[i].second <= W) {
            total_value = total_value + items[i].first;
            W = W - items[i].second;
        } else {
            total_value = total_value + (items[i].first * W)/(items[i].second);
            W = 0;
            break;
        }
    }
    return total_value;
}

int main() {
    cout << max_value({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value({60, 100, 120}, {10, 20, 30}, 55);
}