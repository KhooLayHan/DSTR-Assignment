#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Struct with member variables: title, text, subject, date
#include "Dataset.h"

// Data structures
#include "DLL.h"

// Sorting Algorithm for Doubly Linked List
#include "MergeSortDLL.h"

// File handling
#include "FileHandling.h"

// Helper classes for debugging and parsing dates
#include "DateUtility.h"
#include "SimpleLogger.h"

namespace PerformanceEvaluation
{
    /**
     * Reads CSV data and inserts into a Doubly Linked List.
     */
    void readCSV(const std::string &filename, LinkedList &newsList)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::cout << "Successfully opened: " << filename << std::endl; // Debugging line

        std::string line, title, text, subject, date;
        int id = 1; // Assigning incremental ID

        // Read header line and ignore it
        getline(file, line);

        while (getline(file, line))
        {
            std::stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, text, ',');
            getline(ss, subject, ',');
            getline(ss, date, ',');

            // Insert data into the linked list
            newsList.insertEnd(Dataset{id++, title, text, subject, date});
        }
        file.close();
    }

    /**
     *  Reads CSV, applies MergeSort, and displays results.
     */
    void runAssignmentTests()
    {
        LinkedList linked_list_true;
        LinkedList linked_list_fake;

        static constexpr int32_t MAX_DISPLAY_COUNT = 5;

        // Use the correct CSV folder path
        std::string file_path_true = "./CSV/true.csv";
        std::string file_path_fake = "./CSV/fake.csv";

        // Read CSV files into linked lists
        readCSV(file_path_true, linked_list_true);
        readCSV(file_path_fake, linked_list_fake);

        // Display before sorting
        std::cout << "Before Sorting... TRUE NEWS\n";
        linked_list_true.displayFirst(MAX_DISPLAY_COUNT);

        std::cout << "Before Sorting... FAKE NEWS\n";
        linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);

        // Apply MergeSort to both datasets
        clock_t start = clock();
        linked_list_true.sortMerge();
        linked_list_fake.sortMerge();
        clock_t end = clock();

        std::cout << "\nMergeSort took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";

        // Display after sorting
        std::cout << "After Sorting... TRUE NEWS\n";
        linked_list_true.displayFirst(MAX_DISPLAY_COUNT);

        std::cout << "After Sorting... FAKE NEWS\n";
        linked_list_fake.displayFirst(MAX_DISPLAY_COUNT);

        linked_list_true.displayLength(file_path_true);
        linked_list_fake.displayLength(file_path_fake);
    }
} // namespace PerformanceEvaluation
