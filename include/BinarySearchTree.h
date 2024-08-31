#pragma once

class BinarySearchTree {
public:
    /**
     * Constructor
     */
    BinarySearchTree();

    /**
     * Destructor
     */
    ~BinarySearchTree();

    /**
     * Insert a new node in the tree
     * @param data The data to be inserted
     */
    void insert(int data);

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    /**
     * Insert a new node in the tree
     * @param root The root of the tree
     * @param data The data to be inserted
     * @return The root of the tree
     */
    static Node* insertNode(Node* root, int data);

    /**
     * Create a new node
     * @param data The data of the node
     * @return The new node
     */
    static Node* createNode(int data);

    Node* root; ///< The root of the tree
};

