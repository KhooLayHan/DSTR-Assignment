// // C Headers
// #include <cstdio>

// // C++ Headers
// #include <cassert>
// #include <iomanip>
// #include <iostream>
// #include <string>

// // Modules
// #include "Algorithms.cpp" 
// #include "FileHandling.cpp"
// #include "Benchmark.cpp"
// #include "LinkedList.h"
// #include "Dataset.cpp"
// // #include "SimpleLogger.cpp"

// //     // (__DATE__, __TIME__, __FILE__, __LINE__, log_level, msg) 
// // #define LOG(msg, log_level) 
// // { 
// //     std::cout << "[" << __DATE__ << " | " 
// //         << __TIME__ << " | " 
// //         << std::setw(50) << __FILE__ << " | " 
// //         << std::setw(5) << __LINE__ << " | " 
// //         << std::setw(5) << (int)log_level << "] " 
// //         << msg << "\n" 
// //     ; 
// // } 
// // ! Not allow to use this list of built-in containers: https://www.geeksforgeeks.org/containers-cpp-stl/

// static int s_AllocationCount = 0; 

// void* operator new(size_t size) {
//     // std::cout << "Allocated " << size << " bytes\n";
//     s_AllocationCount++;
//     return malloc(size);
// }

// int main(/* int argc, char** argv */)
// {
//     {
//         PerformanceEvaluation::Benchmark benchmark;
//         PerformanceEvaluation::LinkedList linked_list;
        
//         // PerformanceEvaluation::FileHandling::readCSV("./CSV/test.csv", linked_list);
//         PerformanceEvaluation::FileHandling::readCSV("./CSV/test.csv", linked_list);

//         // linked_list.bubbleSort();
        
//         // linked_list.displayAll();
//         // linked_list.displayTitle();
//         // linked_list.displayText();
//         // linked_list.displaySubject();
//         // linked_list.displayDate();

//         // benchmark.duration([&]{ linked_list.displayAll(); });
//         // linked_list.displayAll();
//     }
//     {
//         // PerformanceEvaluation::Benchmark benchmark_2;
//         // PerformanceEvaluation::LinkedList linked_list_2;
//         // linked_list_2.addBegin({ "text", "title", "subject", "2016" });
//         // // linked_list.addBegin("text 2016");
//         // linked_list_2.addEnd({ "text2", "title2", "subject2", "2017" });
//         // linked_list_2.display();
//     }
//     // benchmark.startTimer();

//     // PerformanceEvaluation::Dataset::getDataset().getDate();

//     // PerformanceEvaluation::LinkedList linked_list;
//     // linked_list.addBegin({ "text", "title", "subject", "2016" });
//     // linked_list.addBegin("text 2016");
//     // linked_list.addEnd({ "text2", "title2", "subject2", "2017" });

//     // linked_list.addEnd("date 2016");

//     // linked_list.findTargetIndex();

//     // linked_list.display();
//     // std::cout << "----------------" << std::endl;
//     // linked_list.search("2016", PerformanceEvaluation::Criteria::DATE);
//     // linked_list.search("subject", PerformanceEvaluation::Criteria::SUBJECT);
//     // linked_list.deleteNode("One");
//     // linked_list.display();

//     // PerformanceEvaluation::Sort::bubbleSort();
    

//     // std::cout << "\nIgnore: HelloWorld\n";
//     // if (argc == 1)  {
//     //     std::cout << "No command-line arguments specified.\n";
//     // } else {
//     //     std::cout << argv[0] << "\t" << argv[1] << "\n";
//     // }


//     // std::cout << "----------------" << std::endl;
//     // PerformanceEvaluation::FileHandling::readFile("sample.txt");
//     // PerformanceEvaluation::FileHandling file_handle;
//     // file_handle.readCSVFile("./CSV/fake.csv", linked_list);

//     // file_handle.readFile("sample.txt");

//     // linked_list.display();
//     // linked_list.deleteNode("date");
//     // linked_list.deleteNode("subject");

//     // PerformanceEvaluation::FileHandling::writeFile("./Logs/log.txt", "test");


//     // std::cout << "\n\n\n---------------------------------\n\n\n\n";
    
//     // benchmark.endTimer();
//     // benchmark.durationMicroseconds();

//     std::cout << s_AllocationCount << " allocations.\n";

// }

//     // int *x = new int[42];
//     // delete [] x;

//     // ... some complex body of code

//     // delete [] x;

