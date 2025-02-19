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
        static LinkedListNode* mergeSort(LinkedListNode* head);

    private:
        // Function to split the linked list into two halves
        static LinkedListNode* split(LinkedListNode* head);

        // Function to merge two sorted linked lists
        static LinkedListNode* mergeSortedLists(LinkedListNode* left, LinkedListNode* right);
    };
}

#endif // MERGESORT_DLL_H
