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
#include "DateUtility.cpp"
#include "SimpleLogger.h"

/**
 * For each problem statement, you can look at how we solved each questions from the functions implemented here.
 *
 */

namespace PerformanceEvaluation
{
    class Assignment
    {
    public:
        /**
         * Problem Statement 1:
         * How can you efficiently sort the news articles by year and
         * display the total number of articles in both datasets?
         */
        static void Question_1()
        {
            LinkedList linked_list_true;
            LinkedList linked_list_fake;

            static constexpr int32_t MAX_DISPLAY_COUNT = 5;
            std::string file_path_true = "./CSV/true.csv";
            std::string file_path_fake = "./CSV/fake.csv";

            FileHandling::readCSV(file_path_true, linked_list_true);
            FileHandling::readCSV(file_path_fake, linked_list_fake);

            std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
            linked_list_true.displayFirst(MAX_DISPLAY_COUNT);

            std::cout << "\033[35;1mBefore Sorting...\033[31;1mFAKE\033[0m\n";
            linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);

            // linked_list_true.mergeSort();
            Algorithm::MergeSort(linked_list_true);
            Algorithm::MergeSort(linked_list_fake);

            // linked_list_true.displayDate();

            std::cout << "\033[35;1mAfter Sorting...\033[31;1mTRUE\033[0m\n";
            linked_list_true.displayFirst(MAX_DISPLAY_COUNT);

            std::cout << "\033[35;1mAfter Sorting...\033[31;1mFAKE\033[0m\n";
            linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);

            linked_list_true.displayLength(file_path_true);
            linked_list_fake.displayLength(file_path_fake);
        }

        /**
         * Problem Statement 2:
         * What percentage of political news articles (including fake and true news)
         * from the year of 2016 are fake?
         */
        static void Question2()
        {
        }

        /**
         * Problem Statement 3:
         * Which words are most frequently used in fake news articles
         * related to government topics?
         */
        static void Question3()
        {
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
