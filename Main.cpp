// C Headers
#include <cstdio>

// C++ Headers
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>

// Header files
#include "Dataset.h"
#include "DateUtility.cpp"
#include "Assignment.cpp"
#include "Algorithm.cpp"
#include "Array.h"

static int s_AllocationCount = 0;

void *operator new(size_t size)
{
    // std::cout << "Allocated " << size << " bytes\n";
    s_AllocationCount++;
    return malloc(size);
}

// Function to read data from CSV and insert into Array
void readCSV(const std::string &filename, PerformanceEvaluation::Array &newsArray)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line, title, text, subject, date;
    int id = 1; // Assigning incremental ID

    // Read header line and ignore it
    getline(file, line);

    while (getline(file, line))
    {
        std::stringstream ss(line);

        // Read CSV values
        getline(ss, title, ',');
        getline(ss, text, ',');
        getline(ss, subject, ',');
        getline(ss, date, ',');

        // Convert date from string to integer (assuming YYYY format)
        int year = std::stoi(date.substr(date.length() - 4));

        // Insert into newsArray
        newsArray.insertEnd(PerformanceEvaluation::Dataset{id++, title, text, subject, date});
    }

    file.close();
}

int main(/* int argc, char** argv */)
{
    PerformanceEvaluation::Assignment::Question_1();

    // --- START OF ARRAY SORTING IMPLEMENTATIONS ---

    using namespace PerformanceEvaluation;

    Array newsArray;

    // Load data from CSV files
    readCSV("true.csv", newsArray);
    readCSV("fake.csv", newsArray);

    std::cout << "Total articles loaded: " << newsArray.getLength() << "\n\n";

    // QuickSort
    clock_t start = clock();
    Array *sortedQuick = Algorithm::QuickSort(&newsArray);
    clock_t end = clock();
    std::cout << "QuickSort took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    sortedQuick->displayFirst(5);

    // MergeSort
    start = clock();
    Array *sortedMerge = Algorithm::MergeSort(&newsArray);
    end = clock();
    std::cout << "MergeSort took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    sortedMerge->displayFirst(5);

    // HeapSort
    start = clock();
    Array *sortedHeap = Algorithm::HeapSort(&newsArray);
    end = clock();
    std::cout << "HeapSort took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    sortedHeap->displayFirst(5);

    // --- END OF ARRAY SORTING IMPLEMENTATIONS ---

    std::cout << "\n"
              << s_AllocationCount << " allocations.\n";

    // Example usage of DateUtility
    PerformanceEvaluation::DateUtility date = PerformanceEvaluation::DateUtility::parseDate("January 1, 2023");
    std::cout << "Day: " << date.getDay("January 1, 2023") << std::endl;
    std::cout << "Month: " << date.getMonth("January 1, 2023") << std::endl;
    std::cout << "Year: " << date.getYear("January 1, 2023") << std::endl;

    return 0;
}
