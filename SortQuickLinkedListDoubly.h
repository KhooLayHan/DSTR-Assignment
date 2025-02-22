#pragma once

#ifndef SORT_QUICK_LINKED_LIST_HPP
#define SORT_QUICK_LINKED_LIST_HPP

#include "Sort.h"

namespace PerformanceEvaluation {
    class SortQuickLinkedListDoubly final : public Sort<LinkedListDoubly, LinkedListDoublyNode*> {
        protected:
            void SortBy(LinkedListDoubly&) override;
        private:
            // Applies quick sort
            LinkedListDoublyNode* QuickSort(LinkedListDoublyNode*);

            // Partition the linked list around a pivot, ensuring smaller values comes before it and is to the left
            LinkedListDoublyNode* Partition(LinkedListDoublyNode*, LinkedListDoublyNode**, LinkedListDoublyNode**);
    };
} // namespace PerformanceEvaluation

#endif