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
    int update(Node* n) { return 1 + max(height(n->left), height(n->right)); }

    Node* right_rotate(Node* y) {
        Node* x = y->left;
        Node* t = x->right;
        x->right = y;
        y->left = t;
        y->height = update(y);
        x->height = update(x);
        return x;
    }

    Node* left_rotate(Node* x) {
        Node* y = x->right;
        Node* t = y->left;
        y->left = x;
        x->right = t;
        x->height = update(x);
        y->height = update(y);
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key) node->left = insert(node->left, key);
        else if (key > node->key) node->right = insert(node->right, key);

        node->height = update(node);
        int bf = height(node->left) - height(node->right);

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

    void insert(int k) { root = insert(root, k); }

    int count(Node* n) {
        return n ? 1 + count(n->left) + count(n->right) : 0;
    }

    int kth_smallest(Node* n, int k) {
        int left = count(n->left);

        if (k == left + 1) return n->key;
        if (k <= left) return kth_smallest(n->left, k);
        return kth_smallest(n->right, k - left - 1);
    }

    int kth_largest(Node* n, int k) {
        int total = count(root);
        return kth_smallest(root, total - k + 1);
    }
};

int main() {
    AVL t;
    int arr[] = {20, 4, 26, 3, 9, 15};
    for (int x : arr) t.insert(x);

    cout << "Task #4:\n";
    cout << "2nd Smallest = " << t.kth_smallest(t.root, 2) << endl;
    cout << "3rd Largest = " << t.kth_largest(t.root, 3) << endl;

    cout << "Left Subtree Height = " << t.height(t.root->left) << endl;
    cout << "Right Subtree Height = " << t.height(t.root->right) << endl;

    return 0;
}
