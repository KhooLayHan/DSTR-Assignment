#pragma once

#ifndef SORT_HEAP_LINKED_LIST_HPP
#define SORT_HEAP_LINKED_LIST_HPP

#include "Sort.h"

namespace PerformanceEvaluation {
    class SortHeapLinkedList final : public Sort<LinkedList, LinkedListNode*> {
        protected:
            void SortBy(LinkedList&) override;
        private:
            // Applies heap sort
            LinkedListNode* HeapSort(LinkedListNode*);

            // Convert to array
            void HeapSortArray(LinkedListNode**, size_t);        
        
            // Min-heap for ascending order, ensures the smallest element is always at the top
            void Heapify(LinkedListNode**, int32_t, int32_t);
    };
} // namespace PerformanceEvaluation

#endif