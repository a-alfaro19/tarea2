#pragma once

#include <functional>
#include <optional>
#include <string>

#include <LinkedList.h>
#include "BinarySearchTree.h"

class AlgorithmsTester {
public:
    /**
     * Constructor
     */
    AlgorithmsTester();

    /**
     * Run a test for the given algorithm and test case
     * @param algorithm The algorithm to be tested
     * @param testCase The test case to be used
     * @return The experimental results
     */
    static std::optional<std::vector<double>> runTest(const std::string& algorithm , const std::string& testCase);

    /**
     * Get the theoretical complexity for the given algorithm and test case
     * @param algorithm The algorithm to be tested
     * @param testCase The test case to be used
     * @return The theoretical results
     */
    static std::optional<std::vector<double>> getTheoreticalComplexity(const std::string& algorithm, const std::string& testCase);

    static const std::vector<int> sizes; ///< The sizes of the arrays

private:
    enum TestCase {
        BEST_CASE,
        AVERAGE_CASE,
        WORST_CASE,
    };

    /**
     * Convert a string to a test case
     * @param testCase The string to be converted
     * @return The test case
     */
    static TestCase stringToTestCase(const std::string& testCase);

    enum Algorithms {
        BUBBLE_SORT,
        SELECTION_SORT,
        MERGE_SORT,
        LINKED_LIST_SEARCH,
        BS_TREE_INSERTION,
    };

    /**
     * Convert a string to an algorithm
     * @param algorithm The string to be converted
     * @return The algorithm
     */
    static Algorithms stringToSortingAlgorithm(const std::string& algorithm);

    /**
     * Create a sorted array with the given size
     * @param array The array to be created
     * @param size The size of the array
     */
    static void createSortedArray(int* array, int size);

    /**
     * Create a random array with the given size
     * @param array The array to be created
     * @param size The size of the array
     */
    static void createRandomArray(int* array, int size);

    /**
     * Create a reversed array with the given size
     * @param array The array to be created
     * @param size The size of the array
     */
    static void createReversedArray(int* array, int size);

    /**
     * Create a sorted linked list with the given size
     * @param n The size of the linked list
     * @return The sorted linked list
     */
    static LinkedList* createSortedList(int n);

    /**
     * Create a random linked list with the given size
     * @param n The size of the linked list
     * @return The random linked list
     */
    static BinarySearchTree* createBalancedTree(int n);

    /**
     * Create a random binary search tree with the given size
     * @param n The size of the binary search tree
     * @return The random binary search tree
     */
    static BinarySearchTree* createRandomTree(int n);

    /**
     * Create an unbalanced binary search tree with the given size
     * @param n The size of the binary search tree
     * @return The unbalanced binary search tree
     */
    static BinarySearchTree* createUnbalancedTree(int n);

    /**
     * Measure the time taken to execute the given function
     * @param func The function to be executed
     * @return The time taken to execute the function
     */
    static double measureTime(const std::function<void()>& func);

    /**
     * Test the given sorting algorithm
     * @param algorithm The algorithm to be tested
     * @param testCase The test case to be used
     * @param size The size of the array
     * @return The time taken to execute the algorithm
     */
    static double testSortAlgorithm(Algorithms algorithm, TestCase testCase, int size);

    /**
     * Test the given linked list search
     * @param testCase The test case to be used
     * @param size The size of the linked list
     * @return The time taken to execute the search
     */
    static double testSortedLinkedListSearch(TestCase testCase, int size);

    /**
     * Test the given binary search tree insertion
     * @param testCase The test case to be used
     * @param size The size of the binary search tree
     * @return The time taken to execute the insertion
     */
    static double testBSTreeInsertion(TestCase testCase, int size);

    Algorithms sortingAlgorithms[3]; ///< Bubble sort, insertion sort, merge sort
    TestCase testCases[3]; ///< Best case, average case, worst case
};

