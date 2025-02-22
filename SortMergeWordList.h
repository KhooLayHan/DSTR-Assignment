#pragma once

#include "Sort.h"

namespace PerformanceEvaluation {
    class SortMergeWordList final : public Sort<WordList, WordListNode*> {
        protected:
            void SortBy(WordList&) override;
        private:
            // Applies merge sort recursively 
            void Merge(WordListNode**);

            // Helper function to split the linked list into two halves
            void SplitAndGetMiddle(WordListNode*, WordListNode**, WordListNode**);

            // Helper function to merge two sorted linked lists 
            WordListNode* SortAndMerge(WordListNode*, WordListNode*);
    };
} // namespace PerformanceEvaluation
