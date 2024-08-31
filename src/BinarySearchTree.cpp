#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() = default;

void BinarySearchTree::insert(const int data) {
    root = insertNode(root, data);
}

BinarySearchTree::Node* BinarySearchTree::insertNode(Node* root, const int data) {
    if (root == nullptr) return createNode(data);

    if (data < root->data) root->left = insertNode(root->left, data);
    else if(data > root->data) root->right = insertNode(root->right, data);
    return root;
}

BinarySearchTree::Node *BinarySearchTree::createNode(const int data) {
    const auto newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}