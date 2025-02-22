#pragma once

#ifndef SORT_HEAP_LINKED_LIST_HPP
#define SORT_HEAP_LINKED_LIST_HPP

#include "Sort.h"

namespace PerformanceEvaluation {
    class SortHeapLinkedListDoubly final : public Sort<LinkedListDoubly, LinkedListDoublyNode*> {
        protected:
            void SortBy(LinkedListDoubly&) override;
        private:
            // Applies heap sort
            LinkedListDoublyNode* HeapSort(LinkedListDoublyNode*);

            // Convert to array
            void HeapSortArray(LinkedListDoublyNode**, size_t);        
        
            // Min-heap for ascending order, ensures the smallest element is always at the top
            void Heapify(LinkedListDoublyNode**, int32_t, int32_t);
    };
} // namespace PerformanceEvaluation

#endif