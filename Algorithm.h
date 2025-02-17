#pragma once

#include <memory>
#include <string>
#include <string_view>

#include "Array.h"
#include "LinkedList.h"

#include "Search.h"
#include "SearchLinkedList.h"
#include "Sort.h"

namespace PerformanceEvaluation {

    // TODO: Can implement each of the various searching and sorting algorithms.

    /*
    * Sorting algorithms
    * 1. Bubble Sort
    * 2. Selection Sort
    * 3. Insertion Sort
    * 4. Merge Sort
    * 5. Quick Sort
    * 6. Heap Sort
    * ... 
    **/ 

    /*
    * Searching algorithms
    * 1. Linear Search
    * 2. Binary Search 
    **/ 

    class Algorithm {
        public:
            static LinkedListNode*  LinearSearch            (LinkedList&, const std::unique_ptr<Search<LinkedList, LinkedListNode*>>&, std::string_view, Criteria, SearchType);
            static LinkedList       LinearSearchAndCopy     (LinkedList&, const std::unique_ptr<Search<LinkedList, LinkedListNode*>>&, std::string_view, Criteria, SearchType);
            static void             LinearSearchAndDisplay  (LinkedList&, const std::unique_ptr<Search<LinkedList, LinkedListNode*>>&, std::string_view, Criteria, SearchType);
            
            static void SortBy                  (LinkedList&, const std::unique_ptr<Sort<LinkedList, LinkedListNode*>>&);
    };
} // namespace PerformanceEvaluation
