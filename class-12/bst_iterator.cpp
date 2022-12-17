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

stack<Node*> s;

class BSTIterator {


    private:
    void pushLeft(Node *root, stack<Node*> &s) {
        while (root != NULL) {
            s.push(root->left);
            root = root->left;
        }
    }

    public:
    BSTIterator(Node *root) {
        while (!s.empty()) { // since the stack is global..
            s.pop();
        }

        pushLeft(root, s);
    }

    // check if the BST has the next element present
    bool hasNext() {
        return !s.empty();
    }

    // return the next element from the BST
    int next() {
        Node* result = s.top();
        s.pop();
        pushLeft(result->right, s);
        return result->data;
    }
};

/*

while (it.hasNext()) {
    cout << it.next() << endl;
}

[2, 3, 5, 6, 8, 9]
*/

int main() {

    Node *rt = new Node(5);
    rt->left = new Node(3);
    rt->right = new Node(8);
    rt->left->left = new Node(2);
    rt->right->left = new Node(6);
    rt->right->right = new Node(6);

    BSTIterator *it = new BSTIterator(rt);
    while (it->hasNext()) {
        cout << it->next() << endl;
    }

}