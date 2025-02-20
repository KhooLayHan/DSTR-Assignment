#include "QuickSortDLL.h"

namespace PerformanceEvaluation
{
    LinkedListNode* QuickSortDLL::getTail(LinkedListNode* node)
    {
        while (node && node->next)
            node = node->next;
        return node;
    }

    LinkedListNode* QuickSortDLL::partition(LinkedListNode* low, LinkedListNode* high)
    {
        Dataset pivot = high->data;
        LinkedListNode* i = low->prev;

        for (LinkedListNode* j = low; j != high; j = j->next)
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

    void QuickSortDLL::quickSortHelper(LinkedListNode* low, LinkedListNode* high)
    {
        if (high != nullptr && low != high && low != high->next)
        {
            LinkedListNode* pivot = partition(low, high);
            quickSortHelper(low, pivot->prev);
            quickSortHelper(pivot->next, high);
        }
    }

    void QuickSortDLL::quickSort(LinkedListNode* head)
    {
        LinkedListNode* tail = getTail(head);
        quickSortHelper(head, tail);
    }
}
