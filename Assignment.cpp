#include <iostream>
#include <ctime>
#include "Dataset.h"
#include "DateUtility.h"
#include "Algorithm.h"
#include "Array.h"
#include "DLL.h"
#include "QuickSortDLL.h"
#include "HeapSortDLL.h"
#include "MergeSortDLL.h"

#include "Benchmark.h"

namespace PerformanceEvaluation
{
    // Reads data from CSV into an Array
    void readCSVArray(const std::string &filename, Array &newsArray)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line, title, text, subject, date;
        int id = 1;

        getline(file, line); // Ignore header

        while (getline(file, line))
        {
            std::stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, text, ',');
            getline(ss, subject, ',');
            getline(ss, date, ',');

            newsArray.insertEnd(Dataset{id++, title, text, subject, date});
        }
        file.close();
    }

    // Reads data from CSV into a Doubly Linked List
    void readCSVLinkedListDoubly(const std::string &filename, LinkedListDoubly &newsList)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line, title, text, subject, date;
        int id = 1;

        getline(file, line); // Ignore header

        while (getline(file, line))
        {
            std::stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, text, ',');
            getline(ss, subject, ',');
            getline(ss, date, ',');

            newsList.insertEnd(Dataset{id++, title, text, subject, date});
        }
        file.close();
    }

    // Function to run all sorting types for ARRAY
    void runArraySorting()
    {
        Array newsArray;
        readCSVArray("true.csv", newsArray);
        readCSVArray("fake.csv", newsArray);

        std::cout << "Total articles loaded (Array): " << newsArray.getLength() << "\n\n";

        // clock_t start, end;

        // QuickSort
        // start = clock();
        // Array *sortedQuickArray = Algorithm::QuickSort(newsArray);
        // end = clock();
        // std::cout << "QuickSort (Array) took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
        // sortedQuickArray->displayFirst(5);
        // delete sortedQuickArray;

        Benchmark benchmark;
        benchmark.startTimer();
        benchmark.endTimer();

        // // MergeSort
        // start = clock();
        // Array *sortedMergeArray = Algorithm::MergeSort(newsArray);
        // end = clock();
        // std::cout << "MergeSort (Array) took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
        // sortedMergeArray->displayFirst(5);
        // delete sortedMergeArray;

        // // HeapSort
        // start = clock();
        // Array *sortedHeapArray = Algorithm::HeapSort(newsArray);
        // end = clock();
        // std::cout << "HeapSort (Array) took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
        // sortedHeapArray->displayFirst(5);
        // delete sortedHeapArray;

        std::cout << "\n====================================================\n";

        benchmark.endTimer();
    }

    // Function to run all sorting types for DOUBLY LINKED LIST
    void runLinkedListSorting()
    {
        LinkedListDoubly newsList;
        PerformanceEvaluation::readCSVLinkedListDoubly("./CSV/fake.csv", newsList);
        // PerformanceEvaluation::readCSVLinkedListDoubly("./CSV/true.csv", newsList);
        
        // readCSVLinkedListDoubly("true.csv", newsList);
        // readCSVLinkedListDoubly("fake.csv", newsList);

        std::cout << "Total articles loaded (Linked List): " << newsList.getLength() << "\n\n";

        clock_t start, end;

        // MergeSort
        LinkedListDoubly mergeSortedList = newsList;
        start = clock();
        mergeSortedList.setHead(MergeSortDLL::mergeSort(mergeSortedList.getHead()));
        end = clock();
        std::cout << "MergeSort (Linked List) took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
        mergeSortedList.displayFirst(5);

        // QuickSort
        LinkedListDoubly quickSortedList = newsList;
        start = clock();
        QuickSortDLL::quickSort(quickSortedList.getHead());
        end = clock();
        std::cout << "QuickSort (Linked List) took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
        quickSortedList.displayFirst(5);

        // HeapSort
        LinkedListDoubly heapSortedList = newsList;
        start = clock();
        HeapSortDLL::heapSort(heapSortedList);
        end = clock();
        std::cout << "HeapSort (Linked List) took: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
        heapSortedList.displayFirst(5);
    }
}
