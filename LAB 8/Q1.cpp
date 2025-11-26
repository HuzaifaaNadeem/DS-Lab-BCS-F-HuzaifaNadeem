#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert_node(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert_node(root->left, key);
    else if (key > root->data)
        root->right = insert_node(root->right, key);

    return root;
}

Node* search_node(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search_node(root->left, key);
    
    return search_node(root->right, key);
}

Node* find_min(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* delete_node(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = delete_node(root->left, key);
    }
    else if (key > root->data) {
        root->right = delete_node(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Searching 40: ";
    if (search_node(root, 40))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Deleting 20..." << endl;
    root = delete_node(root, 20);
    inorder(root);
    cout << endl;

    cout << "Deleting 30..." << endl;
    root = delete_node(root, 30);
    inorder(root);
    cout << endl;

    cout << "Deleting 50..." << endl;
    root = delete_node(root, 50);
    inorder(root);
    cout << endl;

    return 0;
}
