#include <iostream>
#include "Assignment.cpp"

int main()
{
    using namespace PerformanceEvaluation;

    std::cout << "Running Sorting Algorithms on Array Data...\n";
    runArraySorting(); // Calls sorting for Array

    std::cout << "\nRunning Sorting Algorithms on Doubly Linked List Data...\n";
    runLinkedListSorting(); // Calls sorting for LinkedList

    return 0;
}
