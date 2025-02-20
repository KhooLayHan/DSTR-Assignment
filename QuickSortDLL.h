#pragma once

#ifndef QUICKSORTDLL_H
#define QUICKSORTDLL_H

#include "DLL.h"

namespace PerformanceEvaluation
{
    class QuickSortDLL
    {
    public:
        static void quickSort(LinkedListNode* head);
    
    private:
        static LinkedListNode* partition(LinkedListNode* low, LinkedListNode* high);
        static void quickSortHelper(LinkedListNode* low, LinkedListNode* high);
        static LinkedListNode* getTail(LinkedListNode* node);
    };
}

#endif // QUICKSORTDLL_H
