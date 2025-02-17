#pragma once

#ifndef SORT_QUICK_LINKED_LIST_HPP
#define SORT_QUICK_LINKED_LIST_HPP

#include "Sort.h"

namespace PerformanceEvaluation {
    class SortQuickLinkedList final : public Sort<LinkedList, LinkedListNode*> {
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