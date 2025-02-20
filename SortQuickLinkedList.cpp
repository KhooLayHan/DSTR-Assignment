#include "SortQuickLinkedList.h"

namespace PerformanceEvaluation {
    void SortQuickLinkedList::SortBy(LinkedList& linked_list) {
        LinkedListNode* head = linked_list.getHead();
        QuickSort(head);
        linked_list.setHead(head);
    }
    
    // Applies quick sort
    LinkedListNode* SortQuickLinkedList::QuickSort(LinkedListNode* head) {
        if (!head || !head->m_Next) {
            return head;
        }
    
        LinkedListNode *left = nullptr, *right = nullptr;
        LinkedListNode *pivot = Partition(head, &left, &right);
    
        left = QuickSort(left);
        right = QuickSort(right);
    
        LinkedListNode* result = nullptr;
        LinkedListNode* tail = nullptr;
    
        // Connect left part to pivot
        if (left) {
            result = left;
            tail = left;
            while (tail->m_Next) {
                tail = tail->m_Next;
            }
            tail->m_Next = pivot;
        } else {
            result = pivot;
        }
    
        pivot->m_Next = right;
    
        return result;
    }
     
    // Partition the linked list around a pivot, ensuring smaller values comes before it and is to the left
    LinkedListNode* SortQuickLinkedList::Partition(LinkedListNode* head, LinkedListNode** left, LinkedListNode** right) {
        DateUtility date_utility;
    
        LinkedListNode* pivot = head;
        LinkedListNode* current = head->m_Next;
        pivot->m_Next = nullptr;
    
        LinkedListNode* left_tail = nullptr;
        LinkedListNode* right_tail = nullptr;
    
        while (current) {
            LinkedListNode* m_Next = current->m_Next;
            current->m_Next = nullptr;
    
            if (CompareAndSortDate(date_utility, current->m_Data.m_Date, pivot->m_Data.m_Date)) {
                if (!*left) {
                    *left = current;
                    left_tail = current;
                } else {
                    left_tail->m_Next = current;
                    left_tail = current;
                }
            } else {
                if (!*right) {
                    *right = current;
                    right_tail = current;
                } else {
                    right_tail->m_Next = current;
                    right_tail = current;
                }
            }

            current = m_Next;
        }
    
        return pivot;
    }
} // namespace PerformanceEvaluation
