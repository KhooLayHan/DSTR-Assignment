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
#include "SearchLinearLinkedList.h"
#include "SearchLinearArray.h"
#include "SortMergeLinkedList.h"
#include "SortQuickLinkedList.h"
#include "SortHeapLinkedList.h"
#include "SortQuickArray.h"
#include "SortHeapArray.h"
#include "Sort.h"

#include "ConversionUtility.h"
#include "HashMap.h"
#include "HashSet.h"

#include "WordList.h"
#include "WordListSorted.h"
#include "Vector.h"

#include <regex>

/**
 * For each problem statement, you can look at how we solved each questions from the functions implemented here.
 *
 */

namespace PerformanceEvaluation
{

    template <typename Func>
    auto test = [](Func func)
    {
        std::cout << "Start Testing...\n";
        func();
        std::cout << "End Testing...\n";
    };

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
            Benchmark benchmark;

            LinkedList linked_list_true;
            LinkedList linked_list_fake;

            Array<Dataset> array_true;
            Array<Dataset> array_fake;

            static constexpr int32_t MAX_DISPLAY_COUNT = 5;
            std::string file_path_true = "./CSV/true.csv";
            std::string file_path_fake = "./CSV/fake.csv";

            // FileHandling::ReadFile(file_path_true, linked_list_true);
            // FileHandling::ReadFile(file_path_fake, linked_list_fake);

            FileHandling::ReadFile(file_path_true, array_true);
            FileHandling::ReadFile(file_path_fake, array_fake);

            // std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
            // linked_list_true.DisplayFirst(MAX_DISPLAY_COUNT);

            // std::cout << "\033[35;1mBefore Sorting...\033[31;1mFAKE\033[0m\n";
            // linked_list_fake.DisplayFirst(MAX_DISPLAY_COUNT);

            std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
            array_true.DisplayFirst(MAX_DISPLAY_COUNT);

            // std::cout << "\033[35;1mBefore Sorting...\033[31;1mTRUE\033[0m\n";
            // array_fake.DisplayFirst(MAX_DISPLAY_COUNT);

            // Algorithm::SortBy(linked_list_true, std::make_unique<SortMergeLinkedList>().get());
            // Algorithm::SortBy(linked_list_true, std::make_unique<SortQuickLinkedList>().get());
            // Algorithm::SortBy(linked_list_true, std::make_unique<SortHeapLinkedList>().get());

            // Algorithm::SortBy(array_true, std::make_unique<SortMergeArray>().get());
            // Algorithm::SortBy(array_true, std::make_unique<SortQuickArray>().get());
            // Algorithm::SortBy(array_true, std::make_unique<SortHeapArray>().get());

            // Algorithm::SortBy(array_fake, std::make_unique<SortMergeArray>().get());
            // Algorithm::SortBy(array_fake, std::make_unique<SortQuickArray>().get());
            // Algorithm::SortBy(array_fake, std::make_unique<SortHeapArray>().get());

            // // // linked_list_true.mergeSort();

            // // // linked_list_true.displayDate();

            // std::cout << "\033[35;1mAfter Sorting...\033[31;1mTRUE\033[0m\n";
            // linked_list_true.DisplayFirst(MAX_DISPLAY_COUNT);

            // std::cout << "\033[35;1mAfter Sorting...\033[31;1mFAKE\033[0m\n";
            // linked_list_fake.DisplayFirst(MAX_DISPLAY_COUNT);

            std::cout << "\033[35;1mAfter Sorting...\033[31;1mTRUE\033[0m\n";
            array_true.DisplayFirst(MAX_DISPLAY_COUNT);

            // std::cout << "\033[35;1mAfter Sorting...\033[31;1mFAKE\033[0m\n";
            // array_fake.DisplayFirst(MAX_DISPLAY_COUNT);

            linked_list_true.DisplayLength(file_path_true);
            linked_list_fake.DisplayLength(file_path_fake);

