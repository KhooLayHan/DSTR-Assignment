#include "MergeSortDLL.h"

namespace PerformanceEvaluation
{
    /*
     * Merge two sorted linked lists into one sorted list.
     */
    LinkedListNode* MergeSortDLL::mergeSortedLists(LinkedListNode* left, LinkedListNode* right)
    {
        if (!left) return right;
        if (!right) return left;

        // Compare and link nodes
        if (left->data.date <= right->data.date)
        {
            left->next = mergeSortedLists(left->next, right);
            if (left->next) left->next->prev = left;
            left->prev = nullptr;
            return left;
        }
        else
        {
            right->next = mergeSortedLists(left, right->next);
            if (right->next) right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    }

    /*
     * Split the linked list into two halves.
     */
    LinkedListNode* MergeSortDLL::split(LinkedListNode* head)
    {
        if (!head || !head->next) return head;

        LinkedListNode* slow = head;
        LinkedListNode* fast = head->next;

        // Move `fast` two steps and `slow` one step
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        LinkedListNode* mid = slow->next;
        slow->next = nullptr;
        if (mid) mid->prev = nullptr;

        return mid;
    }

    /*
     * Perform MergeSort on a Doubly Linked List.
     */
    LinkedListNode* MergeSortDLL::mergeSort(LinkedListNode* head)
    {
        if (!head || !head->next) return head;

        // Split the list into two halves
        LinkedListNode* mid = split(head);

        // Recursively sort both halves
        LinkedListNode* left = mergeSort(head);
        LinkedListNode* right = mergeSort(mid);

        // Merge the sorted halves
        return mergeSortedLists(left, right);
    }
}
