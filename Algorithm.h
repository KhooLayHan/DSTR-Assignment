#pragma once

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <string>
#include <memory>

#include "Array.h"
#include "Dataset.h"
#include "LinkedList.h"
#include "DateUtility.h"

namespace PerformanceEvaluation
{
  class Algorithm
  {
  public:
    Algorithm() = default;                                    
    Algorithm(const Algorithm &) = delete;            
    Algorithm &operator=(const Algorithm &) = delete; 
    ~Algorithm() = default;                                   

    static Array* MergeSort(Array& arr);
    static Array* QuickSort(Array& arr);
    static Array* HeapSort(Array& arr);

  private:
    void mergeSortImpl(LinkedList &linked_list);
    void mergeSort(LinkedListNode **headRef);
    LinkedListNode *mergeSortedLists(LinkedListNode *a, LinkedListNode *b);
    LinkedListNode *getMiddle(LinkedListNode *head);

    // Sorting Implementations
    static int partition(Dataset arr[], int low, int high);
    static void _quickSortImpl(Dataset arr[], int low, int high);
    static void mergeSortImpl(Dataset arr[], int left, int right);
    static void merge(Dataset arr[], int left, int mid, int right);
    static void heapSortImpl(Dataset arr[], int n);
    static void heapify(Dataset arr[], int n, int i);
  };
} // namespace PerformanceEvaluation

#endif
