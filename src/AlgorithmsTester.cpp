#include "AlgorithmsTester.h"
#include "Algorithms.h"

#include <chrono>
#include <iostream>
#include <random>

using namespace std;

const vector<int> AlgorithmsTester::sizes = {10, 2507, 5050, 7502, 10000};

AlgorithmsTester::AlgorithmsTester() {
    sortingAlgorithms[0] = BUBBLE_SORT;
    sortingAlgorithms[1] = SELECTION_SORT;
    sortingAlgorithms[2] = MERGE_SORT;

    testCases[0] = BEST_CASE;
    testCases[1] = AVERAGE_CASE;
    testCases[2] = WORST_CASE;
}

optional<vector<double>> AlgorithmsTester::runTest(const string &algorithm, const string &testCase) {
    Algorithms alg;
    TestCase tc;
    try {
        alg = stringToSortingAlgorithm(algorithm);
        tc = stringToTestCase(testCase);
    } catch ([[maybe_unused]] const invalid_argument& e) {
        return nullopt;
    }

    vector<double> results;
    for (const auto& size : sizes) {
        double result;
        switch (alg) {
            case LINKED_LIST_SEARCH:
                result = testSortedLinkedListSearch(tc, size);
                break;
            case BS_TREE_INSERTION:
                result = testBSTreeInsertion(tc, size);
                break;
            default:
                result = testSortAlgorithm(alg, tc, size);
                break;
        }
        results.push_back(result);
    }
    return results;
}

optional<vector<double>> AlgorithmsTester::getTheoreticalComplexity(const string &algorithm, const string &testCase) {
    Algorithms alg;
    TestCase tc;
    try {
        alg = stringToSortingAlgorithm(algorithm);
        tc = stringToTestCase(testCase);
    } catch ([[maybe_unused]] const invalid_argument& e) {
        return nullopt;
    }

    vector<double> results;
    for (const auto& n : sizes) {
        double result;
        switch (alg) {
            case BUBBLE_SORT:
                if (tc == WORST_CASE || tc == AVERAGE_CASE) {
                    result = n * n; // O(n^2)
                } else {
                    result = n; // O(n)
                }
            break;
            case SELECTION_SORT:
                result = n * n; // O(n^2)
            break;
            case MERGE_SORT:
                result = n * log(n); // O(n log n)
            break;
            case LINKED_LIST_SEARCH:
                if (tc == WORST_CASE || tc == AVERAGE_CASE) {
                    result = n; // O(n)
                } else {
                    result = 1; // O(1)
                }
            break;
            case BS_TREE_INSERTION:
                if (tc == BEST_CASE || tc == AVERAGE_CASE) {
                    result = log(n); // O(log n)
                } else {
                    result = n; // O(n)
                }
            break;
        }
        results.push_back(result);
        }
    return results;
}

AlgorithmsTester::TestCase AlgorithmsTester::stringToTestCase(const std::string& testCase) {
    if (testCase == "BEST_CASE") return BEST_CASE;
    if (testCase == "AVG_CASE") return AVERAGE_CASE;
    if (testCase == "WORST_CASE") return WORST_CASE;
    throw std::invalid_argument("Invalid test case");
}

AlgorithmsTester::Algorithms AlgorithmsTester::stringToSortingAlgorithm(const std::string& algorithm) {
    if (algorithm == "BUBBLE_SORT") return BUBBLE_SORT;
    if (algorithm == "SELECTION_SORT") return SELECTION_SORT;
    if (algorithm == "MERGE_SORT") return MERGE_SORT;
    if (algorithm == "LINKED_LIST_SEARCH") return LINKED_LIST_SEARCH;
    if (algorithm == "BS_TREE_INSERTION") return BS_TREE_INSERTION;
    throw std::invalid_argument("Invalid algorithm");
}

void AlgorithmsTester::createSortedArray(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
}

void AlgorithmsTester::createRandomArray(int* array, const int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < size; i++) {
        array[i] = dis(gen);
    }
}

void AlgorithmsTester::createReversedArray(int* array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = size - i;
    }
}

LinkedList* AlgorithmsTester::createSortedList(const int n) {
    auto* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(i);
    }
    return list;
}

BinarySearchTree* AlgorithmsTester::createBalancedTree(const int n) {
    auto* tree = new BinarySearchTree();
    int count = 0;
    while (count != n) {
        constexpr int first = 40;
        tree->insert(first);
        if (count % 2 == 0) {
            tree->insert(first + 20);
        } else {
            tree->insert(first - 20);
        }
        count += 2;

    }
    return tree;
}

BinarySearchTree* AlgorithmsTester::createRandomTree(const int n) {
    auto* tree = new BinarySearchTree();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < n; i++) {
        tree->insert(dis(gen));
    }
    return tree;
}

BinarySearchTree* AlgorithmsTester::createUnbalancedTree(const int n) {
    auto* tree = new BinarySearchTree();
    for (int i = 0; i < n; i++) {
        tree->insert(i);
    }
    return tree;
}

double AlgorithmsTester::measureTime(const std::function<void()>& func) {
    const auto start = std::chrono::high_resolution_clock::now();
    func();
    const auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

double AlgorithmsTester::testSortAlgorithm(const Algorithms algorithm, const TestCase testCase, const int size) {
    const auto array = new int[size];
    switch (testCase) {
        case BEST_CASE:
            createSortedArray(array, size);
            break;
        case AVERAGE_CASE:
            createRandomArray(array, size);
            break;
        case WORST_CASE:
            createReversedArray(array, size);
            break;
    }

    double duration = 0;
    switch (algorithm) {
        case BUBBLE_SORT:
            duration = measureTime([&]() { ALGORITHMS::bubbleSort(array, size); });
            break;
        case SELECTION_SORT:
            duration = measureTime([&]() { ALGORITHMS::selectionSort(array, size); });
            break;
        case MERGE_SORT:
            duration = measureTime([&]() { ALGORITHMS::mergeSort(array, size); });
            break;
        default:
            break;
    }

    delete[] array;
    return duration;
}

double AlgorithmsTester::testSortedLinkedListSearch(const TestCase testCase, const int size) {
    const auto* list = createSortedList(size);

    double duration = 0;
    switch (testCase) {
        case BEST_CASE:
            duration = measureTime([&]() { list->search(0); });
            break;
        case AVERAGE_CASE:
            duration = measureTime([&]() { list->search((size - 1) / 2); });
            break;
        case WORST_CASE:
            duration = measureTime([&]() { list->search(size - 1); });
    }

    delete list;
    return duration;
}

double AlgorithmsTester::testBSTreeInsertion(const TestCase testCase, const int size) {
    double duration = 0;
    switch (testCase) {
        case BEST_CASE:
            duration = measureTime([&]() { createBalancedTree(size); });
            break;
        case AVERAGE_CASE:
            duration = measureTime([&]() { createRandomTree(size); });
            break;
        case WORST_CASE:
            duration = measureTime([&]() { createUnbalancedTree(size); });
            break;
    }

    return duration;
}