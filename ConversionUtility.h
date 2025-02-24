#pragma once

#include <cmath>

#include "Array.h"
#include "Dataset.h"
#include "FileHandling.h"
#include "HashMap.h"
#include "HashSet.h"
#include "LinkedList.h"
#include "Vector.h"
#include "WordList.h"
#include "WordListSorted.h"

#include "DynamicArray.h"

#include <functional>
namespace PerformanceEvaluation
{
    HashMap<std::string, int32_t> GetWordCount(const WordList&);
    
    HashMap<std::string, int32_t> GetWordCount(const DynamicArray<std::string>&);
 
    WordList ConvertLinkedListToWordList(const LinkedList&, HashSet<std::string>&);

    DynamicArray<std::string> ConvertDynamicArrayToWordArray(const DynamicArray<Dataset>&, HashSet<std::string>&);

    // Extract word-count pairs and sort them to sorted linked list
    WordListSorted CheckAndSortHashMapLinkedList(HashMap<std::string, int32_t>&);
    
    // Extract word-count pairs and sort them to sorted word array
    DynamicArray<std::string> CheckAndSortHashMapArray(HashMap<std::string, int32_t>&);

    struct KeyValue {
        std::string m_Key;
        int32_t m_Value;

        // Allow construction from a std::pair<std::string, int>
        KeyValue& operator=(const std::pair<std::string, int>& p) {
            m_Key = p.first;
            m_Value = p.second;
            return *this;
        }
    };

    // Miscellaneous Question 2 Extra Exclusive
    void Question_2_LinkedList_ExtraExclusive(const FilePath& true_file_path = "./CSV/true.csv", const FilePath& fake_file_path = "./CSV/fake.csv");

    void Question_2_Array_ExtraExclusive(const FilePath& true_file_path = "./CSV/true.csv", const FilePath& fake_file_path = "./CSV/fake.csv");

    constexpr double CalculatePercentage(size_t numerator, size_t denominator) {
        return denominator == 0 ? 0.0 : std::round((static_cast<double>(numerator) / denominator) * 10000) / 100.0;
    };

    void DisplayFirst(size_t, const DynamicArray<Dataset>&);
    void DisplayAll(const DynamicArray<std::string>&);

    template <typename T>
    void MergeSort(DynamicArray<T>& arr) {
        if (arr.GetLength() <= 1)
            return; // Already sorted

        DynamicArray<T> temp(arr.GetLength()); // Temporary array for merging

        auto merge = [](DynamicArray<T>& arr, DynamicArray<T>& temp, size_t left, size_t mid, size_t right) {
            size_t i = left, j = mid + 1, k = left;

            // Merge both halves
            while (i <= mid && j <= right) {
                if (arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }

            // Copy any remaining elements from left subarray
            while (i <= mid)
                temp[k++] = arr[i++];

            // Copy any remaining elements from right subarray
            while (j <= right)
                temp[k++] = arr[j++];

            // Copy sorted elements back into original array
            for (size_t idx = left; idx <= right; idx++)
                arr[idx] = temp[idx];
        };

        std::function<void(DynamicArray<T>&, DynamicArray<T>&, size_t, size_t)> mergeSortHelper =
            [&](DynamicArray<T>& arr, DynamicArray<T>& temp, size_t left, size_t right) {
                if (left >= right)
                    return;

                size_t mid = left + (right - left) / 2;
                mergeSortHelper(arr, temp, left, mid);
                mergeSortHelper(arr, temp, mid + 1, right);
                merge(arr, temp, left, mid, right);
            };

        mergeSortHelper(arr, temp, 0, arr.GetLength() - 1);
    }
} // namespace PerformanceEvaluation
