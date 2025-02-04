// #pragma once

// #include <iostream>

// /*
// * Sorting algorithms
// * 1. Bubble Sort
// * 2. Selection Sort
// * 3. Insertion Sort
// * 4. Merge Sort
// * 5. Quick Sort
// * 6. Heap Sort
// * ... 
// **/ 

// #include "Dataset.cpp"
// #include "LinkedList.h"

// namespace PerformanceEvaluation
// {
//     // Implemented just using functions/methods.

//     enum class SortingAlgorithm {
//         BUBBLE = 0,
//         SELECTION = 1,
//         INSERTION = 2,
//         MERGE = 3,
//         QUICK = 4,
//         HEAP = 5,
//     };

//     void bubbleSort(const Dataset::Category& category, ) {
//         for (int k = 0; k != size; k++) {
//             bool is_swapped = false;
            
//             for (int i = 0; i != (size - k); i++) {    
//                 // In ascending order 
//                 if (category.subject)
                
//                 if (arr[i] > arr[i+1]) {
//                     int32_t temp = arr[i];
//                     arr[i] = arr[i+1];
//                     arr[i+1] = temp;

//                     is_swapped = true;
//                 }
//             }

//             if (is_swapped == false) {
//                 break;
//             }
//         }
//     }


//     class Sort {
//         public: 
//             static void bubbleSort(int32_t arr[], std::size_t size) {
//                 for (int k = 0; k != size; k++) {
//                     bool is_swapped = false;
                    
//                     for (int i = 0; i != (size - k); i++) {    
//                         // In ascending order 
//                         if (arr[i] > arr[i+1]) {
//                             int32_t temp = arr[i];
//                             arr[i] = arr[i+1];
//                             arr[i+1] = temp;

//                             is_swapped = true;
//                         }
//                     }

//                     if (is_swapped == false) {
//                         break;
//                     }
//                 }
//             }

//             void bubbleSort(const Dataset::Category& category_1, const Dataset::Category& category_2) {
//                 auto [text_1, title_1, subject_1, date_1] = category_1;
//                 auto [text_2, title_2, subject_2, date_2] = category_2;
                
//                 std::string temp = "";

//                 for (int k = 0; k != size; k++) {
//                     bool is_swapped = false;
                    
//                     for (int i = 0; i != (size - k); i++) {    
//                         // In ascending order 

//                         if (compareDate(date_1, date_2)) {
//                             temp = date_1;
//                             date_1 = date_2;
//                             date_2 = temp;
//                         } 
//                         if (compareText(text_1, text_2)) {
//                             temp = t_1;
//                             date_1 = date_2;
//                             date_2 = temp;
//                         } 
//                         if (compareDate(date_1, date_2)) {
//                             temp = date_1;
//                             date_1 = date_2;
//                             date_2 = temp;
//                         } 
//                         if (compareDate(date_1, date_2)) {
//                             temp = date_1;
//                             date_1 = date_2;
//                             date_2 = temp;
//                         } 
//                     }

//                     if (is_swapped == false) {
//                         break;
//                     }
//                 }
//             }

//             void swap(Dataset::Category&& category_1, Dataset::Category&& category_2) {
//                 Dataset::Category temp = std::move(category_1);
//                 category_1 = std::move(category_2);
//                 category_2 = std::move(temp);
//             }

//             bool compareDataset(const Dataset::Category& category_1, const Dataset::Category& category_2) {
//                 auto [text_1, title_1, subject_1, date_1] = category_1;
//                 auto [text_2, title_2, subject_2, date_2] = category_2;
                
//                 if (date_1 != date_2)
//                     return compareDate(date_1, date_2);
//                 // if (text_1 != text_2)
//                 //     return compareDate(date_1, date_2);
//                 // if (date_1 != date_2)
//                 //     return compareDate(date_1, date_2);
//                 // if (date_1 != date_2)
//                 //     return compareDate(date_1, date_2);
//             }



//             bool compareTitle(const Dataset::Category& category_1, const Dataset::Category& category_2) {
//                 return category_1.title > category_2.title;
//             }
            
//             bool compareText(const Dataset::Category& category_1, const Dataset::Category& category_2) {
//                 return category_1.text > category_2.text;
//             }

//             bool compareSubject(const Dataset::Category& category_1, const Dataset::Category& category_2) {
//                 return category_1.subject > category_2.subject;
//             }

//             bool compareDate(const Dataset::Category& category_1, const Dataset::Category& category_2) {
//                 return category_1.date > category_2.date;
//             }

//             bool compareDate(std::string_view date_1, std::string_view date_2) {
//                 return date_1 > date_2;
//             }

//             static void bubbleSort(const LinkedList& linked_list_1, const LinkedList& linked_list_2, std::size_t size) {
//                 for (int k = 0; k != size; k++) {
//                     bool is_swapped = false;

//                     // linked_list_1

//                     // for (int i = 0; i != sizeof(category); i++) {    
//                     //     // In ascending order 
//                     //     if (arr[i] > arr[i+1]) {
//                     //         int32_t temp = arr[i];
//                     //         arr[i] = arr[i+1];
//                     //         arr[i+1] = temp;

//                     //         is_swapped = true;
//                     //     }
//                     // }

//                     // if (is_swapped == false) {
//                     //     break;
//                     // }
//                 }
//             }
//     };

        
//         // for (int i = 0; i < n - 1; i++) {
//         //     for (int j = 0; j < n - i - 1; j++) {
//         //         if (arr[j] > arr[j + 1])
//         //             swap(arr[j], arr[j + 1]);
//         //     }
//         // }
    
    

// } // namespace PerformanceEvaluation
