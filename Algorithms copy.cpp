// #pragma once

// #include <array>
// #include <iostream>
// #include <string>
// #include <memory>
// #include <vector>

// #include "Array.h"
// #include "Dataset.cpp"
// #include "LinkedList.h"

// namespace PerformanceEvaluation {

//     // TODO: Can implement each of the various searching and sorting algorithms.

//     /*
//     * Sorting algorithms
//     * 1. Bubble Sort
//     * 2. Selection Sort
//     * 3. Insertion Sort
//     * 4. Merge Sort
//     * 5. Quick Sort
//     * 6. Heap Sort
//     * ... 
//     **/ 

//     /*
//     * Searching algorithms
//     * 1. Linear Search
//     * 2. Binary Search 
//     **/ 

//     class Algorithm {
//         public:
//             Algorithm(const Algorithm&) = delete;
            
//             Algorithm& operator=(const Algorithm&) = delete; 

//             static void MergeSort(LinkedList& linked_list) {
//                 getAlgorithm().mergeSortImpl(linked_list);
//             }
            
//             static void QuickSort(LinkedList& linked_list) {
//                 getAlgorithm().quickSortImpl(linked_list);
//             }
            
//             static void HeapSort(LinkedList& linked_list) {
//                 getAlgorithm().heapSortImpl(linked_list);
//             }
            
//             static void SelectionSort(LinkedList& linked_list) {
//                 getAlgorithm().selectionSortImpl(linked_list);
//             }
            
//             static void InsertionSort(LinkedList& linked_list) {
//                 getAlgorithm().insertionSortImpl(linked_list);
//             }

//             static void BubbleSort(LinkedList& linked_list) {
//                 getAlgorithm().bubbleSortImpl(linked_list);
//             }

//         private:
//             Algorithm() {}

//             void mergeSortImpl(LinkedList& linked_list) {
//                 mergeSort(linked_list.getHead());
//             }
            
//             void quickSortImpl(LinkedList& linked_list) {
//                 quickSort(linked_list.getHead());
//             }
            
//             void heapSortImpl(LinkedList& linked_list) {
//                 heapSort(linked_list.getHead());
//             }
            
//             void bubbleSortImpl(LinkedList& linked_list) {
//                 bubbleSort(linked_list.getHead());
//             }
            
//             void selectionSortImpl(LinkedList& linked_list) {
//                 selectionSort(linked_list.getHead());
//             }
            
//             void insertionSortImpl(LinkedList& linked_list) {
//                 insertionSort(linked_list.getHead());
//             }

//         protected:
//             static Algorithm& getAlgorithm() {
//                 static Algorithm algorithm;
//                 return algorithm;
//             }

//             LinkedListNode* quickSort(LinkedListNode* temp) {
                
//             }
            
//             LinkedListNode* heapSort(LinkedListNode* temp) {

//             }
            
//             LinkedListNode* bubbleSort(LinkedListNode* temp) {

//             }
            
//             LinkedListNode* selectionSort(LinkedListNode* temp) {

//             }
            
//             LinkedListNode* insertionSort(LinkedListNode* temp) {

//             }

//             // Helper function to split the linked list into two halves
//             LinkedListNode* getMiddle(LinkedListNode* temp) {
//                 if (temp == nullptr) {
//                     // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
//                     return temp;
//                 }

//                 LinkedListNode* first_half = temp;
//                 LinkedListNode* second_half = temp->next;
                
//                 // Iterate until second_half reaches the end of node, by then first_half will be the middle node
//                 while (second_half && second_half->next) {
//                     first_half = first_half->next;
//                     second_half = second_half->next->next;
//                 }

//                 return first_half; // first_half is the middle node
//             }

//             // Helper function to merge two sorted linked lists 
//             LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right) {
//                 LinkedListNode* dummy = new LinkedListNode({}); // Dummy node to simplify the merge process
//                 LinkedListNode* tail = dummy;

//                 DateUtility date_utility{};
//                 int32_t left_year = date_utility.getYear(left->data.date);
//                 int32_t right_year = date_utility.getYear(right->data.date);
            
//                 while (left != nullptr && right != nullptr) {
//                     if (left_year <= right_year) {
//                         tail->next = left;
//                         left = left->next;
//                     } else {
//                         tail->next = right;
//                         right = right->next;
//                     }

//                     tail = tail->next;
//                 }

//                 // Attach the remaining elements
//                 if (left != nullptr) {
//                     tail->next = left;
//                 } else {
//                     tail->next = right;
//                 }

//                 LinkedListNode* merged_head = dummy->next;
                
//                 delete dummy;
//                 dummy = nullptr;
                
//                 return merged_head;
//             }

//             // Applies merge sort recursively 
//             LinkedListNode* mergeSort(LinkedListNode* temp) {                
//                 // List is already sorted if list is empty
//                 if (temp == nullptr || temp->next == nullptr) {
//                     // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
//                     return temp;
//                 }

//                 // Get the middle of list
//                 LinkedListNode* middle = getMiddle(temp);
//                 LinkedListNode* second_half = middle->next;

//                 // Split the list into two halves
//                 middle->next = nullptr;

//                 // Recursive sort
//                 LinkedListNode* left = mergeSort(temp);
//                 LinkedListNode* right = mergeSort(second_half);

//                 // Merge the sorted halves
//                 return merge(left, right);
//             }

//     protected:
//         // bool setCriteria(const Dataset& first_dataset, const Dataset& second_dataset) {
//         //     // Primary criteria is to sort from date, then secondary criteria is from subject 
//         //     if (first_dataset.date != second_dataset.date)
//         //         return compareDate(first_dataset.date, second_dataset.date);

//         //     return compareSubject(first_dataset.subject, second_dataset.subject);
//         // }

//         // constexpr bool compareTitle(std::string_view first_title, std::string_view second_title) {
//         //     return first_title > second_title;
//         // }
        
//         // constexpr bool compareText(std::string_view first_text, std::string_view second_text) {
//         //     return first_text > second_text;
//         // }

//         // constexpr bool compareSubject(std::string_view first_subject, std::string_view second_subject) {
//         //     return first_subject > second_subject;
//         // }

//         // constexpr bool compareDate(std::string_view first_date, std::string_view second_date) {
//         //     // std::cout << "Date compared!\n";
            
//         //     return first_date > second_date;
//         // }

//         // template<typename T> 
//         // void swap(T value_1, T value_2) {
//         //     T temp = std::move(value_1);
//         //     value_1 = std::move(value_2);
//         //     value_2 = std::move(temp);
//         // }

//         // template<typename T> 
//         // void swap(T value_1, T value_2, bool (*compareFunc)(const Dataset&, const Dataset&)) {
//         //     if (compareFunc) {
//         //         T temp = std::move(value_1);
//         //         value_1 = std::move(value_2);
//         //         value_2 = std::move(temp);
//         //     }
//         // }
//     };
// } // namespace PerformanceEvaluation



//             // void bubbleSort(const std::array<Dataset, 25000>& dataset) {
//             //     size_t size = dataset.size();

//             //     for (size_t i = 0; i != size; i++) {
//             //         for (size_t j = 0; j != size - i; j++) {
//             //             bool criteria = setCriteria(dataset[j], dataset[j+1]);
//             //             if (criteria)
//             //                 swap(dataset[j], dataset[j+1]);
//             //         }
//             //     }
//             // }
