#include <iostream>
using namespace std;

class Node {
public:
    int key, height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVL {
public:
    Node* root = nullptr;

    int height(Node* n) { return n ? n->height : 0; }
    int balance(Node* n) { return height(n->left) - height(n->right); }

    Node* right_rotate(Node* y) {
        Node* x = y->left;
        Node* t = x->right;
        x->right = y;
        y->left = t;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    Node* left_rotate(Node* x) {
        Node* y = x->right;
        Node* t = y->left;
        y->left = x;
        x->right = t;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key) node->left = insert(node->left, key);
        else if (key > node->key) node->right = insert(node->right, key);

        node->height = 1 + max(height(node->left), height(node->right));
        int bf = balance(node);

        // Rotations
        if (bf > 1 && key < node->left->key) return right_rotate(node);
        if (bf < -1 && key > node->right->key) return left_rotate(node);
        if (bf > 1 && key > node->left->key) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
        if (bf < -1 && key < node->right->key) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    void insert(int key) { root = insert(root, key); }

    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->key << " ";
        inorder(n->right);
    }
};

int main() {
    AVL t;

    int arr[] = {10, 5, 15, 3, 7};
    for (int x : arr) t.insert(x);

    t.insert(12);

    cout << "Task #3 Final Balanced AVL Tree (Inorder): ";
    t.inorder(t.root);

    cout << "\nHeight of Tree: " << t.height(t.root) << endl;
    cout << "Root Balance Factor: " << t.balance(t.root) << endl;

    if (t.root->left)
        cout << "Left Child BF: " << t.balance(t.root->left) << endl;

    if (t.root->right)
        cout << "Right Child BF: " << t.balance(t.root->right) << endl;

    return 0;
}
