#pragma once

#include <array>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Array.h"
#include "Dataset.h"
#include "LinkedList.h"
#include "DateUtility.cpp"

namespace PerformanceEvaluation {

    // TODO: Can implement each of the various searching and sorting algorithms.

    /*
    * Sorting algorithms
    * 1. Bubble Sort
    * 2. Selection Sort
    * 3. Insertion Sort
    * 4. Merge Sort
    * 5. Quick Sort
    * 6. Heap Sort
    * ... 
    **/ 

    /*
    * Searching algorithms
    * 1. Linear Search
    * 2. Binary Search 
    **/ 

    class Algorithm {
        public:
            Algorithm(const Algorithm&) = delete;
            
            Algorithm& operator=(const Algorithm&) = delete; 

            static void MergeSort(LinkedList& linked_list) {
                getAlgorithm().mergeSortImpl(linked_list);
            }
            
            // virtual void MergeSort() const = 0;

            // static void QuickSort(LinkedList& linked_list) {
            //     getAlgorithm().quickSortImpl(linked_list);
            // }
            
            // static void HeapSort(LinkedList& linked_list) {
            //     getAlgorithm().heapSortImpl(linked_list);
            // }
            
            // static void SelectionSort(LinkedList& linked_list) {
            //     getAlgorithm().selectionSortImpl(linked_list);
            // }
            
            // static void InsertionSort(LinkedList& linked_list) {
            //     getAlgorithm().insertionSortImpl(linked_list);
            // }

            // static void BubbleSort(LinkedList& linked_list) {
            //     getAlgorithm().bubbleSortImpl(linked_list);
            // }

        private:
            Algorithm() {}

            void mergeSortImpl(LinkedList& linked_list) {
                LinkedListNode* head = linked_list.getHead();
                mergeSort(&head);
                linked_list.setHead(head);
            }
            
            // void quickSortImpl(LinkedList& linked_list) {
            //     quickSort(linked_list.getHead());
            // }
            
            // void heapSortImpl(LinkedList& linked_list) {
            //     heapSort(linked_list.getHead());
            // }
            
            // void bubbleSortImpl(LinkedList& linked_list) {
            //     bubbleSort(linked_list.getHead());
            // }
            
            // void selectionSortImpl(LinkedList& linked_list) {
            //     selectionSort(linked_list.getHead());
            // }
            
            // void insertionSortImpl(LinkedList& linked_list) {
            //     insertionSort(linked_list.getHead());
            // }

        protected:
            static Algorithm& getAlgorithm() {
                static Algorithm algorithm;
                return algorithm;
            }

            // LinkedListNode* quickSort(LinkedListNode* temp) {
                
            // }
            
            // LinkedListNode* heapSort(LinkedListNode* temp) {

            // }
            
            // LinkedListNode* bubbleSort(LinkedListNode* temp) {

            // }
            
            // LinkedListNode* selectionSort(LinkedListNode* temp) {

            // }
            
            // LinkedListNode* insertionSort(LinkedListNode* temp) {

            // }

            // Applies merge sort recursively 
            void mergeSort(LinkedListNode** head) {                
                // List is already sorted if list is empty
                if (!(*head) || !((*head)->next)) {
                    // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
                    return;
                }

                LinkedListNode* left = nullptr;
                LinkedListNode* right = nullptr;

                //Split and get middle of list
                getMiddle(*head, &left, &right);

                // LinkedListNode* middle = getMiddle(temp);
                // LinkedListNode* second_half = middle->next;

                // // Split the list into two halves
                // middle->next = nullptr;

                // // Recursive sort
                // LinkedListNode* left = mergeSort(temp);
                // LinkedListNode* right = mergeSort(second_half);

                mergeSort(&left);
                mergeSort(&right);

                // Merge the sorted halves                
                *head = merge(left, right);
            }

            // Helper function to split the linked list into two halves
            void getMiddle(LinkedListNode* source, LinkedListNode** left, LinkedListNode** right) {
                if (!source || !(source->next)) {
                    // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
                    *left = source;
                    *right = nullptr;

                    return;
                }

                LinkedListNode* first_half = source;
                LinkedListNode* second_half = source->next;
                
                // Iterate until second_half reaches the end of node, by then first_half will be the middle node
                while (second_half && second_half->next) {
                    first_half = first_half->next;
                    second_half = second_half->next->next;
                }

                *left = source;
                *right = first_half->next;
                first_half->next = nullptr;
                
                // return first_half; // first_half is the middle node
            }

            // Helper function to merge two sorted linked lists 
            LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right) {
                DateUtility date_utility{};

                // Sort by year
                if (!left)
                    return right;
                if (!right)
                    return left;

                LinkedListNode* result = nullptr;

                // int32_t left_year = date_utility.getYear(left->data.date);
                // int32_t right_year = date_utility.getYear(right->data.date);
                // int32_t left_month = date_utility.getMonth(left->data.date);
                // int32_t right_month = date_utility.getMonth(right->data.date);
                
                auto [left_day, left_month, left_year] = date_utility.parseDate(left->data.date);
                auto [right_day, right_month, right_year] = date_utility.parseDate(right->data.date);

                // std::cout << left_year << "\t" << right_year << "\n";

                // LinkedListNode* dummy = new LinkedListNode({}); // Dummy node to simplify the merge process
                // LinkedListNode* tail = dummy;

            
                // while (left != nullptr && right != nullptr) {
                //     if (left_year <= right_year) {
                //         tail->next = left;
                //         left = left->next;
                //     } else {
                //         tail->next = right;
                //         right = right->next;
                //     }

                //     tail = tail->next;
                // }
                
                if (left_year != right_year) {
                    if (left_year <= right_year) {
                        result = left;
                        result->next = merge(left->next, right);
                    } else {
                        result = right;
                        result->next = merge(left, right->next);
                    }
                } else if (left_year == right_year && left_month != right_month) {
                    if (left_month <= right_month) {
                        result = left;
                        result->next = merge(left->next, right);
                    } else {
                        result = right;
                        result->next = merge(left, right->next);
                    }
                } else if (left_year == right_year && left_month == right_month && left_day != right_day) {
                    if (left_day <= right_day) {
                        result = left;
                        result->next = merge(left->next, right);
                    } else {
                        result = right;
                        result->next = merge(left, right->next);
                    }
                }

                return result;

                // Attach the remaining elements
                // if (left != nullptr) {
                //     tail->next = left;
                // } else {
                //     tail->next = right;
                // }

                // LinkedListNode* merged_head = dummy->next;
                
                // delete dummy;
                // dummy = nullptr;
                
                // return merged_head;
            }
    };
} // namespace PerformanceEvaluation
