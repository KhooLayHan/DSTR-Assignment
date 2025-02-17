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

#include <future>
#include <memory>

// File handling
#include "FileHandling.h"

// Helper classes for debugging and parsing dates
#include "DateUtility.h"
#include "SimpleLogger.h"

#include "Benchmark.h"
#include "SearchLinkedList.h"
#include "SortMergeLinkedList.h"
#include "Sort.h"

/**
 * For each problem statement, you can look at how we solved each questions from the functions implemented here.
 *  
 */

namespace PerformanceEvaluation {

    template <typename Func>
    auto test = [](Func func) {
        std::cout << "Start Testing...\n";
        func();
        std::cout << "End Testing...\n";
    };

    class Assignment {
        public:
            /**
             * Problem Statement 1:
             * How can you efficiently sort the news articles by year and 
             * display the total number of articles in both datasets? 
             */
            static void Question_1() {
                Benchmark benchmark;
                      
                LinkedList linked_list_true;
                LinkedList linked_list_fake;
                
                // static constexpr int32_t MAX_DISPLAY_COUNT = 5;
                std::string file_path_true = "./CSV/true.csv"; 
                std::string file_path_fake = "./CSV/fake.csv";

                // FileHandling::ReadFile(file_path_true, linked_list_true);
                FileHandling::ReadFile(file_path_fake, linked_list_fake);

                // std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
                // linked_list_true.displayFirst(MAX_DISPLAY_COUNT);

                // std::cout << "\033[35;1mBefore Sorting...\033[31;1mFAKE\033[0m\n";
                // linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);
                
                // // // linked_list_true.mergeSort();
                // Algorithm::MergeSort(linked_list_true);
                // Algorithm::MergeSort(linked_list_fake);

                // // // linked_list_true.displayDate();
                
                // std::cout << "\033[35;1mAfter Sorting...\033[31;1mTRUE\033[0m\n";
                // linked_list_true.displayFirst(MAX_DISPLAY_COUNT);
                
                // std::cout << "\033[35;1mAfter Sorting...\033[31;1mFAKE\033[0m\n";
                // linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);

                // linked_list_true.displayLength(file_path_true);
                linked_list_fake.displayLength(file_path_fake);
            }

