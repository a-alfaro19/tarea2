#include <iostream>
#include "LinkedList.h"

void insertElements(LinkedList& list, const int n) {
    for (int i = 0; i < n; i++) {
        list.insert(i);
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
    insertElements(list, 10);
    list.print();
    removeElements(list, 10);
    list.print();

    return 0;
}
