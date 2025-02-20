#pragma once

#include <string>

// Struct with member variables: title, text, subject, date
#include "Dataset.h"

// Data structures
#include "Array.h"
#include "LinkedList.h"

// Search and sort algorithms 
#include "Algorithm.h"

// Benchmarking
#include "Benchmark.h"

// File handling
#include "FileHandling.h"

// Helper classes for debugging and parsing dates
#include "DateUtility.h"
#include "SimpleLogger.h"

#include "SortMergeLinkedList.h"
#include "Sort.h"
/**
 * For each problem statement, you can look at how we solved each questions from the functions implemented here.
 *  
 */

namespace PerformanceEvaluation {
    class Assignment {
        public:
            /**
             * Problem Statement 1:
             * How can you efficiently sort the news articles by year and 
             * display the total number of articles in both datasets? 
             */
            static void Question_1() {
                Benchmark benchmark;
                benchmark.startTimer();
                LinkedList linked_list_true;
                LinkedList linked_list_fake;

                Array array_list_true;
                Array array_list_fake;
                
                static constexpr int32_t MAX_DISPLAY_COUNT = 5;
                std::string file_path_true = "./CSV/true.csv"; 
                std::string file_path_fake = "./CSV/fake.csv";

                // Linked List
                FileHandling::ReadFile(file_path_true, linked_list_true);
                // FileHandling::readCSV(file_path_fake, linked_list_fake);

                // Array
                // FileHandling::ReadFile(file_path_true, array_list_true);
                // FileHandling::readCSV(file_path_fake, array_list_fake);

                std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
                linked_list_true.displayFirst(MAX_DISPLAY_COUNT);

                // std::cout << "\033[35;1mBefore Sorting...\033[31;1mFAKE\033[0m\n";
                // linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);

                // std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
                // array_list_true.displayFirst(MAX_DISPLAY_COUNT);

                // std::cout << "\033[35;1mBefore Sorting...\033[31;1mFAKE\033[0m\n";
                // array_list_fake.displayFirst(MAX_DISPLAY_COUNT);

                // array_list_true.displayTitle();
                
                // Algorithm::MergeSort(linked_list_true);

                Algorithm::SortBy(linked_list_true, std::make_unique<SortMergeLinkedList>().get());

                // Algorithm::MergeSort(linked_list_fake);

                // Algorithm::MergeSort(array_list_true);
                // Algorithm::MergeSort(array_list_fake);

                // Algorithm::QuickSort(array_list_true);

                // Algorithm::HeapSort(array_list_true);
                
                // Merge/ Quick/ Heap/ (Sally)

                // Algorithm::LinearSearch(array_list_true);
                // Algorithm::LinearSearch(array_list_fake);
                
                std::cout << "\033[35;1mAfter Sorting...\033[31;1mTRUE\033[0m\n";
                linked_list_true.displayFirst(MAX_DISPLAY_COUNT);
                
                // std::cout << "\033[35;1mAfter Sorting...\033[31;1mFAKE\033[0m\n";
                // linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);

                // std::cout << "\033[35;1mAfter Sorting...\033[31;1mTRUE\033[0m\n";
                // array_list_true.displayFirst(MAX_DISPLAY_COUNT);

                linked_list_true.displayLength(file_path_true);
                // linked_list_fake.displayLength(file_path_fake);

                // array_list_true.displayLength(file_path_true);

                benchmark.endTimer();
            }

            /**
             * Problem Statement 2:
             * What percentage of political news articles (including fake and true news) 
             * from the year of 2016 are fake?  
             */
            static void Question2() {
                // * Step 1: Combine both true.csv and fake.csv, called combined.csv
                // * Step 2: Impartial search all articles with value "2016" from combined.csv
                // * Step 3: Partial search all articles with value "politics" to get fake articles 
                // * Step 4: Impartial search all articles with value "politics" to get true and fake articles that has value "politics" ("politics" and "politicsNews")
                // * Step 5: New partial searched linked list will be numerator 
                // * Step 6: New impartial searched linked list will be denominator 
                // * Step 7: Get ratio and percentage of partial / impartial 

                Benchmark benchmark;

                static constexpr int32_t MAX_DISPLAY_COUNT = 5;

                const FilePath& file_path_true = "./CSV/true.csv"; 
                const FilePath& file_path_fake = "./CSV/fake.csv";
                const FilePath& file_path_combined = "./CSV/combined.csv";

                FileHandling::AppendFileContent(file_path_true, file_path_combined);
                FileHandling::AppendFileContent(file_path_fake, file_path_combined);

                const FilePath& file_path_test = "./CSV/test.csv";
            }

            /**
             * Problem Statement 3:
             * Which words are most frequently used in fake news articles 
             * related to government topics?
             */
            static void Question3() {

            }
    };
} // namespace PerformanceEvaluation


        // PerformanceEvaluation::Benchmark benchmark;
        // PerformanceEvaluation::LinkedList linked_list;
        
        

                  // PerformanceEvaluation::FileHandling::appendFileContent("./CSV/true.csv", "./CSV/assignment.csv");
        // PerformanceEvaluation::FileHandling::appendFileContent("./CSV/fake.csv", "./CSV/assignment.csv");
        
        // linked_list.mergeSort();
        
        // linked_list.displayAll();
        // linked_list.displayTitle();
        // linked_list.displayText();
        // linked_list.displaySubject();

        // linked_list.search("2017", PerformanceEvaluation::Criteria::DATE);
        // std::cout << linked_list.getLength() << "\n";
        // linked_list.displayDate();

        // benchmark.duration([&]{ linked_list.displayAll(); });
        // linked_list.displayAll();
        // linked_list.deleteAll();

