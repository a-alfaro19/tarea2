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
     * Search for a node in the list
     * @param data The data to be searched
     * @return The index of the node in the list
     */
    [[nodiscard]] int search(int data) const;

    /**
     * Print the list
     */
    void print() const;

    /**
     * Sort the list using bubble sort
     */
    void bubbleSort() const;

    /**
     * Sort the list using selection sort
     */
    void selectionSort() const;

    /**
     * Sort the list using insertion sort
     */
    void insertionSort();

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

