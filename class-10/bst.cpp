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
 * TC: O(H)
 * Aux space: O(H)
 * SC: O(n)
*/
bool search(Node *root, int x) {
    // base-case
    if (root == NULL) {
        return false;
    }

    if (root->data == x) {
        return true;
    }
    if (x > root->data) {
        return search(root->right, x);
    }
    return search(root->left, x);
}

/**
 * TC: O(H)
 * Aux space: O(1)
 * SC: O(n)
*/
bool searchIterative(Node *root, int x) {

    while (root != NULL) {
        if (root->data == x) {
            return true;
        }
        if (x > root->data) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return false;
}

/**
 * TC: O(H)
 * Aux space: O(H)
 * SC: O(n)
*/
// This function takes the root node as input and returns the modified root after inserting x.
Node* insert(Node *root, int x) {

    // base-case
    if (root == NULL) {
        return new Node(x);
    }

    // if the value is already present
    if (root->data == x) {
        return root;
    }

    // insert(root->right, x): return the modified root node of the tree rooted at (root->right) after inserting x.
    if (x > root->data) {
        root->right = insert(root->right, x);
    } else {
        root->left = insert(root->left, x);
    }
    return root;
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

    cout << search(root, 9) << endl;
    cout << searchIterative(root, 9) << endl;

    cout << search(root, 6) << endl;
    cout << searchIterative(root, 6);
}