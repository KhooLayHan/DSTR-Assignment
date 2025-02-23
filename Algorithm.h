#pragma once

#include <memory>
#include <string>
#include <string_view>

#include "Array.h"
#include "LinkedList.h"

#include "Search.h"
#include "SortMergeArray.h"
#include "SearchLinearLinkedList.h"
#include "SearchLinearArray.h"
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
            static LinkedListNode*  LinearSearch            (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);

            // static Array<Dataset> LinearSearchAndCopy(Array<Dataset>& array, Search<Array<Dataset>>* search_interface, 
            //     std::string_view target, Criteria criteria, SearchType type);

            static LinkedList       LinearSearchAndCopy     (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            static void             LinearSearchAndDisplay  (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            
            static void SortBy                  (LinkedList&, Sort<LinkedList, LinkedListNode*>*);
            static void SortBy(Array<Dataset>& array, Sort<Array<Dataset>>* sorter);
    };
} // namespace PerformanceEvaluation
