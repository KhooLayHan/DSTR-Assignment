// #pragma once

// #include <array>
// #include <iostream>
// #include <string>
// #include <memory>
// #include <vector>

// #include "Array.h"
// #include "Dataset.h"
// #include "LinkedList.h"
// #include "DateUtility.cpp"

#include "Algorithm.h"

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

    LinkedListNode* Algorithm::LinearSearch(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseLinearSearchAlgorithm(target, linked_list, criteria, type);
        }

        return nullptr;
    }

    LinkedList Algorithm::LinearSearchAndCopy(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            return search_interface->UseLinearSearchAndCopyAlgorithm(target, linked_list, criteria, type);
        }

        return {};
    }
    
    void Algorithm::LinearSearchAndDisplay(LinkedList& linked_list, Search<LinkedList, LinkedListNode*>* search_interface, std::string_view target, Criteria criteria, SearchType type) {
        if (search_interface) {
            search_interface->UseLinearSearchAndDisplayAlgorithm(target, linked_list, criteria, type);
        }
    }

    void Algorithm::SortBy(LinkedList& linked_list, Sort<LinkedList, LinkedListNode*>* sort_interface) {
        if (sort_interface) {
            sort_interface->UseSortingAlgorithm(linked_list);
        }
    }

    // class Algorithm {
    //     public:
    //         Algorithm(const Algorithm&) = delete;
            
    //         Algorithm& operator=(const Algorithm&) = delete; 

    //         static void MergeSort(LinkedList& linked_list) {
    //             getAlgorithm().mergeSortImpl(linked_list);
    //         }
            
    //         // static void QuickSort(LinkedList& linked_list) {
    //         //     getAlgorithm().quickSortImpl(linked_list);
    //         // }
            
    //         // static void HeapSort(LinkedList& linked_list) {
    //         //     getAlgorithm().heapSortImpl(linked_list);
    //         // }
            
    //         // static void SelectionSort(LinkedList& linked_list) {
    //         //     getAlgorithm().selectionSortImpl(linked_list);
    //         // }
            
    //         // static void InsertionSort(LinkedList& linked_list) {
    //         //     getAlgorithm().insertionSortImpl(linked_list);
    //         // }

    //         // static void BubbleSort(LinkedList& linked_list) {
    //         //     getAlgorithm().bubbleSortImpl(linked_list);
    //         // }

    //         static void MergeSort(Array& array) {
    //             getAlgorithm().mergeSortImpl(array, 0, array.getSize() - 1);
    //         }

    //         static void QuickSort(Array& array) {
    //             getAlgorithm().quickSortImpl(array, 0, array.getSize() - 1);
    //         }

    //         static void HeapSort(Array& array) {
    //             getAlgorithm().heapSortImpl(array);
    //         }

    //     private:
    //         Algorithm() {}

    //         void mergeSortImpl(LinkedList& linked_list) {
    //             LinkedListNode* head = linked_list.getHead();
    //             mergeSort(&head);
    //             linked_list.setHead(head);
    //         }
            
    //         // void quickSortImpl(LinkedList& linked_list) {
    //         //     quickSort(linked_list.getHead());
    //         // }
            
    //         // void heapSortImpl(LinkedList& linked_list) {
    //         //     heapSort(linked_list.getHead());
    //         // }
            
    //         // void bubbleSortImpl(LinkedList& linked_list) {
    //         //     bubbleSort(linked_list.getHead());
    //         // }
            
    //         // void selectionSortImpl(LinkedList& linked_list) {
    //         //     selectionSort(linked_list.getHead());
    //         // }
            
    //         // void insertionSortImpl(LinkedList& linked_list) {
    //         //     insertionSort(linked_list.getHead());
    //         // }

    //     protected:
    //         static Algorithm& getAlgorithm() {
    //             static Algorithm algorithm;
    //             return algorithm;
    //         }

    //         // LinkedListNode* quickSort(LinkedListNode* temp) {
                
    //         // }
            
    //         // LinkedListNode* heapSort(LinkedListNode* temp) {

    //         // }
            
    //         // LinkedListNode* bubbleSort(LinkedListNode* temp) {

    //         // }
            
    //         // LinkedListNode* selectionSort(LinkedListNode* temp) {

    //         // }
            
    //         // LinkedListNode* insertionSort(LinkedListNode* temp) {

    //         // }

    //         // Applies merge sort recursively 
    //         void mergeSort(LinkedListNode** head) {                
    //             // List is already sorted if list is empty
    //             if (!(*head) || !((*head)->m_Next)) {
    //                 // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
    //                 return;
    //             }

    //             LinkedListNode* left = nullptr;
    //             LinkedListNode* right = nullptr;

    //             //Split and get middle of list
    //             getMiddle(*head, &left, &right);

    //             // LinkedListNode* middle = getMiddle(temp);
    //             // LinkedListNode* second_half = middle->next;

    //             // // Split the list into two halves
    //             // middle->next = nullptr;

    //             // // Recursive sort
    //             // LinkedListNode* left = mergeSort(temp);
    //             // LinkedListNode* right = mergeSort(second_half);

    //             mergeSort(&left);
    //             mergeSort(&right);

    //             // Merge the sorted halves                
    //             *head = merge(left, right);
    //         }

    //         // Helper function to split the linked list into two halves
    //         void getMiddle(LinkedListNode* source, LinkedListNode** left, LinkedListNode** right) {
    //             if (!source || !(source->m_Next)) {
    //                 // SimpleLogger::Warn("The linked list is empty.", LogHandler::FILE);
    //                 *left = source;
    //                 *right = nullptr;

    //                 return;
    //             }

    //             LinkedListNode* first_half = source;
    //             LinkedListNode* second_half = source->m_Next;
                
    //             // Iterate until second_half reaches the end of node, by then first_half will be the middle node
    //             while (second_half && second_half->m_Next) {
    //                 first_half = first_half->m_Next;
    //                 second_half = second_half->m_Next->m_Next;
    //             }

    //             *left = source;
    //             *right = first_half->m_Next;
    //             first_half->m_Next = nullptr;
                
    //             // return first_half; // first_half is the middle node
    //         }

    //         // Helper function to merge two sorted linked lists 
    //         LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right) {
    //             DateUtility date_utility{};

    //             // Sort by year
    //             if (!left)
    //                 return right;
    //             if (!right)
    //                 return left;

    //             LinkedListNode* result = nullptr;

    //             // int32_t left_year = date_utility.getYear(left->data.date);
    //             // int32_t right_year = date_utility.getYear(right->data.date);
    //             // int32_t left_month = date_utility.getMonth(left->data.date);
    //             // int32_t right_month = date_utility.getMonth(right->data.date);
                
    //             auto [left_day, left_month, left_year] = date_utility.parseDate(left->m_Data.m_Date);
    //             auto [right_day, right_month, right_year] = date_utility.parseDate(right->m_Data.m_Date);

    //             // std::cout << left_year << "\t" << right_year << "\n";

    //             // LinkedListNode* dummy = new LinkedListNode({}); // Dummy node to simplify the merge process
    //             // LinkedListNode* tail = dummy;

            
    //             // while (left != nullptr && right != nullptr) {
    //             //     if (left_year <= right_year) {
    //             //         tail->next = left;
    //             //         left = left->next;
    //             //     } else {
    //             //         tail->next = right;
    //             //         right = right->next;
    //             //     }

    //             //     tail = tail->next;
    //             // }
                
    //             if (left_year != right_year) {
    //                 if (left_year <= right_year) {
    //                     result = left;
    //                     result->m_Next = merge(left->m_Next, right);
    //                 } else {
    //                     result = right;
    //                     result->m_Next = merge(left, right->m_Next);
    //                 }
    //             } else if (left_year == right_year && left_month != right_month) {
    //                 if (left_month <= right_month) {
    //                     result = left;
    //                     result->m_Next = merge(left->m_Next, right);
    //                 } else {
    //                     result = right;
    //                     result->m_Next = merge(left, right->m_Next);
    //                 }
    //             } else if (left_year == right_year && left_month == right_month && left_day != right_day) {
    //                 if (left_day <= right_day) {
    //                     result = left;
    //                     result->m_Next = merge(left->m_Next, right);
    //                 } else {
    //                     result = right;
    //                     result->m_Next = merge(left, right->m_Next);
    //                 }
    //             }

    //             return result;

    //             // Attach the remaining elements
    //             // if (left != nullptr) {
    //             //     tail->next = left;
    //             // } else {
    //             //     tail->next = right;
    //             // }

    //             // LinkedListNode* merged_head = dummy->next;
                
    //             // delete dummy;
    //             // dummy = nullptr;
                
    //             // return merged_head;
    //         }

    //         // Merge Sort Implementation for Array
    //         void mergeSortImpl(Array& array, int left, int right) {
    //             if (left >= right) return;

    //             int mid = left + (right - left) / 2;
    //             mergeSortImpl(array, left, mid);
    //             mergeSortImpl(array, mid + 1, right);
    //             merge(array, left, mid, right);
    //         }

    //         void merge(Array& array, int left, int mid, int right) {
    //             int n1 = mid - left + 1;
    //             int n2 = right - mid;

    //             std::vector<Dataset> leftArray(n1);
    //             std::vector<Dataset> rightArray(n2);

    //             for (int i = 0; i < n1; ++i) leftArray[i] = array.getElement(left + i);
    //             for (int i = 0; i < n2; ++i) rightArray[i] = array.getElement(mid + 1 + i);

    //             int i = 0, j = 0, k = left;
    //             DateUtility date_utility;

    //             while (i < n1 && j < n2) {
    //                 auto [left_day, left_month, left_year] = date_utility.parseDate(leftArray[i].m_Date);
    //                 auto [right_day, right_month, right_year] = date_utility.parseDate(rightArray[j].m_Date);

    //                 if (left_year < right_year || (left_year == right_year && left_month < right_month) ||
    //                     (left_year == right_year && left_month == right_month && left_day <= right_day)) {
    //                     array.setElement(k++, leftArray[i++]);
    //                 } else {
    //                     array.setElement(k++, rightArray[j++]);
    //                 }
    //             }

    //             while (i < n1) array.setElement(k++, leftArray[i++]);
    //             while (j < n2) array.setElement(k++, rightArray[j++]);
    //         }

    //         // QuickSort Implementation for Array
    //         void quickSortImpl(Array& array, int low, int high) {
    //             if (low < high) {
    //                 // Partition the array
    //                 int pivot = partition(array, low, high);
    //                 // Recursively sort the two subarrays
    //                 quickSortImpl(array, low, pivot - 1);
    //                 quickSortImpl(array, pivot + 1, high);
    //             }
    //         }

    //         // Partition function to divide the array into two subarrays based on the pivot
    //         int partition(Array& array, int low, int high) {
    //             Dataset pivot = array.getElement(high); // Pivot is the last element
    //             int i = low - 1; // Index of the smaller element

    //             DateUtility date_utility;

    //             // Iterate through the array and rearrange elements
    //             for (int j = low; j < high; ++j) {
    //                 auto [day, month, year] = date_utility.parseDate(array.getElement(j).m_Date);
    //                 auto [pivot_day, pivot_month, pivot_year] = date_utility.parseDate(pivot.m_Date);

    //                 // Compare the current element with the pivot
    //                 if (year < pivot_year || 
    //                 (year == pivot_year && month < pivot_month) ||
    //                 (year == pivot_year && month == pivot_month && day <= pivot_day)) {
    //                     // Swap elements if they are smaller than the pivot
    //                     ++i;
    //                     array.swap(i, j);
    //                 }
    //             }

    //             // Swap the pivot element to the correct position
    //             array.swap(i + 1, high);
    //             return i + 1; // Return the pivot index
    //         }

    //         // HeapSort Implementation for Array
    //         void heapSortImpl(Array& array) {
    //             int n = array.getSize();

    //             // Build a max heap
    //             for (int i = n / 2 - 1; i >= 0; --i) {
    //                 heapify(array, n, i);
    //             }

    //             // Extract elements from the heap one by one
    //             for (int i = n - 1; i > 0; --i) {
    //                 // Swap the root (maximum element) with the last element
    //                 array.swap(0, i);

    //                 // Heapify the reduced heap
    //                 heapify(array, i, 0);
    //             }
    //         }

    //         // Helper function to maintain the max heap property
    //         void heapify(Array& array, int n, int i) {
    //             int largest = i; // Initialize largest as root
    //             int left = 2 * i + 1; // Left child
    //             int right = 2 * i + 2; // Right child

    //             DateUtility date_utility;

    //             // If left child is larger than root
    //             if (left < n) {
    //                 auto [left_day, left_month, left_year] = date_utility.parseDate(array.getElement(left).m_Date);
    //                 auto [root_day, root_month, root_year] = date_utility.parseDate(array.getElement(largest).m_Date);

    //                 if (left_year > root_year || (left_year == root_year && left_month > root_month) ||
    //                     (left_year == root_year && left_month == root_month && left_day > root_day)) {
    //                     largest = left;
    //                 }
    //             }

    //             // If right child is larger than largest so far
    //             if (right < n) {
    //                 auto [right_day, right_month, right_year] = date_utility.parseDate(array.getElement(right).m_Date);
    //                 auto [largest_day, largest_month, largest_year] = date_utility.parseDate(array.getElement(largest).m_Date);

    //                 if (right_year > largest_year || (right_year == largest_year && right_month > largest_month) ||
    //                     (right_year == largest_year && right_month == largest_month && right_day > largest_day)) {
    //                     largest = right;
    //                 }
    //             }

    //             // If largest is not root, swap and continue heapifying
    //             if (largest != i) {
    //                 array.swap(i, largest);
    //                 heapify(array, n, largest);
    //             }
    //         }
    // };
} // namespace PerformanceEvaluation
