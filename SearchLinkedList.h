#pragma once

#include "Search.h"

#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

namespace PerformanceEvaluation
{
    class SearchLinkedList : public Search<LinkedList, LinkedListNode*> {
        public:
            LinkedListNode* LinearSearch            (std::string_view, const LinkedList&, Criteria, SearchType) override;
            LinkedList      LinearSearchAndCopy     (std::string_view, const LinkedList&, Criteria, SearchType) override;
            void            LinearSearchAndDisplay  (std::string_view, const LinkedList&, Criteria, SearchType) override;
            void            LinearSearchAll         (const LinkedList&) override;

            // LinkedListNode* BinarySearch            (std::string_view, const LinkedList&, Criteria) override;
            // LinkedList*     BinarySearchAndCopy     (std::string_view, const LinkedList&, Criteria) override;
            // void            BinarySearchAndDisplay  (std::string_view, const LinkedList&, Criteria) override;
    };

    // front end 3, 4 = 7 / 2 = 3.5 = 3

    // target close to front node
} // namespace PerformanceEvaluation
