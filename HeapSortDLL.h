#pragma once

#ifndef HEAPSORTDLL_H
#define HEAPSORTDLL_H

#include "DLL.h"

namespace PerformanceEvaluation
{
    class HeapSortDLL
    {
    public:
        static void heapSort(LinkedListDoubly &list);
    
    private:
        static void heapify(LinkedListDoublyNode* head, int n, int i);
    };
}

#endif // HEAPSORTDLL_H
