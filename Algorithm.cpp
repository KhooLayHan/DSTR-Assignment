#include <array>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Array.cpp"
#include "Dataset.h"
#include "DLL.h"
#include "DateUtility.cpp"

using namespace std;

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
            
            static void QuickSort(LinkedList& linked_list) {
                 getAlgorithm().quickSortImpl(linked_list);
             }
            
            static void HeapSort(LinkedList& linked_list) {
                 getAlgorithm().heapSortImpl(linked_list);
            }

            // static void SelectionSort(LinkedList& linked_list) {
            //     getAlgorithm().selectionSortImpl(linked_list);
            // }
            
            static void InsertionSortCircular(LinkedList& linked_list) {
                getAlgorithm().insertionSortCircularImpl(linked_list);
            }
            

            // static void BubbleSort(LinkedList& linked_list) {
            //     getAlgorithm().bubbleSortImpl(linked_list);
            // }

            // Linear Search Function
            static LinkedListNode* LinearSearch(LinkedList& linked_list, const string& targetDate) {
                return getAlgorithm().linearSearchImpl(linked_list, targetDate);
            }

            // Binary Search Function
            static LinkedListNode* BinarySearch(LinkedList& linked_list, const std::string& targetDate) {
                return getAlgorithm().binarySearchImpl(linked_list, targetDate);
            }
            
        private:
            Algorithm() {}

            void mergeSortImpl(LinkedList& linked_list) {
                LinkedListNode* head = linked_list.getHead();
                mergeSort(&head);
                linked_list.setHead(head);
            }
            
            void quickSortImpl(LinkedList& linked_list) {
                LinkedListNode* head = linked_list.getHead();
                head = quickSort(head);
                linked_list.setHead(head);
            }
            
            
            void heapSortImpl(LinkedList& linked_list) {
                LinkedListNode* head = linked_list.getHead();
                head = heapSort(head);
                linked_list.setHead(head);
            }
        
            
            // void bubbleSortImpl(LinkedList& linked_list) {
            //     bubbleSort(linked_list.getHead());
            // }
            
            // void selectionSortImpl(LinkedList& linked_list) {
            //    selectionSort(linked_list.getHead());
            // }
            
            void insertionSortCircularImpl(LinkedList& linked_list) {
                LinkedListNode* head = linked_list.getHead();
                head = insertionSortCircular(head);
                linked_list.setHead(head);
            }

            // Linear Search Implementation
            LinkedListNode* linearSearchImpl(LinkedList& linked_list, const string& targetDate) {
                DateUtility dateUtility;
                LinkedListNode* current = linked_list.getHead();
    
                while (current != nullptr) {
                    if (current->data.date == targetDate) {
                        cout << "Record found with date: " << current->data.date << endl;
                        return current;
                    }
                    current = current->next;
                }
    
                cout << "Record not found with date: " << targetDate << endl;
                return nullptr;
            }

            // Binary Search Implementation
            LinkedListNode* binarySearchImpl(LinkedList& linked_list, const std::string& targetDate) {
                if (!linked_list.getHead()) {
                    return nullptr;
                }
            
                LinkedListNode* left = linked_list.getHead();
                LinkedListNode* right = nullptr;
            
                // Get the last node (right)
                LinkedListNode* temp = left;
                while (temp->next) {
                    temp = temp->next;
                }
                right = temp;
            
                DateUtility date_utility;
            
                while (left && right && left != right->next) {
                    LinkedListNode* middle = getMiddle(left, right);
            
                    auto [middle_day, middle_month, middle_year] = date_utility.parseDate(middle->data.date);
                    auto [target_day, target_month, target_year] = date_utility.parseDate(targetDate);
            
                    if (middle_year == target_year && middle_month == target_month && middle_day == target_day) {
                        return middle;
                    }
            
                    bool isTargetBeforeMiddle = (target_year < middle_year) ||
                                                (target_year == middle_year && target_month < middle_month) ||
                                                (target_year == middle_year && target_month == middle_month && target_day < middle_day);
            
                    if (isTargetBeforeMiddle) {
                        right = middle->prev;
                    } else {
                        left = middle->next;
                    }
                }
            
                return nullptr;
            }
            
            LinkedListNode* getMiddle(LinkedListNode* left, LinkedListNode* right) {
                if (!left) return nullptr;
            
                LinkedListNode* slow = left;
                LinkedListNode* fast = left;
            
                while (fast != right && fast->next != right) {
                    fast = fast->next;
                    if (fast != right) {
                        fast = fast->next;
                        slow = slow->next;
                    }
                }
            
                return slow;
            }

        protected:
            static Algorithm& getAlgorithm() {
                static Algorithm algorithm;
                return algorithm;
            }

            LinkedListNode* quickSort(LinkedListNode* head) {
                if (!head || !head->next) {
                    return head;
                }
            
                LinkedListNode *left = nullptr, *right = nullptr;
                LinkedListNode *pivot = partition(head, &left, &right);
            
                left = quickSort(left);
                right = quickSort(right);
            
                LinkedListNode* result = nullptr;
                LinkedListNode* tail = nullptr;
            
                // Connect left part to pivot
                if (left) {
                    result = left;
                    tail = left;
                    while (tail->next) {
                        tail = tail->next;
                    }
                    tail->next = pivot;
                } else {
                    result = pivot;
                }
            
                pivot->next = right;
            
                return result;
            }
            
            LinkedListNode* partition(LinkedListNode* head, LinkedListNode** left, LinkedListNode** right) {
                DateUtility date_utility;
            
                LinkedListNode* pivot = head;
                LinkedListNode* current = head->next;
                pivot->next = nullptr;
            
                LinkedListNode* leftTail = nullptr;
                LinkedListNode* rightTail = nullptr;
            
                while (current) {
                    LinkedListNode* next = current->next;
                    current->next = nullptr;
            
                    auto [curr_day, curr_month, curr_year] = date_utility.parseDate(current->data.date);
                    auto [pivot_day, pivot_month, pivot_year] = date_utility.parseDate(pivot->data.date);
            
                    bool isLess = (curr_year < pivot_year) ||
                                  (curr_year == pivot_year && curr_month < pivot_month) ||
                                  (curr_year == pivot_year && curr_month == pivot_month && curr_day < pivot_day);
            
                    if (isLess) {
                        if (!*left) {
                            *left = current;
                            leftTail = current;
                        } else {
                            leftTail->next = current;
                            leftTail = current;
                        }
                    } else {
                        if (!*right) {
                            *right = current;
                            rightTail = current;
                        } else {
                            rightTail->next = current;
                            rightTail = current;
                        }
                    }
                    current = next;
                }
            
                return pivot;
            }
            
            
            LinkedListNode* heapSort(LinkedListNode* head) {
                if (!head || !head->next) {
                    return head;
                }
            
                // Convert linked list to array
                int length = 0;
                LinkedListNode* temp = head;
                while (temp) {
                    length++;
                    temp = temp->next;
                }
            
                LinkedListNode** nodeArray = new LinkedListNode*[length];
            
                temp = head;
                for (int i = 0; i < length; i++) {
                    nodeArray[i] = temp;
                    temp = temp->next;
                }
            
                // Perform heap sort on nodeArray based on dates
                heapSortArray(nodeArray, length);
            
                // Reconstruct the linked list from the sorted array
                for (int i = 0; i < length - 1; ++i) {
                    nodeArray[i]->next = nodeArray[i + 1];
                }
                nodeArray[length - 1]->next = nullptr;
            
                LinkedListNode* newHead = nodeArray[0];
            
                delete[] nodeArray;
                return newHead;
            }
            
            void heapSortArray(LinkedListNode** arr, int n) {
                // Build Min Heap (ascending order)
                for (int i = n / 2 - 1; i >= 0; i--) {
                    heapify(arr, n, i);
                }
            
                // Extract elements from heap one by one
                for (int i = n - 1; i > 0; i--) {
                    std::swap(arr[0], arr[i]);
                    heapify(arr, i, 0);
                }
            }
            
            void heapify(LinkedListNode** arr, int n, int i) {
                int smallest = i;  // We need Min-Heap
                int left = 2 * i + 1;
                int right = 2 * i + 2;
            
                DateUtility date_utility;
            
                // auto getDateKey = [&](LinkedListNode* node) -> std::tuple<int, int, int> {
                //     return date_utility.parseDate(node->data.date);
                // };

                constexpr auto CompareAndSortDate = [](const DateUtility& date_utility, const std::string& first_date, const std::string& second_date) {
                    const auto& [left_day, left_month, left_year] = date_utility.parseDate(first_date);
                    const auto& [right_day, right_month, right_year] = date_utility.parseDate(second_date);
                
                    // TODO: Might need to replace this with own implementation for std::tie() 
                    return std::tie(left_year, left_month, left_day) <= std::tie(right_year, right_month, right_day);
                };
            
                if (left < n && CompareAndSortDate(date_utility, arr[left]->data.date, arr[smallest]->data.date)) {
                    smallest = left;
                }
            
                if (right < n && CompareAndSortDate(date_utility, arr[right]->data.date, arr[smallest]->data.date)) {
                    smallest = right;
                }
            
                if (smallest != i) {
                    std::swap(arr[i], arr[smallest]);
                    heapify(arr, n, smallest);
                }
            }
            
            
            // LinkedListNode* bubbleSort(LinkedListNode* temp) {

            // }
            
            // LinkedListNode* selectionSort(LinkedListNode* temp) {

            // }
            
            LinkedListNode* insertionSortCircular(LinkedListNode* head) {
                if (!head || !head->next || head->next == head) {
                    return head; // Already sorted if 0, 1 node, or self-looped circular
                }
            
                DateUtility date_utility;
                LinkedListNode* sorted = nullptr;
                LinkedListNode* current = head;
            
                // We need to break the circle temporarily to traverse
                LinkedListNode* end = head;
                while (end->next != head) {
                    end = end->next;
                }
                end->next = nullptr; // Break the circle temporarily
            
                // Process each node and insert into sorted
                while (current != nullptr) {
                    LinkedListNode* next = current->next;
            
                    if (!sorted || compareDate(current, sorted, date_utility)) {
                        // Insert at head
                        current->next = sorted;
                        sorted = current;
                    } else {
                        LinkedListNode* temp = sorted;
                        while (temp->next != nullptr && !compareDate(current, temp->next, date_utility)) {
                            temp = temp->next;
                        }
                        current->next = temp->next;
                        temp->next = current;
                    }
            
                    current = next;
                }
            
                // Restore the circular structure
                LinkedListNode* tail = sorted;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
                tail->next = sorted; // Make it circular again
            
                return sorted;
            }
            
            // Helper to compare dates between nodes
            bool compareDate(LinkedListNode* a, LinkedListNode* b, DateUtility& date_utility) {
                auto [a_day, a_month, a_year] = date_utility.parseDate(a->data.date);
                auto [b_day, b_month, b_year] = date_utility.parseDate(b->data.date);
            
                if (a_year != b_year) return a_year < b_year;
                if (a_month != b_month) return a_month < b_month;
                return a_day < b_day;
            }
            

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
