#pragma once

#ifndef MERGESORT_DLL_H
#define MERGESORT_DLL_H

#include "DLL.h"

namespace PerformanceEvaluation
{
    class MergeSortDLL
    {
    public:
        // Function to perform MergeSort on a Doubly Linked List
        static LinkedListDoublyNode* mergeSort(LinkedListDoublyNode* head);

    private:
        // Function to split the linked list into two halves
        static LinkedListDoublyNode* split(LinkedListDoublyNode* head);

        // Function to merge two sorted linked lists
        static LinkedListDoublyNode* mergeSortedLists(LinkedListDoublyNode* left, LinkedListDoublyNode* right);
    };
}

#endif // MERGESORT_DLL_H
