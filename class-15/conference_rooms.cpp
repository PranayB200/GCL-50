#include<bits/stdc++.h>
using namespace std;

/**
 * TC: O(n * log(n))
 * Aux space: O(n)
 * SC: O(n)
*/

// bool comp(pair<int, char> &a, pair<int, char> &b) {
//     if (a.first == b.first) {
//         if (a.second == 'e') {
//             return true;
//         }
//         return false;
//     }
//     return a.first < b.first;
// }

int min_conf_rooms(vector<vector<int>> meetings) {
    int n = meetings.size();

    // {time, +-1} (+1 for start event, -1 for end event)
    vector<pair<int, int>> timeline;

    for (int i = 0; i < n; i++) {
        timeline.push_back({meetings[i][0], +1}); // start time of ith meeting
        timeline.push_back({meetings[i][1], -1}); // end time of ith meeting
    }

    sort(timeline.begin(), timeline.end());

    int current_events = 0, max_events = 0;
    for (int i = 0; i < timeline.size(); i++) {
        // if (timeline[i].second == +1) {
        //     current_events++;
        // } else {
        //     current_events--;
        // }
        current_events += timeline[i].second;
        max_events = max(max_events, current_events);
    }
    return max_events;
}

int main() {

    cout << min_conf_rooms({{1, 18},
                            {18, 23},
                            {15, 29},
                            {4, 15},
                            {2, 11},
                            {5, 13}}) << endl;
}