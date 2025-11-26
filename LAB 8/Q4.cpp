#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    Node* insertNode(Node* r, int v) {
        if (!r) return new Node(v);
        if (v < r->val) r->left = insertNode(r->left, v);
        else r->right = insertNode(r->right, v);
        return r;
    }

    void insertValue(int v) {
        root = insertNode(root, v);
    }

    bool searchNode(Node* r, int v) {
        if (!r) return false;
        if (r->val == v) return true;
        if (v < r->val) return searchNode(r->left, v);
        return searchNode(r->right, v);
    }

    bool searchValue(int v) {
        return searchNode(root, v);
    }

    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->val << " ";
        inorder(r->right);
    }

    void printTree() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST t;

    t.insertValue(50);
    t.insertValue(30);
    t.insertValue(70);
    t.insertValue(20);
    t.insertValue(40);
    t.insertValue(60);
    t.insertValue(80);

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    if (t.searchValue(x)) {
        cout << "Value found in tree" << endl;
    } else {
        cout << "Value not found. Inserting..." << endl;
        t.insertValue(x);
        cout << "Updated Tree: ";
        t.printTree();
    }

    return 0;
}

