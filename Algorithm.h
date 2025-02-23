#pragma once

#include <memory>
#include <string>
#include <string_view>

#include "Array.h"
#include "LinkedList.h"
#include "WordList.h"
#include "SortMergeArray.h"

#include "Search.h"
// #include "SearchLinkedList.h"
#include "Sort.h"

namespace PerformanceEvaluation {

    // TODO: Can implement each of the various searching and sorting algorithms.

    /*
    * Sorting algorithms
    * 1. Merge Sort
    * 2. Quick Sort
    * 3. Heap Sort
    * ... 
    **/ 

    /*
    * Searching algorithms
    * 1. Linear Search
    * 2. Binary Search 
    **/ 

    class Algorithm {
        public:
            // Linear Search Singly Linked List
            static LinkedListNode*  LinearSearch            (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            static LinkedList       LinearSearchAndCopy     (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            static void             LinearSearchAndDisplay  (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            
            // Binary Search Singly Linked List
            static LinkedListNode*  BinarySearch            (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            static LinkedList       BinarySearchAndCopy     (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            static void             BinarySearchAndDisplay  (LinkedList&, Search<LinkedList, LinkedListNode*>*, std::string_view, Criteria, SearchType);
            
            // Linear Seach Doubly Linked List 
            static LinkedListDoublyNode*    LinearSearch            (LinkedListDoubly&, Search<LinkedListDoubly, LinkedListDoublyNode*>*, std::string_view, Criteria, SearchType);
            static LinkedListDoubly         LinearSearchAndCopy     (LinkedListDoubly&, Search<LinkedListDoubly, LinkedListDoublyNode*>*, std::string_view, Criteria, SearchType);
            static void                     LinearSearchAndDisplay  (LinkedListDoubly&, Search<LinkedListDoubly, LinkedListDoublyNode*>*, std::string_view, Criteria, SearchType);
            
            
            static void SortBy                  (LinkedList&, Sort<LinkedList, LinkedListNode*>*);
            static void SortBy                  (LinkedListDoubly&, Sort<LinkedListDoubly, LinkedListNode*>*);

            static void SortBy(Array<Dataset>& array, Sort<Array<Dataset>>* sorter);
            
            // For Linked List Words
            static WordList         LinearSearchWordAndCopy     (WordList&, Search<WordList, WordListNode*>*, std::string_view, SearchType);
            // static LinkedListDoubly LinearSearchAndCopy     (WordListDoubly&, Search<WordListDoubly, WordListDoublyNode*>*, std::string_view, Criteria, SearchType);
            static void             SortBy                  (WordList&, Sort<WordList, WordListNode*>*);
    };
} // namespace PerformanceEvaluation
