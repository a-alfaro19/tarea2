#include "../include/Algorithms.h"
#include <algorithm>

void ALGORITHMS::bubbleSort(int* array, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                const int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void ALGORITHMS::selectionSort(int* array, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(array[i], array[minIndex]);
    }
}

void ALGORITHMS::mergeSort(int* array, const int size) {
    if (size <= 1) {
        return;
    }

    const int mid = size / 2;

    mergeSort(array, mid);
    mergeSort(array + mid, size - mid);

    const auto temp = new int[size];
    int i = 0, j = mid, k = 0;
    while (i < mid && j < size) {
        if (array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    while (i < mid) {
        temp[k++] = array[i++];
    }

    while (j < size) {
        temp[k++] = array[j++];
    }

    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }

    delete[] temp;
}