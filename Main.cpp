// C Headers
#include <cstdio>

// C++ Headers
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>

// Header files

#include "Assignment.cpp"

// #include "Algorithms.cpp" 
// #include "FileHandling.h"
// #include "Benchmark.h"
// #include "LinkedList.h"
// #include "Dataset.h"
// #include "SimpleLogger.h"

// ! Not allow to use this list of built-in containers: https://www.geeksforgeeks.org/containers-cpp-stl/

static int s_AllocationCount = 0; 

void* operator new(size_t size) {
    // std::cout << "Allocated " << size << " bytes\n";
    s_AllocationCount++;
    return malloc(size);
}

int main(/* int argc, char** argv */)
{
    PerformanceEvaluation::Assignment::Question_1();

    // PerformanceEvaluation::LinkedList linked_list_true;
    // PerformanceEvaluation::LinkedList linked_list_fake;

    // std::string file_path_true = "./CSV/true.csv"; 
    // // std::string file_path_fake = "./CSV/fake.csv";

    // // PerformanceEvaluation::FileHandling::readCSV(file_path_true, linked_list_true);
    // // FileHandling::readCSV(file_path_fake, linked_list_fake);

    // Algorithm::MergeSort(linked_list_true);
    // // Algorithm::MergeSort(linked_list_fake);

    // linked_list_true.displayLength(file_path_true);
    // linked_list_true.displayLength(file_path_fake);

    // using namespace PerformanceEvaluation;

    {
        // PerformanceEvaluation::SimpleLogger::Info("\033[31;42mRed TEXT \033[0m", PerformanceEvaluation::LogHandler::CONSOLE);
        // std::cout << "\033[31;42;1mRed TEXT \033[0m" << "\n";
        // std::cerr << "\033[31mRed TEXT \033[0m" << "\n";

        // PerformanceEvaluation::Benchmark benchmark;
        // PerformanceEvaluation::LinkedList linked_list;
        
        // PerformanceEvaluation::FileHandling::readCSV("./CSV/test.csv", linked_list);
        
        // PerformanceEvaluation::FileHandling::appendFileContent("./CSV/test.csv", "./CSV/assignment.csv");
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
    }
    {
        // PerformanceEvaluation::Benchmark benchmark_2;
        // PerformanceEvaluation::LinkedList linked_list_2;
        // linked_list_2.addBegin({ "text", "title", "subject", "2016" });
        // // linked_list.addBegin("text 2016");
        // linked_list_2.insertEnd({ "text1", "title1", "subject1", "December 15, 2015" });
        // linked_list_2.insertEnd({ "text2", "title2", "subject2", "October 10, 2012" });
        // linked_list_2.insertEnd({ "text3", "title3", "subject3", "January 14, 2017" });
        // linked_list_2.insertEnd({ "text4", "title4", "subject4", "March 20, 2011" });
        // linked_list_2.display();
    }

    std::cout << s_AllocationCount << " allocations.\n";
}

    // int *x = new int[42];
    // delete [] x;

    // ... some complex body of code

    // delete [] x;

