// #include "SortQuickLinkedList.h"

// namespace PerformanceEvaluation {
//     void SortQuickLinkedList::SortBy(LinkedList& linked_list) {
//         LinkedListNode* head = linked_list.GetHead();
//         QuickSort(head);
//         linked_list.SetHead(head);
//     }
    
//     // Applies quick sort
//     LinkedListNode* SortQuickLinkedList::QuickSort(LinkedListNode* head) {
//         if (!head || !head->m_Next) {
//             return head;
//         }
    
//         LinkedListNode *left = nullptr, *right = nullptr;
//         LinkedListNode *pivot = Partition(head, &left, &right);
    
//         left = QuickSort(left);
//         right = QuickSort(right);
    
//         LinkedListNode* result = nullptr;
//         LinkedListNode* tail = nullptr;
    
//         // Connect left part to pivot
//         if (left) {
//             result = left;
//             tail = left;
//             while (tail->m_Next) {
//                 tail = tail->m_Next;
//             }
//             tail->m_Next = pivot;
//         } else {
//             result = pivot;
//         }
    
//         pivot->m_Next = right;
    
//         return result;
//     }
     
//     // Partition the linked list around a pivot, ensuring smaller values comes before it and is to the left
//     LinkedListNode* SortQuickLinkedList::Partition(LinkedListNode* head, LinkedListNode** left, LinkedListNode** right) {
//         DateUtility date_utility;
    
//         LinkedListNode* pivot = head;
//         LinkedListNode* current = head->m_Next;
//         pivot->m_Next = nullptr;
    
//         LinkedListNode* left_tail = nullptr;
//         LinkedListNode* right_tail = nullptr;
    
//         while (current) {
//             LinkedListNode* m_Next = current->m_Next;
//             current->m_Next = nullptr;
    
//             if (CompareAndSortDate(date_utility, current->m_Data.m_Date, pivot->m_Data.m_Date)) {
//                 if (!*left) {
//                     *left = current;
//                     left_tail = current;
//                 } else {
//                     left_tail->m_Next = current;
//                     left_tail = current;
//                 }
//             } else {
//                 if (!*right) {
//                     *right = current;
//                     right_tail = current;
//                 } else {
//                     right_tail->m_Next = current;
//                     right_tail = current;
//                 }
//             }

//             current = m_Next;
//         }
    
//         return pivot;
//     }
// } // namespace PerformanceEvaluation

// #include "SortQuickLinkedList.h"

// namespace PerformanceEvaluation {
//     void SortQuickLinkedList::SortBy(LinkedList& linked_list) {
//         LinkedListNode* head = linked_list.GetHead();
//         head = QuickSort(head); // Ensure sorted head is returned and updated
//         linked_list.SetHead(head);
//     }
    
//     // QuickSort implementation for Linked List
//     LinkedListNode* SortQuickLinkedList::QuickSort(LinkedListNode* head) {
//         if (!head || !head->m_Next) {
//             return head;
//         }
    
//         LinkedListNode *left = nullptr, *right = nullptr;
//         LinkedListNode *pivot = Partition(head, &left, &right);
    
//         left = QuickSort(left);
//         right = QuickSort(right);
    
//         LinkedListNode* result = nullptr;
//         LinkedListNode* tail = nullptr;
    
//         // Connect left part to pivot
//         if (left) {
//             result = left;
//             tail = left;
//             while (tail->m_Next) {
//                 tail = tail->m_Next;
//             }
//             tail->m_Next = pivot;
//         } else {
//             result = pivot;
//         }
    
//         pivot->m_Next = right;
    
//         return result;
//     }
     
//     // Partition the linked list around a pivot, sorting by **year only**
//     LinkedListNode* SortQuickLinkedList::Partition(LinkedListNode* head, LinkedListNode** left, LinkedListNode** right) {
//         DateUtility date_utility;
    
//         LinkedListNode* pivot = head;
//         LinkedListNode* current = head->m_Next;
//         pivot->m_Next = nullptr;
    
//         LinkedListNode* left_tail = nullptr;
//         LinkedListNode* right_tail = nullptr;
    
//         while (current) {
//             LinkedListNode* next = current->m_Next;
//             current->m_Next = nullptr;
    
//             // Extract **year only** from date
//             int pivot_year = date_utility.ExtractYear(pivot->m_Data.m_Date);
//             int current_year = date_utility.ExtractYear(current->m_Data.m_Date);
    
//             if (current_year < pivot_year) { // Sorting by year
//                 if (!*left) {
//                     *left = current;
//                     left_tail = current;
//                 } else {
//                     left_tail->m_Next = current;
//                     left_tail = current;
//                 }
//             } else {
//                 if (!*right) {
//                     *right = current;
//                     right_tail = current;
//                 } else {
//                     right_tail->m_Next = current;
//                     right_tail = current;
//                 }
//             }

//             current = next;
//         }
    
//         return pivot;
//     }
// } // namespace PerformanceEvaluation

#include "SortQuickLinkedList.h"


namespace PerformanceEvaluation {
    void SortQuickLinkedList::SortBy(LinkedList& linked_list) {
        LinkedListNode* head = linked_list.GetHead();
        head = QuickSort(head); // Ensure sorted head is returned and updated
        linked_list.SetHead(head);
    }
    
    // QuickSort implementation for Linked List
    LinkedListNode* SortQuickLinkedList::QuickSort(LinkedListNode* head) {
        if (!head || !head->m_Next) {
            return head;
        }

        LinkedListNode *left = nullptr, *right = nullptr;
        LinkedListNode *pivot = Partition(head, &left, &right);

        left = QuickSort(left);
        right = QuickSort(right);

        // Merge left -> pivot -> right
        return MergeLists(left, pivot, right);
    }

    LinkedListNode* SortQuickLinkedList::MergeLists(LinkedListNode* left, LinkedListNode* pivot, LinkedListNode* right) {
        LinkedListNode* result = nullptr;
        LinkedListNode* tail = nullptr;
    
        // If left part exists, connect it to pivot
        if (left) {
            result = left;
            tail = left;
            while (tail->m_Next) {  // Find the last node in left list
                tail = tail->m_Next;
            }
            tail->m_Next = pivot;  // Connect left list to pivot
        } else {
            result = pivot;  // If no left list, pivot becomes the new head
        }
    
        pivot->m_Next = right;  // Connect pivot to right list
    
        return result;
    }

    // Partition the linked list around a pivot, sorting by **year → month → day**
    LinkedListNode* SortQuickLinkedList::Partition(LinkedListNode* head, LinkedListNode** left, LinkedListNode** right) {
        DateUtility date_utility;

        LinkedListNode* pivot = head;
        LinkedListNode* current = head->m_Next;
        pivot->m_Next = nullptr;  // Ensure pivot is detached

        LinkedListNode* left_tail = nullptr;
        LinkedListNode* right_tail = nullptr;

        while (current) {
            LinkedListNode* next = current->m_Next;
            current->m_Next = nullptr;

            // Use CompareAndSortDate function for proper sorting
            if (CompareAndSortDate(date_utility, current->m_Data.m_Date, pivot->m_Data.m_Date) < 0) {  
                // ✅ If current date < pivot date, move to left partition
                if (!*left) {
                    *left = current;
                    left_tail = current;
                } else {
                    left_tail->m_Next = current;
                    left_tail = current;
                }
            } else {
                // ✅ Otherwise, move to right partition
                if (!*right) {
                    *right = current;
                    right_tail = current;
                } else {
                    right_tail->m_Next = current;
                    right_tail = current;
                }
            }

            current = next;
        }

        return pivot;
    }
} // namespace PerformanceEvaluation

