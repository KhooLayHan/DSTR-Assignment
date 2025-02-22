// #include <iostream>

// #include "SearchWordList.h"

// #include "SimpleConsoleLogger.h"
// #include "SimpleLoggingService.h"

// namespace PerformanceEvaluation
// {
//     WordListNode* SearchWordList::LinearSearchWord(std::string_view target, const WordList& linked_list, SearchType type) {
//         WordListNode* temp = linked_list.GetHead();
        
//         while (temp) {
//             const std::string& str = temp->m_Data;

//             auto is_found = [&, temp](std::string_view target, std::string_view dataset_str) {
//                 if (dataset_str.empty()) {
//                     SimpleConsoleLogger console;
//                     SimpleLoggingService::UseWarnLogger(console, "Criteria to search for target node was not specified, defaulted to empty string.");
//                 } 
                
//                 return Contains(target, dataset_str, type) ? temp : nullptr;
//             };

//             is_found(target, str);

//             temp = temp->m_Next;
//         }

//         return nullptr;
//     } 

//     WordList SearchWordList::LinearSearchWordAndCopy(std::string_view target, const WordList& linked_list, SearchType type) {
//         WordList new_list;
//         WordListNode* new_tail = nullptr;
//         WordListNode* temp = linked_list.GetHead();
    
//         while (temp) {
//             const std::string& str = temp->m_Data;
                
//             auto is_found_and_copy = [&, temp](std::string_view target, std::string_view str) {
//                 if (str.empty()) {
//                     SimpleConsoleLogger console;
//                     SimpleLoggingService::UseWarnLogger(console, "Criteria to search for target node was not specified, defaulted to empty string.");
//                 }
                
//                 if (Contains(target, str, type)) {
//                     WordListNode* new_node = new WordListNode(temp->m_Data); // Deep copy
                    
//                     if (!new_list.GetHead()) {
//                         new_list.InsertEnd(new_node->m_Data);
//                         new_tail = new_list.GetHead();
//                     } else {
//                         new_tail->m_Next = new_node;
//                         new_tail = new_node;
                        
//                         // new_list.setLength(++i);
//                     }
//                 }
//             };

//             is_found_and_copy(target, str);

//             temp = temp->m_Next;
//         }

//         return new_list;
//     }

//     void SearchWordList::LinearSearchWordAndDisplay(std::string_view target, const WordList& linked_list, SearchType type) {
//         WordListNode* temp = linked_list.GetHead();
                
//         while (temp) {
//             const std::string& str = temp->m_Data;
                
//             auto is_found_and_display = [&, temp](std::string_view target, std::string_view dataset_str) {
//                 if (dataset_str.empty()) {
//                     SimpleConsoleLogger console;
//                     SimpleLoggingService::UseWarnLogger(console, "Criteria to search for target node was not specified, defaulted to empty string.");
//                 }
                
//                 if (Contains(target, dataset_str, type)) {
//                     std::cout << str << "\n";
//                 }
//             };

//             is_found_and_display(target, str);
//             temp = temp->m_Next;
//         }
//     }

//     // void SearchWordList::LinearSearchAll(const WordList& linked_list) {
//     //     WordListNode* temp = linked_list.GetHead();
//     //     temp = nullptr;
//     //     // while (temp) {
//     //     //     const Dataset& dataset = temp->m_Data;

//     //     //     // for (std::string word : dataset.m_Title) {

//     //     //     // }
//     //     // }
//     // }

//     // void Binary(std::string_view target, WordList& linked_list, Criteria criteria) override {

//     // }
// } // namespace PerformanceEvaluation


//         // if (linked_list.getHead() == nullptr) {
//         //     SimpleConsoleLogger console;
//         //     SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");

//         //     return;
//         // }

//         // WordListNode* temp = linked_list.getHead();
        
//         // while (temp != nullptr) { 
//         //     Dataset dataset = temp->data;
            
//         //     // switch (criteria) {
//         //     //     case Criteria::TITLE:

//         //             if (dataset.title.find(target) != std::string::npos) {
//         //                 m_LinkedList.insertEnd(dataset);                                
//         //             } 
//         //         return m_LinkedList;
//         //             // displayAllAfterSearch(dataset, dataset.title, target);
//         //             // break;
//         //         // case Criteria::TEXT:
//         //         //     displayAllAfterSearch(dataset, dataset.text, target);
//         //         //     break;
//         //         // case Criteria::SUBJECT:
//         //         //     displayAllAfterSearch(dataset, dataset.subject, target);
//         //         //     break;
//         //         // case Criteria::DATE:
//         //         //     displayAllAfterSearch(dataset, dataset.date, target);
//         //         //     break;
//         //     // }

//         //     // temp = temp->next;
//         // };
