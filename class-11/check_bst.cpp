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
 * TC: O(n)
 * Aux Space: O(height)
 * SC: O(n)
*/

// Space Complexity: input space + aux space + output space


bool check_bst_helper(Node *root, int low, int high) {

    // base-case
    if (root == NULL) {
        return true;
    }

    /*
    check:
        1. if the current node lies in its permissible range.
        2. if the left subtree is a bst (after tweaking the upper bound).
        3. if the right subtree is a bst (after tweaking the lower bound).
    */

   return 
        (root->data >= low and root->data <= high) and
        check_bst_helper(root->left, low, root->data - 1) and
        check_bst_helper(root->right, root->data + 1, high);

}

bool check_bst(Node *root) {
    return check_bst_helper(root, INT_MIN, INT_MAX);
}

int main() {
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(10);
    root->right->right->left = new Node(9);

    cout << check_bst(root);
}