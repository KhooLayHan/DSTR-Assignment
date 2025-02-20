#include "QuickSortDLL.h"

namespace PerformanceEvaluation
{
    LinkedListDoublyNode* QuickSortDLL::getTail(LinkedListDoublyNode* node)
    {
        while (node && node->next)
            node = node->next;
        return node;
    }

    LinkedListDoublyNode* QuickSortDLL::partition(LinkedListDoublyNode* low, LinkedListDoublyNode* high)
    {
        Dataset pivot = high->data;
        LinkedListDoublyNode* i = low->prev;

        for (LinkedListDoublyNode* j = low; j != high; j = j->next)
        {
            if (j->data < pivot)
            {
                i = (i == nullptr) ? low : i->next;
                std::swap(i->data, j->data);
            }
        }

        i = (i == nullptr) ? low : i->next;
        std::swap(i->data, high->data);
        return i;
    }

    void QuickSortDLL::quickSortHelper(LinkedListDoublyNode* low, LinkedListDoublyNode* high)
    {
        if (high != nullptr && low != high && low != high->next)
        {
            LinkedListDoublyNode* pivot = partition(low, high);
            quickSortHelper(low, pivot->prev);
            quickSortHelper(pivot->next, high);
        }
    }

    void QuickSortDLL::quickSort(LinkedListDoublyNode* head)
    {
        LinkedListDoublyNode* tail = getTail(head);
        quickSortHelper(head, tail);
    }
}
