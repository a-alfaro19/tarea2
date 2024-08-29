#pragma once

class BinarySearchTree {
public:
    struct Node;
    BinarySearchTree();
    ~BinarySearchTree();

    static Node* insertNode(Node* root, int data);

    static Node* searchNode(Node* root, int key);

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    static Node* createNode(int data);

    Node* root;
};

