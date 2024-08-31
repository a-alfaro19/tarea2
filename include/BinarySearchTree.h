#pragma once

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int data);

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* insertNode(Node* root, int data);
    static Node* createNode(int data);

    Node* root;
};