            array_true.DisplayLength(file_path_true);
            array_fake.DisplayLength(file_path_fake);
        }

        /**
         * Problem Statement 2:
         * What percentage of political news articles (including fake and true news)
         * from the year of 2016 are fake?
         */
        static void Question_2()
        {
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

            Array<Dataset> array_true;
            Array<Dataset> array_fake;
            // Array<Dataset> array_combined;

            // static constexpr int32_t MAX_DISPLAY_COUNT = 5;

            const FilePath &file_path_true = "./CSV/true.csv";
            const FilePath &file_path_fake = "./CSV/fake.csv";
            const FilePath &file_path_combined = "./CSV/combined.csv";

            // ! IMPORTANT: If you want to do testing with AppendFileContent(), please use a new file that does not have the entire contents
            // ! of true.csv and fake.csv. Otherwise, your program will run very slow and file_path_combined will be too large.
            // ! Please manually insert new data for testing (just use a few lines from true.csv and fake.csv).

            FileHandling::AppendFileContent(file_path_true, file_path_combined);
            FileHandling::AppendFileContent(file_path_fake, file_path_combined);

            // FileHandling::ReadFile(file_path_true, linked_list_true);
            FileHandling::ReadFile(file_path_fake, linked_list_fake);

            FileHandling::ReadFile(file_path_combined, linked_list_combined);

            FileHandling::ReadFile(file_path_true, array_true);
            FileHandling::ReadFile(file_path_fake, array_fake);

            // 🔄 Reuse `array_true` to store combined data
            // FileHandling::ReadFile(file_path_combined, array_true);

            // IMPARTIAL Denominator&Numerator

            // Denominator
            LinkedList linked_list_combined_impartial_search_date_2016 = Algorithm::LinearSearchAndCopy(
                linked_list_combined, std::make_unique<SearchLinearLinkedList>().get(),
                "2016", Criteria::DATE, SearchType::IMPARTIAL);

            LinkedList linked_list_combined_impartial_search_date_2016_and_impartial_search_subject_politics = Algorithm::LinearSearchAndCopy(
                linked_list_combined_impartial_search_date_2016, std::make_unique<SearchLinearLinkedList>().get(),
                "politics", Criteria::SUBJECT, SearchType::IMPARTIAL);

            // Numerator
            LinkedList linked_list_fake_impartial_searched_date_2016 = Algorithm::LinearSearchAndCopy(
                linked_list_fake, std::make_unique<SearchLinearLinkedList>().get(),
                "2016", Criteria::DATE, SearchType::IMPARTIAL);

            LinkedList linked_list_fake_impartial_searched_date_2016_and_impartial_search_subject_politics = Algorithm::LinearSearchAndCopy(
                linked_list_fake_impartial_searched_date_2016, std::make_unique<SearchLinearLinkedList>().get(),
                "politics", Criteria::SUBJECT, SearchType::IMPARTIAL);

            // PARTIAL Denominator&Numerator

            // Denominator
            // LinkedList linked_list_combined_partial_searched_date_2016 = Algorithm::LinearSearchAndCopy(
            //     linked_list_combined, std::make_unique<SearchLinkedList>().get(),
            //     "2016", Criteria::DATE, SearchType::PARTIAL
            // );

            // LinkedList linked_list_combined_partial_searched_date_2016_and_partial_search_subject_politics = Algorithm::LinearSearchAndCopy(
            //     linked_list_combined_partial_searched_date_2016, std::make_unique<SearchLinkedList>().get(),
            //     "politics", Criteria::SUBJECT, SearchType::PARTIAL
            // );

            // // Numerator
            // LinkedList linked_list_fake_partial_searched_date_2016 = Algorithm::LinearSearchAndCopy(
            //     linked_list_fake, std::make_unique<SearchLinkedList>().get(),
            //     "2016", Criteria::DATE, SearchType::PARTIAL
            // );

            // Perform search on array_true (now containing combined data)

            // Array array_combined_impartial_search_date_2016 = Algorithm::LinearSearchAndCopy(
            //     array_true, std::make_unique<SearchLinearArray>().get(),
            //     "2016", Criteria::DATE, SearchType::IMPARTIAL
            // );

            // Array<Dataset> array_find;

            // // Choose search method:
            // double fakeNewsPercentage = array_find.CalculateFakeNewsPercentage(array_true, array_fake);
            // std::cout << "Fake News Percentage: " << fakeNewsPercentage << "%" << std::endl;

            // able to search by date/ date/ title/ text

            constexpr auto calculate_percentage = [](size_t numerator, size_t denominator)
            {
                return denominator == 0 ? 0.0 : (static_cast<double>(numerator) * 100.0) / static_cast<double>(denominator);
            };

            size_t numerator = linked_list_fake_impartial_searched_date_2016_and_impartial_search_subject_politics.GetLength();
            size_t denominator = linked_list_combined_impartial_search_date_2016_and_impartial_search_subject_politics.GetLength();

            std::cout << "Out of " << denominator << " true and fake articles from the year 2016, "
                      << calculate_percentage(numerator, denominator) << " of political news articles are fake.\n";

            // LinkedList linked_list_true_searched_date_2016
            //     = Algorithm::LinearSearchAndCopy(linked_list_true, std::make_unique<SearchLinkedList>(), "2016", Criteria::DATE, SearchType::IMPARTIAL);
            // LinkedList linked_list_true_searched_subject_world
            //     = Algorithm::LinearSearchAndCopy(linked_list_true_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT, SearchType::PARTIAL);

            // LinkedList linked_list_fake_searched_date_2016
            //     = Algorithm::LinearSearchAndCopy(linked_list_fake, std::make_unique<SearchLinkedList>(), "2016", Criteria::DATE);
            // LinkedList linked_list_fake_searched_subject_world
            //     = Algorithm::LinearSearchAndCopy(linked_list_fake_searched_date_2016, std::make_unique<SearchLinkedList>(), "politics", Criteria::SUBJECT);

            // * ----- *

            // Question_2_ExtraExclusive();

            const FilePath &file_path_test = "./CSV/test.csv";

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
        static void Question_3()
        {
            const FilePath &file_path_fake = "./CSV/fake.csv";

            LinkedList linked_list_fake;
            FileHandling::ReadFile(file_path_fake, linked_list_fake);

            auto search_interface = std::make_unique<SearchLinearLinkedList>();

            // Search for "government" in the subject
            LinkedList linked_list_fake_impartial_searched_subject_government =
                Algorithm::LinearSearchAndCopy(
                    linked_list_fake,
                    search_interface.get(),
                    "government",
                    Criteria::SUBJECT,
                    SearchType::IMPARTIAL);

            // Stopwords to remove common words
            HashSet<std::string> stopwords = {
                "a", "an", "and", "are", "as", "at", "be", "but", "by",
                "for", "if", "in", "into", "is", "it", "no", "not", "of",
                "on", "or", "such", "that", "the", "their", "then", "there",
                "these", "they", "this", "to", "was", "will", "with"};

            // Convert LinkedList to WordList (tokenization + stopwords removal)
            WordList word_list_fake = ConvertLinkedListToWordList(
                linked_list_fake_impartial_searched_subject_government,
                stopwords);

            // Create a HashMap of word frequencies
            HashMap<std::string, int32_t> word_map = GetWordCount(word_list_fake);

            // Convert HashMap to Sorted Array (Descending Order)
            std::vector<std::pair<std::string, int32_t>> sorted_words;
            for (const auto &pair : word_map)
            {
                sorted_words.emplace_back(pair);
            }

            // Sort by frequency (high to low)
            std::sort(
                sorted_words.begin(),
                sorted_words.end(),
                [](const auto &a, const auto &b)
                {
                    return a.second > b.second;
                });

            // Display results
            std::cout << "Top 10 most common words in fake government-related news:\n";
            for (size_t i = 0; i < std::min(sorted_words.size(), size_t(10)); i++)
            {
                std::cout << sorted_words[i].first << " - "
                          << sorted_words[i].second << " times\n";
            }
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
