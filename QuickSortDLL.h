#pragma once

#ifndef QUICKSORTDLL_H
#define QUICKSORTDLL_H

#include "DLL.h"

namespace PerformanceEvaluation
{
    class QuickSortDLL
    {
    public:
        static void quickSort(LinkedListDoublyNode* head);
    
    private:
        static LinkedListDoublyNode* partition(LinkedListDoublyNode* low, LinkedListDoublyNode* high);
        static void quickSortHelper(LinkedListDoublyNode* low, LinkedListDoublyNode* high);
        static LinkedListDoublyNode* getTail(LinkedListDoublyNode* node);
    };
}

#endif // QUICKSORTDLL_H
