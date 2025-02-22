#pragma once

#ifndef SORT_MERGE_LINKED_LIST_HPP
#define SORT_MERGE_LINKED_LIST_HPP

#include "Sort.h"

namespace PerformanceEvaluation {
    class SortMergeLinkedListDoubly final : public Sort<LinkedListDoubly, LinkedListDoublyNode*> {
        protected:
            void SortBy(LinkedListDoubly&) override;
        private:
            // Applies merge sort recursively 
            void Merge(LinkedListDoublyNode**);

            // Helper function to split the linked list into two halves
            void SplitAndGetMiddle(LinkedListDoublyNode*, LinkedListDoublyNode**, LinkedListDoublyNode**);

            // Helper function to merge two sorted linked lists 
            LinkedListDoublyNode* SortAndMerge(LinkedListDoublyNode*, LinkedListDoublyNode*);
    };
} // namespace PerformanceEvaluation

#endif