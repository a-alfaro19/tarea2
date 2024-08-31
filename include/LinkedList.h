#pragma once

class LinkedList {
public:
    /**
     * Constructor
     */
    LinkedList();

    /**
     * Destructor
     */
    ~LinkedList();

    /**
     * Insert a new node at the end of the list
     * @param data The data to be inserted
     */
    void insert(int data);

    /**
     * Search for a node in the list
     * @param data The data to be searched
     * @return The index of the node in the list
     */
    int search(int data) const;

    /**
     * Print the list
     */
    void print() const;

private:
    /**
     * Node structure
     */
    struct Node {
        int data;
        Node* next;
    };

    Node* head; ///< The head of the list
};

