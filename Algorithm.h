#pragma once

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <array>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Array.h"
#include "Dataset.h"
#include "LinkedList.h"
#include "DateUtility.cpp"

namespace PerformanceEvaluation
{
  class Algorithm
  {
  public:
    Algorithm() {}                                    
    Algorithm(const Algorithm &) = delete;            
    Algorithm &operator=(const Algorithm &) = delete; 
    ~Algorithm() {}                                   

    static void MergeSort(Dataset arr[], int length);
    static void QuickSort(Dataset arr[], int length);
    static void HeapSort(Dataset arr[], int length);

  private:
    void mergeSortImpl(LinkedList &linked_list);
    void MergeSortImpl(std::array<Dataset, 4> &linked_list);
    void mergeSort(LinkedListNode **headRef);
    LinkedListNode *mergeSortedLists(LinkedListNode *a, LinkedListNode *b);
    LinkedListNode *getMiddle(LinkedListNode *head);

    // Declaration of partition function
    static int partition(Dataset arr[], int low, int high); 

  protected:
    static Algorithm &getAlgorithm()
    {
      static Algorithm algorithm;
      return algorithm;
    }

    // --- QuickSort Implementation ---
    static void _quickSortImpl(Dataset arr[], int low, int high);
    static void mergeSortImpl(Dataset arr[], int left, int right);
    static void merge(Dataset arr[], int left, int mid, int right);
    static void heapSortImpl(Dataset arr[], int n);
    static void heapify(Dataset arr[], int n, int i);
  };
} // namespace PerformanceEvaluation

#endif