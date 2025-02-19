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
#include "DateUtility.h"  
#include "Assignment.cpp"   
#include "Algorithm.h"    
#include "Array.h"
#include "DLL.h"

static int s_AllocationCount = 0;

void *operator new(size_t size)
{
    s_AllocationCount++;
    return malloc(size);
}

void operator delete(void *ptr, size_t) noexcept
{
    s_AllocationCount--;
    free(ptr);
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
        getline(ss, title, ',');
        getline(ss, text, ',');
        getline(ss, subject, ',');
        getline(ss, date, ',');

        newsArray.insertEnd(PerformanceEvaluation::Dataset{id++, title, text, subject, date});
    }
    file.close();
}

int main()
{
    using namespace PerformanceEvaluation;
    Array newsArray;

    // Load data from CSV files
    readCSV("true.csv", newsArray);
    readCSV("fake.csv", newsArray);

    std::cout << "Total articles loaded: " << newsArray.getLength() << "\n\n";

    // QuickSort
    clock_t start = clock();
    Array *sortedQuick = Algorithm::QuickSort(newsArray);
    clock_t end = clock();
    std::cout << "QuickSort took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    sortedQuick->displayFirst(5);
    delete sortedQuick;

    // MergeSort
    start = clock();
    Array *sortedMerge = Algorithm::MergeSort(newsArray);
    end = clock();
    std::cout << "MergeSort took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    sortedMerge->displayFirst(5);
    delete sortedMerge;

    // HeapSort
    start = clock();
    Array *sortedHeap = Algorithm::HeapSort(newsArray); 
    end = clock();
    std::cout << "HeapSort took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
    sortedHeap->displayFirst(5);
    delete sortedHeap;

    std::cout << "\n" << s_AllocationCount << " allocations.\n";
}
