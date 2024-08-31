#pragma once

#include <functional>
#include <optional>
#include <string>

#include <LinkedList.h>
#include "BinarySearchTree.h"

class AlgorithmsTester {
public:
    AlgorithmsTester();

    std::optional<std::vector<double>> runTest(const std::string& algorithm , const std::string& testCase);

    std::optional<std::vector<double>> getTheoreticalComplexity(const std::string& algorithm, const std::string& testCase);

private:
    enum TestCase {
        BEST_CASE,
        AVERAGE_CASE,
        WORST_CASE,
    };

    static std::string testCaseToString(TestCase testCase);
    static TestCase stringToTestCase(const std::string& testCase);

    enum Algorithms {
        BUBBLE_SORT,
        INSERTION_SORT,
        MERGE_SORT,
        LINKED_LIST_SEARCH,
        BS_TREE_INSERTION,
    };

    static std::string sortingAlgorithmToString(Algorithms algorithm);
    static Algorithms stringToSortingAlgorithm(const std::string& algorithm);

    static void createSortedArray(int* array, int size);

    static void createRandomArray(int* array, int size);

    static void createReversedArray(int* array, int size);

    static LinkedList* createSortedList(int n);

    static BinarySearchTree* createBalancedTree(int n);

    static BinarySearchTree* createRandomTree(int n);

    static BinarySearchTree* createUnbalancedTree(int n);

    static double measureTime(const std::function<void()>& func);

    static double testSortAlgorithm(Algorithms algorithm, TestCase testCase, int size);

    static double testSortedLinkedListSearch(TestCase testCase, int size);

    static double testBSTreeInsertion(TestCase testCase, int size);

    Algorithms sortingAlgorithms[3];
    TestCase testCases[3];
    std::vector<int> sizes = {100, 5050, 10000};
};

