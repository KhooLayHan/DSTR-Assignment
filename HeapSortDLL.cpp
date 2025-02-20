#include "HeapSortDLL.h"

namespace PerformanceEvaluation
{
    void HeapSortDLL::heapify(LinkedListNode* head, int n, int i)
    {
        LinkedListNode* largest = head;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        LinkedListNode* left = head;
        LinkedListNode* right = head;

        for (int j = 0; j < leftIndex && left; j++)
            left = left->next;
        for (int j = 0; j < rightIndex && right; j++)
            right = right->next;

        if (left && leftIndex < n && left->data > largest->data)
            largest = left;

        if (right && rightIndex < n && right->data > largest->data)
            largest = right;

        if (largest != head)
        {
            std::swap(head->data, largest->data);
            heapify(head, n, largest == left ? leftIndex : rightIndex);
        }
    }

    void HeapSortDLL::heapSort(LinkedList &list)
    {
        int n = list.getLength();
        LinkedListNode* head = list.getHead();

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            LinkedListNode* temp = head;
            for (int j = 0; j < i; j++)
                temp = temp->next;
            heapify(temp, n, i);
        }

        for (int i = n - 1; i > 0; i--)
        {
            LinkedListNode* temp = head;
            for (int j = 0; j < i; j++)
                temp = temp->next;
            std::swap(head->data, temp->data);
            heapify(head, i, 0);
        }
    }
}
