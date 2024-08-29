#include <iostream>
#include <random>

#include "LinkedList.h"

void insertRandomElements(LinkedList& list, const int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < n; i++) {
        list.insert(dis(gen));
    }
}

void removeElements(LinkedList& list, const int n) {
    for (int i = 0; i < n; i++) {
        list.remove(i);
    }
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    LinkedList list;
    insertRandomElements(list, 10);
    list.print();
    list.insertionSort();
    list.print();
    // removeElements(list, 10);
    // list.print();

    return 0;
}
