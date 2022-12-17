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

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);

    vector<Node*> result1 = getPath(root, 5);
    vector<Node*> result2 = getPath(root, 7);

    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i]->data << " ";
    }
    cout << endl;

    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i]->data << " ";
    }
    cout << endl;
}