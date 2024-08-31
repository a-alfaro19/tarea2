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