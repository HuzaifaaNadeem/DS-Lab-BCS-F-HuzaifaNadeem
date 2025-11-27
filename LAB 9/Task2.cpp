#include <iostream>
using namespace std;

class Node {
public:
    int key, height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() { root = nullptr; }

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int update_height(Node* n) {
        return 1 + max(height(n->left), height(n->right));
    }

    Node* left_rotate(Node* x) {
        Node* y = x->right;
        Node* t = y->left;

        y->left = x;
        x->right = t;

        x->height = update_height(x);
        y->height = update_height(y);

        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        node->height = update_height(node);

        return node;  
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->key << " ";
        inorder(n->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) tree.insert(x);

    tree.insert(55);

    
    tree.root = tree.left_rotate(tree.root);

    cout << "Task #2 Output (After inserting 55 and left rotating root):\n";
    tree.display();

    return 0;
}