            /**
             * Problem Statement 2:
             * What percentage of political news articles (including fake and true news) 
             * from the year of 2016 are fake?  
             */
            static void Question_2() {
                // * Step 1: Combine both true.csv and fake.csv, called combined.csv
                // * Step 2: Impartial search all articles with value "2016" from combined.csv
                // * Step 3: Partial search all articles with value "politics" to get fake articles 
                // * Step 4: Impartial search all articles with value "politics" to get true and fake articles that has value "politics" ("politics" and "politicsNews")
                // * Step 5: New partial searched linked list will be numerator 
                // * Step 6: New impartial searched linked list will be denominator 
                // * Step 7: Get ratio and percentage of partial / impartial 
                
                Benchmark benchmark;
              // static const std::string& political_news = {
                //     "politicsNews", "politics"
                // }; 
                // LinkedList linked_list_true;
                // LinkedList linked_list_fake;
                // LinkedList linked_list_combined;
                
                static constexpr int32_t MAX_DISPLAY_COUNT = 5;

                const FilePath& file_path_true = "./CSV/true.csv"; 
                const FilePath& file_path_fake = "./CSV/fake.csv";
                const FilePath& file_path_combined = "./CSV/combined.csv";
                
                // ! IMPORTANT: If you want to do testing with AppendFileContent(), please use a new file that does not have the entire contents
                // ! of true.csv and fake.csv. Otherwise, your program will run very slow and file_path_combined will be too large.
                // ! Please manually insert new data for testing (just use a few lines from true.csv and fake.csv). 
                
                // FileHandling::AppendFileContent(file_path_true, file_path_combined);
                // FileHandling::AppendFileContent(file_path_fake, file_path_combined);
                
                // FileHandling::ReadFile(file_path_true, linked_list_true);
                // FileHandling::ReadFile(file_path_fake, linked_list_fake);

                // LinkedList linked_list_combined_searched_date_2016 = Algorithm::LinearSearchAndCopy(
                //     linked_list_combined, std::make_unique<SearchLinkedList>(), 
                //     "2016", Criteria::DATE, SearchType::IMPARTIAL
                // );

                // LinkedList linked_list_combined_searched_date_2016_and_subject_politics = Algorithm::LinearSearchAndCopy(
                //     linked_list_combined_searched_date_2016, std::make_unique<SearchLinkedList>(), 
                //     "politics", Criteria::SUBJECT, SearchType::PARTIAL
                // );

                // LinkedList linked_list_true_searched_date_2016 
                //     = Algorithm::LinearSearchAndCopy(linked_list_true, std::make_unique<SearchLinkedList>(), "2016", Criteria::DATE, SearchType::IMPARTIAL);
                // LinkedList linked_list_true_searched_subject_world 
                //     = Algorithm::LinearSearchAndCopy(linked_list_true_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT, SearchType::PARTIAL);
                
                // LinkedList linked_list_fake_searched_date_2016 
                //     = Algorithm::LinearSearchAndCopy(linked_list_fake, std::make_unique<SearchLinkedList>(), "2016", Criteria::DATE);
                // LinkedList linked_list_fake_searched_subject_world 
                //     = Algorithm::LinearSearchAndCopy(linked_list_fake_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT);

                // * ----- *

                const FilePath& file_path_test = "./CSV/test.csv";

                LinkedList linked_list_test;
                LinkedList linked_list_assignment;

                // ! Please manually remove the contents of assignment.csv to preevent from the file being too large
                
                // FileHandling::AppendFileContent(file_path_test, file_path_assignment);

                FileHandling::ReadFile(file_path_test, linked_list_test); 

                LinkedList linked_list_test_impartial_searched_date_2016 
                    = Algorithm::LinearSearchAndCopy(linked_list_test, std::make_unique<SearchLinkedList>(), "2016", Criteria::DATE, SearchType::IMPARTIAL);

                // True and Fake data "politics", "politicsNews"; Denominator
                LinkedList linked_list_test_impartial_searched_date_2016_and_impartial_searched_subject_politics 
                    = Algorithm::LinearSearchAndCopy(linked_list_test_impartial_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT, SearchType::IMPARTIAL);

                // Fake data "politics"; Numerator
                LinkedList linked_list_test_impartial_searched_date_2016_and_partial_searched_subject_politics 
                    = Algorithm::LinearSearchAndCopy(linked_list_test_impartial_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT, SearchType::PARTIAL);

                constexpr auto calculate_percentage = [](size_t numerator, size_t denominator) {
                    return (numerator * 100) / denominator;
                };

                size_t numerator = linked_list_test_impartial_searched_date_2016_and_partial_searched_subject_politics.getLength();
                size_t denominator = linked_list_test_impartial_searched_date_2016_and_impartial_searched_subject_politics.getLength();

                std::cout << "Out of " << denominator << " true and fake articles from the year 2016, " 
                    << calculate_percentage(numerator, denominator) << "% of political news articles are fake.\n";
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


                // std::unique_ptr<Sort<LinkedList, LinkedListNode*>> sorter = std::make_unique<SortMergeLinkedList>();
                // linked_list_true.UseSortingAlgorithm(sorter);
                
                // std::cout << search_linked_list_subject_world.getLength() << "\n";
                // search_linked_list_subject_world.displayFirst(MAX_DISPLAY_COUNT);

                // Algorithm::SortBy(search_linked_list, std::make_unique<SortMergeLinkedList>());
                
                // auto sort_by = [](const Dataset& first_dataset, const Dataset& second_dataset){
                //     return first_dataset.m_Subject < second_dataset.m_Subject;
                // }

                // Algorithm::SortBy(search_linked_list, std::make_unique<SortMergeLinkedList>(), sort_by());
