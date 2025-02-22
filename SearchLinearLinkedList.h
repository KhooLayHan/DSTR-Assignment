#pragma once

#include "SearchLinear.h"

#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

namespace PerformanceEvaluation
{
    class SearchLinearLinkedList final : public SearchLinear {
        public:
            // Public API that returns a LinkedListNode object
            LinkedListNode* LinearSearch            (std::string_view, const LinkedList&, Criteria, SearchType) override;
            
            // Public API that copies to a new Linked List
            LinkedList      LinearSearchAndCopy     (std::string_view, const LinkedList&, Criteria, SearchType) override;
            
            // Public function to perform linear search and display results
            void            LinearSearchAndDisplay  (std::string_view, const LinkedList&, Criteria, SearchType) override;
    };
} // namespace PerformanceEvaluation
