#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head) {
        const Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(const int data) {
    const auto newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::remove(const int data) {
    if (!head) {
        return;
    }

    if (head->data == data) {
        const Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        if (temp->next->data == data) {
            const Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
}

int LinkedList::search(const int data) const {
    if (!head) {
        return -1;
    }

    int index = 0;
    const Node* temp = head;
    while (temp) {
        if (temp->data == data) {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;
}

void LinkedList::print() const {
    const Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void LinkedList::bubbleSort() const {
    if (!head) {
        return;
    }

    bool swapped;
    const Node* last = nullptr;

    do {
        swapped = false;
        Node *temp = head;

        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                const int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
}

void LinkedList::selectionSort() const {
    if (!head) {
        return;
    }

    Node* temp = head;
    while (temp) {
        Node* min = temp;
        Node* r = temp->next;

        while (r) {
            if (min->data > r->data) {
                min = r;
            }
            r = r->next;
        }

        const int tempData = temp->data;
        temp->data = min->data;
        min->data = tempData;
        temp = temp->next;
    }
}

void LinkedList::insertionSort() {
    if (!head) {
        return;
    }

    Node* temp = head;
    Node* sorted = nullptr;

    while (temp) {
        Node* next = temp->next;

        if (!sorted || sorted->data >= temp->data) {
            temp->next = sorted;
            sorted = temp;
        } else {
            Node* current = sorted;
            while (current->next && current->next->data < temp->data) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }

        temp = next;
    }

    head = sorted;
}
