#pragma once

#include <string>

// Struct with member variables: title, text, subject, date
#include "Dataset.h"

// Data structures
#include "Array.h"
// #include "WordList.h"
#include "LinkedList.h"

// Search and sort algorithms 
#include "Algorithm.h"

// Benchmarking
#include "Benchmark.h"

#include <future>
#include <memory>

// File handling
#include "FileHandling.h"

// Helper classes for debugging and parsing dates
#include "DateUtility.h"
#include "SimpleLogger.h"

#include "Benchmark.h"
#include "SearchLinearLinkedList.h"
#include "SearchBinaryLinkedList.h"
// #include "SearchWordList.h"
#include "SortMergeLinkedList.h"
#include "SortQuickLinkedList.h"
#include "SortHeapLinkedList.h"

#include "SortMergeArray.h"
#include "SortQuickArray.h"
#include "SortHeapArray.h"

#include "Sort.h"

#include "ConversionUtility.h"
#include "HashMap.h"
// #include "HashMap.h"

#include "WordList.h"
#include "WordListSorted.h"

#include "HashSet.h"
#include "Vector.h"
#include "DynamicArray.h"

#include "SearchLinearDynamicArray.h"
namespace PerformanceEvaluation {
    class Assignment {
        public:
            /**
             * Problem Statement 1:
             * How can you efficiently sort the news articles by year and 
             * display the total number of articles in both datasets? 
             */
            static void Question_1_Array();
            static void Question_1_LinkedList();

            /**
             * Problem Statement 2:
             * What percentage of political news articles (including fake and true news) 
             * from the year of 2016 are fake?  
             */
            static void Question_2_Array();
            static void Question_2_LinkedList();

            /**
             * Problem Statement 3:
             * Which words are most frequently used in fake news articles 
             * related to government topics?
             */
            static void Question_3_Array();
            static void Question_3_LinkedList();
    }; // class Assignment
} // namespace PerformanceEvaluation