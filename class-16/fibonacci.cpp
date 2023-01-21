#include<bits/stdc++.h>
using namespace std;


// TC: O(n)
// Aux space: O(n)
int fib_helper(int n, vector<int> &memo) {
    if (n <= 1) {
        return n;
    }

    // if the value has already been computed, return the result immediately.
    if (memo[n] != -1) {
        return memo[n];
    }

    // store the restult in the memo and return;
    memo[n] = fib_helper(n - 1, memo) + fib_helper(n - 2, memo);
    return memo[n];
}

int fib(int n) {
    vector<int> memo(n + 1, -1);
    return fib_helper(n, memo);
}

// TC: O(n)
// Aux space: O(n)
int fib_bottomUp(int n) {

    vector<int> dp(n + 1);

    // filling the base cases.
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}


// TC: O(n)
// Aux space: O(1)
int fib_optimal(int n) {

    if (n <= 1) {
        return n;
    }

    int a = 0; // prev prev
    int b = 1; // prev
    int result;

    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

int main() {

    cout << fib(5) << endl;
    cout << fib_bottomUp(5) << endl;
    cout << fib_optimal(5);
}