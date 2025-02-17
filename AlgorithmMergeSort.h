// #pragma once

// #include <array>
// #include <iostream>
// #include <string>
// #include <memory>
// #include <vector>

// #include "Array.h"
// #include "Dataset.h"
// #include "LinkedList.h"
// #include "DateUtility.h"

// #include "SimpleConsoleLogger.h"
// #include "SimpleLoggingService.h"

// namespace PerformanceEvaluation {
//     class AlgorithmMergeSort {
//         public:
//             void MergeSort(LinkedList& linked_list) {
//                 LinkedListNode* head = linked_list.getHead();
//                 mergeSort(&head);
//                 linked_list.setHead(head);
//             }
        
//         protected:
//             // Applies merge sort recursively 
//             void mergeSort(LinkedListNode** head) {                
//                 // List is already sorted if list is empty
//                 if (!(*head) || !((*head)->m_Next)) {
//                     SimpleConsoleLogger console;
//                     SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");
                    
//                     return;
//                 }

//                 LinkedListNode* left = nullptr;
//                 LinkedListNode* right = nullptr;

//                 //Split and get middle of list
//                 getMiddle(*head, &left, &right);

//                 mergeSort(&left);
//                 mergeSort(&right);

//                 // Merge the sorted halves                
//                 *head = merge(left, right);
//             }

//             // Helper function to split the linked list into two halves
//             void getMiddle(LinkedListNode* source, LinkedListNode** left, LinkedListNode** right) {
//                 if (!source || !(source->m_Next)) {
//                     SimpleConsoleLogger console;
//                     SimpleLoggingService::UseWarnLogger(console, "The linked list is empty.");
                    
//                     *left = source;
//                     *right = nullptr;

//                     return;
//                 }

//                 LinkedListNode* first_half = source;
//                 LinkedListNode* second_half = source->m_Next;
                
//                 // Iterate until second_half reaches the end of node, by then first_half will be the middle node
//                 while (second_half && second_half->m_Next) {
//                     first_half = first_half->m_Next;
//                     second_half = second_half->m_Next->m_Next;
//                 }

//                 *left = source;
//                 *right = first_half->m_Next;
//                 first_half->m_Next = nullptr;
//             }

//             // Helper function to merge two sorted linked lists 
//             LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right) {
//                 DateUtility date_utility{};

//                 // Sort by year
//                 if (!left)
//                     return right;
//                 if (!right)
//                     return left;

//                 LinkedListNode* result = nullptr;

//                 // auto [left_day, left_month, left_year] = date_utility.parseDate(left->m_Data.m_Date);
//                 // auto [right_day, right_month, right_year] = date_utility.parseDate(right->m_Data.m_Date);

//                 constexpr auto CompareAndSortDate = [](const DateUtility& date_utility, const std::string& first_date, const std::string& second_date) {
//                     const auto [left_day, left_month, left_year] = date_utility.ParseDate(first_date);
//                     const auto [right_day, right_month, right_year] = date_utility.ParseDate(second_date);
                
//                     return std::tie(left_year, left_month, left_day) <= std::tie(right_year, right_month, right_day);
//                 };

//                 if (CompareAndSortDate(date_utility, left->m_Data.m_Date, right->m_Data.m_Date)) {
//                     result = left;
//                     result->m_Next = merge(left->m_Next, right);
//                 } else {
//                     result = right;
//                     result->m_Next = merge(left, right->m_Next);
//                 }
            
//                 return result;
//             } 
//     };
// } // namespace PerformanceEvaluation
