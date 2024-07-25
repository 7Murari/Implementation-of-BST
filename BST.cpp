#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Delete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Delete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Delete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    cout << endl;

    Node* result = search(root, 40);
    if (result) {
        cout << "Found: " << result->key << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
