#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

/**
 * TC: O(n*log(n) + n*max_deadline)
 * Aux space: O(max_deadline)
 * SC: O(max_deadline + n)
*/

bool comp(Job &a, Job &b) {
    return a.profit > b.profit;
}

int max_profit(vector<Job> jobs) {

    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);

    int max_deadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    vector<bool> slots(max_deadline + 1, true); // all slots are empty

    int result = 0;
    for (int i = 0; i < n; i++) {
        int d = jobs[i].deadline;
        // this job must be accommodated at the rightmost slot available in [1 ... d]
        for (int j = d; j >= 1; j--) {
            if (slots[j]) { // we found an empty slot
                slots[j] = false;
                result += jobs[i].profit;
                break;
            }
        }
    }

    return result;
}

int main() {

    cout << max_profit({{1, 2, 100},
                        {2, 1, 19},
                        {3, 2, 27},
                        {4, 1, 25},
                        {5, 1, 15}}) << endl;
}