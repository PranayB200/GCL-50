#include<bits/stdc++.h>
using namespace std;

/*
TC: O(n*m)
Aux space: O(n*m)
*/

vector<vector<int>> memo;

int edit_distance_helper(string &A, int i, string &B, int j) {
    if (i == A.length()) {      // insert in A
        return B.length() - j;
    }
    if (j == B.length()) {      // delete from A
        return A.length() - i;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (A[i] == B[j]) {
        return memo[i][j] = edit_distance_helper(A, i + 1, B, j + 1);
    }

    return memo[i][j] = min({1 + edit_distance_helper(A, i, B, j + 1),        // insert in A
                            1 + edit_distance_helper(A, i + 1, B, j),        // delete from A
                            1 + edit_distance_helper(A, i + 1, B, j + 1)});   // replace in A
}

int edit_distance(string A, string B) {
    int n = A.length();
    int m = B.length();

    memo = vector<vector<int>> (n + 1, vector<int> (m + 1, -1));
    return edit_distance_helper(A, 0, B, 0);
}

int main() {

    cout << edit_distance("abad", "abac") << endl;
    cout << edit_distance("anshuman", "antihuman") << endl;
    
}