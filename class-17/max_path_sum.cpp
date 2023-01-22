#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

/*
TC: O(n)
Aux space: O(height)
*/

int linear_path_sum(Node *root, int &result) {
    if (root == NULL) {
        return 0;
    }

    int left_sum = linear_path_sum(root->left, result);
    int right_sum = linear_path_sum(root->right, result);

    result = max(result,
                 max(0, left_sum) + root->data + max(0, right_sum));

    return max({root->data,
                root->data + left_sum,
                root->data + right_sum});
}

int max_path_sum(Node *root) {

    int result = INT_MIN;
    linear_path_sum(root, result);
    return result;
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(-1);
    root->right->right = new Node(-10);
    root->right->left->right = new Node(4);

    cout << max_path_sum(root);
}