#pragma once

#ifndef SORT_HEAP_LINKED_LIST_HPP
#define SORT_HEAP_LINKED_LIST_HPP

#include "Sort.h"

namespace PerformanceEvaluation {
    class SortHeapLinkedList final : public Sort<LinkedList, LinkedListNode*> {
        // protected:
        //     void Sort(LinkedList&);
        // private:
        //     // Applies merge sort recursively 
        //     void Merge(LinkedListNode**);

        //     // Helper function to split the linked list into two halves
        //     void SplitAndGetMiddle(LinkedListNode*, LinkedListNode**, LinkedListNode**);

        //     // Helper function to merge two sorted linked lists 
        //     LinkedListNode* SortAndMerge(LinkedListNode*, LinkedListNode*);
    };
} // namespace PerformanceEvaluation

#endif