#pragma once

#include "Search.h"

#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

namespace PerformanceEvaluation
{
    class SearchWordList : public Search<WordList, WordListNode*> {
        public:
            // WordListNode* LinearSearchWord          (std::string_view, const WordList&, SearchType) override;
            // WordList      LinearSearchWordAndCopy   (std::string_view, const WordList&, SearchType) override;
            // void          LinearSearchWordAndDisplay(std::string_view, const WordList&, SearchType) override;
            
            // LinkedListNode* BinarySearch            (std::string_view, const LinkedList&, Criteria) override;
            // LinkedList*     BinarySearchAndCopy     (std::string_view, const LinkedList&, Criteria) override;
            // void            BinarySearchAndDisplay  (std::string_view, const LinkedList&, Criteria) override;
            
            // void            LinearSearchAll         (std::string_view, const WordList&, SearchType) override;
    };
} // namespace PerformanceEvaluation
