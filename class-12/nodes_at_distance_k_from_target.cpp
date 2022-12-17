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

void getPathHelper(Node *root, int x, vector<Node*> &current_path, vector<Node*> &result) {
    if (root == NULL || result.size() > 0) {
        return;
    }

    current_path.push_back(root);
    if (root->data == x) {
        result = current_path;
        return;
    }

    getPathHelper(root->left, x, current_path, result);
    getPathHelper(root->right, x, current_path, result);

    current_path.pop_back();
}


vector<Node*> getPath(Node *root, int x) {
    vector<Node*> current_path;
    vector<Node*> result;

    getPathHelper(root, x, current_path, result);
    return result;
}

/*
finds all the nodes in the subtree of `root` which are at a distance `k` from `root` and pushes
them into `result`.
*/
void nodesAtDistKInSubtree(Node *root, int k, vector<int> &result) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        result.push_back(root->data);
        return;
    }

    nodesAtDistKInSubtree(root->left, k - 1, result);
    nodesAtDistKInSubtree(root->right, k - 1, result);
}

/**
 * TC: 
 * 
 * Time taken to compute the path: O(n)
 * 
 * Time taken to find the nodes at a distance K from a given node, ie `nodesAtDistKInSubtree()`: O(n)
 * number of times `nodesAtDistKInSubtree()` gets invokes: min(k, n-1)
 * Overall for `nodesAtDistKInSubtree()`: O(n * min(k, n-1))
 * 
 * 
 * Theoritically TC: O(n) + O(n * min(k, n-1)) = O(n * min(k, n-1))
 * 
 * But O(n) is a more tighter and valid upper bound for TC of this as we are not traversing the same nodes again and again..
 * 
 * Aux space: 
 * path[] -> O(H)
 * getPath() and nodesAtDistKInSubtree() takes O(H) amount of recursive stack space
 * 
 * Final Aux space: O(H)
 * 
 * SC: O(n)
*/
vector<int> nodesAtDistKFromTarget(Node *root, int target, int k) {

    vector<int> result;
    vector<Node*> path = getPath(root, target);
    int n = path.size();

    // we need all the nodes in the subtree of target which are at a distance K
    nodesAtDistKInSubtree(path[n - 1], k, result);
    k--;

    for (int i = n - 2; i >= 0; i--) {
        // we need all the nodes which are at distance k from path[i]
        if (k == 0) {
            result.push_back(path[i]->data);
            break;
        }
        if (path[i + 1] == path[i]->right) {
            nodesAtDistKInSubtree(path[i]->left, k-1, result);
        } else {
            nodesAtDistKInSubtree(path[i]->right, k-1, result);
        }
        k--;
    }

    return result;
}

int main() {
    Node *rt = new Node(1);
    rt->left = new Node(2);
    rt->right = new Node(3);
    rt->right->left = new Node(4);
    rt->right->right = new Node(5);
    rt->right->right->left = new Node(6);
    rt->right->right->right = new Node(7);
    rt->right->right->left->left = new Node(8);
    rt->right->right->right->right = new Node(9);
    rt->right->right->right->right->left = new Node(10);
    rt->right->right->right->right->left->left = new Node(11);

    vector<int> result = nodesAtDistKFromTarget(rt, 7, 3);
    for (int i : result) {
        cout << i << " ";
    }
}