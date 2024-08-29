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

void LinkedList::print() const {
    const Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
