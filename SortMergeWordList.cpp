#include <iostream>
#include <string>

#include "SimpleConsoleLogger.h"
#include "SimpleLoggingService.h"

#include "SortMergeWordList.h"

namespace PerformanceEvaluation {
    void SortMergeWordList::SortBy(WordList& linked_list) {
        WordListNode* head = linked_list.GetHead();
        Merge(&head);
        linked_list.SetHead(head);
    }

    // Applies merge sort recursively 
    void SortMergeWordList::Merge(WordListNode** head) {                
        // List is already sorted if list is empty
        if (!(*head) || !((*head)->m_Next)) {
            // SimpleConsoleLogger console;
            // SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");
            
            return;
        }

        WordListNode* left = nullptr;
        WordListNode* right = nullptr;

        //Split and get middle of list
        SplitAndGetMiddle(*head, &left, &right);

        Merge(&left);
        Merge(&right);

        // Merge the sorted halves                
        *head = SortAndMerge(left, right);
    }

    // Helper function to split the linked list into two halves
    void SortMergeWordList::SplitAndGetMiddle(WordListNode* source, WordListNode** left, WordListNode** right) {
        if (!source || !(source->m_Next)) {
            SimpleConsoleLogger console;
            SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");
            
            *left = source;
            *right = nullptr;

            return;
        }

        WordListNode* first_half = source;
        WordListNode* second_half = source->m_Next;
        
        // Iterate until second_half reaches the end of node, by then first_half will be the middle node
        while (second_half && second_half->m_Next) {
            first_half = first_half->m_Next;
            second_half = second_half->m_Next->m_Next;
        }

        *left = source;
        *right = first_half->m_Next;
        first_half->m_Next = nullptr;
    }

    // Helper function to merge two sorted linked lists 
    WordListNode* SortMergeWordList::SortAndMerge(WordListNode* left, WordListNode* right) {
        DateUtility date_utility{};

        // Sort by year
        if (!left)
            return right;
        if (!right)
            return left;

        WordListNode* result = nullptr;

        if (CompareAndSortDate(date_utility, left->m_Data, right->m_Data)) {
            result = left;
            result->m_Next = SortAndMerge(left->m_Next, right);
        } else {
            result = right;
            result->m_Next = SortAndMerge(left, right->m_Next);
        }
    
        return result;
    } 
} // namespace PerformanceEvaluation