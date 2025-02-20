#pragma once

#ifndef HEAPSORTDLL_H
#define HEAPSORTDLL_H

#include "DLL.h"

namespace PerformanceEvaluation
{
    class HeapSortDLL
    {
    public:
        static void heapSort(LinkedList &list);
    
    private:
        static void heapify(LinkedListNode* head, int n, int i);
    };
}

#endif // HEAPSORTDLL_H
