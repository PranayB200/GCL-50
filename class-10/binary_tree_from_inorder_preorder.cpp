#include <bits/stdc++.h>
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

/**
 * TC: O(n^2)
 * Aux space: O(n)
 * SC: O(n) + O(n) + O(n) = O(n)
*/


Node *helper(vector<int> &in, vector<int> &pre, int low, int high, int &pre_index) {

    // base-case: when the inorder traversal of the current subtree is empty
    if (low > high) {
        return NULL;
    }

    Node *root = new Node(pre[pre_index]);
    pre_index++;

    // search for the root node in inorder traversal
    int in_index = low;
    for (int i = low + 1; i < high; i++) {
        if (in[i] == root->data) {
            in_index = i;
            break;
        }
    }

    root->left = helper(in, pre, low, in_index - 1, pre_index);
    root->right = helper(in, pre, in_index + 1, high, pre_index);

    return root;
}

Node* build_tree_from_inorder_preorder(vector<int> &in, vector<int> &pre) {

    int n = in.size();

    int pre_index = 0;
    return helper(in, pre, 0, n - 1, pre_index);
}

int main() {

    // Node *root = build_tree_from_inorder_preorder({}, {});
}