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
// #include "Sort.h"

#include "ConversionUtility.h"
#include "HashMap.h"
// #include "HashMap.h"

#include "WordList.h"
#include "WordListSorted.h"

#include "HashSet.h"
#include "Vector.h"

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
                      
                LinkedList linked_list_true;
                LinkedList linked_list_fake;
                
                static constexpr int32_t MAX_DISPLAY_COUNT = 5;
                std::string file_path_true = "./CSV/true.csv"; 
                std::string file_path_fake = "./CSV/fake.csv";

                FileHandling::ReadFile(file_path_true, linked_list_true);
                FileHandling::ReadFile(file_path_fake, linked_list_fake);

                std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
                linked_list_true.DisplayFirst(MAX_DISPLAY_COUNT);

                std::cout << "\033[35;1mBefore Sorting...\033[31;1mFAKE\033[0m\n";
                linked_list_fake.DisplayFirst(MAX_DISPLAY_COUNT);
                
                // auto interface = std::make_unique<SortMergeLinkedList>();

                // Algorithm::SortBy(linked_list_true, interface.get());
                // // // linked_list_true.mergeSort();

                // // // linked_list_true.displayDate();
                
                std::cout << "\033[35;1mAfter Sorting...\033[31;1mTRUE\033[0m\n";
                linked_list_true.DisplayFirst(MAX_DISPLAY_COUNT);
                
                std::cout << "\033[35;1mAfter Sorting...\033[31;1mFAKE\033[0m\n";
                linked_list_fake.DisplayFirst(MAX_DISPLAY_COUNT);

                linked_list_true.DisplayLength(file_path_true);
                linked_list_fake.DisplayLength(file_path_fake);
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
                LinkedList linked_list_true;
                LinkedList linked_list_fake;
                LinkedList linked_list_combined;
                
                // static constexpr int32_t MAX_DISPLAY_COUNT = 5;

                const FilePath& file_path_true = "./CSV/true.csv"; 
                const FilePath& file_path_fake = "./CSV/fake.csv";
                const FilePath& file_path_combined = "./CSV/combined.csv";
                
                // ! IMPORTANT: If you want to do testing with AppendFileContent(), please use a new file that does not have the entire contents
                // ! of true.csv and fake.csv. Otherwise, your program will run very slow and file_path_combined will be too large.
                // ! Please manually insert new data for testing (just use a few lines from true.csv and fake.csv). 
                
                FileHandling::AppendFileContent(file_path_true, file_path_combined);
                FileHandling::AppendFileContent(file_path_fake, file_path_combined);
                
                // FileHandling::ReadFile(file_path_true, linked_list_true);
                // FileHandling::ReadFile(file_path_fake, linked_list_fake);
                
                FileHandling::ReadFile(file_path_combined, linked_list_combined);

                // Denominator
                LinkedList linked_list_combined_impartial_search_date_2016 = Algorithm::LinearSearchAndCopy(
                    linked_list_combined, std::make_unique<SearchLinearLinkedList>().get(), 
                    "2016", Criteria::DATE, SearchType::IMPARTIAL
                );

                // // Denominator
                // LinkedList linked_list_combined_impartial_search_date_2016_and_impartial_search_subject_politics = Algorithm::LinearSearchAndCopy(
                //     linked_list_combined_impartial_search_date_2016, std::make_unique<SearchLinkedList>().get(), 
                //     "politics", Criteria::SUBJECT, SearchType::IMPARTIAL
                // );

                // Numerator
                LinkedList linked_list_combined_impartial_search_date_2016_and_partial_search_subject_politics = Algorithm::LinearSearchAndCopy(
                    linked_list_combined_impartial_search_date_2016, std::make_unique<SearchLinearLinkedList>().get(), 
                    "politics", Criteria::SUBJECT, SearchType::PARTIAL
                );

                constexpr auto calculate_percentage = [](size_t numerator, size_t denominator) {
                    return (numerator * 100) / denominator;
                };

                size_t numerator = linked_list_combined_impartial_search_date_2016_and_partial_search_subject_politics.GetLength();
                size_t denominator = linked_list_combined_impartial_search_date_2016.GetLength();

                std::cout << "Out of " << denominator << " true and fake articles from the year 2016, " 
                    << calculate_percentage(numerator, denominator) << "% of political news articles are fake.\n";

                // LinkedList linked_list_true_searched_date_2016 
                //     = Algorithm::LinearSearchAndCopy(linked_list_true, std::make_unique<SearchLinkedList>(), "2016", Criteria::DATE, SearchType::IMPARTIAL);
                // LinkedList linked_list_true_searched_subject_world 
                //     = Algorithm::LinearSearchAndCopy(linked_list_true_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT, SearchType::PARTIAL);
                
                // LinkedList linked_list_fake_searched_date_2016 
                //     = Algorithm::LinearSearchAndCopy(linked_list_fake, std::make_unique<SearchLinkedList>(), "2016", Criteria::DATE);
                // LinkedList linked_list_fake_searched_subject_world 
                //     = Algorithm::LinearSearchAndCopy(linked_list_fake_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT);

                // * ----- *

                // Question 2 Extra Exclusive

                Question_2_ExtraExclusive();

                // LinkedListDoubly linked_list_doubly;
                
                LinkedList linked_list;
                
                const FilePath& file_path_fake = "./CSV/fake.csv";
                LinkedList linked_list_fake;

                FileHandling::ReadFile(file_path_fakelinked_list_fake);

                auto search_interface = std::make_unique<SearchLinearLinkedList>();

                LinkedList linked_list_impartial_searched_2016 = Algorithm::LinearSearchAndCopy(linked_list_fake, search_interface.get(), "2016", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_and_partial_search_subject_politics
                    = Algorithm::LinearSearchAndCopy(linked_list, search_interface.get(), "politics", Criteria::SUBJECT, SearchType::PARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_january 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Jan", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_february 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Feb", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_march 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Mar", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_april 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Apr", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_may 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "May", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_june 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Jun", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_july 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Jul", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_august 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Aug", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_september 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Sep", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_october 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Oct", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_november 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Nov", Criteria::DATE, SearchType::IMPARTIAL);
                
                LinkedList linked_list_impartial_searched_2016_december 
                    = Algorithm::LinearSearchAndCopy(linked_list_impartial_searched_2016_and_partial_search_subject_politics, search_interface.get(), "Dec", Criteria::DATE, SearchType::IMPARTIAL);

                size_t january      = linked_list_impartial_searched_2016_january.GetLength();
                size_t february     = linked_list_impartial_searched_2016_february.GetLength();
                size_t march        = linked_list_impartial_searched_2016_march.GetLength();
                size_t april        = linked_list_impartial_searched_2016_april.GetLength();
                size_t may          = linked_list_impartial_searched_2016_may.GetLength();
                size_t june         = linked_list_impartial_searched_2016_june.GetLength();
                size_t july         = linked_list_impartial_searched_2016_july.GetLength();
                size_t august       = linked_list_impartial_searched_2016_august.GetLength();
                size_t september    = linked_list_impartial_searched_2016_september.GetLength();
                size_t october      = linked_list_impartial_searched_2016_october.GetLength();
                size_t november     = linked_list_impartial_searched_2016_november.GetLength();
                size_t december     = linked_list_impartial_searched_2016_december.GetLength();
                
                size_t fake_2016    = linked_list_impartial_searched_2016_and_partial_search_subject_politics.GetLength(); 

                float jan_fake_2016 = calculate_percentage(january, fake_2016); 
                float feb_fake_2016 = calculate_percentage(january, fake_2016); 
                float mar_fake_2016 = calculate_percentage(january, fake_2016); 
                float apr_fake_2016 = calculate_percentage(january, fake_2016); 
                float may_fake_2016 = calculate_percentage(january, fake_2016); 
                float jun_fake_2016 = calculate_percentage(january, fake_2016); 
                float jul_fake_2016 = calculate_percentage(january, fake_2016); 
                float aug_fake_2016 = calculate_percentage(january, fake_2016); 
                float sep_fake_2016 = calculate_percentage(january, fake_2016); 
                float oct_fake_2016 = calculate_percentage(january, fake_2016); 
                float nov_fake_2016 = calculate_percentage(january, fake_2016); 
                float dec_fake_2016 = calculate_percentage(january, fake_2016); 

                std::cout << "Percentage of Fake Political News Articles in 2016"; 

                std::cout << "January   | " << jan_fake_2016 << "%\n";
                std::cout << "February  | " << feb_fake_2016 << "%\n";
                std::cout << "March     | " << mar_fake_2016 << "%\n";
                std::cout << "April     | " << apr_fake_2016 << "%\n";
                std::cout << "May       | " << may_fake_2016 << "%\n";
                std::cout << "June      | " << jun_fake_2016 << "%\n";
                std::cout << "July      | " << jul_fake_2016 << "%\n";
                std::cout << "August    | " << aug_fake_2016 << "%\n";
                std::cout << "September | " << sep_fake_2016 << "%\n";
                std::cout << "October   | " << oct_fake_2016 << "%\n";
                std::cout << "November  | " << nov_fake_2016 << "%\n";
                std::cout << "December  | " << dec_fake_2016 << "%\n";

                // linked_list_doubly.InsertEnd()

                
                const FilePath& file_path_test = "./CSV/test.csv";

                LinkedList linked_list_test;
                LinkedList linked_list_assignment;

                // ! Please manually remove the contents of assignment.csv to preevent from the file being too large
                
                // FileHandling::AppendFileContent(file_path_test, file_path_assignment);

                // FileHandling::ReadFile(file_path_test, linked_list_test); 

                // LinkedList linked_list_test_impartial_searched_date_2016 
                //     = Algorithm::LinearSearchAndCopy(linked_list_test, std::make_unique<SearchLinkedList>().get(), "2016", Criteria::DATE, SearchType::IMPARTIAL);

                // // True and Fake data "politics", "politicsNews"; Denominator
                // LinkedList linked_list_test_impartial_searched_date_2016_and_impartial_searched_subject_politics 
                //     = Algorithm::LinearSearchAndCopy(linked_list_test_impartial_searched_date_2016, std::make_unique<SearchLinkedList>().get(), "politics", Criteria::SUBJECT, SearchType::IMPARTIAL);

                // // Fake data "politics"; Numerator
                // LinkedList linked_list_test_impartial_searched_date_2016_and_partial_searched_subject_politics 
                //     = Algorithm::LinearSearchAndCopy(linked_list_test_impartial_searched_date_2016, std::make_unique<SearchLinkedList>().get(), "politics", Criteria::SUBJECT, SearchType::PARTIAL);

                // constexpr auto calculate_percentage = [](size_t numerator, size_t denominator) {
                //     return (numerator * 100) / denominator;
                // };

                // size_t numerator = linked_list_test_impartial_searched_date_2016_and_partial_searched_subject_politics.GetLength();
                // size_t denominator = linked_list_test_impartial_searched_date_2016_and_impartial_searched_subject_politics.GetLength();

                // std::cout << "Out of " << denominator << " true and fake articles from the year 2016, " 
                //     << calculate_percentage(numerator, denominator) << "% of political news articles are fake.\n";
            }

            /**
             * Problem Statement 3:
             * Which words are most frequently used in fake news articles 
             * related to government topics?
             */
            static void Question_3() {
                const FilePath& file_path_fake = "./CSV/fake.csv";

                LinkedList linked_list_fake;
                FileHandling::ReadFile(file_path_fake, linked_list_fake);

                auto search_interface = std::make_unique<SearchLinearLinkedList>();

                LinkedList linked_list_fake_impartial_searched_subject_government = 
                    Algorithm::LinearSearchAndCopy(linked_list_fake, search_interface.get(), "government", Criteria::SUBJECT, SearchType::IMPARTIAL);

                HashSet<std::string> stopwords = {
                    "a", "an", "and", "are", "as", "at", "be", "but", "by", 
                    "for", "if", "in", "into", "is", "it", "no", "not", "of", 
                    "on", "or", "such", "that", "the", "their", "then", "there", 
                    "these", "they", "this", "to", "was", "will", "with"
                };

                // std::cout << stopwords.Size() << '\n';

                WordList word_list_fake = ConvertLinkedListToWordList(linked_list_fake_impartial_searched_subject_government, stopwords);

                HashMap<std::string, int32_t> word_map = GetWordCount(word_list_fake);
                
                WordListSorted word_list_sorted = CheckAndSortHashMap(word_map);

                // * Please convert from HashMap to Sorted Array (WEI SHEN)

                word_list_sorted.DisplayAll();
            }
    }; // class Assignment
} // namespace PerformanceEvaluation