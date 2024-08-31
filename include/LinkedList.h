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
     * @param value The data to be searched
     * @return True if the value is found, false otherwise
     */
    bool search(int value) const;

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

