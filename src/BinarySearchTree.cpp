#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() = default;

BinarySearchTree::Node* BinarySearchTree::insertNode(Node* root, const int data) {
    if (root == nullptr) return createNode(data);

    if (data < root->data) root->left = insertNode(root->left, data);
    else if(data > root->data) root->right = insertNode(root->right, data);
    return root;
}

BinarySearchTree::Node* BinarySearchTree::searchNode(Node* root, const int key) {
    if (root == nullptr || root->data == key) return root;
    if (root->data < key) return searchNode(root->right, key);
    return searchNode(root->left, key);
}

BinarySearchTree::Node *BinarySearchTree::createNode(const int data) {
    const auto newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}