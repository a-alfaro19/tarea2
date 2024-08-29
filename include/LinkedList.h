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
     * Remove a node from the list
     * @param data The data to be removed
     */
    void remove(int data);

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

